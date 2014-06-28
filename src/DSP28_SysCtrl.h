//
//      TMDX ALPHA RELEASE
//      Intended for product evaluation purposes
//
//###########################################################################
//
// FILE:	DSP28_SysCtrl.h
//
// TITLE:	DSP28 Device System Control Register Definitions.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  0.55| 06 May 2002 | L.H. | EzDSP Alpha Release
//  0.56| 20 May 2002 | L.H. | No change
//  0.57| 27 May 2002 | L.H. | No change
//###########################################################################

#ifndef DSP28_SYS_CTRL_H
#define DSP28_SYS_CTRL_H

//---------------------------------------------------------------------------
// System Control Individual Register Bit Definitions:
//
// High speed peripheral clock register bit definitions:
struct HISPCP_BITS  {   // bits  description
   Uint16 HSPCLK:3;       // 2:0   Rate relative to SYSCLKOUT
   Uint16 rsvd1:13;       // 15:3  reserved
};

union HISPCP_REG {
   Uint16                all;
   struct HISPCP_BITS  bit;
};

// Low speed peripheral clock register bit definitions:
struct LOSPCP_BITS  {   // bits  description
   Uint16 LSPCLK:3;       // 2:0   Rate relative to SYSCLKOUT
   Uint16 rsvd1:13;       // 15:3  reserved
};

union LOSPCP_REG {
   Uint16                all;
   struct LOSPCP_BITS  bit;
};

// Peripheral clock control register bit definitions:
struct PCLKCR_BITS  {   // bits  description
   Uint16 EVAENCLK:1;     // 0     Enable high speed clk to EV-A
   Uint16 EVBENCLK:1;     // 1     Enable high speed clk to EV-B
   Uint16 rsvd1:1;        // 2 
   Uint16 ADCENCLK:1;     // 3     Enable high speed clk to ADC
   Uint16 rsvd2:4;        // 7:4   reserved
   Uint16 SPIENCLK:1;     // 8     Enable low speed clk to SPI
   Uint16 rsvd3:1;        // 9     reserved
   Uint16 SCIENCLKA:1;    // 10    Enable low speed clk to SCI-A
   Uint16 SCIENCLKB:1;    // 11    Enable low speed clk to SCI-B
   Uint16 MCBSPENCLK:1;   // 12    Enable low speed clk to McBSP
   Uint16 rsvd4:1;        // 13    reserved
   Uint16 ECANENCLK:1;    // 14    Enable system clk to eCAN
};

union PCLKCR_REG {
   Uint16                all;
   struct PCLKCR_BITS  bit;
};   

// System control and status register bit definitions:
struct SCSR_BITS {      // bits  description
   Uint16 WDOVERRIDE:1;   // 0     Allow watchdog disable
   Uint16 WDENINT:1;      // 1     Enable/disable WD interrupt
   Uint16 rsvd1:14;       // 15:2  reserved
};

union SCSR_REG {
   Uint16              all;
   struct SCSR_BITS  bit;
};

//---------------------------------------------------------------------------
// System Control Register File:
//
struct SYS_CTRL_REGS {
   Uint16  rsvd1[10];            // 0-9
   union HISPCP_REG HISPCP;      // 10: High-speed peripheral clock pre-scaler
   union LOSPCP_REG LOSPCP;      // 11: Low-speed peripheral clock pre-scaler
   union PCLKCR_REG PCLKCR;      // 12: Peripheral clock control register
   Uint16  rsvd2;                // 13
   Uint16  LPMCR0;               // 14: Low-power mode control register 0
   Uint16  LPMCR1;               // 15: Low-power mode control register 1
   Uint16  rsvd3;                // 16
   Uint16  PLLCR;                // 17: PLL control register
   union SCSR_REG SCSR;          // 18: System control and status register
   Uint16  WDCNTR;               // 19: WD counter register
   Uint16  rsvd4;                // 20
   Uint16  WDKEY;                // 21: WD reset key register
   Uint16  rsvd5[3];             // 22-24
   Uint16  WDCR;                 // 25: WD timer control register
   Uint16  rsvd6[6];             // 26-31
};


/* --------------------------------------------------- */
/* CSM Registers                                       */
/*                                                     */
/* ----------------------------------------------------*/

/* CSM Status & Control register bit definitions */
struct  CSMSCR_BITS {      // bit   description
   Uint16     SECURE:1;    // 0     Secure flag
   Uint16     rsvd1:14;    // 14-1  reserved
   Uint16     FORCESEC:1;  // 15    Force Secure control bit

}; 

/* Allow access to the bit fields or entire register */
union CSMSCR_REG {
   Uint16       all;
   struct CSMSCR_BITS bit;
};

/* CSM Register File */ 
struct  CSM_REGS {      
   Uint16         KEY0;       // KEY reg bits 15-0 
   Uint16         KEY1;       // KEY reg bits 31-16 
   Uint16         KEY2;       // KEY reg bits 47-32
   Uint16         KEY3;       // KEY reg bits 63-48
   Uint16         KEY4;       // KEY reg bits 79-64
   Uint16         KEY5;       // KEY reg bits 95-80
   Uint16         KEY6;       // KEY reg bits 111-96
   Uint16         KEY7;       // KEY reg bits 127-112
   Uint16         rsvd1;      // reserved
   Uint16         rsvd2;      // reserved
   Uint16         rsvd3;      // reserved
   Uint16         rsvd4;      // reserved
   Uint16         rsvd5;      // reserved
   Uint16         rsvd6;      // reserved
   Uint16         rsvd7;      // reserved 
   union CSMSCR_REG CSMSCR;     // CSM Status & Control register
};

