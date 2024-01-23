#include "SPI.h"

uint16_t* cs1;
static void (*SPI1_OverflowCallback)(void);
static void SPI1_DefaultOverflowCallback(void);

void init_SPI(){
    initSPI1(1);
    initSPI2();
}

void initSPI1(uint8_t mode){
    SPI1CON1bits.MSTEN = 1;
    setSPI1MODE(mode);
	SPI1CON1bits.MODE16	=	0;
    
    /*set spi clock*/
    //SPRE
    //1:1 111, 1:2 110, 1:3 101, 1:4 100, 1:5 011, 1:6 010, 1:7 001, 1:8 000
	SPI1CON1bits.SPRE	=	0b110;
    //PPRE
    //1:1 11, 1:4 10, 1:16 01, 1:64 00
	SPI1CON1bits.PPRE	=	0b10;
    
    
	SPI1CON1bits.DISSDO	=	0;
	SPI1CON1bits.DISSCK	=	0;
    SPI1_OverflowCallbackRegister(SPI1_DefaultOverflowCallback);
    _SPI1IF = 0;
    _SPI1IE = 1;
	SPI1STATbits.SPIEN = 1;
}

void setSPI1MODE(uint8_t mode){
    switch(mode){
        case 0:
            SPI1CON1bits.CKP	=	0;
            SPI1CON1bits.CKE	=	1;
            break;
        case 1:
            SPI1CON1bits.CKP	=	0;
            SPI1CON1bits.CKE	=	0;
            break;
        case 2:
            SPI1CON1bits.CKP	=	1;
            SPI1CON1bits.CKE	=	1;
            break;
        case 3:
            SPI1CON1bits.CKP	=	1;
            SPI1CON1bits.CKE	=	0;
            break;
    }
}

uint8_t sendSPI1BUF( unsigned char i ){
    SPI1BUF = i;					// write to buffer for TX
    while(!SPI1STATbits.SPIRBF);	// wait for transfer to complete
    return SPI1BUF;
}

uint8_t readSPI1BUF(void){
    SPI1BUF = 0;
    while(!SPI1STATbits.SPIRBF);
    return SPI1BUF;
}

void SPI1_Write_object(uint16_t* CS, uint8_t * object_addr, uint16_t size){
    *CS = 0;
    uint8_t* byte;
    for(byte = object_addr ; size-- ; byte++){
       sendSPI1BUF(*byte);
    }
    *CS = 1;
}

void SPI1_OverflowCallbackRegister(void (* CallbackHandler)(void))
{
    SPI1_OverflowCallback = CallbackHandler;
}

static void SPI1_DefaultOverflowCallback(void){
    
}

void __attribute__((__interrupt__)) _SPI1Interrupt(void)
{
    _SPI1IF = 0;
    if(SPI1_OverflowCallback){
        SPI1_OverflowCallback();
    }
}




void initSPI2(){        //플래시 메모리에서 사용
    SPI2CON1bits.CKP	=	0;  //Idle state for clock is a low level; active state is a high level
	SPI2CON1bits.CKE	=	1;  //Serial output data changes on transition from active clock state to Idle clock state
	SPI2CON1bits.MODE16	=	0;
	SPI2CON1bits.MSTEN	=	1;
    //SCL 10MHz
	SPI2CON1bits.SPRE	=	0b100;
	SPI2CON1bits.PPRE	=	0b10;
	SPI2CON1bits.DISSDO	=	0;
	SPI2CON1bits.DISSCK	=	0;
	// ?Enable SPI module (SPI1STATbits.SPIEN=?)
	SPI2STATbits.SPIEN = 1;
}

uint8_t sendSPI2BUF( unsigned char i ){
    SPI2BUF = i;					// write to buffer for TX
    while(!SPI2STATbits.SPIRBF);	// wait for transfer to complete
    return SPI2BUF;    				// read the received value
}

uint8_t readSPI2BUF(void){
    SPI2BUF = 0;
    while(!SPI2STATbits.SPIRBF);
    return SPI2BUF;
}