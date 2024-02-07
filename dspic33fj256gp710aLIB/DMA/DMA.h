/* 
 * File:   DMA.h
 * Author: THESYSTEM
 *
 * Created on January 19, 2024, 4:51 PM
 */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef DMA_H
#define	DMA_H

#ifdef	__cplusplus
extern "C" {
#endif
    
/* DMA는 총 8개가 있음 0~7까지 */
    
/* EX ADC DMA */
//void initDma0Analog(void){
//    DMA0CONbits.AMODE = 2; // Peripheral Indirect Addressing mode
//    DMA0CONbits.MODE = 0; // Continuous, Ping-Pong modes disabled
//    DMA0CONbits.DIR = 0; //Read from Peripheral address, write to DPSRAM address
//    DMA0PAD = (volatile unsigned int)&ADC2BUF0; // ADCBUF에서 가지고옴
//    DMA0CNT = 95;   //DMA로 몇 번(몇 번 - 1) 처리할 거?
//    DMA0REQ = 21;   //뭐를 DMA로 처리할 거?
//    DMA0STA = __builtin_dmaoffset(&ADC1buffer); //ADCBUF에서 가지고 온거를 여기 받음
//    IFS0bits.DMA0IF = 0;
//    IEC0bits.DMA0IE = 1;
//    DMA0CONbits.CHEN = 1;
//}
/* EX UART DMA */
//void initDma0UART(void){
//    IFS0bits.DMA0IF = 0;
//    IEC0bits.DMA0IE = 0;
//    // DMAXCON: DMA Channel X Control Register
//    DMA0CONbits.SIZE = 1; // BYTE
//    DMA0CONbits.DIR = 1; // Read from DPSRAM address, write to peripheral address
//    DMA0CONbits.AMODE = 0;
//    DMA0CONbits.MODE = 1;
//    //DMAXREQ: DMA Channel X IRQ Select Register
//    DMA0REQbits.IRQSEL = 0b0001100; //U1TX
//    
//    DMA0STA = __builtin_dmaoffset(TxBuffer);
//    DMA0PAD = (volatile unsigned int) &U1TXREG;
//    
//    DMA0CNT = 15; // uart tx로 보낼 버퍼의 사이즈 - 1
//    
//    DMA0CONbits.CHEN = 0;
//    DMA0REQbits.FORCE = 1;
//}

/* DMA처리할 수 있는 목록임
DMAXREQbits.IRQSEL: DMA Peripheral IRQ Number Select bits
1001111 = DAC1 Left Data Output (DAC1)
1001110 = DAC1 Right Data Output (DAC1)
1000110 = TX Data Request (ECAN1)
0111100 = CODEC Transfer Done (DCI)
0101101 = PMP Master Data Transfer (PMP)
0100010 = RX Data Ready (ECAN1)
0100001 = SPI2 Transfer Done (SPI2)SPI는 연구가 더 필요함
0011111 = UART2 Transmitter (UART2TX)
0011110 = UART2 Receiver (UART2RX)
0001101 = ADC1 Convert Done (ADC1)
0001100 = UART1 Transmitter (UART1TX)
0001011 = UART1 Receiver (UART1RX)
0001010 = Transfer Done (SPI1)
0001000 = Timer3 (TMR3)
0000111 = Timer2 (TMR2)
0000110 = Output Compare 2 (OC2)
0000101 = Input Capture 2 (IC2)
0000010 = Output Compare 1 (OC1)
0000001 = Input Capture 1 (IC1)
0000000 = External Interrupt 0 (INT0)
 */
    
    
void init_DMA();
uint8_t cal_checksum(uint8_t* buffer, uint16_t size);
void initDMA0();
void set_DMA0CNT(uint16_t size);
void DMA0_OverflowCallbackRegister(void (* CallbackHandler)(uint16_t adcbuf[]));
void initDMA1();
void start_dma();


#ifdef	__cplusplus
}
#endif

#endif	/* DMA_H */