/* Password locations */
struct  CSM_PWL {
   Uint16         PSWD0;      // PSWD bits 15-0
   Uint16         PSWD1;      // PSWD bits 31-16
   Uint16         PSWD2;      // PSWD bits 47-32
   Uint16         PSWD3;      // PSWD bits 63-48
   Uint16         PSWD4;      // PSWD bits 79-64
   Uint16         PSWD5;      // PSWD bits 95-80
   Uint16         PSWD6;      // PSWD bits 111-96
   Uint16         PSWD7;      // PSWD bits 127-112
};



/* Flash Registers */

/* Flash Option Register bit definitions */
struct  FOPT_BITS {             // bit   description
   Uint16     ENPIPE:1;   // 0     Enable Pipeline Mode
   Uint16     rsvd:15;    // 1-15  reserved
};

/* Allow access to the bit fields or entire register */
union FOPT_REG {
   Uint16     all;
   struct FOPT_BITS bit;
};

/* Flash Power Modes Register bit definitions */
struct  FPWR_BITS {             // bit   description
   Uint16     PWR:2;      // 0-1   Power Mode bits
   Uint16     rsvd:14;    // 2-15  reserved
};

/* Allow access to the bit fields or entire register */
union FPWR_REG {
   Uint16     all;
   struct FPWR_BITS bit;
};


/* Flash Status Register bit definitions */
struct  FSTATUS_BITS {             // bit   description
   Uint16     PWRS:2;        // 0-1   Power Mode Status bits
   Uint16     STDBYWAITS:1;  // 2     Bank/Pump Sleep to Standby Wait Counter Status bits
   Uint16     ACTIVEWAITS:1; // 3     Bank/Pump Standby to Active Wait Counter Status bits
   Uint16     rsvd1:4;       // 4-7   reserved
   Uint16     V3STAT:1;      // 8     VDD3V Status Latch bit
   Uint16     rsvd2:7;       // 9-15  reserved
};

/* Allow access to the bit fields or entire register */
union FSTATUS_REG {
   Uint16        all;
   struct FSTATUS_BITS bit;
};

/* Flash Sleep to Standby Wait Counter Register bit definitions */
struct  FSTDBYWAIT_BITS {          // bit   description
   Uint16     STDBYWAIT:8;   // 0-7   Bank/Pump Sleep to Standby Wait Count bits
   Uint16     rsvd:8;        // 8-15  reserved
};

/* Allow access to the bit fields or entire register */
union FSTDBYWAIT_REG {
   Uint16           all;
   struct FSTDBYWAIT_BITS bit;
};

/* Flash Standby to Active Wait Counter Register bit definitions */
struct  FACTIVEWAIT_BITS {         // bit   description
   Uint16     ACTIVEWAIT:8;  // 0-7   Bank/Pump Standby to Active Wait Count bits
   Uint16     rsvd:8;        // 8-15  reserved
};

/* Allow access to the bit fields or entire register */
union FACTIVEWAIT_REG {
   Uint16            all;
   struct FACTIVEWAIT_BITS bit;
};

/* Bank Read Access Wait State Register bit definitions */
struct  FBANKWAIT_BITS {           // bit   description
   Uint16     RANDWAIT:4;    // 0-3   Flash Random Read Wait State bits
   Uint16     rsvd1:4;       // 4-7   reserved
   Uint16     PAGEWAIT:4;    // 8-11  Flash Paged Read Wait State bits
   Uint16     rsvd2:4;       // 12-15 reserved
};

/* Allow access to the bit fields or entire register */
union FBANKWAIT_REG {
   Uint16          all;
   struct FBANKWAIT_BITS bit;
};

/* OTP Read Access Wait State Register bit definitions */
struct  FOTPWAIT_BITS {            // bit   description
   Uint16     OPTWAIT:5;     // 0-4   OTP Read Wait State bits
   Uint16     rsvd:11;       // 5-15  reserved
};

/* Allow access to the bit fields or entire register */
union FOTPWAIT_REG {
   Uint16         all;
   struct FOTPWAIT_BITS bit;
};


struct FLASH_REGS {
   union FOPT_REG        FOPT;        // Option Register
   Uint16 rsvd1;                      // reserved
   union FPWR_REG        FPWR;        // Power Modes Register
   union FSTATUS_REG     FSTATUS;     // Status Register
   union FSTDBYWAIT_REG  FSTDBYWAIT;  // Pump/Bank Sleep to Standby Wait State Register
   union FACTIVEWAIT_REG FACTIVEWAIT; // Pump/Bank Standby to Active Wait State Register
   union FBANKWAIT_REG   FBANKWAIT;   // Bank Read Access Wait State Register
   union FOTPWAIT_REG    FOTPWAIT;    // OTP Read Access Wait State Register
};

//---------------------------------------------------------------------------
// System Control External References & Function Declarations:
//
extern volatile struct SYS_CTRL_REGS SysCtrlRegs;
extern volatile struct CSM_REGS CsmRegs;
extern volatile struct CSM_PWL CsmPwl;
extern volatile struct FLASH_REGS FlashRegs;

#endif  // end of DSP28_SYS_CTRL_H definition

//===========================================================================
// No more.
//===========================================================================
