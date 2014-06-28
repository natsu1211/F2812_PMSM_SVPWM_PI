//###########################################################################
//
// FILE:	DSP281x_ECan.c
//
// TITLE:	DSP281x Enhanced CAN Initialization & Support Functions.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  1.00| 11 Sep 2003 | H.J. | Changes since previous version (v.58 Alpha)
//      |             |      | Added several initialization routines
//###########################################################################

#include "DSP281x_Device.h"     // DSP28 Headerfile Include File
#include "DSP281x_Examples.h"   // DSP28 Examples Include File


//---------------------------------------------------------------------------
// InitECan: 
//---------------------------------------------------------------------------
// This function initializes the eCAN module to a known state.
//
void InitECan(void)
{

long	i;

asm("  EALLOW");

/* Disable Watchdog  */
   DisableDog();    
    
/* Enable peripheral clocks  */   
   InitPeripheralClocks();    
    
/* Set PLL multiplication factor */
   InitPll(0xA);
   
   asm("  EALLOW");	
   				
/* Configure eCAN pins using GPIO regs*/

	GpioMuxRegs.GPFMUX.bit.CANTXA_GPIOF6 = 1;
	GpioMuxRegs.GPFMUX.bit.CANRXA_GPIOF7 = 1;	
	
/* Configure eCAN RX and TX pins for eCAN transmissions using eCAN regs*/  
    
    ECanaRegs.CANTIOC.bit.TXFUNC = 1;
    ECanaRegs.CANRIOC.bit.RXFUNC = 1;   

/* Configure eCAN for HECC mode - (reqd to access mailboxes 16 thru 31) */
									// HECC mode also enables time-stamping feature
	ECanaRegs.CANMC.bit.SCB = 1;				

/* Initialize all bits of 'Master Control Field' to zero */
// Some bits of MSGCTRL register come up in an unknown state. For proper operation,
// all bits (including reserved bits) of MSGCTRL must be initialized to zero
 
    ECanaMboxes.MBOX0.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX1.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX2.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX3.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX4.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX5.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX6.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX7.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX8.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX9.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX10.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX11.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX12.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX13.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX14.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX15.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX16.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX17.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX18.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX19.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX20.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX21.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX22.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX23.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX24.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX25.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX26.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX27.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX28.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX29.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX30.MSGCTRL.all = 0x00000000;
    ECanaMboxes.MBOX31.MSGCTRL.all = 0x00000000;

// TAn, RMPn, GIFn bits are all zero upon reset and are cleared again
//	as a matter of precaution. 

/* Clear all TAn bits */      
	
	ECanaRegs.CANTA.all	= 0xFFFFFFFF;

/* Clear all RMPn bits */      
	
	ECanaRegs.CANRMP.all = 0xFFFFFFFF;
	
/* Clear all interrupt flag bits */      
	
	ECanaRegs.CANGIF0.all = 0xFFFFFFFF;
	ECanaRegs.CANGIF1.all = 0xFFFFFFFF;
	
/* Configure bit timing parameters */

	ECanaRegs.CANMC.bit.CCR = 1 ;            // Set CCR = 1
    
    while(ECanaRegs.CANES.bit.CCE != 1 ) {}   // Wait for CCE bit to be set..
    
    ECanaRegs.CANBTC.bit.BRPREG = 9;
    ECanaRegs.CANBTC.bit.TSEG2REG = 2;
    ECanaRegs.CANBTC.bit.TSEG1REG = 10;  
    
    ECanaRegs.CANMC.bit.CCR = 0 ;             // Set CCR = 0
    while(ECanaRegs.CANES.bit.CCE == !0 ) {}   // Wait for CCE bit to be cleared..
	
/* Disable all Mailboxes  */
	
 	ECanaRegs.CANME.all = 0;		// Required before writing the MSGIDs

}	
	
/***************************************************/
/* Bit configuration parameters for 150 MHz SYSCLKOUT*/ 
/***************************************************/
/*

The table below shows how BRP field must be changed to achieve different bit
rates with a BT of 15, for a 80% SP:
---------------------------------------------------
BT = 15, TSEG1 = 10, TSEG2 = 2, Sampling Point = 80% 
---------------------------------------------------
1   Mbps : BRP+1 = 10 	: CAN clock = 15 MHz
500 kbps : BRP+1 = 20 	: CAN clock = 7.5 MHz 
250 kbps : BRP+1 = 40 	: CAN clock = 3.75 MHz 
125 kbps : BRP+1 = 80 	: CAN clock = 1.875 MHz 
100 kbps : BRP+1 = 100 	: CAN clock = 1.5 MHz
50  kbps : BRP+1 = 200 	: CAN clock = 0.75 MHz

The table below shows how to achieve different sampling points with a BT of 25:
-------------------------------------------------------------
Achieving desired SP by changing TSEG1 & TSEG2 with BT = 25  
-------------------------------------------------------------

TSEG1 = 18, TSEG2 = 4, SP = 80% 
TSEG1 = 17, TSEG2 = 5, SP = 76% 
TSEG1 = 16, TSEG2 = 6, SP = 72% 
TSEG1 = 15, TSEG2 = 7, SP = 68% 
TSEG1 = 14, TSEG2 = 8, SP = 64% 

The table below shows how BRP field must be changed to achieve different bit
rates with a BT of 25, for the sampling points shown above: 

1   Mbps : BRP+1 = 6 
500 kbps : BRP+1 = 12 
250 kbps : BRP+1 = 24 
125 kbps : BRP+1 = 48 
100 kbps : BRP+1 = 60
50  kbps : BRP+1 = 120

*/


