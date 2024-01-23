#include "AT45DB021D.h"



void initFlash(){
    MEM_CS(1);
    while(!flashReady()){
    }
}


bool flashReady(){
    unsigned char tempBuffer = 0;
    MEM_CS(0);
    sendSPI2BUF(STATUS_REGISTER_READ);
    tempBuffer = sendSPI2BUF(0);
    MEM_CS(1);
    if((tempBuffer & 0x80) == 0x80){
        return true;    //ready
    }
    else{
        return false;   //not yet ready
    }
}

bool flashRead(unsigned int *page, unsigned char *buffer){
    
    while(!flashReady()){
    }
    //페이지는 무조건 10페이지부터 시작
    unsigned int addr = 0;
    MEM_CS(0);
    sendSPI2BUF(MAIN_MEMORY_PAGE_READ);
    sendSPI2BUF((*page >> 6) & 0xff);  //page addr
    sendSPI2BUF(*page & 0xff);
    sendSPI2BUF((unsigned char)addr);  //무조건 페이지 처음부터 읽어옴
    sendSPI2BUF(0);
    sendSPI2BUF(0);
    sendSPI2BUF(0);
    sendSPI2BUF(0);
    for(int i = 0 ; i < 8 ; i++){
        buffer[i] = sendSPI2BUF(0);
    }
    for(int i = 0 ; i < 256 ; i++){
        buffer[i] = sendSPI2BUF(0);
    }
    MEM_CS(1);
}

//나중에 주소값 넣는 부분 재확인 필요 아마도 무조건 0부터 읽을 거라 상관은 없을듯
//그리고 가장 앞 8바이트 제외하고 읽도록 수정해야함
void flashWrite(unsigned int *page, unsigned char *buffer){
    
    while(!flashReady()){
    }
    unsigned char test[100];
    for(int i = 0 ; i < 100 ; i++){
        test[i] = i;
    }
    MEM_CS(0);
    sendSPI2BUF(BUFFER_WRITE);
    sendSPI2BUF(0);  //don't care
    sendSPI2BUF(0);  //don't care
    sendSPI2BUF(0);  //buffer start addr
    for(int i = 0 ; i < 8 ; i++){
        sendSPI2BUF(1);
    }
    for(int i = 0 ; i < 256 ; i++){
        sendSPI2BUF(buffer[i]);
    }
    MEM_CS(1);
    while(!flashReady()){
    }
    MEM_CS(0);
    sendSPI2BUF(BUFFER_TO_MAIN_MEMORY_PAGE_PROGRAM_WITH_BUILTIN_ERASE);
    sendSPI2BUF((*page >> 6) & 0xff);  //page addr
    sendSPI2BUF((*page) & 0xff);  //page addr
    sendSPI2BUF(0);  //don't care
    MEM_CS(1);
}


