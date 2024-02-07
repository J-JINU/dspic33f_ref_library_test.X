
#include <p33FJ256GP710A.h>

#include "gpio.h"

/* GPIO */
void init_GPIO(){
    // Port Direction and ...
	AD1PCFGL=0xFFFF;
	AD1PCFGH=0xFFFF;
    AD2PCFGL=0xFFFF;
    
	// #### PORTA Direction ####
    TRISAbits.TRISA15 = 1;
    TRISAbits.TRISA14 = 1;
    TRISAbits.TRISA13 = 1;
    TRISAbits.TRISA12 = 1;
    TRISAbits.TRISA10 = 1;
    TRISAbits.TRISA9 = 1;
    TRISAbits.TRISA7 = 1;
    TRISAbits.TRISA6 = 1;
    TRISAbits.TRISA5 = 0;
    TRISAbits.TRISA4 = 0;
    TRISAbits.TRISA3 = 0;
    TRISAbits.TRISA2 = 0;
    TRISAbits.TRISA1 = 0;
    TRISAbits.TRISA0 = 0;
	

	// #### PORTB Direction ####
    TRISBbits.TRISB15 = 1;
    TRISBbits.TRISB14 = 1;
    TRISBbits.TRISB13 = 1;
    TRISBbits.TRISB12 = 1;
    TRISBbits.TRISB11 = 1;
    TRISBbits.TRISB10 = 1;
    TRISBbits.TRISB9 = 1;
    TRISBbits.TRISB8 = 1;
    TRISBbits.TRISB7 = 1;
    TRISBbits.TRISB6 = 1;
    TRISBbits.TRISB5 = 1;
    TRISBbits.TRISB4 = 1;
    TRISBbits.TRISB3 = 1;
    TRISBbits.TRISB2 = 1;
    TRISBbits.TRISB1 = 1;
    TRISBbits.TRISB0 = 1;
    
	
	// #### PORTC Direction ####
    TRISCbits.TRISC15 = 1;
    TRISCbits.TRISC14 = 1;
    TRISCbits.TRISC13 = 1;
    TRISCbits.TRISC12 = 1;
    TRISCbits.TRISC4 = 1;
    TRISCbits.TRISC3 = 1;
    TRISCbits.TRISC2 = 1;
    TRISCbits.TRISC1 = 1;
	
	
	// #### PORTD Direction ####
    TRISDbits.TRISD15 = 1;
    TRISDbits.TRISD14 = 0;
    TRISDbits.TRISD13 = 0;
    TRISDbits.TRISD12 = 0;
    TRISDbits.TRISD11 = 1;
    TRISDbits.TRISD10 = 1;
    TRISDbits.TRISD9 = 1;
    TRISDbits.TRISD8 = 1;
    TRISDbits.TRISD7 = 0;
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD5 = 0;
    TRISDbits.TRISD4 = 0;
    TRISDbits.TRISD3 = 0;
    TRISDbits.TRISD2 = 0;
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD0 = 0;
	
	
	// #### PORTE Direction ####
    TRISEbits.TRISE7 = 0;
    TRISEbits.TRISE6 = 0;
    TRISEbits.TRISE5 = 0;
    TRISEbits.TRISE4 = 0;
    TRISEbits.TRISE3 = 0;
    TRISEbits.TRISE2 = 0;
    TRISEbits.TRISE1 = 0;
    TRISEbits.TRISE0 = 0;
	
	
	// #### PORTF Direction ####
    TRISFbits.TRISF13 = 0;
    TRISFbits.TRISF12 = 0;
    TRISFbits.TRISF8 = 1;
//    ODCFbits.ODCF8 = 1;
    TRISFbits.TRISF7 = 0;
//    ODCFbits.ODCF7 = 1;
    TRISFbits.TRISF6 = 0;
    TRISFbits.TRISF5 = 1;
    TRISFbits.TRISF4 = 1;
    TRISFbits.TRISF3 = 0;
    TRISFbits.TRISF2 = 1;
    TRISFbits.TRISF1 = 1;
    TRISFbits.TRISF0 = 1;

    
	// #### PORTG Direction ####
    TRISGbits.TRISG15 = 1;
    TRISGbits.TRISG14 = 1;
    TRISGbits.TRISG13 = 1;
    TRISGbits.TRISG12 = 0;
    TRISGbits.TRISG9 = 0;
    TRISGbits.TRISG8 = 1;
    TRISGbits.TRISG7 = 0;
    TRISGbits.TRISG6 = 0;
    TRISGbits.TRISG3 = 1;
    TRISGbits.TRISG2 = 1;
    TRISGbits.TRISG1 = 1;
    TRISGbits.TRISG0 = 1;
    LATA = 0x0000;
    LATB = 0x0000;
    LATC = 0x0000;
    LATD = 0x0000;
    LATE = 0x0000;
    LATF = 0x0000;
    LATG = 0x0000;
    
    _LATA0 = 1;
    _LATA1 = 1;
    _LATA2 = 1;
    _LATA3 = 1;
    _LATA4 = 1;
    _LATA5 = 1;
    _LATF12 = 1;
    _LATG9 = 1;
}

void extIntPin(){
    
    INTCON2bits.INT1EP = 1; //negative edge
    IFS1bits.INT1IF = 0;
    IEC1bits.INT1IE = 1;
}