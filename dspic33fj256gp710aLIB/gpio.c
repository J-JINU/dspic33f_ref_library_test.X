
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
    TRISAbits.TRISA12 = 1;  //W5500 INT
    TRISAbits.TRISA10 = 1;
    TRISAbits.TRISA9 = 1;
    TRISAbits.TRISA7 = 1;
    TRISAbits.TRISA6 = 1;
    TRISAbits.TRISA5 = 0;   //LED5
    TRISAbits.TRISA4 = 0;   //LED4
    TRISAbits.TRISA3 = 0;   //LED3
    TRISAbits.TRISA2 = 0;   //LED2
    TRISAbits.TRISA1 = 0;   //LED1
    TRISAbits.TRISA0 = 0;   //LED0
	

	// #### PORTB Direction ####
    TRISBbits.TRISB15 = 1;  //HUMIDI sig
    TRISBbits.TRISB14 = 1;  //COM sig
    TRISBbits.TRISB13 = 1;  //INFAN sig
    TRISBbits.TRISB12 = 1;  //OUTFAN sig
    TRISBbits.TRISB11 = 1;  //압력스위치 고압
    TRISBbits.TRISB10 = 1;  //압력스위치 실외기팬
    TRISBbits.TRISB9 = 1;   //압력스위치 저압
    TRISBbits.TRISB8 = 1;   //히터바이메탈2
    TRISBbits.TRISB7 = 1;   //히터바이메탈1
    TRISBbits.TRISB6 = 1;   //AN06
    TRISBbits.TRISB5 = 1;   //AN05
    TRISBbits.TRISB4 = 1;   //AN04
    TRISBbits.TRISB3 = 1;   //AN03
    TRISBbits.TRISB2 = 1;   //AN02
    TRISBbits.TRISB1 = 1;   //AN01
    TRISBbits.TRISB0 = 1;   //AN00
    
	
	// #### PORTC Direction ####
    TRISCbits.TRISC15 = 1;
    TRISCbits.TRISC14 = 1;
    TRISCbits.TRISC13 = 1;
    TRISCbits.TRISC12 = 1;
    TRISCbits.TRISC4 = 1;   //DIP3
    TRISCbits.TRISC3 = 1;   //DIP2
    TRISCbits.TRISC2 = 1;   //DIP1
    TRISCbits.TRISC1 = 1;   //DIP0
	
	
	// #### PORTD Direction ####
    TRISDbits.TRISD15 = 1;  //MCP3201 DATA
    TRISDbits.TRISD14 = 0;  //MCP3201 CLK
    TRISDbits.TRISD13 = 0;  //ACV CS
    TRISDbits.TRISD12 = 0;  //CT CS
    TRISDbits.TRISD11 = 1;  //eocr humid
    TRISDbits.TRISD10 = 1;  //eocr comp
    TRISDbits.TRISD9 = 1;   //eocr outFan
    TRISDbits.TRISD8 = 1;   //EOCR blower
    TRISDbits.TRISD7 = 0;   //DO1
    TRISDbits.TRISD6 = 0;   //DO2
    TRISDbits.TRISD5 = 0;   //DO3
    TRISDbits.TRISD4 = 0;   //DO4
    TRISDbits.TRISD3 = 0;   //DO5
    TRISDbits.TRISD2 = 0;   //DO6
    TRISDbits.TRISD1 = 0;   //DO7
    TRISDbits.TRISD0 = 0;   //DO8
	
	
	// #### PORTE Direction ####
    TRISEbits.TRISE7 = 0;   //DO16
    TRISEbits.TRISE6 = 0;   //DO15
    TRISEbits.TRISE5 = 0;   //DO14
    TRISEbits.TRISE4 = 0;   //DO13
    TRISEbits.TRISE3 = 0;   //DO12
    TRISEbits.TRISE2 = 0;   //DO11
    TRISEbits.TRISE1 = 0;   //DO10
    TRISEbits.TRISE0 = 0;   //DO9
	
	
	// #### PORTF Direction ####
    TRISFbits.TRISF13 = 0;  //W5500_RST
    TRISFbits.TRISF12 = 0;  //W5500_CS
    TRISFbits.TRISF8 = 1;   //W5500_MOSI
//    ODCFbits.ODCF8 = 1;
    TRISFbits.TRISF7 = 0;   //W5500_MISO
//    ODCFbits.ODCF7 = 1;
    TRISFbits.TRISF6 = 0;   //W5500_SCK
    TRISFbits.TRISF5 = 1;
    TRISFbits.TRISF4 = 1;
    TRISFbits.TRISF3 = 0;   //RS232_TX
    TRISFbits.TRISF2 = 1;   //RS232_RX
    TRISFbits.TRISF1 = 1;
    TRISFbits.TRISF0 = 1;

    
	// #### PORTG Direction ####
    TRISGbits.TRISG15 = 1;
    TRISGbits.TRISG14 = 1;
    TRISGbits.TRISG13 = 1;
    TRISGbits.TRISG12 = 0;  //BUZZER
    TRISGbits.TRISG9 = 0;   //FLASH MEMORY_CS
    TRISGbits.TRISG8 = 1;   //FLASH MEMORY_SI
    TRISGbits.TRISG7 = 0;   //FLASH MEMORY_SO
    TRISGbits.TRISG6 = 0;   //FLASH MEMORY_SCK
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
    _LATG12 = 1;
}

void extIntPin(){
    
    INTCON2bits.INT1EP = 1; //negative edge
    IFS1bits.INT1IF = 0;
    IEC1bits.INT1IE = 1;
}