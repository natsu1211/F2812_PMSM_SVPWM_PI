//###########################################################################
//
// FILE:	DSP281x_SWPrioritizedDefaultIsr.c
//
// TITLE:	DSP281x Device Default Software Prioritized Interrupt Service Routines.
//
//###########################################################################
//
// Original Author: A.T.
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  1.00| 11 Sep 2003 | L.H. | Changes since previous version (v.1 Alpha)
//      |             |      | Updated revision version number to align with
//      |             |      | other files.
//      |             |      | Corrections made to the following ISR's
//      |             |      | INT13_ISR, INT14_ISR, XINT1_ISR, XINT2_ISR
//      |             |      | DATALOG_ISR
//      |             |      | 
// -----|-------------|------|-----------------------------------------------
//###########################################################################

#include "DSP281x_Device.h"     // DSP281x Headerfile Include File
#include "DSP281x_Examples.h"   // DSP281x Examples Include File

//---------------------------------------------------------------------------
// XINT13, TINT2, NMI, XINT1, XINT2 Default ISRs:
//---------------------------------------------------------------------------
//
// Connected to INT13 of CPU (use MINT13 mask):
#if (INT13PL != 0)
interrupt void INT13_ISR(void)     // XINT13 
{
	IER &= MINT13;                 // Set "global" priority
	EINT;

  	// Insert ISR Code here.......

  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;
}
#endif

// Connected to INT14 of CPU (use MINT14 mask):
#if (INT14PL != 0)
interrupt void INT14_ISR(void)     // CPU-Timer2
{
	IER &= MINT14;                 // Set "global" priority
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;
}
#endif

// Connected to NMI of CPU (non-maskable):
interrupt void NMI_ISR(void)      // Non-maskable interrupt
{
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;
}

// Connected to PIEIER1_4 (use MINT1 and MG14 masks):
#if (G14PL != 0)
interrupt void  XINT1_ISR(void)
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER1.all;
	IER |= M_INT1;                     // Set "global" priority	
	IER &= MINT1;                      // Set "global" priority
	PieCtrlRegs.PIEIER1.all &= MG14;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......

  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER1.all = TempPIEIER;
}     
#endif

// Connected to PIEIER1_5 (use MINT1 and MG15 masks):
#if (G15PL != 0)
interrupt void  XINT2_ISR(void)
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER1.all;
	IER |= M_INT1;                 // Set "global" priority	
	IER &= MINT1;                  // Set "global" priority
	PieCtrlRegs.PIEIER1.all &= MG15;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER1.all = TempPIEIER;
}
#endif

//---------------------------------------------------------------------------
// DATALOG, RTOSINT, EMUINT Default ISRs:
//---------------------------------------------------------------------------
//
// Connected to INT15 of CPU (use MINT15 mask):
#if (INT15PL != 0)
interrupt void DATALOG_ISR(void)   // Datalogging interrupt
{
	IER &= MINT15;                 // Set "global" priority
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;
}
#endif

// Connected to INT16 of CPU (use MINT16 mask):
#if (INT16PL != 0)
interrupt void RTOSINT_ISR(void)   // RTOS interrupt
{
	IER &= MINT16;                 // Set "global" priority
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;
}
#endif

// Connected to EMUINT of CPU (non-maskable):
interrupt void EMUINT_ISR(void)    // Emulation interrupt
{
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;
}

//---------------------------------------------------------------------------
// ILLEGAL Instruction Trap ISR:
//
interrupt void ILLEGAL_ISR(void)   // Illegal operation TRAP
{
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;
}

//---------------------------------------------------------------------------
// USER Traps Default ISRs:
//
interrupt void USER0_ISR(void)     // User Defined trap 0
{
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;
}

interrupt void USER1_ISR(void)     // User Defined trap 1
{
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;
}

interrupt void USER2_ISR(void)     // User Defined trap 2
{
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;
}

interrupt void USER3_ISR(void)     // User Defined trap 3
{
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;
}

interrupt void USER4_ISR(void)     // User Defined trap 4
{
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;
}

interrupt void USER5_ISR(void)     // User Defined trap 5
{
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;
}

interrupt void USER6_ISR(void)     // User Defined trap 6
{
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;
}

