//###########################################################################
//
// FILE:   DSP281x_Device.h
//
// TITLE:  DSP281x Device Definitions.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  1.00| 11 Sep 2003 | L.H. | Changes since previous version (v.58 Alpha)
//      |             |      | Added symbols created by the linker
//      |             |      |     cmd file for relocating code.
//      |             |      | Added float to the datatype typedefs
//      |             |      | Added #if DSP28_DATA_TYPES wrapper around the 
//      |             |      |     typedefs 
//      |             |      | Added DSP28_BIOS and DSP28_NONBIOS switches
//      |             |      |     to include or not include the default ISR's 
//      |             |      | Moved files and info specific to the DSP28 examples
//      |             |      |     to DSP28_common\include\DSP28_Examples.h
//      |             |      | Changed F2812 -> DSP28_F2812
//      |             |      | Changed F2810 -> DSP28_F2810
//###########################################################################

#ifndef DSP281x_DEVICE_H
#define DSP281x_DEVICE_H


#ifdef __cplusplus
extern "C" {
#endif


#define   TARGET   1
//---------------------------------------------------------------------------
// User To Select Target Device:

#define   DSP28_F2812   TARGET
#define   DSP28_F2810   0

//---------------------------------------------------------------------------
// Common CPU Definitions:
//

extern cregister volatile unsigned int IFR;
extern cregister volatile unsigned int IER;

#define  EINT   asm(" clrc INTM")
#define  DINT   asm(" setc INTM")
#define  ERTM   asm(" clrc DBGM")
#define  DRTM   asm(" setc DBGM")
#define  EALLOW asm(" EALLOW")
#define  EDIS   asm(" EDIS")
#define  ESTOP0 asm(" ESTOP0")

#define M_INT1  0x0001
#define M_INT2  0x0002
#define M_INT3  0x0004
#define M_INT4  0x0008
#define M_INT5  0x0010
#define M_INT6  0x0020
#define M_INT7  0x0040
#define M_INT8  0x0080
#define M_INT9  0x0100
#define M_INT10 0x0200
#define M_INT11 0x0400
#define M_INT12 0x0800
#define M_INT13 0x1000
#define M_INT14 0x2000
#define M_DLOG  0x4000
#define M_RTOS  0x8000

#define BIT0    0x0001
#define BIT1    0x0002
#define BIT2    0x0004
#define BIT3    0x0008
#define BIT4    0x0010
#define BIT5    0x0020
#define BIT6    0x0040
#define BIT7    0x0080
#define BIT8    0x0100
#define BIT9    0x0200
#define BIT10   0x0400
#define BIT11   0x0800
#define BIT12   0x1000
#define BIT13   0x2000
#define BIT14   0x4000
#define BIT15   0x8000



//---------------------------------------------------------------------------
// For Portability, User Is Recommended To Use Following Data Type Size
// Definitions For 16-bit and 32-Bit Signed/Unsigned Integers:
//

#ifndef DSP28_DATA_TYPES
#define DSP28_DATA_TYPES
typedef int             int16;
typedef long            int32;
typedef unsigned int    Uint16;
typedef unsigned long   Uint32;
typedef float           float32;
typedef long double     float64;
#endif


//---------------------------------------------------------------------------
// Include All Peripheral Header Files:
//

#include "DSP281x_SysCtrl.h"            // System Control/Power Modes
#include "DSP281x_DevEmu.h"             // Device Emulation Registers
#include "DSP281x_Xintf.h"              // External Interface Registers
#include "DSP281x_CpuTimers.h"          // 32-bit CPU Timers
#include "DSP281x_PieCtrl.h"            // PIE Control Registers
#include "DSP281x_PieVect.h"            // PIE Vector Table
#include "DSP281x_Spi.h"                // SPI Registers
#include "DSP281x_Sci.h"                // SCI Registers
#include "DSP281x_Mcbsp.h"              // McBSP Registers
#include "DSP281x_ECan.h"               // Enhanced eCAN Registers
#include "DSP281x_Gpio.h"               // General Purpose I/O Registers
#include "DSP281x_Ev.h"                 // Event Manager Registers
#include "DSP281x_Adc.h"                // ADC Registers
#include "DSP281x_XIntrupt.h"           // External Interrupts

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP281x_DEVICE_H definition


//===========================================================================
// No more.
//===========================================================================
