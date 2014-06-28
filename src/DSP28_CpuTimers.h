//
//      TMDX ALPHA RELEASE
//      Intended for product evaluation purposes
//
//###########################################################################
//
// FILE:	DSP28_CpuTimers.h
//
// TITLE:	DSP28 CPU 32-bit Timers Register Definitions.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  0.55| 06 May 2002 | L.H. | EzDSP Alpha Release
//  0.56| 20 May 2002 | L.H. | No change
//  0.57| 27 May 2002 | L.H. | No change
//###########################################################################

#ifndef DSP28_CPU_TIMERS_H
#define DSP28_CPU_TIMERS_H

//---------------------------------------------------------------------------
// CPU Timer Register Bit Definitions:
//
//
// TCR: Control register bit definitions:
struct  TCR_BITS {        // bits  description
   Uint16    OUTSTS:1;      // 0     Current state of TOUT
   Uint16    FORCE:1;       // 1     Force TOUT
   Uint16    POL:1;         // 2     Output polarity
   Uint16    TOG:1;         // 3     Output toggle mode
   Uint16    TSS:1;         // 4     Timer Start/Stop
   Uint16    TRB:1;         // 5     Timer reload
   Uint16    FRCEN:1;       // 6     Force enable
   Uint16    PWIDTH:3;      // 9:7   BitTOUT output pulse width
   Uint16    SOFT:1;        // 10    Emulation modes
   Uint16    FREE:1;        // 11
   Uint16    rsvd:2;        // 12:13 reserved
   Uint16    TIE:1;         // 14    Output enable
   Uint16    TIF:1;         // 15    Interrupt flag
}; 

union TCR_REG {
   Uint16             all;
   struct TCR_BITS  bit;
};

// TPR: Pre-scale low bit definitions:
struct  TPR_BITS {        // bits  description
   Uint16     TDDR:8;       // 7:0   Divide-down low
   Uint16     PSC:8;        // 15:8  Prescale counter low
};

union TPR_REG {
   Uint16             all;
   struct TPR_BITS  bit;
};

// TPRH: Pre-scale high bit definitions:
struct  TPRH_BITS {       // bits  description
   Uint16     TDDRH:8;      // 7:0   Divide-down high
   Uint16     PSCH:8;       // 15:8  Prescale counter high
};

union TPRH_REG {
   Uint16             all;
   struct TPRH_BITS bit;
};

// TIM, TIMH: Timer register definitions:
struct TIM_REG {
   Uint16  LSW;
   Uint16  MSW;
};

union TIM_GROUP {
   Uint32            all;
   struct TIM_REG  half;
};

// PRD, PRDH: Period register definitions:
struct PRD_REG {
   Uint16  LSW;
   Uint16  MSW;
};

union PRD_GROUP {
   Uint32            all;
   struct PRD_REG  half;
};

//---------------------------------------------------------------------------
// CPU Timer Register File:
//
struct CPUTIMER_REGS {
   union TIM_GROUP TIM;   // Timer counter register
   union PRD_GROUP PRD;   // Period register
   union TCR_REG  TCR;    // Timer control register
   Uint16  rsvd1;         // reserved
   union TPR_REG  TPR;    // Timer pre-scale low
   union TPRH_REG TPRH;   // Timer pre-scale high
};

//---------------------------------------------------------------------------
// CPU Timer Support Variables:
//
struct CPUTIMER_VARS {
   volatile struct  CPUTIMER_REGS  *RegsAddr;
   Uint32    InterruptCount;
   float   CPUFreqInMHz;
   float   PeriodInUSec;
};

//---------------------------------------------------------------------------
// Function prototypes and external definitions:
//
void InitCpuTimers(void);
void ConfigCpuTimer(struct CPUTIMER_VARS *Timer, float Freq, float Period);

extern volatile struct CPUTIMER_REGS CpuTimer0Regs;
extern volatile struct CPUTIMER_REGS CpuTimer1Regs;
extern volatile struct CPUTIMER_REGS CpuTimer2Regs;

extern struct CPUTIMER_VARS CpuTimer0;
extern struct CPUTIMER_VARS CpuTimer1;
extern struct CPUTIMER_VARS CpuTimer2;

//---------------------------------------------------------------------------
// Usefull Timer Operations:
//
// Start Timer:
#define	StartCpuTimer0()  CpuTimer0Regs.TCR.bit.TSS = 0
#define	StartCpuTimer1()  CpuTimer1Regs.TCR.bit.TSS = 0
#define	StartCpuTimer2()  CpuTimer2Regs.TCR.bit.TSS = 0

// Stop Timer:
#define	StopCpuTimer0()   CpuTimer0Regs.TCR.bit.TSS = 1
#define	StopCpuTimer1()   CpuTimer1Regs.TCR.bit.TSS = 1
#define	StopCpuTimer2()   CpuTimer2Regs.TCR.bit.TSS = 1

// Reload Timer With period Value:
#define	ReloadCpuTimer0() CpuTimer0Regs.TCR.bit.TRB = 1
#define	ReloadCpuTimer1() CpuTimer1Regs.TCR.bit.TRB = 1
#define	ReloadCpuTimer2() CpuTimer2Regs.TCR.bit.TRB = 1

// Read 32-Bit Timer Value:
#define	ReadCpuTimer0Counter() CpuTimer0Regs.TIM.all
#define	ReadCpuTimer1Counter() CpuTimer1Regs.TIM.all
#define	ReadCpuTimer2Counter() CpuTimer2Regs.TIM.all

// Read 32-Bit Period Value:
#define	ReadCpuTimer0Period() CpuTimer0Regs.PRD.all
#define	ReadCpuTimer1Period() CpuTimer1Regs.PRD.all
#define	ReadCpuTimer2Period() CpuTimer2Regs.PRD.all

#endif  // end of DSP28_CPU_TIMERS_H definition


//===========================================================================
// No more.
//===========================================================================
