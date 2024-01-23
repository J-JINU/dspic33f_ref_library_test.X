#include "PWM.h"
#include "timer.h"


void init_PWM1(){
    //need timer
    OC1CON = 0;
    OC1CONbits.OCTSEL = 0; // Timer2 is the clock source for Compare x
    OC1R = 0;
    OC1RS = 0;
    OC1CONbits.OCM = 0b110; //PWM mode on OCx, Fault pin disabled
    
}

void turnOffPWM1(){
    OC1CONbits.OCM = 0b000;
}

void set_pwm1_duty(uint16_t duty){
    OC1R = duty;
}

void turnOnPWM2(){
    //need timer
    OC2CON = 0;
    OC2CONbits.OCTSEL = 0;
    OC2CONbits.OCM = 0b110;
    OC2R = 0;
    OC2RS = 0;
}

void turnOffPWM2(){
    OC2CONbits.OCM = 0;
}