interrupt void USER7_ISR(void)     // User Defined trap 7
{
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;
}

interrupt void USER8_ISR(void)     // User Defined trap 8
{
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;
}

interrupt void USER9_ISR(void)     // User Defined trap 9
{
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;
}

interrupt void USER10_ISR(void)    // User Defined trap 10
{
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;
}

interrupt void USER11_ISR(void)    // User Defined trap 11
{
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;
}

//---------------------------------------------------------------------------
// ADC Default ISR: 
//
// Connected to PIEIER1_6 (use MINT1 and MG16 masks):
#if (G16PL != 0)
interrupt void  ADCINT_ISR(void)     // ADC
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER9.all;
	IER |= M_INT1;
	IER	&= MINT1;                      // Set "global" priority
	PieCtrlRegs.PIEIER9.all &= MG16;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER9.all = TempPIEIER;
}     
#endif

//---------------------------------------------------------------------------
// CPU Timer 0 Default ISR: 
//
// Connected to PIEIER1_7 (use MINT1 and MG17 masks):
#if (G17PL != 0)
interrupt void  TINT0_ISR(void)      // CPU-Timer 0
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER1.all;
	IER |= M_INT1;
	IER	&= MINT1;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER1.all &= MG17;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER1.all = TempPIEIER;
}     
#endif

//---------------------------------------------------------------------------
// Watchdog/Low Power Modes Default ISR: 
//
// Connected to PIEIER1_8 (use MINT1 and MG18 masks):
#if (G18PL != 0)
interrupt void  WAKEINT_ISR(void)    // WD/LPM
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER1.all;
	IER |= M_INT1;
	IER	&= MINT1;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER1.all &= MG18;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER1.all = TempPIEIER;
}     
#endif

//---------------------------------------------------------------------------
// EV-A Default ISRs: 
//
// Connected to PIEIER1_1 (use MINT1 and MG11 masks):
#if (G11PL != 0)
interrupt void PDPINTA_ISR( void )    // EV-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER1.all;
	IER |= M_INT1;
	IER	&= MINT1;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER1.all &= MG11;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER1.all = TempPIEIER;
}     
#endif

// Connected to PIEIER2_1 (use MINT2 and MG21 masks):
#if (G21PL != 0)
interrupt void CMP1INT_ISR(void)    // EV-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER2.all;
	IER |= M_INT2;
	IER	&= MINT2;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER2.all &= MG21;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER2.all = TempPIEIER;
}     
#endif

// Connected to PIEIER2_2 (use MINT2 and MG22 masks):
#if (G22PL != 0)
interrupt void CMP2INT_ISR(void)    // EV-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER2.all;
	IER |= M_INT2;
	IER	&= MINT2;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER2.all &= MG22;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER2.all = TempPIEIER;
}     
#endif

// Connected to PIEIER2_3 (use MINT2 and MG23 masks):
#if (G23PL != 0)
interrupt void CMP3INT_ISR(void)    // EV-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER2.all;
	IER |= M_INT2;
	IER	&= MINT2;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER2.all &= MG23;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER2.all = TempPIEIER;
}     
#endif

// Connected to PIEIER2_4 (use MINT2 and MG24 masks):
#if (G24PL != 0)
interrupt void T1PINT_ISR(void)    // EV-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER2.all;
	IER |= M_INT2;
	IER	&= MINT2;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER2.all &= MG24;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER2.all = TempPIEIER;
}     
#endif

// Connected to PIEIER2_5 (use MINT2 and MG25 masks):
#if (G25PL != 0)
interrupt void T1CINT_ISR(void)    // EV-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER2.all;
	IER |= M_INT2;
	IER	&= MINT2;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER2.all &= MG25;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER2.all = TempPIEIER;
}     
#endif

// Connected to PIEIER2_6 (use MINT2 and MG26 masks):
#if (G26PL != 0)
interrupt void T1UFINT_ISR(void)    // EV-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER2.all;
	IER |= M_INT2;
	IER	&= MINT2;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER2.all &= MG26;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;
eva_timer1_isr();
  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER2.all = TempPIEIER;
}     
#endif

