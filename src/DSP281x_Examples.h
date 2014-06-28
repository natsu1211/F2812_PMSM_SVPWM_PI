//###########################################################################
//
// FILE:   DSP281x_Examples.h
//
// TITLE:  DSP281x Device Definitions.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  1.00| 11 Sep 2003 | L.H. | First release.  Seperated example specific headers
//      |             |      |     from the DSP28 peripheral headers.
//      |             |      | Added DSP28_BIOS and DSP28_NONBIOS switches
//      |             |      |     to include or not include the default ISR's 
//###########################################################################

#ifndef DSP281x_EXAMPLES_H
#define DSP281x_EXAMPLES_H


#ifdef __cplusplus
extern "C" {
#endif


/*-----------------------------------------------------------------------------
      Specify the clock rate of the CPU (SYSCLKOUT) in nS.

      Take into account the input clock frequency and the PLL multiplier
      selected in step 1.
 
      Use one of the values provided, or define your own.
      The trailing L is required tells the compiler to treat 
      the number as a 64-bit value.  

      Only one statement should be uncommented.

      Example:  CLKIN is a 30MHz crystal. 
 
                In step 1 the user specified PLLCR = 0xA for a 
                150Mhz CPU clock (SYSCLKOUT = 150MHz).  

                In this case, the CPU_RATE will be 6.667L
                Uncomment the line:  #define CPU_RATE  6.667L   
-----------------------------------------------------------------------------*/
#define CPU_RATE    6.667L   // for a 150MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE    7.143L   // for a 140MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE    8.333L   // for a 120MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE   10.000L   // for a 100MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE   13.330L   // for a 75MHz CPU clock speed (SYSCLKOUT)
//#define CPU_RATE   20.000L   // for a 50MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   33.333L   // for a 30MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   41.667L   // for a 24MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   50.000L   // for a 20MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE   66.667L   // for a 15MHz CPU clock speed  (SYSCLKOUT)
//#define CPU_RATE  100.000L   // for a 10MHz CPU clock speed  (SYSCLKOUT)

//----------------------------------------------------------------------------



//---------------------------------------------------------------------------
// Include Example Header Files:
//

#include "DSP281x_GlobalPrototypes.h"       // Prototypes for global functions within the 
                                            // .c files.

#include "DSP281x_SWPrioritizedIsrLevels.h" // Used for Software Prioritization of ISR's


// Include files not used with DSP/BIOS
#ifndef DSP28_BIOS
#include "DSP281x_DefaultISR.h"
#endif


// DO NOT MODIFY THIS LINE.  
#define DELAY_US(A)  DSP28x_usDelay(((((long double) A * 1000.0L) / (long double)CPU_RATE) - 9.0L) / 5.0L)


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP281x_EXAMPELS_H definition


//===========================================================================
// No more.
//===========================================================================
