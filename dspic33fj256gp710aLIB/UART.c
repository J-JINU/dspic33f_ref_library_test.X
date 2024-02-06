#include "UART.h"

/* cmd 있을때 사용할 콜백 */
void (*UART1_RxCompleteInterruptHandler)(uint16_t, uint8_t*);
static void UART1_RxDefaultInterruptHandler(uint16_t, uint8_t*);
void (*UART2_RxCompleteInterruptHandler)(uint16_t, uint8_t*);
static void UART2_RxDefaultInterruptHandler(uint16_t, uint8_t*);

unsigned long * timecount;

uint8_t uart1_rx_buf[100];
uint8_t uart2_rx_buf[100];

void init_uart(){
    init_uart1(Baud115200);
    init_uart2(Baud9600);
}

void set_timeoutcount(unsigned long * milliscount){
    timecount = milliscount;
}

uint8_t CRC16 (const uint8_t *nData, uint16_t wLength)
{
static const uint16_t wCRCTable[] = {
   0X0000, 0XC0C1, 0XC181, 0X0140, 0XC301, 0X03C0, 0X0280, 0XC241,
   0XC601, 0X06C0, 0X0780, 0XC741, 0X0500, 0XC5C1, 0XC481, 0X0440,
   0XCC01, 0X0CC0, 0X0D80, 0XCD41, 0X0F00, 0XCFC1, 0XCE81, 0X0E40,
   0X0A00, 0XCAC1, 0XCB81, 0X0B40, 0XC901, 0X09C0, 0X0880, 0XC841,
   0XD801, 0X18C0, 0X1980, 0XD941, 0X1B00, 0XDBC1, 0XDA81, 0X1A40,
   0X1E00, 0XDEC1, 0XDF81, 0X1F40, 0XDD01, 0X1DC0, 0X1C80, 0XDC41,
   0X1400, 0XD4C1, 0XD581, 0X1540, 0XD701, 0X17C0, 0X1680, 0XD641,
   0XD201, 0X12C0, 0X1380, 0XD341, 0X1100, 0XD1C1, 0XD081, 0X1040,
   0XF001, 0X30C0, 0X3180, 0XF141, 0X3300, 0XF3C1, 0XF281, 0X3240,
   0X3600, 0XF6C1, 0XF781, 0X3740, 0XF501, 0X35C0, 0X3480, 0XF441,
   0X3C00, 0XFCC1, 0XFD81, 0X3D40, 0XFF01, 0X3FC0, 0X3E80, 0XFE41,
   0XFA01, 0X3AC0, 0X3B80, 0XFB41, 0X3900, 0XF9C1, 0XF881, 0X3840,
   0X2800, 0XE8C1, 0XE981, 0X2940, 0XEB01, 0X2BC0, 0X2A80, 0XEA41,
   0XEE01, 0X2EC0, 0X2F80, 0XEF41, 0X2D00, 0XEDC1, 0XEC81, 0X2C40,
   0XE401, 0X24C0, 0X2580, 0XE541, 0X2700, 0XE7C1, 0XE681, 0X2640,
   0X2200, 0XE2C1, 0XE381, 0X2340, 0XE101, 0X21C0, 0X2080, 0XE041,
   0XA001, 0X60C0, 0X6180, 0XA141, 0X6300, 0XA3C1, 0XA281, 0X6240,
   0X6600, 0XA6C1, 0XA781, 0X6740, 0XA501, 0X65C0, 0X6480, 0XA441,
   0X6C00, 0XACC1, 0XAD81, 0X6D40, 0XAF01, 0X6FC0, 0X6E80, 0XAE41,
   0XAA01, 0X6AC0, 0X6B80, 0XAB41, 0X6900, 0XA9C1, 0XA881, 0X6840,
   0X7800, 0XB8C1, 0XB981, 0X7940, 0XBB01, 0X7BC0, 0X7A80, 0XBA41,
   0XBE01, 0X7EC0, 0X7F80, 0XBF41, 0X7D00, 0XBDC1, 0XBC81, 0X7C40,
   0XB401, 0X74C0, 0X7580, 0XB541, 0X7700, 0XB7C1, 0XB681, 0X7640,
   0X7200, 0XB2C1, 0XB381, 0X7340, 0XB101, 0X71C0, 0X7080, 0XB041,
   0X5000, 0X90C1, 0X9181, 0X5140, 0X9301, 0X53C0, 0X5280, 0X9241,
   0X9601, 0X56C0, 0X5780, 0X9741, 0X5500, 0X95C1, 0X9481, 0X5440,
   0X9C01, 0X5CC0, 0X5D80, 0X9D41, 0X5F00, 0X9FC1, 0X9E81, 0X5E40,
   0X5A00, 0X9AC1, 0X9B81, 0X5B40, 0X9901, 0X59C0, 0X5880, 0X9841,
   0X8801, 0X48C0, 0X4980, 0X8941, 0X4B00, 0X8BC1, 0X8A81, 0X4A40,
   0X4E00, 0X8EC1, 0X8F81, 0X4F40, 0X8D01, 0X4DC0, 0X4C80, 0X8C41,
   0X4400, 0X84C1, 0X8581, 0X4540, 0X8701, 0X47C0, 0X4680, 0X8641,
   0X8201, 0X42C0, 0X4380, 0X8341, 0X4100, 0X81C1, 0X8081, 0X4040 };

    uint8_t nTemp;
    uint16_t wCRCWord = 0xFFFF;

   while (wLength--)
   {
      nTemp = *nData++ ^ wCRCWord;
      wCRCWord >>= 8;
      wCRCWord  ^= wCRCTable[nTemp];
   }
   return wCRCWord;
} // End: CRC16

