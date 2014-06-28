//
//      TMDX ALPHA RELEASE
//      Intended for product evaluation purposes
//
//###########################################################################
//
// FILE:	DSP28_Device.h
//
// TITLE:	DSP28 Device Definitions.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  0.55| 06 May 2002 | L.H. | EzDSP Alpha Release
//  0.56| 20 May 2002 | L.H. | No change
//  0.57| 24 May 2002 | L.H. | Added generic BIT# #define statements
//###########################################################################

#ifndef DSP28_DEVICE_H
#define DSP28_DEVICE_H

#define	TARGET	1
//---------------------------------------------------------------------------
// User To Select Target Device:

#define	F2812   TARGET
#define	F2810   0

//---------------------------------------------------------------------------
// Common CPU Definitions:
//

extern cregister volatile unsigned int IFR;
extern cregister volatile unsigned int IER;
#define  EINT   asm(" clrc INTM")
#define  DINT   asm(" setc INTM")
#define  ERTM   asm(" clrc DBGM")
#define  DRTM   asm(" setc DBGM")
#define	 EALLOW	asm(" EALLOW")
#define	 EDIS	asm(" EDIS")
#define  ESTOP0 asm(" ESTOP0")
#define  NOP asm(" NOP")

#define	M_INT1		0x0001
#define	M_INT2		0x0002
#define	M_INT3		0x0004
#define	M_INT4		0x0008
#define	M_INT5		0x0010
#define	M_INT6		0x0020
#define	M_INT7		0x0040
#define	M_INT8		0x0080
#define	M_INT9		0x0100
#define	M_INT10		0x0200
#define	M_INT11		0x0400
#define	M_INT12		0x0800
#define	M_INT13		0x1000
#define	M_INT14		0x2000
#define	M_DLOG		0x4000
#define	M_RTOS		0x8000

#define	BIT0		0x0001
#define	BIT1		0x0002
#define	BIT2		0x0004
#define	BIT3		0x0008
#define	BIT4		0x0010
#define	BIT5		0x0020
#define	BIT6		0x0040
#define	BIT7		0x0080
#define	BIT8		0x0100
#define	BIT9		0x0200
#define	BIT10		0x0400
#define	BIT11		0x0800
#define	BIT12		0x1000
#define	BIT13		0x2000
#define	BIT14		0x4000
#define	BIT15		0x8000



//---------------------------------------------------------------------------
// For Portability, User Is Recommended To Use Following Data Type Size
// Definitions For 16-bit and 32-Bit Signed/Unsigned Integers:
//

typedef int  		int16;
typedef long 		int32;
typedef unsigned int  	Uint16;
typedef unsigned long 	Uint32;

//---------------------------------------------------------------------------
// Include All Peripheral Header Files:
//

#include "DSP28_GlobalPrototypes.h"   // Prototypes for global functions within the 
                                      // .c files.

#include "DSP28_SysCtrl.h"    // System Control/Power Modes
#include "DSP28_DevEmu.h"     // Device Emulation Registers
#include "DSP28_Xintf.h"      // External Interface Registers
#include "DSP28_CpuTimers.h"  // 32-bit CPU Timers
#include "DSP28_PieCtrl.h"    // PIE Control Registers
#include "DSP28_PieVect.h"    // PIE Vector Table
#include "DSP28_DefaultIsr.h" // Software Prioritization for PIE Interrupts
#include "DSP28_Spi.h"        // SPI Registers
#include "DSP28_Sci.h"        // SCI Registers
#include "DSP28_Mcbsp.h"      // McBSP Registers
#include "DSP28_ECan.h"       // Enhanced eCAN Registers
#include "DSP28_Gpio.h"       // General Purpose I/O Registers
#include "DSP28_Ev.h"         // Event Manager Registers
#include "DSP28_Adc.h"        // ADC Registers
#include "DSP28_XIntrupt.h"   // External Interrupts

//---------------------------------------------------------------------------
// Define Device Init Function Prototype:
//


#endif  // end of DSP28_DEVICE_H definition


//===========================================================================
// No more.
//===========================================================================