//bool flash_status_rdy()
//{
//	unsigned char nValue;
//	eeprom_chipselect( 0 );
//	eeprom_spi_transfer( MEM_FLASH_STATUS );
//	nValue = eeprom_spi_transfer( 0xFF );
//	eeprom_chipselect( 1 );
//
//	return (  ((nValue&0x0C) == 0x0C) && ((nValue&0x80) == 0x80) );
//}
//
//bool flash_read_page( unsigned int wBlock, unsigned char *pBuffer)
//{
//	unsigned char bcc[2];
//	unsigned char nStep;
//	unsigned int wStep;
//	unsigned int addr = 0;
//	unsigned char nValue;
//
//		
//	for(wStep=0;wStep<0x8000;wStep++)
//	{
//		if(flash_status_rdy()) break;
//		delay_us(1);
//	}
//
//		
//	eeprom_spi_transfer( 0x00 );
//		
//		
//	eeprom_chipselect( 0 ); // enable DataFlash
//	eeprom_spi_transfer( MEM_FLASH_READ );
//		
//	eeprom_spi_transfer( (unsigned char)(wBlock>>5) );
//	eeprom_spi_transfer( (unsigned char)(wBlock<<2) | ((unsigned char)(addr>>8)&0x03) );
//	eeprom_spi_transfer( (unsigned char)addr );
//		
//	eeprom_spi_transfer( 0x00 );
//	eeprom_spi_transfer( 0x00 );
//	eeprom_spi_transfer( 0x00 );
//	eeprom_spi_transfer( 0x00 );
//		
//	bcc[0] = 0;
//	bcc[1] = 0;
//	for( nStep=0;nStep<EEPROM_SECTOR_DATA;nStep++ )
//	{
//		nValue = eeprom_spi_transfer( 0xff );
//		if((nStep&0x01) == 0) bcc[0] ^= nValue;
//		else bcc[1] ^= nValue;
//		pBuffer[nStep] = nValue;
//	}
//		
//	nValue = eeprom_spi_transfer( 0xff );
//	bcc[0] ^= nValue;
//	nValue = eeprom_spi_transfer( 0xff );
//	bcc[1] ^= nValue;
//		
//	eeprom_chipselect( 1 ); // disable DataFlash
//		//return TRUE;
//	
//	// NullÀÏ°æ¿ì ÇØ´çµÊ.
//	if((bcc[0] == 0) && (bcc[1] == 0)) return TRUE;
//	return FALSE;
//}
//
//bool flash_write_page( unsigned int wBlock, unsigned char *pBuffer)
//{
//	unsigned char bcc[2];
//	unsigned char nStep;
//	unsigned int wStep;
//	unsigned int addr = 0;
//	
//	//-----------------------------------------------------------------------------------
//	for(wStep=0;wStep<0x8000;wStep++)
//	{
//		if(flash_status_rdy()) break;
//	}
//	//-----------------------------------------------------------------------------------
//	
//	
//	eeprom_spi_transfer( 0x00 );
//	
//	
//	//-----------------------------------------------------------------------------------
//	eeprom_chipselect( 0 ); // enable DataFlash
//	eeprom_spi_transfer( MEM_FLASH_LOAD_BUFF );
//	eeprom_spi_transfer( (unsigned char)(wBlock>>5) );
//	eeprom_spi_transfer( (unsigned char)(wBlock<<2) );
//	eeprom_spi_transfer( 0x00 );
//	eeprom_chipselect( 1 );
//	//-----------------------------------------------------------------------------------
//	
//	eeprom_spi_transfer( 0x00 );
//	
//	//-----------------------------------------------------------------------------------
//	
//	for(wStep=0;wStep<0x8000;wStep++)
//	{
//		if(flash_status_rdy()) break;
//	}
//	
//	//-----------------------------------------------------------------------------------
//	
//	eeprom_spi_transfer( 0x00 );
//	
//	//-----------------------------------------------------------------------------------
//	eeprom_chipselect( 0 ); // enable DataFlash
//	eeprom_spi_transfer( MEM_FLASH_BUFF_WRITE );
//	eeprom_spi_transfer( 0x00 );
//	eeprom_spi_transfer( (unsigned char)(addr>>8)&0x03 );
//	eeprom_spi_transfer( (unsigned char)addr );
//	
//	bcc[0] = 0; bcc[1] = 0;
//	for( nStep=0;nStep<EEPROM_SECTOR_DATA;nStep++ )
//	{
//		if((nStep&0x01) == 0) bcc[0] ^= pBuffer[nStep];
//		else bcc[1] ^= pBuffer[nStep];
//		
//		eeprom_spi_transfer( pBuffer[nStep] );
//	}
//// 	
//// 	for( nStep=0;nStep<EEPROM_SECTOR_DATA;nStep++ )
//// 		eeprom_spi_transfer( pBuffer[nStep] );
//		
//	eeprom_spi_transfer( (unsigned char)bcc[0] );
//	eeprom_spi_transfer( (unsigned char)bcc[1] );
//	
//	eeprom_chipselect( 1 ); // disable DataFlash
//	//-----------------------------------------------------------------------------------
//	
//	eeprom_spi_transfer( 0x00 );
//	
//	//-----------------------------------------------------------------------------------
//	for(wStep=0;wStep<0x8000;wStep++)
//	{
//		if(flash_status_rdy()) break;
//		delay_us(1);
//	}
//	//-----------------------------------------------------------------------------------
//	
//	eeprom_spi_transfer( 0x00 );
//	
//	//-----------------------------------------------------------------------------------
//	eeprom_chipselect( 0 ); // enable DataFlash
//	eeprom_spi_transfer( MEM_FLASH_REWRITE );
//	eeprom_spi_transfer( (unsigned char)(wBlock>>5) );
//	eeprom_spi_transfer( (unsigned char)(wBlock<<2) );
//	eeprom_spi_transfer( 0x00 );
//	eeprom_chipselect( 1 ); // disable DataFlash
//	//-----------------------------------------------------------------------------------
//	return TRUE;
//}