void init_uart1(uint16_t baud){
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
    UART1_RxCompleteInterruptHandler = callbackHandler;
}

void __attribute__((interrupt, no_auto_psv)) _U1RXInterrupt(void)
{
    static uint8_t chksum = 0;
    static uint16_t recv_cmd = 0;
    static uint16_t recv_len = 0;
    static uint16_t total_recv_len = 0;
    static uint16_t recv_count = 0;
    static unsigned long timeout_count;
    static uint8_t temp = 0;
    _U1RXIF = 0;
    if((*timecount - timeout_count) > 5){
    /*
     * byte간 timeout으로 5ms선정
     * 5ms의 근거:9600bps는 1초에 960bytes 전송함
     * 9600에서 1byte당 소요시간은 약1.042ms임
     * 그리고 어떤 통신이던 연속으로 무한정 보낼 수 없음
     * 요청이 있을때마다 통신이 진행될 것임.
    */
        recv_count = 0;
        chksum = 0;
    }
    temp = U1RXREG;
    chksum += temp;
    if(recv_count < 2){
        recv_cmd = (recv_cmd << 8) + temp;
    }
    else if(recv_count < 4){
        recv_len = (recv_len << 8) + temp;
        total_recv_len = recv_len + 5;
         //total_recv_len = len + cmd.size+len.size+checksum.size
    }
    else if(recv_count < total_recv_len){
        uart1_rx_buf[recv_count-4] = temp;
    }
    recv_count++;
    timeout_count = *timecount;
    if((UART1_RxCompleteInterruptHandler != NULL) && (recv_count == total_recv_len))
    {
        if(chksum == 0){
            (*UART1_RxCompleteInterruptHandler)(recv_cmd, uart1_rx_buf);
        }
        recv_count = 0;
        chksum = 0;
    }
}
static void UART1_RxDefaultInterruptHandler(uint16_t cmd, uint8_t* buf){
//        U1TXREG = U1RXREG; // loopback
}



void init_uart2(uint16_t baud){//modbus
    // configure U1MODE
	U2MODEbits.UARTEN = 0;			// Bit15 TX, RX DISABLED, ENABLE at end of func
	//U1MODEbits.notimplemented;	// Bit14
	U2MODEbits.USIDL = 0;			// Bit13 Continue in Idle
	U2MODEbits.IREN = 0;			// Bit12 No IR translation
	U2MODEbits.RTSMD = 0;			// Bit11 Simplex Mode
	//U1MODEbits.notimplemented;	// Bit10
	U2MODEbits.UEN = 0;				// Bits8,9 TX,RX enabled, CTS,RTS not
	U2MODEbits.WAKE = 0;			// Bit7 No Wake up (since we don't sleep here)
	U2MODEbits.LPBACK = 0;			// Bit6 No Loop Back
	U2MODEbits.ABAUD = 0;			// Bit5 No Autobaud (would require sending '55')
	U2MODEbits.URXINV = 0;			// Bit4 IdleState = 1  (for dsPIC)
	U2MODEbits.BRGH = 0;			// Bit3 16 clocks per bit period
	U2MODEbits.PDSEL = 0;			// Bits1,2 8bit, No Parity
	U2MODEbits.STSEL = 0;			// Bit0 One Stop Bit
	
	// Load a value into Baud Rate Generator.  Example is for 9600.
	// See section 19.3.1 of datasheet.
	//  U1BRG = (Fcy/(16*BaudRate))-1
	//  U1BRG = (32M/(16*9600))-1
	//  U1BRG = 240
	U2BRG = baud;

	// Load all values in for U1STA SFR
	U2STAbits.UTXISEL1 = 1;			//Bit15 Int when Char is transferred (1/2 config!)
	U2STAbits.UTXINV = 0;			//Bit14 N/A, IRDA config
	U2STAbits.UTXISEL0 = 0;			//Bit13 Other half of Bit15
	//U1STAbits.notimplemented = 0;	//Bit12
	U2STAbits.UTXBRK = 0;			//Bit11 Disabled
    U2STAbits.UTXBF = 0;			//Bit9 *Read Only Bit*
	U2STAbits.TRMT = 0;				//Bit8 *Read Only bit*
	U2STAbits.URXISEL = 0;			//Bits6,7 Int. on character recieved
	U2STAbits.ADDEN = 0;			//Bit5 Address Detect Disabled
	U2STAbits.RIDLE = 0;			//Bit4 *Read Only Bit*
	U2STAbits.PERR = 0;				//Bit3 *Read Only Bit*
	U2STAbits.FERR = 0;				//Bit2 *Read Only Bit*
	U2STAbits.OERR = 0;				//Bit1 *Read Only Bit*
	U2STAbits.URXDA = 0;			//Bit0 *Read Only Bit*

	_U2RXIP = 5;
	_U2TXIP = 5;
    UART2_SetRXInterruptHandler(UART2_RxDefaultInterruptHandler);
	_U2TXIF = 0;			// Clear the Transmit Interrupt Flag
	_U2TXIE = 0;			// Enable Transmit Interrupts
	_U2RXIF = 0;			// Clear the Recieve Interrupt Flag
	_U2RXIE = 1;			// Enable Recieve Interrupts

	U2MODEbits.UARTEN = 1;			// And turn the peripheral on
    U2STAbits.UTXEN = 1;			//Bit10 TX pins controlled by periph
}

