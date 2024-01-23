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
void SPI1_Write_object(uint16_t* CS, uint8_t * object_addr, uint16_t size);
void SPI1_OverflowCallbackRegister(void (* CallbackHandler)(void));
void initSPI2();
unsigned char sendSPI1BUF( unsigned char i );
unsigned char sendSPI2BUF( unsigned char i );
unsigned char readSPI1BUF(void);

#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

