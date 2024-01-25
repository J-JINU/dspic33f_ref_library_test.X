#include "AT45DB021D.h"

static uint8_t (*flash_readwrite)(uint16_t);

void init_Flash(){
    FLASH_CS(1);
    while(!flash_status_rdy()){
    }
}

void flash_readwriteRegister(uint8_t (* CallbackHandler)(uint16_t))
{
    flash_readwrite = CallbackHandler;
}

bool flash_status_rdy(){
    uint8_t nValue;
	FLASH_CS( 0 );
	flash_readwrite( STATUS_REGISTER_READ );
	nValue = flash_readwrite( 0xFF );
	FLASH_CS( 1 );
    
	return ((nValue&0x80) == 0x80);
}

bool flash_read_page(uint16_t wBlock, uint8_t *pBuffer){

    uint8_t bcc[2];
	uint8_t nStep;
	uint16_t addr = 0;
	uint8_t nValue;

    while(!flash_status_rdy()){
    }

		
	flash_readwrite( 0x00 );
		
		
	FLASH_CS( 0 ); // enable DataFlash
	flash_readwrite( MAIN_MEMORY_PAGE_READ );
		
	flash_readwrite( (uint8_t)(wBlock>>5) );
	flash_readwrite( (uint8_t)(wBlock<<2) | ((uint8_t)(addr>>8)&0x03) );
	flash_readwrite( (uint8_t)addr );
		
	flash_readwrite( 0x00 );
	flash_readwrite( 0x00 );
	flash_readwrite( 0x00 );
	flash_readwrite( 0x00 );
		
	bcc[0] = 0;
	bcc[1] = 0;
	for( nStep=0;nStep<EEPROM_SECTOR_DATA;nStep++ )
	{
		nValue = flash_readwrite( 0xff );
		if((nStep&0x01) == 0) bcc[0] ^= nValue;
		else bcc[1] ^= nValue;
		pBuffer[nStep] = nValue;
	}
		
	nValue = flash_readwrite( 0xff );
	bcc[0] ^= nValue;
	nValue = flash_readwrite( 0xff );
	bcc[1] ^= nValue;
		
	FLASH_CS( 1 ); // disable DataFlash
		//return TRUE;
	
	// NullÀÏ°æ¿ì ÇØ´çµÊ.
	if((bcc[0] == 0) && (bcc[1] == 0)) return true;
	return false;
}


bool flash_write_page( uint16_t wBlock, uint8_t *pBuffer){
    
	uint8_t bcc[2];
	uint8_t nStep;
	uint16_t addr = 0;
	
	while(!flash_status_rdy()){
    }
	
	flash_readwrite( 0x00 );
	
	
//	//-----------------------------------------------------------------------------------
//	FLASH_CS( 0 ); // enable DataFlash
//	flash_readwrite( MAIN_MEMORY_PAGE_TO_BUFFER_TRANSFER );
//	flash_readwrite( (uint8_t)(wBlock>>5) );
//	flash_readwrite( (uint8_t)(wBlock<<2) );
//	flash_readwrite( 0x00 );
//	FLASH_CS( 1 );
//	//-----------------------------------------------------------------------------------
	
	flash_readwrite( 0x00 );
	
	while(!flash_status_rdy()){
    }
	
    
	flash_readwrite( 0x00 );
//	set_buffer(pBuffer);
	//-----------------------------------------------------------------------------------
	FLASH_CS( 0 ); // enable DataFlash
	flash_readwrite( BUFFER_WRITE );
	flash_readwrite( 0x00 );
	flash_readwrite( (uint16_t)(addr>>8)&0x03 );
	flash_readwrite( (uint16_t)addr );
//	start_dma();
	bcc[0] = 0; bcc[1] = 0;
	for( nStep=0;nStep<EEPROM_SECTOR_DATA;nStep++ )
	{
		if((nStep&0x01) == 0) bcc[0] ^= pBuffer[nStep];
		else bcc[1] ^= pBuffer[nStep];
		
		flash_readwrite( pBuffer[nStep] );
	}
 	
// 	for( nStep=0;nStep<EEPROM_SECTOR_DATA;nStep++ )
// 		eeprom_spi_transfer( pBuffer[nStep] );
		
	flash_readwrite( (uint8_t)bcc[0] );
	flash_readwrite( (uint8_t)bcc[1] );
	
	FLASH_CS( 1 ); // disable DataFlash
//    return true;
	//-----------------------------------------------------------------------------------
	
	flash_readwrite( 0x00 );
	
    while(!flash_status_rdy()){
    }
	flash_readwrite( 0x00 );
	
	//-----------------------------------------------------------------------------------
	FLASH_CS( 0 ); // enable DataFlash
	flash_readwrite( BUFFER_TO_MAIN_MEMORY_PAGE_PROGRAM_WITH_BUILTIN_ERASE );
	flash_readwrite( (uint8_t)(wBlock>>5) );
	flash_readwrite( (uint8_t)(wBlock<<2) );
	flash_readwrite( 0x00 );
	FLASH_CS( 1 ); // disable DataFlash
	//-----------------------------------------------------------------------------------
	return true;
}


void flash_commit(uint16_t wBlock, uint8_t *pBuffer){
    //-----------------------------------------------------------------------------------
	
	flash_readwrite( 0x00 );
	
    while(!flash_status_rdy()){
    }
	flash_readwrite( 0x00 );
	
	//-----------------------------------------------------------------------------------
	FLASH_CS( 0 ); // enable DataFlash
	flash_readwrite( BUFFER_TO_MAIN_MEMORY_PAGE_PROGRAM_WITH_BUILTIN_ERASE );
	flash_readwrite( (uint8_t)(wBlock>>5) );
	flash_readwrite( (uint8_t)(wBlock<<2) );
	flash_readwrite( 0x00 );
	FLASH_CS( 1 ); // disable DataFlash
	//-----------------------------------------------------------------------------------
}