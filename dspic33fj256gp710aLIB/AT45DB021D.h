/* 
 * File:   AT45DB021D.h
 * Author: THESYSTEM
 * '더'에서 고정으로 사용하는 플래시 메모리임 항상 SPI2에 사용함
 * Created on October 5, 2022, 10:58 AM
 */

#ifndef AT45DB021D_H
#define	AT45DB021D_H

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SPI.h"

//Flash Memory Spec
//페이지당 264바이트이다. 하지만 페이지의 가장 앞 8바이트는 내가 사용하지 않는다.
#define POWEROF2 8
#define BYTE_PER_PAGE_ALLOW 256
#define BYTE_PER_PAGE_CHKSUM (BYTE_PER_PAGE_ALLOW - 1)// 1byte checksum
#define BYTE_PER_PAGE   264
//#define EEPROM_SECTOR_SIZE			250
//#define EEPROM_SECTOR_DATA			(EEPROM_SECTOR_SIZE - 1)	// 1byte checksum
#define NUM_OF_PAGE     1024

//Read Commands
#define MAIN_MEMORY_PAGE_READ           0xD2
/*      MAIN_MEMORY_PAGE_READ
 * D2 + PAGEADDRESS + INPAGEADDRESS + 4 DONT'CARE BYTE
 */
#define CONTINUOUS_ARRAY_READ_LEGACY    0xE8
#define CONTINUOUS_ARRAY_READ_LOW       0x03
#define CONTINUOUS_ARRAY_READ_HIGH      0x0B
#define BUFFER_READ_LOW                 0xD1
#define BUFFER_READ                     0xD4

//Program(Write) and Erase Commands
#define BUFFER_WRITE                                                0x84
#define BUFFER_TO_MAIN_MEMORY_PAGE_PROGRAM_WITH_BUILTIN_ERASE       0x83
#define BUFFER_TO_MAIN_MEMORY_PAGE_PROGRAM_WITHOUT_BUILTIN_ERASE    0X88
#define PAGE_ERASE                                                  0x81
#define BLOCK_ERASE                                                 0x50
#define SECTOR_ERASE                                                0x7C
#define CHIP_ERASE_1                                                0x7C
#define CHIP_ERASE_2                                                0x94
#define CHIP_ERASE_3                                                0x80
#define CHIP_ERASE_4                                                0x9A
#define MAIN_MEMORY_PAGE_PROGRAM_THROUGH_BUFFER                     0x82

//Protection and Security Commands
#define ENABLE_SECTOR_PROTECTION_1              0x3D
#define ENABLE_SECTOR_PROTECTION_2              0x2A
#define ENABLE_SECTOR_PROTECTION_3              0x7F
#define ENABLE_SECTOR_PROTECTION_4              0xA9
#define DISABLE_SECTOR_PROTECTION_1             0x3D
#define DISABLE_SECTOR_PROTECTION_2             0x2A
#define DISABLE_SECTOR_PROTECTION_3             0x7F
#define DISABLE_SECTOR_PROTECTION_4             0x9A
#define ERASE_SECTOR_PROTECTION_REGISTER_1      0x3D
#define ERASE_SECTOR_PROTECTION_REGISTER_2      0x2A
#define ERASE_SECTOR_PROTECTION_REGISTER_3      0x7F
#define ERASE_SECTOR_PROTECTION_REGISTER_4      0xCF
#define PROGRAM_SECTOR_PROTECTION_REGISTER_1    0x3D
#define PROGRAM_SECTOR_PROTECTION_REGISTER_2    0x2A
#define PROGRAM_SECTOR_PROTECTION_REGISTER_3    0x7F
#define PROGRAM_SECTOR_PROTECTION_REGISTER_4    0xFC
#define READ_SECTOR_PROTECTION_REGISTER         0x32
#define SECTOR_LOCKDOWN_1                       0x3D
#define SECTOR_LOCKDOWN_2                       0x2A
#define SECTOR_LOCKDOWN_3                       0x7F
#define SECTOR_LOCKDOWN_4                       0x30
#define READ_SECTOR_LOCKDOWN_REGISTER           0x35
#define PROGRAM_SECURITY_REGISTER_1             0x9B
#define PROGRAM_SECURITY_REGISTER_2             0x00
#define PROGRAM_SECURITY_REGISTER_3             0x00
#define PROGRAM_SECURITY_REGISTER_4             0x00
#define READ_SECURITY_REGISTER                  0x77

//Additional Commands
#define MAIN_MEMORY_PAGE_TO_BUFFER_TRANSFER     0x53
#define MAIN_MEMORY_PAGE_TO_BUFFER_COMPARE      0x60
#define AUTO_PAGE_REWRITE_THROUGH_BUFFER        0x58
#define DEEP_POWER_DOWN                         0xB9
#define RESUME_FROM_DEEP_POWER_DOWN             0xAB
#define STATUS_REGISTER_READ                    0xD7
/*      STATUS_REGISTER_READ
 * BIT7 1 --> READY / 0 --> BUSY
 * BIT6 1 --> MEMORY PAGE와 BUFFER NOT MATCH / 0 --> MEMORY PAGE와 BUFFER MATCH
 * BIT5~2   0101로 그냥 나옴
 * BIT1 1 --> SECTOR PROTECTION ENABLE / 0 --> SECTOR PROTECTION DISENABLE
 * BIT0 1 --> PAGE SIZE 256 BYTE / 0 --> PAGE SIZE 264 BYTE
 */
#define MANUFACTURER_AND_DEVICE_ID_READ         0x9F

////Legacy Commands--NOT RECOMMAEND
//#define BUFFER_READ                 0x54
//#define MAIN_MEMORY_PAGE_READ       0x52
//#define CONTINUOUS_ARRAY_READ       0x68
//#define STATUS_REGISTER_READ        0x57

//Pin Control
//#define eeprom_chipreset(IsHighLow)		(_LATG14=IsHighLow)
#define FLASH_CS(x) (_LATG9=x)

#ifdef	__cplusplus
extern "C" {
#endif


#ifdef	__cplusplus
}
#endif
#define HiByte(X)   (unsigned char)((X>>8) & 0x00ff)
#define LoByte(X)   (unsigned char)(X & 0x00ff)


void init_Flash();
void flash_readwriteRegister(uint8_t (* CallbackHandler)(uint16_t));
bool flash_status_rdy();
bool flash_read_page(uint16_t wBlock, uint8_t *pBuffer);
void flash_write_page(uint16_t wBlock, uint8_t *pBuffer);


#endif	/* AT45DB021D_H */

