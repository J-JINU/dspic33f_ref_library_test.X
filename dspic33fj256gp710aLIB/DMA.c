#include "DMA.h"

static void (*DMA0_OverflowCallback)(void);
static void DMA0_DefaultOverflowCallback();

uint8_t TxBuffer[248] __attribute__((space(dma)));

void init_DMA(){
    initDMA0();
//    initDMA1();
}

void initDMA0(){
//    DMA3REQ = 0x000C;	// Select UART1 Transmitter
//	DMA3PAD = (volatile unsigned int) &U1TXREG;
//	DMA3CONbits.AMODE = 0;
//	DMA3CONbits.MODE  = 1;
//	DMA3CONbits.DIR   = 1;
//	DMA3CONbits.SIZE  = 1;	// Byte Transfer
//
//	DMA3CNT = 21;			// 22 DMA requests
//	DMA3CONbits.CHEN  = 0;
//	DMA3REQbits.FORCE = 1;
//
//	DMA3STA = __builtin_dmaoffset(DMA_TX_USART1);
//	_DMA3IF  = 0;			// Clear DMA Interrupt Flag
//	_DMA3IE  = 0;			// Clear DMA interrupt
    DMA0_OverflowCallbackRegister(DMA0_DefaultOverflowCallback);
    IFS0bits.DMA0IF = 0;
    IEC0bits.DMA0IE = 0;
    // DMAXCON: DMA Channel X Control Register
    DMA0CONbits.SIZE = 1; // BYTE
    DMA0CONbits.DIR = 1; // Read from DPSRAM address, write to peripheral address
    DMA0CONbits.AMODE = 0;
    DMA0CONbits.MODE = 1;
    //DMAXREQ: DMA Channel X IRQ Select Register
    DMA0REQbits.IRQSEL = 0b0001100; //U1TX
    
    DMA0STA = __builtin_dmaoffset(TxBuffer);
    DMA0PAD = (volatile unsigned int) &U1TXREG;
    
    DMA0CNT = 15; // uart tx로 보낼 버퍼의 사이즈 - 1
    
    DMA0CONbits.CHEN = 0;
    DMA0REQbits.FORCE = 1;
}

void set_DMA0CNT(uint16_t size){
    DMA0CNT = size -1;
}

void set_buffer(uint8_t * object_addr, uint16_t size){
    set_DMA0CNT(size);
    for(int i = 0 ; i < size; i++){
        TxBuffer[i] = *(object_addr + i);
    }
    start_dma();
}

void start_dma(){
    DMA0CONbits.CHEN = 1;
    DMA0REQbits.FORCE = 1;
}

void DMA0_OverflowCallbackRegister(void (* CallbackHandler)(void))
{
    DMA0_OverflowCallback = CallbackHandler;
}

static void DMA0_DefaultOverflowCallback(){
    //add code
}

void __attribute__((interrupt, no_auto_psv)) _DMA0Interrupt(void){
    IFS0bits.DMA0IF = 0;
//    DMA0CONbits.CHEN = 1; 
//    DMA0REQbits.FORCE = 1;
    if(DMA0_OverflowCallback){
        DMA0_OverflowCallback();
    }
}
void initDMA1(){
    
}



