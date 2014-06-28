//###########################################################################
//
// FILE:    DSP28_DefaultIsr.h
//
// TITLE:   DSP28 Devices Default Interrupt Service Routines Definitions.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  0.55| 06 May 2002 | L.H. | EzDSP Alpha Release
//  0.56| 20 May 2002 | L.H. | No change
//  0.57| 27 May 2002 | L.H. | No change
//###########################################################################

#ifndef DSP28_DEFAULT_ISR_H
#define DSP28_DEFAULT_ISR_H

//---------------------------------------------------------------------------
// Default Interrupt Service Routine Declarations:
// 
// The following function prototypes are for the 
// default ISR routines used with the default PIE vector table.
// This default vector table is found in the DSP28_PieVect.h 
// file.  
//

// Non-Peripheral Interrupts:
interrupt void INT13_ISR(void);     // XINT13 or CPU-Timer 1
interrupt void INT14_ISR(void);     // CPU-Timer2
interrupt void DATALOG_ISR(void);   // Datalogging interrupt
interrupt void RTOSINT_ISR(void);   // RTOS interrupt
interrupt void EMUINT_ISR(void);    // Emulation interrupt
interrupt void NMI_ISR(void);       // Non-maskable interrupt
interrupt void ILLEGAL_ISR(void);   // Illegal operation TRAP
interrupt void USER0_ISR(void);     // User Defined trap 0
interrupt void USER1_ISR(void);     // User Defined trap 1
interrupt void USER2_ISR(void);     // User Defined trap 2
interrupt void USER3_ISR(void);     // User Defined trap 3
interrupt void USER4_ISR(void);     // User Defined trap 4
interrupt void USER5_ISR(void);     // User Defined trap 5
interrupt void USER6_ISR(void);     // User Defined trap 6
interrupt void USER7_ISR(void);     // User Defined trap 7
interrupt void USER8_ISR(void);     // User Defined trap 8
interrupt void USER9_ISR(void);     // User Defined trap 9
interrupt void USER10_ISR(void);    // User Defined trap 10
interrupt void USER11_ISR(void);    // User Defined trap 11

// Group 1 PIE Interrupt Service Routines:
interrupt void  PDPINTA_ISR(void);   // EV-A
interrupt void  PDPINTB_ISR(void);   // EV-B
interrupt void  XINT1_ISR(void);     
interrupt void  XINT2_ISR(void);
interrupt void  ADCINT_ISR(void);    // ADC
interrupt void  TINT0_ISR(void);     // Timer 0
interrupt void  WAKEINT_ISR(void);   // WD

// Group 2 PIE Interrupt Service Routines:
interrupt void CMP1INT_ISR(void);   // EV-A
interrupt void CMP2INT_ISR(void);   // EV-A
interrupt void CMP3INT_ISR(void);   // EV-A
interrupt void T1PINT_ISR(void);    // EV-A
interrupt void T1CINT_ISR(void);    // EV-A
interrupt void T1UFINT_ISR(void);   // EV-A
interrupt void T1OFINT_ISR(void);   // EV-A
      
// Group 3 PIE Interrupt Service Routines:
interrupt void T2PINT_ISR(void);    // EV-A
interrupt void T2CINT_ISR(void);    // EV-A
interrupt void T2UFINT_ISR(void);   // EV-A
interrupt void T2OFINT_ISR(void);   // EV-A
interrupt void CAPINT1_ISR(void);   // EV-A
interrupt void CAPINT2_ISR(void);   // EV-A
interrupt void CAPINT3_ISR(void);   // EV-A
      
// Group 4 PIE Interrupt Service Routines:
interrupt void CMP4INT_ISR(void);   // EV-B
interrupt void CMP5INT_ISR(void);   // EV-B
interrupt void CMP6INT_ISR(void);   // EV-B
interrupt void T3PINT_ISR(void);    // EV-B
interrupt void T3CINT_ISR(void);    // EV-B
interrupt void T3UFINT_ISR(void);   // EV-B
interrupt void T3OFINT_ISR(void);   // EV-B
     
// Group 5 PIE Interrupt Service Routines:
interrupt void T4PINT_ISR(void);    // EV-B
interrupt void T4CINT_ISR(void);    // EV-B
interrupt void T4UFINT_ISR(void);   // EV-B
interrupt void T4OFINT_ISR(void);   // EV-B
interrupt void CAPINT4_ISR(void);   // EV-B
interrupt void CAPINT5_ISR(void);   // EV-B
interrupt void CAPINT6_ISR(void);   // EV-B

// Group 6 PIE Interrupt Service Routines:
interrupt void SPIRXINTA_ISR(void);   // SPI
interrupt void SPITXINTA_ISR(void);    // SPI
interrupt void MRINTA_ISR(void);    // McBSP
interrupt void MXINTA_ISR(void);    // McBSP
 
   
// Group 9 PIE Interrupt Service Routines:
interrupt void SCIRXINTA_ISR(void); // SCI-A
interrupt void SCITXINTA_ISR(void); // SCI-A
interrupt void SCIRXINTB_ISR(void); // SCI-B
interrupt void SCITXINTB_ISR(void); // SCI-B
interrupt void ECAN0INTA_ISR(void); // eCAN
interrupt void ECAN1INTA_ISR(void); // eCAN


// Catch-all for Reserved Locations For testing purposes:
interrupt void PIE_RESERVED(void);       // Reserved for test
interrupt void rsvd_ISR(void);           // for test

#endif    // end of DSP28_DEFAULT_ISR_H definition

