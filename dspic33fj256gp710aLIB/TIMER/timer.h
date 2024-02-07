/* 
 * File:   timer.h
 * Author: THESYSTEM
 *
 * Created on September 25, 2022, 9:41 AM
 */

#ifndef TIMER_H
#define	TIMER_H

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>

#define OSC_CLOCK 40000000
#define TIMER_DIV1 0
#define TIMER_DIV8 1
#define TIMER_DIV64 2
#define TIMER_DIV256 3


#ifdef	__cplusplus
extern "C" {
#endif

void init_timer();
void init_T1();
void Timer1_OverflowCallbackRegister(void (* CallbackHandler)(void));
void init_T2();
void Timer2_OverflowCallbackRegister(void (* CallbackHandler)(void));
void init_T3();
void Timer3_OverflowCallbackRegister(void (* CallbackHandler)(void));
void init_T8();
void Timer8_OverflowCallbackRegister(void (* CallbackHandler)(void));


#ifdef	__cplusplus
}
#endif

//void setTimer(int nTimer, int timerDiv);
//void setTimerPR();
#endif	/* TIMER_H */

