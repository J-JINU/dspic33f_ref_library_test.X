#include "AT45DB021D.h"

//SPI몇번인지 확인할것

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

bool flash_read_page(uint16_t page, uint8_t *object, uint16_t size){

    uint8_t chksum = 0;
	uint16_t addr = 0;
    while(!flash_status_rdy()){
    }

	FLASH_CS( 0 ); // enable DataFlash
	flash_readwrite( MAIN_MEMORY_PAGE_READ );
		
	flash_readwrite( (uint8_t)(page>>5) );
	flash_readwrite( (uint8_t)(page<<2) | ((uint8_t)(addr>>8)&0x03) );
	flash_readwrite( (uint8_t)addr );
		
	flash_readwrite( 0x00 );
	flash_readwrite( 0x00 );
	flash_readwrite( 0x00 );
	flash_readwrite( 0x00 );

	for(uint16_t i = 0 ; i < size ; i++)
	{
		object[i] = flash_readwrite( 0xff );
		chksum += object[i];
	}
    chksum += flash_readwrite(0xff);
	FLASH_CS( 1 ); // disable DataFlash
	
	if(!chksum) return false;
	return true;
}


void flash_write_page(uint16_t page, uint8_t *object, uint16_t size){
    
	uint8_t chksum = 0;
	uint16_t addr = 0;

	while(!flash_status_rdy());
    
	//-----------------------------------------------------------------------------------
	FLASH_CS( 0 ); // enable DataFlash
	flash_readwrite( BUFFER_WRITE );
	flash_readwrite( 0x00 );
	flash_readwrite( (uint16_t)(addr>>8)&0x03 );
	flash_readwrite( (uint16_t)addr );
	for(uint16_t i = 0 ; i < size ; i++)
	{
		chksum += *(object + i);
		flash_readwrite(*(object + i));
	}
	flash_readwrite(chksum);
	
	FLASH_CS( 1 ); // disable DataFlash
	//-----------------------------------------------------------------------------------
	
    while(!flash_status_rdy());
	
	//-----------------------------------------------------------------------------------
	FLASH_CS( 0 ); // enable DataFlash
	flash_readwrite( BUFFER_TO_MAIN_MEMORY_PAGE_PROGRAM_WITH_BUILTIN_ERASE );
	flash_readwrite( (uint8_t)(page>>5) );
	flash_readwrite( (uint8_t)(page<<2) );
	flash_readwrite( 0x00 );
	FLASH_CS( 1 ); // disable DataFlash
	//-----------------------------------------------------------------------------------
}