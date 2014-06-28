//###########################################################################
//
// FILE:   DSP281x_SWPiroritizedPieVect.c
//
// TITLE:  DSP281x Devices SW Prioritized PIE Vector Table Initialization.
//
//###########################################################################
// 
// Original Source by A.T.
// 
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  1.00| 11 Sep 2003 | L.H. | Changes since previous version (v.1 Alpha)
//      |             |      | Updated revision to align with other files
//      |             |      | Moved USER0-USER11 to USER1-USER12 to match the CPU guide
// -----|-------------|------|-----------------------------------------------
//###########################################################################

#include "DSP281x_Device.h"     // DSP281x Headerfile Include File
#include "DSP281x_Examples.h"   // DSP281x Examples Include File


const struct PIE_VECT_TABLE PieVectTableInit = {

      PIE_RESERVED,       // Reserved space
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved
      PIE_RESERVED,       // reserved

// Non-Peripheral Interrupts:
      #if (INT13PL != 0)
      INT13_ISR,    // XINT13
      #else
      INT_NOTUSED_ISR,
      #endif
      
      #if (INT14PL != 0)
      INT14_ISR,     // CPU-Timer2
      #else
      INT_NOTUSED_ISR,
      #endif
      
      #if (INT15PL != 0)
      DATALOG_ISR,   // Datalogging interrupt
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (INT16PL != 0)
      RTOSINT_ISR,   // RTOS interrupt
      #else
      INT_NOTUSED_ISR,
      #endif

      rsvd_ISR,      // reserved interrupt
      NMI_ISR,       // Non-maskable interrupt
      ILLEGAL_ISR,   // Illegal operation TRAP
      USER1_ISR,     // User Defined trap 1
      USER2_ISR,     // User Defined trap 2
      USER3_ISR,     // User Defined trap 3
      USER4_ISR,     // User Defined trap 4
      USER5_ISR,     // User Defined trap 5
      USER6_ISR,     // User Defined trap 6
      USER7_ISR,     // User Defined trap 7
      USER8_ISR,     // User Defined trap 8
      USER9_ISR,     // User Defined trap 9
      USER10_ISR,    // User Defined trap 10
      USER11_ISR,    // User Defined trap 11
      USER12_ISR,     // User Defined trap 12

// Group 1 PIE Vectors:
      #if (G11PL != 0)
      PDPINTA_ISR,   // EV-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G12PL != 0)
      PDPINTB_ISR,   // EV-B
      #else
      INT_NOTUSED_ISR,
      #endif

      rsvd_ISR,

      #if (G14PL != 0)
      XINT1_ISR,     // External
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G15PL != 0)
      XINT2_ISR,     // External
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G16PL != 0)
      ADCINT_ISR,    // ADC
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G17PL != 0)
      TINT0_ISR,     // Timer 0
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G18PL != 0)
      WAKEINT_ISR,   // WD
      #else
      INT_NOTUSED_ISR,
      #endif

// Group 2 PIE Vectors:
      #if (G21PL != 0)
      CMP1INT_ISR,   // EV-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G22PL != 0)
      CMP2INT_ISR,   // EV-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G23PL != 0)
      CMP3INT_ISR,   // EV-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G24PL != 0)
      T1PINT_ISR,    // EV-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G25PL != 0)
      T1CINT_ISR,    // EV-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G26PL != 0)
      T1UFINT_ISR,   // EV-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G27PL != 0)
      T1OFINT_ISR,   // EV-A
      #else
      INT_NOTUSED_ISR,
      #endif

      rsvd_ISR,
      
// Group 3 PIE Vectors:
      #if (G31PL != 0)
      T2PINT_ISR,    // EV-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G32PL != 0)
      T2CINT_ISR,    // EV-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G33PL != 0)
      T2UFINT_ISR,   // EV-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G34PL != 0)
      T2OFINT_ISR,   // EV-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G35PL != 0)
      CAPINT1_ISR,   // EV-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G36PL != 0)
      CAPINT2_ISR,   // EV-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G37PL != 0)
      CAPINT3_ISR,   // EV-A
      #else
      INT_NOTUSED_ISR,
      #endif

      rsvd_ISR,
      
// Group 4 PIE Vectors:
      #if (G41PL != 0)
      CMP4INT_ISR,   // EV-B
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G42PL != 0)
      CMP5INT_ISR,   // EV-B
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G43PL != 0)
      CMP6INT_ISR,   // EV-B
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G44PL != 0)
      T3PINT_ISR,    // EV-B
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G45PL != 0)
      T3CINT_ISR,    // EV-B
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G46PL != 0)
      T3UFINT_ISR,   // EV-B
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G47PL != 0)
      T3OFINT_ISR,   // EV-B
      #else
      INT_NOTUSED_ISR,
      #endif

      rsvd_ISR,      
     
// Group 5 PIE Vectors:
      #if (G51PL != 0)
      T4PINT_ISR,    // EV-B
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G52PL != 0)
      T4CINT_ISR,    // EV-B
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G53PL != 0)
      T4UFINT_ISR,   // EV-B
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G54PL != 0)
      T4OFINT_ISR,   // EV-B
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G55PL != 0)
      CAPINT4_ISR,   // EV-B
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G56PL != 0)
      CAPINT5_ISR,   // EV-B
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G57PL != 0)
      CAPINT6_ISR,   // EV-B
      #else
      INT_NOTUSED_ISR,
      #endif

      rsvd_ISR,      

// Group 6 PIE Vectors:
      #if (G61PL != 0)
      SPIRXINTA_ISR,  // SPI-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G62PL != 0)
      SPITXINTA_ISR,  // SPI-A
      #else
      INT_NOTUSED_ISR,
      #endif

      rsvd_ISR,
      rsvd_ISR,

      #if (G65PL != 0)
      MRINTA_ISR,    // McBSP-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G66PL != 0)
      MXINTA_ISR,    // McBSP-A
      #else
      INT_NOTUSED_ISR,
      #endif

      rsvd_ISR,
      rsvd_ISR,
      
// Group 7 PIE Vectors:
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     

// Group 8 PIE Vectors:
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      
// Group 9 PIE Vectors:
      #if (G91PL != 0)
      SCIRXINTA_ISR,    // SCI-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G92PL != 0)
      SCITXINTA_ISR,    // SCI-A
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G93PL != 0)
      SCIRXINTB_ISR,    // SCI-B
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G94PL != 0)
      SCITXINTB_ISR,    // SCI-B
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G95PL != 0)
      ECAN0INTA_ISR, // eCAN
      #else
      INT_NOTUSED_ISR,
      #endif

      #if (G96PL != 0)
      ECAN1INTA_ISR, // eCAN
      #else
      INT_NOTUSED_ISR,
      #endif

      rsvd_ISR,   
      rsvd_ISR,  
      
// Group 10 PIE Vectors
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
            
// Group 11 PIE Vectors
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     

// Group 12 PIE Vectors
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
      rsvd_ISR,     
};

//---------------------------------------------------------------------------
// InitPieVectTable: 
//---------------------------------------------------------------------------
// This function initializes the PIE vector table to a known state.
// This function must be executed after boot time.
//

void InitPieVectTable(void)
{
   int16 i;
   Uint32 *Source = (void *) &PieVectTableInit;
   Uint32 *Dest = (void *) &PieVectTable;

   EALLOW;
   for(i=0; i < 128; i++) {
      *Dest++ = *Source++;
   }
   EDIS;
}

//===========================================================================
// No more.
//===========================================================================
