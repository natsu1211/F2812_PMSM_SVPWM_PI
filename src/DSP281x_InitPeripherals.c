//###########################################################################
//
// FILE:	DSP281x_InitPeripherals.c
//
// TITLE:	DSP281x Device Initialization To Default State.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  1.00| 11 Sep 2003 | L.H. | No change since previous version (v.58 Alpha)
//###########################################################################

#include "DSP281x_Device.h"     // DSP281x Headerfile Include File
#include "DSP281x_Examples.h"   // DSP281x Examples Include File

//---------------------------------------------------------------------------
// InitPeripherals:
//---------------------------------------------------------------------------
// The following function initializes the peripherals to a default state.
// It calls each of the peripherals default initialization functions.
// This function should be executed at boot time or on a soft reset.
//
void InitPeripherals(void)
{

        #if DSP28_F2812
        // Initialize External Interface To default State:
        InitXintf();
        #endif

	// Initialize CPU Timers To default State:
	InitCpuTimers();

	// Initialize McBSP Peripheral To default State:
	InitMcbsp();

	// Initialize Event Manager Peripheral To default State:
	InitEv();
	
         // Initialize ADC Peripheral To default State:
        InitAdc();
	
	// Initialize eCAN Peripheral To default State:
        InitECan();

	// Initialize SPI Peripherals To default State:
	InitSpi();

	// Initialize SCI Peripherals To default State:
	InitSci();
}

//===========================================================================
// No more.
//===========================================================================
