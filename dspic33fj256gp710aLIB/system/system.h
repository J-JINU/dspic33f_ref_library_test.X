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
#include "../ADC/ADC.h"
#include "../../third_party_peripheral/AT45DB021D/AT45DB021D.h"
#include "../CAN/CAN.h"
#include "../PWM/PWM.h"
#include "../SPI/SPI.h"
#include "../GPIO/gpio.h"
#include "../UART/UART.h"
#include "../TIMER/timer.h"
#include "../IC/InputCapture.h"

void init_system();
void setAbsoluteEnv();

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

