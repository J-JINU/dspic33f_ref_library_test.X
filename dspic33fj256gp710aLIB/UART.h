/* 
 * File:   UART.h
 * Author: THESYSTEM
 *
 * Created on September 19, 2022, 9:51 PM
 */

#ifndef UART_H
#define	UART_H
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef	__cplusplus
extern "C" {
#endif
    
#define Cpu_Cl				40000000

#define Baud2400			((Cpu_Cl/2400)/16)-1
#define Baud9600			((Cpu_Cl/9600)/16)-1
#define Baud14400			((Cpu_Cl/14400)/16)-1
#define Baud19200			((Cpu_Cl/19200)/16)-1
#define Baud28800			((Cpu_Cl/28800)/16)-1
#define Baud38400			((Cpu_Cl/38400)/16)-1
#define Baud57600			((Cpu_Cl/57600)/16)-1
#define Baud115200			((Cpu_Cl/115200)/16)-1
    
    
    

#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