// Connected to PIEIER2_7 (use MINT2 and MG27 masks):
#if (G27PL != 0)
interrupt void T1OFINT_ISR(void)    // EV-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER2.all;
	IER |= M_INT2;
	IER	&= MINT2;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER2.all &= MG27;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER2.all = TempPIEIER;
}     
#endif

// Connected to PIEIER3_1 (use MINT3 and MG31 masks):
#if (G31PL != 0)
interrupt void T2PINT_ISR(void)    // EV-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER3.all;
	IER |= M_INT3;
	IER	&= MINT3;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER3.all &= MG31;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER3.all = TempPIEIER;
}     
#endif

// Connected to PIEIER3_2 (use MINT3 and MG32 masks):
#if (G32PL != 0)
interrupt void T2CINT_ISR(void)    // EV-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER3.all;
	IER |= M_INT3;
	IER	&= MINT3;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER3.all &= MG32;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER3.all = TempPIEIER;
}     
#endif
      
// Connected to PIEIER3_3 (use MINT3 and MG33 masks):
#if (G33PL != 0)
interrupt void T2UFINT_ISR(void)    // EV-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER3.all;
	IER |= M_INT3;
	IER	&= MINT3;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER3.all &= MG33;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER3.all = TempPIEIER;
}     
#endif

// Connected to PIEIER3_4 (use MINT3 and MG34 masks):
#if (G34PL != 0)
interrupt void T2OFINT_ISR(void)    // EV-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER3.all;
	IER |= M_INT3;
	IER	&= MINT3;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER3.all &= MG34;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER3.all = TempPIEIER;
}     
#endif

// Connected to PIEIER3_5 (use MINT3 and MG35 masks):
#if (G35PL != 0)
interrupt void CAPINT1_ISR(void)    // EV-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER3.all;
	IER |= M_INT3;
	IER	&= MINT3;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER3.all &= MG35;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;
CAPINT1();
  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER3.all = TempPIEIER;
}     
#endif

// Connected to PIEIER3_6 (use MINT3 and MG36 masks):
#if (G36PL != 0)
interrupt void CAPINT2_ISR(void)    // EV-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER3.all;
	IER |= M_INT3;
	IER	&= MINT3;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER3.all &= MG36;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;
CAPINT2();
  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER3.all = TempPIEIER;
}     
#endif

// Connected to PIEIER3_7 (use MINT3 and MG37 masks):
#if (G37PL != 0)
interrupt void CAPINT3_ISR(void)    // EV-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER3.all;
	IER |= M_INT3;
	IER	&= MINT3;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER3.all &= MG37;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER3.all = TempPIEIER;
}     
#endif
      
//---------------------------------------------------------------------------
// EV-B Default ISRs: 
//
// Connected to PIEIER1_2 (use MINT1 and MG12 masks):
#if (G12PL != 0)
interrupt void PDPINTB_ISR( void )    // EV-B
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER1.all;
	IER |= M_INT1;
	IER	&= MINT1;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER1.all &= MG12;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER1.all = TempPIEIER;
}     
#endif

// Connected to PIEIER4_1 (use MINT4 and MG41 masks):
#if (G41PL != 0)
interrupt void CMP4INT_ISR(void)    // EV-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER4.all;
	IER |= M_INT4;
	IER	&= MINT4;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER4.all &= MG41;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER4.all = TempPIEIER;
}     
#endif

// Connected to PIEIER4_2 (use MINT4 and MG42 masks):
#if (G42PL != 0)
interrupt void CMP5INT_ISR(void)    // EV-B
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER5.all;
	IER |= M_INT4;
	IER	&= MINT4;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER4.all &= MG42;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER4.all = TempPIEIER;
}     
#endif

// Connected to PIEIER4_3 (use MINT4 and MG43 masks):
#if (G43PL != 0)
interrupt void CMP6INT_ISR(void)    // EV-B
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER4.all;
	IER |= M_INT4;
	IER	&= MINT4;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER4.all &= MG43;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER4.all = TempPIEIER;
}     
#endif

