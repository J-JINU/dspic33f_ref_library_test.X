#include <p33FJ256GP710A.h>

#include "ADC.h"

static void (*ADC1_OverflowCallback)(void);
static void ADC1_DefaultOverflowCallback(void);

void init_ADC(){
    initADC1();
}

void initADC1(){
    
    // Tad : analog module clock,   Tad >= 75ns
    // Tcy = 25ns
    // Tad = Tcy * (ADCS + 1)
    // Tsmp = SAMC<4:0> * Tad
    // Tconv 10bit -> 12Tad, 12bit -> 14Tad
    
//    AD1CON1
    AD1CON1bits.AD12B = 1; // 12-bit, 1-channel ADC operation
    AD1CON1bits.ADDMABM = 0; //DMA buffers are written in Scatter/Gather mode. 
    AD1CON1bits.FORM = 0; // integer
    AD1CON1bits.SSRC = 0b010; //GP timer compare ends sampling and starts conversion
    AD1CON1bits.ASAM = 1; // Sampling begins when SAMP bit is set
//    AD1CON2
    
    /*
     * Vrefh == External Vref+
     * Vrefl == External Vref-
     */
    AD2CON2bits.VCFG = 0; // Vrefh = External Vref+, Vrefl = External Vref-
//    AD1CON2bits.VCFG = 3;
    AD1CON2bits.CSCNA = 1;		// Scan Input Selections for CH0+ during Sample A bit
    AD1CON2bits.CHPS = 0; //Converts CH0
    AD1CON2bits.SMPI = 0;      // Selects Increment Rate for DMA Addresses bits or number of sample/conversion operations per interrupt
    AD1CON2bits.BUFM = 0; // Always starts filling the buffer from the start address
    AD1CON2bits.ALTS = 0; //Always uses channel input selects for Sample A
    
    //    AD1CON3
    
    /*
     * Tad = Tcy(ADCS + 1) = 25ns * (ADCS + 1) >= 75ns
     *--> ADCS >= 2
     */
    AD1CON3bits.ADCS = 10;  // TCY · (ADCS<7:0> + 1) = 256 · TCY = TAD
    AD1CON3bits.SAMC = 16;  // Sampling Time Tsmp = SAMC * Tad
//    AD1CON4
    AD1CON4bits.DMABL = 3;  // Selects number of DMA buffer locations per analog input bits 갯수 - 1
    
    /*  AD1CHS
     *                       MUXA MUXB
     * CH1 positive input is AN0, AN3
     * CH2 positive input is AN1, AN4
     * CH3 positive input is AN2, AN5
     * CH0 positive input is all -> AN6, 7, 8, 9, 10, 11, 12, 13, 14, 15
    */
//    AD1CHS0
    AD1CHS0bits.CH0NB = 0;      //MUX B Vrefl
    AD1CHS0bits.CH0NA = 0;      //MUX A Vrefl
    AD1CHS0bits.CH0SA = 0;      //MUX A Vrefl
 
////    AD1CHS123
//    AD1CHS123bits.CH123NB = 0;      //MUX B Vrefl
//    AD1CHS123bits.CH123SB = 1;      //AN345
//    AD1CHS123bits.CH123NA = 0;      //MUX A Vrefl
//    AD1CHS123bits.CH123SA = 0;      //AN012 
//    AD1CSSH
    AD1CSSL = 0;
    AD1CSSLbits.CSS0 = 1;
//    AD1PCFGH
    AD1PCFGH = 0xFFFF;      //Analog High port -> Digital pin
//    AD1PCFGL
    AD1PCFGL = 0xFFFF;
    AD1PCFGLbits.PCFG0 = 0;
    ADC1_OverflowCallbackRegister(ADC1_DefaultOverflowCallback);
    _AD1IF = 0;
    _AD1IE = 1;
    AD1CON1bits.ADON = 1;
}

void __attribute__((interrupt, no_auto_psv)) _ADC1Interrupt(void) { 
    _AD1IF = 0;
    if(ADC1_OverflowCallback)
    {
        ADC1_OverflowCallback();
    }
}

void ADC1_OverflowCallbackRegister(void (* CallbackHandler)(void))
{
    ADC1_OverflowCallback = CallbackHandler;
}

