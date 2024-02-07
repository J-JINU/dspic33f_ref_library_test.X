/* 
 * File:   ADC.h
 * Author: THESYSTEM
 *
 * Created on October 16, 2022, 8:33 PM
 */

#ifndef ADC_H
#define	ADC_H
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef	__cplusplus
extern "C" {
#endif

void init_ADC();
void initADC1();
void ADC1_OverflowCallbackRegister(void (* CallbackHandler)(void));
void initADC2();
void initGPtimer1();
void initGPtimer2();


#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