// Connected to PIEIER4_4 (use MINT4 and MG44 masks):
#if (G44PL != 0)
interrupt void T3PINT_ISR(void)    // EV-B
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER4.all;
	IER |= M_INT4;
	IER	&= MINT4;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER4.all &= MG44;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;
eva_timer3_isr();
  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER4.all = TempPIEIER;
}     
#endif

// Connected to PIEIER4_5 (use MINT4 and MG45 masks):
#if (G45PL != 0)
interrupt void T3CINT_ISR(void)    // EV-B
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER4.all;
	IER |= M_INT4;
	IER	&= MINT4;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER4.all &= MG45;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER4.all = TempPIEIER;
}     
#endif

// Connected to PIEIER4_6 (use MINT4 and MG46 masks):
#if (G46PL != 0)
interrupt void T3UFINT_ISR(void)    // EV-B
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER4.all;
	IER |= M_INT4;
	IER	&= MINT4;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER4.all &= MG46;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER4.all = TempPIEIER;
}     
#endif

// Connected to PIEIER4_7 (use MINT4 and MG47 masks):
#if (G47PL != 0)
interrupt void T3OFINT_ISR(void)    // EV-B
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER4.all;
	IER |= M_INT4;
	IER	&= MINT4;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER4.all &= MG47;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER4.all = TempPIEIER;
}     
#endif

// Connected to PIEIER5_1 (use MINT5 and MG51 masks):
#if (G51PL != 0)
interrupt void T4PINT_ISR(void)    // EV-B
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER5.all;
	IER |= M_INT5;
	IER	&= MINT5;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER5.all &= MG51;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;
eva_timer4_isr();
  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER5.all = TempPIEIER;
}     
#endif

// Connected to PIEIER5_2 (use MINT5 and MG52 masks):
#if (G52PL != 0)
interrupt void T4CINT_ISR(void)    // EV-B
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER5.all;
	IER |= M_INT5;
	IER	&= MINT5;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER5.all &= MG52;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER5.all = TempPIEIER;
}     
#endif
      
// Connected to PIEIER5_3 (use MINT5 and MG53 masks):
#if (G53PL != 0)
interrupt void T4UFINT_ISR(void)    // EV-B
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER5.all;
	IER |= M_INT5;
	IER	&= MINT5;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER5.all &= MG53;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER5.all = TempPIEIER;
}     
#endif

// Connected to PIEIER5_4 (use MINT5 and MG54 masks):
#if (G54PL != 0)
interrupt void T4OFINT_ISR(void)    // EV-B
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER5.all;
	IER |= M_INT5;
	IER	&= MINT5;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER5.all &= MG54;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER5.all = TempPIEIER;
}     
#endif

// Connected to PIEIER5_5 (use MINT5 and MG55 masks):
#if (G55PL != 0)
interrupt void CAPINT4_ISR(void)    // EV-B
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER5.all;
	IER |= M_INT5;
	IER	&= MINT5;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER5.all &= MG55;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER5.all = TempPIEIER;
}     
#endif

// Connected to PIEIER5_6 (use MINT5 and MG56 masks):
#if (G56PL != 0)
interrupt void CAPINT5_ISR(void)    // EV-B
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER5.all;
	IER |= M_INT5;
	IER	&= MINT5;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER5.all &= MG56;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER5.all = TempPIEIER;
}     
#endif

// Connected to PIEIER5_7 (use MINT5 and MG57 masks):
#if (G57PL != 0)
interrupt void CAPINT6_ISR(void)    // EV-B
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER5.all;
	IER |= M_INT5;
	IER	&= MINT5;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER5.all &= MG57;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER5.all = TempPIEIER;
}     
#endif


//---------------------------------------------------------------------------
// McBSP-A Default ISRs: 
//
// Connected to PIEIER6_5 (use MINT6 and MG65 masks):
#if (G65PL != 0)
interrupt void MRINTA_ISR(void)     // McBSP-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER6.all;
	IER |= M_INT6;
	IER	&= MINT6;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER6.all &= MG65;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER6.all = TempPIEIER;
}     
#endif