bool U2_TX_ready(){
    return U2STAbits.TRMT;
}

void U2_transmit_byte(uint8_t byte){
    while(!U2_TX_ready());
    U2TXREG = byte;
}

void U2_transmit_buf(uint8_t txDatabuf[], uint16_t size){
    uint8_t chksum = 0;
    for(int i = 0 ; i < size ; i++){
        while(!U2_TX_ready());
        chksum += *(txDatabuf + i);
        U2TXREG = *(txDatabuf + i);
    }
    while(!U2_TX_ready());
//    U2TXREG = (uint8_t)(256 - chksum);
    U2TXREG = chksum;
}

void U2_transmit_object(uint16_t cmd, uint8_t * object_addr, uint16_t size){
    uint8_t chksum = 0;
    while(!U2_TX_ready());
    U2TXREG = (uint8_t)(cmd >> 8);
    chksum += (uint8_t)(cmd >> 8);
    while(!U2_TX_ready());
    U2TXREG = (uint8_t)cmd;
    chksum += (uint8_t)cmd;
    while(!U2_TX_ready());
    U2TXREG = (uint8_t)(size >> 8);
    chksum += (uint8_t)(size >> 8);
    while(!U2_TX_ready());
    U2TXREG = (uint8_t)size;
    chksum += (uint8_t)size;
    
    uint8_t* byte;
    for(byte = object_addr ; size-- ; byte++){
        while(!U2_TX_ready());
        U2TXREG = *byte;
        chksum += *byte;
    }
    while(!U2_TX_ready());
//    U1TXREG = (uint8_t)(256 - chksum);
    U2TXREG = chksum;
}

void UART2_SetRXInterruptHandler(void (* callbackHandler)(uint16_t, uint8_t*))
{
    UART2_RxCompleteInterruptHandler = callbackHandler;
}

void __attribute__((interrupt, no_auto_psv)) _U2RXInterrupt(void)
{
    static uint8_t u2_chksum = 0;
    static uint16_t u2_recv_cmd = 0;
    static uint16_t u2_recv_len = 0;
    static uint16_t u2_total_recv_len = 0;
    static uint16_t u2_recv_count = 0;
    static unsigned long u2_timeout_count;
    static uint8_t temp = 0;
    _U2RXIF = 0;
    if((*timecount - u2_timeout_count) > 5){
    /*
     * byte간 timeout으로 5ms선정
     * 5ms의 근거:9600bps는 1초에 960bytes 전송함
     * 9600에서 1byte당 소요시간은 약1.042ms임
     * 그리고 어떤 통신이던 연속으로 무한정 보낼 수 없음
     * 요청이 있을때마다 통신이 진행될 것임.
    */
        u2_recv_count = 0;
        u2_chksum = 0;
    }
    temp = U2RXREG;
    u2_chksum += temp;
    if(u2_recv_count < 2){
        u2_recv_cmd = (u2_recv_cmd << 8) + temp;
    }
    else if(u2_recv_count < 4){
        u2_recv_len = (u2_recv_len << 8) + temp;
        u2_total_recv_len = u2_recv_len + 5;
         //total_recv_len = len + cmd.size+len.size+checksum.size
    }
    else if(u2_recv_count < u2_total_recv_len){
        uart2_rx_buf[u2_recv_count-4] = temp;
    }
    u2_recv_count++;
    u2_timeout_count = *timecount;
    if((UART2_RxCompleteInterruptHandler != NULL) && (u2_recv_count == u2_total_recv_len))
    {
        if(u2_chksum == 0){
            (*UART2_RxCompleteInterruptHandler)(u2_recv_cmd, uart2_rx_buf);
        }
        u2_recv_count = 0;
        u2_chksum = 0;
    }
}

static void UART2_RxDefaultInterruptHandler(uint16_t cmd, uint8_t* buf){
//        U2TXREG = U2RXREG; // loopback
}
