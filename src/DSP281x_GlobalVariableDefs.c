//###########################################################################
//
// FILE:	DSP281x_GlobalVariableDefs.c
//
// TITLE:	DSP281x Global Variables and Data Section Pragmas.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  1.00| 11 Sep 2003 | L.H. | Changes since previous version (v.58 Alpha)
//      |             |      | Added support for C++
//###########################################################################

#include "DSP281x_Device.h"     // DSP281x Headerfile Include File

//---------------------------------------------------------------------------
// Define Global Peripheral Variables:
//

#ifdef __cplusplus 
#pragma DATA_SECTION("AdcRegsFile") 
#else 
#pragma DATA_SECTION(AdcRegs,"AdcRegsFile");
#endif 
volatile struct ADC_REGS AdcRegs;


#ifdef __cplusplus 
#pragma DATA_SECTION("CpuTimer0RegsFile") 
#else 
#pragma DATA_SECTION(CpuTimer0Regs,"CpuTimer0RegsFile");
#endif
volatile struct CPUTIMER_REGS CpuTimer0Regs;


// CPU Timer 1 and Timer2 are reserved for BIOS and thus not used
//#pragma DATA_SECTION(CpuTimer1Regs,"CpuTimer1RegsFile");
//volatile struct CPUTIMER_REGS CpuTimer1Regs;
//#pragma DATA_SECTION(CpuTimer2Regs,"CpuTimer2RegsFile");
//volatile struct CPUTIMER_REGS CpuTimer2Regs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("ECanaRegsFile") 
#else 
#pragma DATA_SECTION(ECanaRegs,"ECanaRegsFile");
#endif
volatile struct ECAN_REGS ECanaRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("ECanaMboxesFile") 
#else 
#pragma DATA_SECTION(ECanaMboxes,"ECanaMboxesFile");
#endif
volatile struct ECAN_MBOXES ECanaMboxes;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("ECanaLAMRegsFile") 
#else 
#pragma DATA_SECTION(ECanaLAMRegs,"ECanaLAMRegsFile");
#endif
volatile struct LAM_REGS ECanaLAMRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("ECanaMOTSRegsFile") 
#else 
#pragma DATA_SECTION(ECanaMOTSRegs,"ECanaMOTSRegsFile");
#endif
volatile struct MOTS_REGS ECanaMOTSRegs;


//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("ECanaMOTORegsFile") 
#else 
#pragma DATA_SECTION(ECanaMOTORegs,"ECanaMOTORegsFile");
#endif
volatile struct MOTO_REGS ECanaMOTORegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("EvaRegsFile") 
#else 
#pragma DATA_SECTION(EvaRegs,"EvaRegsFile");
#endif
volatile struct EVA_REGS EvaRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("EvbRegsFile") 
#else 
#pragma DATA_SECTION(EvbRegs,"EvbRegsFile");
#endif
volatile struct EVB_REGS EvbRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("GpioDataRegsFile") 
#else 
#pragma DATA_SECTION(GpioDataRegs,"GpioDataRegsFile");
#endif
volatile struct GPIO_DATA_REGS GpioDataRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("GpioMuxRegsFile") 
#else 
#pragma DATA_SECTION(GpioMuxRegs,"GpioMuxRegsFile");
#endif
volatile struct GPIO_MUX_REGS GpioMuxRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("McbspaRegsFile") 
#else 
#pragma DATA_SECTION(McbspaRegs,"McbspaRegsFile");
#endif
volatile struct MCBSP_REGS McbspaRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("PieCtrlRegsFile") 
#else
#pragma DATA_SECTION(PieCtrlRegs,"PieCtrlRegsFile");
#endif
volatile struct PIE_CTRL_REGS PieCtrlRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("PieVectTableFile") 
#else
#pragma DATA_SECTION(PieVectTable,"PieVectTableFile");
#endif
struct PIE_VECT_TABLE PieVectTable;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("SciaRegsFile") 
#else
#pragma DATA_SECTION(SciaRegs,"SciaRegsFile");
#endif
volatile struct SCI_REGS SciaRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("ScibRegsFile") 
#else
#pragma DATA_SECTION(ScibRegs,"ScibRegsFile");
#endif
volatile struct SCI_REGS ScibRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("SpiaRegsFile") 
#else
#pragma DATA_SECTION(SpiaRegs,"SpiaRegsFile");
#endif
volatile struct SPI_REGS SpiaRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("SysCtrlRegsFile") 
#else
#pragma DATA_SECTION(SysCtrlRegs,"SysCtrlRegsFile");
#endif
volatile struct SYS_CTRL_REGS SysCtrlRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("DevEmuRegsFile") 
#else
#pragma DATA_SECTION(DevEmuRegs,"DevEmuRegsFile");
#endif
volatile struct DEV_EMU_REGS DevEmuRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("CsmRegsFile") 
#else
#pragma DATA_SECTION(CsmRegs,"CsmRegsFile");
#endif
volatile struct CSM_REGS CsmRegs;

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("CsmPwlFile") 
#else
#pragma DATA_SECTION(CsmPwl,"CsmPwlFile");
#endif
volatile struct CSM_PWL CsmPwl;


//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("FlashRegsFile") 
#else
#pragma DATA_SECTION(FlashRegs,"FlashRegsFile");
#endif
volatile struct FLASH_REGS FlashRegs;

#if DSP28_F2812
//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("XintfRegsFile") 
#else
#pragma DATA_SECTION(XintfRegs,"XintfRegsFile");
#endif
volatile struct XINTF_REGS XintfRegs;
#endif

//----------------------------------------
#ifdef __cplusplus 
#pragma DATA_SECTION("XIntruptRegsFile") 
#else
#pragma DATA_SECTION(XIntruptRegs,"XIntruptRegsFile");
#endif
volatile struct XINTRUPT_REGS XIntruptRegs;



// The following are provided to support alternate notation
// that was used in an early version of the header files 

#define ADCRegs       AdcRegs
#define CPUTimer0Regs CpuTimer0Regs
#define ECANARegs     ECanaRegs
#define ECANAMboxes   ECanaMboxes
#define EVARegs       EvaRegs
#define GPIODataRegs  GpioDataRegs
#define GPIOMuxRegs   GpioMuxRegs
#define MCBSPARegs    McbspaRegs
#define PIECtrlRegs   PieCtrlRegs
#define PIEVectTable  PieVectTable
#define SCIARegs      SciaRegs
#define SCIBRegs      ScibRegs
#define SYSCtrlRegs   SysCtrlRegs
#define DEVEmuRegs    DevEmuRegs
#define CSMRegs       CsmRegs
#define CSMPwl        CsmPwl
#define FLASHRegs     FlashRegs
#define XINTFRegs     XintfRegs
#define XINTRUPTRegs  XIntruptRegs









