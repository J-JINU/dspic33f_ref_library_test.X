/* 
 * File:   system.h
 * Author: THESYSTEM
 *
 * Created on 2024년 1월 18일 (목), 오후 4:55
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif

    
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "ADC.h"
#include "AT45DB021D.h"
#include "CAN.h"
#include "PWM.h"
#include "SPI.h"
#include "gpio.h"
#include "UART.h"
#include "system.h"
#include "timer.h"
#include "InputCapture.h"

void init_system();
void setAbsoluteEnv();

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

