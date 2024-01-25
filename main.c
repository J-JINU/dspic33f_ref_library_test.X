/* 
 * File:   main.c
 * Author: THESYSTEM
 *
 * Created on 2024년 1월 18일 (목), 오후 4:36
 */
#include "dspic33fj256gp710aLIB/system.h"
#include "dspic33fj256gp710aLIB/DMA.h"



///* MCU Environment SET */
//#define FCY 40000000UL
////FOSC
//#pragma config OSCIOFNC = OFF
//#pragma config FCKSM = CSECMD
//#pragma config POSCMD = XT
////FOSCSEL
//#pragma config FNOSC = PRIPLL
////FWDT
//#pragma config FWDTEN = OFF
//#pragma config ICS = PGD2
//#pragma config JTAGEN = OFF


//void setAbsoluteEnv() {
//    /*
//     ** calculate Fosc/Fcy
//     * Fcy = Fosc/2 = 40MHz
//     * Fin = 8MHz
//     * Fosc = Fin * M / (N1 * N2)
//     */
//    
//    PLLFBD = 38; // M = 40 calibration value 30M
//    CLKDIVbits.PLLPOST = 0; // N1 = 2
//    CLKDIVbits.PLLPRE = 0; // N2 = 2
//    OSCTUN = 0; // Tune FRC oscillator, if FRC is used
//
//    // Disable Watch Dog Timer
//    RCONbits.SWDTEN = 0;
//    RCONbits.SWR = 0;
//    RCONbits.WDTO = 0;
//
//    //-----------------------------------------------------------------------------------
//    // Clock switch to incorporate PLL
//    __builtin_write_OSCCONH(0x03); // Initiate Clock Switch to
//    // Primary Osilator with PLL (NOSC=0b011)
//    __builtin_write_OSCCONL(0x01); // Start clock switching
//
//    while (OSCCONbits.COSC != 0b011); // Wait for Clock switch to occur
//    while (OSCCONbits.LOCK != 1) {
//    };
//}




/*
 * 
 */

unsigned long millis = 0;
char testmessage[] = "helloworld!!";
void T1_callback(){
    millis++;
    if((millis&511)==0) _LATA0 = ~ _LATA0;
}
bool testflag = false;
int c = 0;
void dma_testcallback(){
    if(c++ == 247){
        c = 0;
        testflag = true;
    }
}

void init_INT_callback(){
    Timer1_OverflowCallbackRegister(T1_callback);
    DMA0_OverflowCallbackRegister(dma_testcallback);
}

void init_run_callback(){
    flash_readwriteRegister(sendSPI2BUF);
}

uint16_t flashPage= 10;
char test_char[] = "fuck!!fuck!!fuck!!fuck!!";
char test_read_char[50];
void SaveConfig()
{
	uint8_t nStep;
	uint8_t Buffer[EEPROM_SECTOR_SIZE];
	uint8_t *pBuffer;
	pBuffer = (uint8_t*)&test_char;
	for(nStep=0;nStep<(sizeof(test_char)) && (nStep<EEPROM_SECTOR_SIZE);nStep++) Buffer[nStep] = pBuffer[nStep];


	if(flash_write_page(flashPage,Buffer));
}

void committest(){
    if(testflag){
        testflag = false;
        uint8_t Buffer[EEPROM_SECTOR_SIZE];
        flash_commit(flashPage,Buffer);
    }
}

void ReadConfig()
{
	uint8_t nResult;
	uint8_t nStep;
	uint8_t Buffer[EEPROM_SECTOR_SIZE];
	uint8_t *pBuffer;
	
	nResult = flash_read_page(flashPage,Buffer);
	if(!nResult)
	return;

	pBuffer = (uint8_t*)&test_read_char;
	for(nStep=0;nStep<(  sizeof(test_read_char) );nStep++) pBuffer[nStep] = Buffer[nStep];
}

void setup(){
    init_system();
    init_INT_callback();
    init_run_callback();
    init_add_on();
}

void main() {
    setup();
    for(int i = 0; i < 4160; i++)
    {
     Nop();
    }
    U1_transmit_buf(testmessage, sizeof(testmessage)/sizeof(char));
    while(true){
    }
}

