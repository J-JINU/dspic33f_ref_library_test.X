#include "MCP3201.h"


void init3201(){
    CT_CS(1);
    ACV_CS(1);
    MCPCLK(0);
    TMR9 = 0x0000;
    PR9 = 150;
    IFS3bits.T9IF = 0;
    IEC3bits.T9IE = 1;
    T9CONbits.TON = 0;
}




