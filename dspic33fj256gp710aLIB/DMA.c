#include "DMA.h"

static void (*DMA0_OverflowCallback)(void);
static void DMA0_DefaultOverflowCallback();

uint8_t TxBuffer[248] __attribute__((space(dma)));

void init_DMA(){
    initDMA0();
//    initDMA1();
}

void initDMA0(){
    DMA0_OverflowCallbackRegister(DMA0_DefaultOverflowCallback);
    IFS0bits.DMA0IF = 0;
    IEC0bits.DMA0IE = 1;
    // DMAXCON: DMA Channel X Control Register
    DMA0CONbits.SIZE = 1;
    DMA0CONbits.DIR = 1;
    DMA0CONbits.AMODE = 0;
    DMA0CONbits.MODE = 1;
    //DMAXREQ: DMA Channel X IRQ Select Register
    DMA0REQbits.IRQSEL = 0b0100001; //SPI2
    
    DMA0STA = __builtin_dmaoffset(TxBuffer);
    DMA0PAD = (volatile unsigned int) &SPI2BUF;
    
    DMA0CNT = 15;
    
    DMA0CONbits.CHEN = 1;
}

void set_buffer(uint8_t *pBuffer){
        for(int nStep=0;nStep<248;nStep++ )
	{
		TxBuffer[nStep] = pBuffer[nStep];
	}
    DMA0CNT = 247;
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
    DMA0CONbits.CHEN = 1; 
    DMA0REQbits.FORCE = 1;
    if(DMA0_OverflowCallback){
        DMA0_OverflowCallback();
    }
}
void initDMA1(){
    
}



