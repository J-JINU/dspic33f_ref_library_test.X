#include "system.h"

/* MCU Environment SET */
#define FCY 40000000UL
//FOSC
#pragma config OSCIOFNC = OFF
#pragma config FCKSM = CSECMD
#pragma config POSCMD = XT
//FOSCSEL
#pragma config FNOSC = PRIPLL
//FWDT
#pragma config FWDTEN = OFF
#pragma config ICS = PGD2
#pragma config JTAGEN = OFF

void init_system(){
    setAbsoluteEnv();
    init_GPIO();
    init_timer();
    init_ADC();
//    init_PWM1();
    init_SPI();
    init_CAN();
    
}

void setAbsoluteEnv() {
    /*
     ** calculate Fosc/Fcy
     * Fcy = Fosc/2 = 40MHz
     * Fin = 8MHz
     * Fosc = Fin * M / (N1 * N2)
     */
    
    PLLFBD = 38; // M = 40 calibration value 30M
    CLKDIVbits.PLLPOST = 0; // N1 = 2
    CLKDIVbits.PLLPRE = 0; // N2 = 2
    OSCTUN = 0; // Tune FRC oscillator, if FRC is used

    // Disable Watch Dog Timer
    RCONbits.SWDTEN = 0;
    RCONbits.SWR = 0;
    RCONbits.WDTO = 0;

    //-----------------------------------------------------------------------------------
    // Clock switch to incorporate PLL
    __builtin_write_OSCCONH(0x03); // Initiate Clock Switch to
    // Primary Osilator with PLL (NOSC=0b011)
    __builtin_write_OSCCONL(0x01); // Start clock switching

    while (OSCCONbits.COSC != 0b011); // Wait for Clock switch to occur
    while (OSCCONbits.LOCK != 1) {
    };
}