#include "UART.h"

/* cmd 있을때 사용할 콜백 */
void (*UART1_RxInterruptHandler)(uint16_t, uint8_t*);
static void UART1_RxDefaultInterruptHandler(uint16_t, uint8_t*);

void init_uart(){
    init_uart1(Baud115200);
    init_uart2();
}

void init_uart1(uint16_t baud){
    // This is an EXAMPLE, so brutal typing goes into explaining all bit sets

	// The HPC16 board has a DB9 connector wired to UART2, so we will
	// be configuring this port only

	// configure U1MODE
	U1MODEbits.UARTEN = 0;			// Bit15 TX, RX DISABLED, ENABLE at end of func
	//U1MODEbits.notimplemented;	// Bit14
	U1MODEbits.USIDL = 0;			// Bit13 Continue in Idle
	U1MODEbits.IREN = 0;			// Bit12 No IR translation
	U1MODEbits.RTSMD = 0;			// Bit11 Simplex Mode
	//U1MODEbits.notimplemented;	// Bit10
	U1MODEbits.UEN = 0;				// Bits8,9 TX,RX enabled, CTS,RTS not
	U1MODEbits.WAKE = 0;			// Bit7 No Wake up (since we don't sleep here)
	U1MODEbits.LPBACK = 0;			// Bit6 No Loop Back
	U1MODEbits.ABAUD = 0;			// Bit5 No Autobaud (would require sending '55')
	U1MODEbits.URXINV = 0;			// Bit4 IdleState = 1  (for dsPIC)
	U1MODEbits.BRGH = 0;			// Bit3 16 clocks per bit period
	U1MODEbits.PDSEL = 0;			// Bits1,2 8bit, No Parity
	U1MODEbits.STSEL = 0;			// Bit0 One Stop Bit
	
	// Load a value into Baud Rate Generator.  Example is for 9600.
	// See section 19.3.1 of datasheet.
	//  U1BRG = (Fcy/(16*BaudRate))-1
	//  U1BRG = (32M/(16*9600))-1
	//  U1BRG = 240
	U1BRG = baud;

	// Load all values in for U1STA SFR
	U1STAbits.UTXISEL1 = 1;			//Bit15 Int when Char is transferred (1/2 config!)
	U1STAbits.UTXINV = 0;			//Bit14 N/A, IRDA config
	U1STAbits.UTXISEL0 = 0;			//Bit13 Other half of Bit15
	//U1STAbits.notimplemented = 0;	//Bit12
	U1STAbits.UTXBRK = 0;			//Bit11 Disabled
    U1STAbits.UTXBF = 0;			//Bit9 *Read Only Bit*
	U1STAbits.TRMT = 0;				//Bit8 *Read Only bit*
	U1STAbits.URXISEL = 0;			//Bits6,7 Int. on character recieved
	U1STAbits.ADDEN = 0;			//Bit5 Address Detect Disabled
	U1STAbits.RIDLE = 0;			//Bit4 *Read Only Bit*
	U1STAbits.PERR = 0;				//Bit3 *Read Only Bit*
	U1STAbits.FERR = 0;				//Bit2 *Read Only Bit*
	U1STAbits.OERR = 0;				//Bit1 *Read Only Bit*
	U1STAbits.URXDA = 0;			//Bit0 *Read Only Bit*

	_U1RXIP = 5;
	_U1TXIP = 5;
    UART1_SetRXInterruptHandler(UART1_RxDefaultInterruptHandler);
	_U1TXIF = 0;			// Clear the Transmit Interrupt Flag
	_U1TXIE = 0;			// Enable Transmit Interrupts
	_U1RXIF = 0;			// Clear the Recieve Interrupt Flag
	_U1RXIE = 1;			// Enable Recieve Interrupts

	U1MODEbits.UARTEN = 1;			// And turn the peripheral on
    U1STAbits.UTXEN = 1;			//Bit10 TX pins controlled by periph
}

bool U1_TX_ready(){
    return U1STAbits.TRMT;
}

void U1_transmit_byte(uint8_t byte){
    while(!U1_TX_ready());
    U1TXREG = byte;
}

void U1_transmit_buf(uint8_t txDatabuf[], uint16_t size){
    uint8_t chksum = 0;
    for(int i = 0 ; i < size ; i++){
        while(!U1_TX_ready());
        chksum += *(txDatabuf + i);
        U1TXREG = *(txDatabuf + i);
    }
    while(!U1_TX_ready());
//    U1TXREG = (uint8_t)(256 - chksum);
    U1TXREG = chksum;
}

void U1_transmit_object(uint16_t cmd, uint8_t * object_addr, uint16_t size){
    uint8_t chksum = 0;
    while(!U1_TX_ready());
    U1TXREG = (uint8_t)(cmd >> 8);
    chksum += (uint8_t)(cmd >> 8);
    while(!U1_TX_ready());
    U1TXREG = (uint8_t)cmd;
    chksum += (uint8_t)cmd;
    while(!U1_TX_ready());
    U1TXREG = (uint8_t)(size >> 8);
    chksum += (uint8_t)(size >> 8);
    while(!U1_TX_ready());
    U1TXREG = (uint8_t)size;
    chksum += (uint8_t)size;
    
    uint8_t* byte;
    for(byte = object_addr ; size-- ; byte++){
        while(!U1_TX_ready());
        U1TXREG = *byte;
        chksum += *byte;
    }
    while(!U1_TX_ready());
//    U1TXREG = (uint8_t)(256 - chksum);
    U1TXREG = chksum;
}

void UART1_SetRXInterruptHandler(void (* callbackHandler)(uint16_t, uint8_t*))
{
    UART1_RxInterruptHandler = callbackHandler;
}

void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void)
{
    _U1RXIF = 0;
    if(UART1_RxInterruptHandler){
        uint16_t t = 0;
        uint8_t* a;
        UART1_RxDefaultInterruptHandler(t, a);
    }
}
static void UART1_RxDefaultInterruptHandler(uint16_t cmd, uint8_t* buf){
//        U1TXREG = U1RXREG; // loopback
}

void init_uart2(){
    
}