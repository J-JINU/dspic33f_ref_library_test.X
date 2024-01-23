#include "CAN.h"
#include <xc.h>

void init_CAN(){
    initCAN1();
}

void initCAN1(){
    //C1CFG1: CAN Baud Rate Configuration Register 1
    C1CFG1bits.SJW = 0; //Synchronization Jump Width bits
    C1CFG1bits.BRP = 0; //Baud Rate Prescaler bits

    //C2CFG2: CAN Baud Rate Configuration Register 2
    C2CFG2bits.WAKFIL = 0; //Select CAN Bus Line Filter for Wake-up bit
    C2CFG2bits.SEG2PH = 0; //Phase Segment 2 bits
    C2CFG2bits.SEG2PHTS = 0; //Phase Segment 2 Time Select bit
    C2CFG2bits.SAM = 0; //Sample CAN Bus Line bit
    C2CFG2bits.SEG1PH = 0; //Phase Segment 1 bits
    C2CFG2bits.PRSEG = 0; //Propagation Time Segment bits
    
    //C1FEN1: CAN Acceptance Filter Enable Register
    C1FEN1bits.FLTEN = 0; //Enable Filter x bits
    
//    //C1RXFnSID: CAN Acceptance Filter Standard Identifier Register n (n = 0-15)
//    C1RXFnSIDbits.SID = 0; //Standard Identifier bits
//    C1RXFnSIDbits.EXIDE = 0; //Extended Identifier Enable bit
//    C1RXFnSIDbits.EID = 0; //Extended Identifier bits
//    
//    // C1RXFnEID: CAN Acceptance Filter Extended Identifier Register n (n = 0-15)
//    C1RXFnEIDbits.EID = 0; //Extended Identifier bits
//    
//    //C1RXMnSID: CAN Acceptance Filter Mask Standard Identifier Register n (n = 0-2)
//    C1RXMnSIDbits.SID = 0; //Standard Identifier bits
//    C1RXMnSIDbits.MIDE = 0; //Identifier Receive Mode bit
//    C1RXMnSIDbits.EID = 0; //Extended Identifier bits
//    
//    //C1RXMnEID: CAN Acceptance Filter Mask Extended Identifier Register n (n = 0-2)
//    C1RXMnEIDbits.EID = 0; //Extended Identifier bits
    
    // C1FMSKSEL1: CAN Filter 7-0 Mask Selection Register 1
    C1FMSKSEL1bits.F7MSK = 0; //Mask Source for Filter 7 bits
    C1FMSKSEL1bits.F6MSK = 0; //Mask Source for Filter 6 bits
    C1FMSKSEL1bits.F5MSK = 0; //Mask Source for Filter 5 bits
    C1FMSKSEL1bits.F4MSK = 0; //Mask Source for Filter 4 bits
    C1FMSKSEL1bits.F3MSK = 0; //Mask Source for Filter 3 bits
    C1FMSKSEL1bits.F2MSK = 0; //Mask Source for Filter 2 bits
    C1FMSKSEL1bits.F1MSK = 0; //Mask Source for Filter 1 bits
    C1FMSKSEL1bits.F0MSK = 0; //Mask Source for Filter 0 bits
    
    //C1FMSKSEL2: CAN Filter 15-8 Mask Selection Register 2
    C1FMSKSEL2bits.F15MSK = 0; //Mask Source for Filter 15 bits
    C1FMSKSEL2bits.F14MSK = 0; //Mask Source for Filter 14 bits
    C1FMSKSEL2bits.F13MSK = 0; //Mask Source for Filter 13 bits
    C1FMSKSEL2bits.F12MSK = 0; //Mask Source for Filter 12 bits
    C1FMSKSEL2bits.F11MSK = 0; //Mask Source for Filter 11 bits
    C1FMSKSEL2bits.F10MSK = 0; //Mask Source for Filter 10 bits
    C1FMSKSEL2bits.F9MSK = 0; //Mask Source for Filter 9 bits
    C1FMSKSEL2bits.F8MSK = 0; //Mask Source for Filter 8 bits
    
    //C1BUFPNT1: CAN Filter 0-3 Buffer Pointer Register 1
    C1BUFPNT1bits.F3BP = 0; // RX Buffer Mask for Filter 3 bits
    C1BUFPNT1bits.F2BP = 0; // RX Buffer mask for Filter 2 bits (same values as bits 15-12)
    C1BUFPNT1bits.F1BP = 0; // RX Buffer mask for Filter 1 bits (same values as bits 15-12)
    C1BUFPNT1bits.F0BP = 0; // RX Buffer mask for Filter 0 bits (same values as bits 15-12)
    
    //C1BUFPNT2: CAN Filter 4-7 Buffer Pointer Register 2
    C1BUFPNT2bits.F7BP = 0; // RX Buffer Mask for Filter 7 bits
    C1BUFPNT2bits.F6BP = 0; // RX Buffer Mask for Filter 6 bits
    C1BUFPNT2bits.F5BP = 0; // RX Buffer Mask for Filter 5 bits
    C1BUFPNT2bits.F4BP = 0; // RX Buffer Mask for Filter 4 bits
    
}