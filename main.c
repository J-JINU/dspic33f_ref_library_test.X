/* 
 * File:   main.c
 * Author: THESYSTEM
 *
 * Created on 2024년 1월 18일 (목), 오후 4:36
 */
#include "dspic33fj256gp710aLIB/system.h"



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

uint16_t test;
unsigned long millis = 0;

void T1_callback(){
    millis++;
}

void init_INT_callback(){
    Timer1_OverflowCallbackRegister(T1_callback);
}

void setup(){
    init_system();
    init_INT_callback();
}

void main() {
    setup();
    test = LATAbits.LATA0;
    while(true){
        test = 0;
    }
}

