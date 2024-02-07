#include "DMA.h"

static void (*DMA0_OverflowCallback)(uint16_t adcbuf[]);
static void DMA0_DefaultOverflowCallback();
static void (*DMA1_OverflowCallback)();
static void DMA1_DefaultOverflowCallback();

uint16_t ADC1buffer[32] __attribute__((space(dma)));
uint8_t uart1_tx_buf[256] __attribute__((space(dma)));


//uint8_t uart2_tx_buf[100] __attribute__((space(dma)));
//uint16_t adc1_buf[100] __attribute__((space(dma)));
//uint16_t adc2_buf[100] __attribute__((space(dma)));
void init_DMA(){
    initDMA0();
    initDMA1();
}

void initDMA0(){
    DMA0_OverflowCallbackRegister(DMA0_DefaultOverflowCallback);
    DMA0CONbits.AMODE = 2; // Peripheral Indirect Addressing mode
    DMA0CONbits.MODE = 0; // Continuous, Ping-Pong modes disabled
    DMA0CONbits.DIR = 0; //Read from Peripheral address, write to DPSRAM address
    DMA0PAD = (volatile unsigned int)&ADC1BUF0; // ADCBUF에서 가지고옴
    DMA0CNT = 4;   //DMA로 몇 번(몇 번 - 1) 처리할 거?
    DMA0REQ = 0b0001101;   //뭐를 DMA로 처리할 거?
    DMA0STA = __builtin_dmaoffset(&ADC1buffer); //ADCBUF에서 가지고 온거를 여기 받음
    IFS0bits.DMA0IF = 0;
    IEC0bits.DMA0IE = 1;
    DMA0CONbits.CHEN = 1;
}

void DMA0_OverflowCallbackRegister(void (* CallbackHandler)(uint16_t adcbuf[]))
{
    DMA0_OverflowCallback = CallbackHandler;
}

static void DMA0_DefaultOverflowCallback(){
    //add code
}

void __attribute__((interrupt, no_auto_psv)) _DMA0Interrupt(void){
    _DMA0IF = 0;
    if(DMA0_OverflowCallback){
        DMA0_OverflowCallback(ADC1buffer);
    }
}

void initDMA1(){
    _DMA1IF = 0;
    _DMA1IE = 0;
    // DMAXCON: DMA Channel X Control Register
    DMA1CONbits.SIZE = 1; // BYTE
    DMA1CONbits.DIR = 1; // Read from DPSRAM address, write to peripheral address
    DMA1CONbits.AMODE = 0;
    DMA1CONbits.MODE = 1;
    //DMAXREQ: DMA Channel X IRQ Select Register
    DMA1REQbits.IRQSEL = 0b0001100; //U1TX
    
    DMA1STA = __builtin_dmaoffset(&uart1_tx_buf);
    DMA1PAD = (volatile unsigned int) &U1TXREG;
    
    DMA1CNT = 15; // uart tx로 보낼 버퍼의 사이즈 - 1
    
    DMA1CONbits.CHEN = 0;
    DMA1REQbits.FORCE = 1;
}

void DMA1_uart_tx_object(uint16_t cmd, uint8_t * object_addr, uint16_t size){
    DMA1CNT = size + 4; //실제 사이즈에서 -1한 값임
    uart1_tx_buf[0] = (uint8_t)(cmd >> 8);
    uart1_tx_buf[1] = (uint8_t)cmd;
    uart1_tx_buf[2] = (uint8_t)(size >> 8);
    uart1_tx_buf[3] = (uint8_t)size;
//    for(int i = 4 ; i < DMA1CNT - 1; i++){
//        uart1_tx_buf[i] = *(object_addr + i - 4);
//    }
    for(int i = DMA1CNT - 1 ; i >= 4; i--){
        uart1_tx_buf[i] = *(object_addr + i - 4);
    }
    uart1_tx_buf[DMA1CNT] = cal_checksum(uart1_tx_buf, (DMA1CNT - 1));
    DMA1CONbits.CHEN = 1;
    DMA1REQbits.FORCE = 1;
}

uint8_t cal_checksum(uint8_t* buffer, uint16_t size){
    uint8_t checksum = 0;
    for(int i = size ; i >= 0 ; i--){
        checksum += *(buffer + i);
    }
    checksum = 0x100 - checksum;
    return (uint8_t)checksum;
}

void DMA1_OverflowCallbackRegister(void (* CallbackHandler)())
{
    DMA1_OverflowCallback = CallbackHandler;
}

static void DMA1_DefaultOverflowCallback(){
    //add code
}

void __attribute__((interrupt, no_auto_psv)) _DMA1Interrupt(void){
    _DMA1IF = 0;
    if(DMA1_OverflowCallback){
        DMA1_OverflowCallback();
    }
}