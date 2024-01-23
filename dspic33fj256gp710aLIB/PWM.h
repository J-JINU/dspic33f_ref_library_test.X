/* 
 * File:   PWM.h
 * Author: THESYSTEM
 *
 * Created on January 11, 2023, 4:35 PM
 */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#ifndef PWM_H
#define	PWM_H

#ifdef	__cplusplus
extern "C" {
#endif

void initTimer2();
void turnOnPWM1();
void turnOffPWM1();
void initTimer3();
void turnOnPWM2();
void turnOffPWM2();


#ifdef	__cplusplus
}
#endif

#endif	/* PWM_H */