// Connected to PIEIER6_6 (use MINT6 and MG66 masks):
#if (G66PL != 0)
interrupt void MXINTA_ISR(void)     // McBSP-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER6.all;
	IER |= M_INT6;
	IER	&= MINT6;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER6.all &= MG66;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER6.all = TempPIEIER;
}     
#endif

//---------------------------------------------------------------------------
// SPI-A Default ISRs: 
//
// Connected to PIEIER6_1 (use MINT6 and MG61 masks):
#if (G61PL != 0)
interrupt void SPIRXINTA_ISR(void)    // SPI-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER6.all;
	IER |= M_INT6;
	IER	&= MINT6;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER6.all &= MG61;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER6.all = TempPIEIER;
}     
#endif

// Connected to PIEIER6_2 (use MINT6 and MG62 masks):
#if (G62PL != 0)
interrupt void SPITXINTA_ISR(void)     // SPI-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER6.all;
	IER |= M_INT6;
	IER	&= MINT6;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER6.all &= MG62;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER6.all = TempPIEIER;
}     
#endif

//---------------------------------------------------------------------------
// SCI-A Default ISRs: 
//
// Connected to PIEIER9_1 (use MINT9 and MG91 masks):
#if (G91PL != 0)
interrupt void SCIRXINTA_ISR(void)     // SCI-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER9.all;
	IER |= M_INT9;
	IER	&= MINT9;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER9.all &= MG91;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER9.all = TempPIEIER;
}     
#endif

// Connected to PIEIER9_2 (use MINT9 and MG92 masks):
#if (G92PL != 0)
interrupt void SCITXINTA_ISR(void)     // SCI-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER9.all;
	IER |= M_INT9;
	IER	&= MINT9;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER9.all &= MG92;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER9.all = TempPIEIER;
}     
#endif

//---------------------------------------------------------------------------
// SCI-B Default ISRs: 
//
// Connected to PIEIER9_3 (use MINT9 and MG93 masks):
#if (G93PL != 0)
interrupt void SCIRXINTB_ISR(void)     // SCI-B
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER9.all;
	IER |= M_INT9;
	IER	&= MINT9;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER9.all &= MG93;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER9.all = TempPIEIER;
}     
#endif

// Connected to PIEIER9_4 (use MINT9 and MG94 masks):
#if (G94PL != 0)
interrupt void SCITXINTB_ISR(void)     // SCI-B
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER9.all;
	IER |= M_INT9;
	IER	&= MINT9;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER9.all &= MG94;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER9.all = TempPIEIER;
}     
#endif
//---------------------------------------------------------------------------
// eCAN-A Default ISRs: 
//
// Connected to PIEIER9_5 (use MINT9 and MG95 masks):
#if (G95PL != 0)
interrupt void ECAN0INTA_ISR(void)  // eCAN-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER9.all;
	IER |= M_INT9;
	IER	&= MINT9;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER9.all &= MG95;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
    ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER9.all = TempPIEIER;
}     
#endif

// Connected to PIEIER9_6 (use MINT9 and MG96 masks):
#if (G96PL != 0)
interrupt void ECAN1INTA_ISR(void)  // eCAN-A
{
	// Set interrupt priority:
	volatile Uint16 TempPIEIER = PieCtrlRegs.PIEIER9.all;
	IER |= M_INT9;
	IER	&= MINT9;	  	                // Set "global" priority
	PieCtrlRegs.PIEIER9.all &= MG96;   // Set "group"  priority	
	PieCtrlRegs.PIEACK.all = 0xFFFF;   // Enable PIE interrupts	
	EINT;

  	// Insert ISR Code here.......
  
  	// Next line for debug only (remove after inserting ISR Code):
      ESTOP0;

	// Restore registers saved:
	DINT;
	PieCtrlRegs.PIEIER9.all = TempPIEIER;
}     
#endif

//---------------------------------------------------------------------------
// Catch All Default ISRs: 
//

interrupt void PIE_RESERVED(void)    // Interrupt not used default.
{
   ESTOP0;
}

interrupt void INT_NOTUSED_ISR(void)    // Interrupt not used default.
{
   ESTOP0;
}

interrupt void rsvd_ISR(void)           // Interrupt reserved default.
{
   ESTOP0;
}

//===========================================================================
// No more.
//===========================================================================
