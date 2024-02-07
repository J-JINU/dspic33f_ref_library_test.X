#include "timer.h"

static void (*Timer1_OverflowCallback)(void);
static void Timer1_DefaultOverflowCallback(void);
static void (*Timer2_OverflowCallback)(void);
static void Timer2_DefaultOverflowCallback(void);
static void (*Timer3_OverflowCallback)(void);
static void Timer3_DefaultOverflowCallback(void);
static void (*Timer8_OverflowCallback)(void);
static void Timer8_DefaultOverflowCallback(void);

void init_timer() {
    init_T1();
    init_T3();
}

void init_T1(){
    T1CON = 0x0000;
    TMR1 = 0;
    T1CONbits.TCKPS = TIMER_DIV8;

    PR1 = 5000; //1ms
    IEC0bits.T1IE = 1;
    IFS0bits.T1IF = 0;
    IPC0bits.T1IP = 1;
    Timer1_OverflowCallbackRegister(Timer1_DefaultOverflowCallback);
    
    T1CONbits.TON = 1;
}

/* interrupt Function */
void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void) { 
    _T1IF = 0;
    if(Timer1_OverflowCallback)
    {
        Timer1_OverflowCallback();
    }
}

void Timer1_OverflowCallbackRegister(void (* CallbackHandler)(void))
{
    Timer1_OverflowCallback = CallbackHandler;
}

static void Timer1_DefaultOverflowCallback(){
    //add code
}

void init_T2(){ //PWM TIMER
    T2CON = 0x0000;
    TMR2 = 0;
    T2CONbits.TCKPS = TIMER_DIV8;

    PR2 = 500; //0.1ms
    Timer2_OverflowCallbackRegister(Timer2_DefaultOverflowCallback);
    
    T2CONbits.TON = 1;
}

/* interrupt Function */
void __attribute__((interrupt, no_auto_psv)) _T2Interrupt(void) { 
    _T2IF = 0;
    if(Timer2_OverflowCallback)
    {
        Timer2_OverflowCallback();
    }
}

void Timer2_OverflowCallbackRegister(void (* CallbackHandler)(void))
{
    Timer2_OverflowCallback = CallbackHandler;
}

static void Timer2_DefaultOverflowCallback(){
    //add code
}

void init_T3(){
    T3CON = 0x0000;
    T3CONbits.TCKPS = TIMER_DIV8;
    TMR3 = 0;
    PR3 = 1500; //0.3ms
    Timer3_OverflowCallbackRegister(Timer3_DefaultOverflowCallback);
    _T3IE = 0;
    _T3IF = 0;
//    Timer8_OverflowCallbackRegister(Timer8_DefaultOverflowCallback);
    T3CONbits.TON = 1;
}

void __attribute__((interrupt, no_auto_psv)) _T3Interrupt(void) { 
    _T3IF = 0;
    if(Timer3_OverflowCallback)
    {
        Timer3_OverflowCallback();
    }
}

void Timer3_OverflowCallbackRegister(void (* CallbackHandler)(void))
{
    Timer3_OverflowCallback = CallbackHandler;
}

static void Timer3_DefaultOverflowCallback(){
    //add code
}

void init_T8(){
    //Timer 8 전력 계산용
    T8CON = 0x0000;
    T8CONbits.TCKPS = 0b11;
    TMR8 = 0;
    PR8 = 15625; //100ms
    Timer8_OverflowCallbackRegister(Timer8_DefaultOverflowCallback);
    _T8IE = 1;
    _T8IF = 0;
//    Timer8_OverflowCallbackRegister(Timer8_DefaultOverflowCallback);
    T8CONbits.TON = 1;
}

/* interrupt Function */
void __attribute__((interrupt, no_auto_psv)) _T8Interrupt(void) { 
    _T8IF = 0;
    if(Timer8_OverflowCallback)
    {
        Timer8_OverflowCallback();
    }
}

void Timer8_OverflowCallbackRegister(void (* CallbackHandler)(void))
{
    Timer8_OverflowCallback = CallbackHandler;
}

static void Timer8_DefaultOverflowCallback(){
    //add code
}