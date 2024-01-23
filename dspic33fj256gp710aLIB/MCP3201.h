/* 
 * File:   MCP3201.h
 * Author: THESYSTEM
 *
 * Created on September 20, 2022, 12:40 PM
 */

#ifndef MCP3201_H
#define	MCP3201_H

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef	__cplusplus
extern "C" {
#endif

    
#define CT_CS(x) (_LATD12 = x)
#define ACV_CS(x) (_LATD13 = x)
#define MCPCLK(x) (_LATD14 = x)

void init3201();


#ifdef	__cplusplus
}
#endif

#endif	/* MCP3201_H */

