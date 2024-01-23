/* 
 * File:   CAN.h
 * Author: THESYSTEM
 *
 * Created on January 19, 2024, 11:31 AM
 */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef CAN_H
#define	CAN_H

#ifdef	__cplusplus
extern "C" {
#endif
    
void init_CAN();
void initCAN1();

#ifdef	__cplusplus
}
#endif

#endif	/* CNA_H */