static void ADC1_DefaultOverflowCallback(){
    //add code
}

void initADC2(){
        // Tad : analog module clock,   Tad >= 75ns
    // Tcy = 25ns
    // Tad = Tcy * (ADCS + 1)
    // Tsmp = SAMC<4:0> * Tad
    // Tconv 10bit -> 12Tad, 12bit -> 14Tad
    
//    AD2CON1
    AD2CON1bits.AD12B = 0;
    AD2CON1bits.FORM = 0;   //unsigned integer
    AD2CON1bits.SSRC = 0b111;       //010 using GPtimer 111 internal
    AD2CON1bits.ASAM = 1;
    AD2CON1bits.ADDMABM = 0;
    
//    AD2CON2
    
    /*
     * Vrefh == External Vref+
     * Vrefl == External Vref-
     */
    AD2CON2bits.VCFG = 0;
//    AD2CON2bits.VCFG = 0b011;
    AD2CON2bits.CSCNA = 1;		// Scan Input Selections for CH0+ during Sample A bit
    AD2CON2bits.CHPS = 0;       // Convert CH0
    AD2CON2bits.SMPI = 11;       //12, Increment rate for DMA Addresses bits 갯수 - 1;
    AD2CON2bits.BUFM = 0;
        /* 현재 alternate sample 비활성화임 추후 센서 수량이 늘어나면 활용방안 고려함 */
    //    AD2CON3
    
    /*
     * Tad = Tcy(ADCS + 1) = 25ns * (ADCS + 1) >= 75ns
     *--> ADCS >= 2
     */
    AD2CON3bits.ADCS = 19;  // Tad = Tcy * (ADCS + 1) = 0.5us
    AD2CON3bits.SAMC = 10;  // Sampling Time Tsmp = SAMC * Tad = 5us
                            // Converting Time Tconv = 12 * Tad = 6us
                            // 8개 signal을 8번 읽는데 걸리는 산술시간 704us
//    AD2CON4
    AD2CON4bits.DMABL = 0b011;  //Allocates 8 words of buffer to each analog input
    
    /*  AD2CHS
     *                       MUXA MUXB
     * CH1 positive input is AN0, AN3
     * CH2 positive input is AN1, AN4
     * CH3 positive input is AN2, AN5
     * CH0 positive input is all -> AN6, 7, 8, 9, 10// 11, 12, 13, 14, 15
    */
//    AD2CHS0
    AD2CHS0bits.CH0NB = 0;      //MUX B Vrefl
    AD2CHS0bits.CH0NA = 0;      //MUX A Vrefl
    AD2CHS0bits.CH0SA = 0;
 
//    AD2CHS123
    AD2CHS123bits.CH123NB = 0;      //MUX B Vrefl
    AD2CHS123bits.CH123SB = 0;      //AN345
    AD2CHS123bits.CH123NA = 0;      //MUX A Vrefl
    AD2CHS123bits.CH123SA = 0;      //AN012
//    AD2CSSL
    AD2CSSL = 0x00ef;
//    AD2PCFGL
    
    AD2PCFGLbits.PCFG0 = 0;//온도
    AD2PCFGLbits.PCFG1 = 0;//습도
    AD2PCFGLbits.PCFG2 = 0;//x
    AD2PCFGLbits.PCFG3 = 0;//x
    AD2PCFGLbits.PCFG4 = 0;//판넬체크ntc
    AD2PCFGLbits.PCFG5 = 0;//판넬체크ntc
    AD2PCFGLbits.PCFG6 = 0;
    AD2PCFGLbits.PCFG7 = 1;
    AD2PCFGLbits.PCFG8 = 1;
    AD2PCFGLbits.PCFG9 = 1;
    AD2PCFGLbits.PCFG10 = 1;
    AD2PCFGLbits.PCFG11 = 1;
    AD2PCFGLbits.PCFG12 = 1;
    AD2PCFGLbits.PCFG13 = 1;
    AD2PCFGLbits.PCFG14 = 1;
    AD2PCFGLbits.PCFG15 = 1;
    
    IFS0bits.AD1IF = 0;
    IEC0bits.AD1IE = 0;
    AD1CON1bits.ADON = 0;
}