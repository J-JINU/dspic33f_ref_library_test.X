#include "DMA.h"

static void (*DMA0_OverflowCallback)(void);
static void DMA0_DefaultOverflowCallback(void);

void init_DMA(){
    initDMA0();
//    initDMA1();
}

void initDMA0(){
    DMA0_OverflowCallbackRegister(DMA0_DefaultOverflowCallback);
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
    if(DMA0_OverflowCallback){
        DMA0_OverflowCallback();
    }
}
void initDMA1(){
    
}
