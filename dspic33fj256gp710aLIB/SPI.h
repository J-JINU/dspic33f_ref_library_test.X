/* 
 * File:   SPI.h
 * Author: THESYSTEM
 *
 * Created on November 24, 2022, 11:31 AM
 */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef SPI_H
#define	SPI_H

#ifdef	__cplusplus
extern "C" {
#endif
    
void init_SPI();
void initSPI1(uint8_t mode);
void setSPI1MODE(uint8_t mode);
uint8_t sendSPI1BUF(uint16_t i);
uint8_t readSPI1BUF(void);
void SPI1_OverflowCallbackRegister(void (* CallbackHandler)(void));
void initSPI2();
uint8_t sendSPI2BUF(uint16_t i);
uint8_t readSPI2BUF(void);

#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

