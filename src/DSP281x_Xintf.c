//###########################################################################
//
// FILE:   DSP281x_Xintf.c
//
// TITLE:   DSP281x Device External Interface Init & Support Functions.
//
// DESCRIPTION:
//
//          Example initialization function for the external interface (XINTF).
//          This example configures the XINTF to its default state.  For an
//          example of how this function can be modified to configure the XINTF
//          for use with the F2812 eZdsp, refer to the examples/run_from_xintf
//          project.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  1.00| 11 Sep 2003 | L.H. | Changes since previous version (v.58 Alpha)
//      |             |      | Added pipeline flush after the XINTF Init
//###########################################################################

#include "DSP281x_Device.h"     // DSP281x Headerfile Include File
#include "DSP281x_Examples.h"   // DSP281x Examples Include File

//---------------------------------------------------------------------------
// InitXINTF: 
//---------------------------------------------------------------------------
// This function initializes the External Interface the default reset state.
//
// Do not modify the timings of the XINTF while running from the XINTF.  Doing
// so can yield unpredictable results


void InitXintf(void)
{

#if  F2812

    // This shows how to write to the XINTF registers.  The
    // values used here are the default state after reset.
    // Different hardware will require a different configuration.
    
    // For an example of an XINTF configuration used with the
    // F2812 eZdsp, refer to the examples/run_from_xintf project.
    
    // Any changes to XINTF timing should only be made by code
    // running outside of the XINTF. 
    
    // All Zones---------------------------------
    // Timing for all zones based on XTIMCLK = 1/2 SYSCLKOUT 
    XintfRegs.XINTCNF2.bit.XTIMCLK = 1;
    // No write buffering
    XintfRegs.XINTCNF2.bit.WRBUFF = 0;
    // XCLKOUT is enabled
    XintfRegs.XINTCNF2.bit.CLKOFF = 0;
    // XCLKOUT = XTIMCLK/2 
    XintfRegs.XINTCNF2.bit.CLKMODE = 1;
    
    
    // Zone 0------------------------------------
    // When using ready, ACTIVE must be 1 or greater
    // Lead must always be 1 or greater
    // Zone write timing
    XintfRegs.XTIMING0.bit.XWRLEAD = 3;
    XintfRegs.XTIMING0.bit.XWRACTIVE = 7;
    XintfRegs.XTIMING0.bit.XWRTRAIL = 3;
    // Zone read timing
    XintfRegs.XTIMING0.bit.XRDLEAD = 3;
    XintfRegs.XTIMING0.bit.XRDACTIVE = 7;
    XintfRegs.XTIMING0.bit.XRDTRAIL = 3;
    
    // double all Zone read/write lead/active/trail timing 
    XintfRegs.XTIMING0.bit.X2TIMING = 1;

    // Zone will sample XREADY signal 
    XintfRegs.XTIMING0.bit.USEREADY = 1;
    XintfRegs.XTIMING0.bit.READYMODE = 1;  // sample asynchronous

    // Size must be 1,1 - other values are reserved
    XintfRegs.XTIMING0.bit.XSIZE = 3;
    
    // Zone 1------------------------------------
    // When using ready, ACTIVE must be 1 or greater
    // Lead must always be 1 or greater
    // Zone write timing
    XintfRegs.XTIMING1.bit.XWRLEAD = 3;
    XintfRegs.XTIMING1.bit.XWRACTIVE = 7;
    XintfRegs.XTIMING1.bit.XWRTRAIL = 3;
    // Zone read timing
    XintfRegs.XTIMING1.bit.XRDLEAD = 3;
    XintfRegs.XTIMING1.bit.XRDACTIVE = 7;
    XintfRegs.XTIMING1.bit.XRDTRAIL = 3;
    
    // double all Zone read/write lead/active/trail timing 
    XintfRegs.XTIMING1.bit.X2TIMING = 1;

    // Zone will sample XREADY signal 
    XintfRegs.XTIMING1.bit.USEREADY = 1;
    XintfRegs.XTIMING1.bit.READYMODE = 1;  // sample asynchronous

    // Size must be 1,1 - other values are reserved
    XintfRegs.XTIMING1.bit.XSIZE = 3;

    // Zone 2------------------------------------
    // When using ready, ACTIVE must be 1 or greater
    // Lead must always be 1 or greater
    // Zone write timing
    XintfRegs.XTIMING2.bit.XWRLEAD = 3;
    XintfRegs.XTIMING2.bit.XWRACTIVE = 7;
    XintfRegs.XTIMING2.bit.XWRTRAIL = 3;
    // Zone read timing
    XintfRegs.XTIMING2.bit.XRDLEAD = 3;
    XintfRegs.XTIMING2.bit.XRDACTIVE = 7;
    XintfRegs.XTIMING2.bit.XRDTRAIL = 3;
    
    // double all Zone read/write lead/active/trail timing 
    XintfRegs.XTIMING2.bit.X2TIMING = 1;

    // Zone will sample XREADY signal 
    XintfRegs.XTIMING2.bit.USEREADY = 1;
    XintfRegs.XTIMING2.bit.READYMODE = 1;  // sample asynchronous

    // Size must be 1,1 - other values are reserved
    XintfRegs.XTIMING2.bit.XSIZE = 3;


    // Zone 6------------------------------------
    // When using ready, ACTIVE must be 1 or greater
    // Lead must always be 1 or greater
    // Zone write timing
    XintfRegs.XTIMING6.bit.XWRLEAD = 3;
    XintfRegs.XTIMING6.bit.XWRACTIVE = 7;
    XintfRegs.XTIMING6.bit.XWRTRAIL = 3;
    // Zone read timing
    XintfRegs.XTIMING6.bit.XRDLEAD = 3;
    XintfRegs.XTIMING6.bit.XRDACTIVE = 7;
    XintfRegs.XTIMING6.bit.XRDTRAIL = 3;
    
    // double all Zone read/write lead/active/trail timing 
    XintfRegs.XTIMING6.bit.X2TIMING = 1;

    // Zone will sample XREADY signal 
    XintfRegs.XTIMING6.bit.USEREADY = 1;
    XintfRegs.XTIMING6.bit.READYMODE = 1;  // sample asynchronous

    // Size must be 1,1 - other values are reserved
    XintfRegs.XTIMING6.bit.XSIZE = 3;


    // Zone 7------------------------------------
    // When using ready, ACTIVE must be 1 or greater
    // Lead must always be 1 or greater
    // Zone write timing
    XintfRegs.XTIMING7.bit.XWRLEAD = 3;
    XintfRegs.XTIMING7.bit.XWRACTIVE = 7;
    XintfRegs.XTIMING7.bit.XWRTRAIL = 3;
    // Zone read timing
    XintfRegs.XTIMING7.bit.XRDLEAD = 3;
    XintfRegs.XTIMING7.bit.XRDACTIVE = 7;
    XintfRegs.XTIMING7.bit.XRDTRAIL = 3;
    
    // double all Zone read/write lead/active/trail timing 
    XintfRegs.XTIMING7.bit.X2TIMING = 1;

    // Zone will sample XREADY signal 
    XintfRegs.XTIMING7.bit.USEREADY = 1;
    XintfRegs.XTIMING7.bit.READYMODE = 1;  // sample asynchronous

    // Size must be 1,1 - other values are reserved
    XintfRegs.XTIMING7.bit.XSIZE = 3;

    // Bank switching
    // Assume Zone 7 is slow, so add additional BCYC cycles 
    // when ever switching from Zone 7 to another Zone.  
    // This will help avoid bus contention.
    XintfRegs.XBANK.bit.BANK = 7;
    XintfRegs.XBANK.bit.BCYC = 7;

   //Force a pipeline flush to ensure that the write to 
   //the last register configured occurs before returning.  

   asm(" RPT #7 || NOP"); 
    
    #endif
}

//===========================================================================
// No more.
//===========================================================================
