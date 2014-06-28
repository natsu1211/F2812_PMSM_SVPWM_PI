//###########################################################################
//
// FILE:   DSP281x_GlobalPrototypes.h
//
// TITLE:  Global prototypes for DSP28 Examples 
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  1.00| 11 Sep 2003 | L.H. | Changes since previous version (v.58 Alpha)
//      |             |      | Corrected the filename and title in the
//      |             |      | header. 
//      |             |      | Removed unused functions.  Added InitPeripherals()
//###########################################################################

#ifndef DSP281x_GLOBALPROTOTYPES_H
#define DSP281x_GLOBALPROTOTYPES_H


#ifdef __cplusplus
extern "C" {
#endif

/*---- shared global function prototypes -----------------------------------*/
extern void InitAdc(void);
extern void InitPeripherals(void);
extern void InitECan(void);
extern void InitEv(void);
extern void InitGpio(void);
extern void InitMcbsp(void);
extern void InitPieCtrl(void);
extern void InitPieVectTable(void);
extern void EnableInterrupts(void);
extern void InitSci(void);
extern void InitSpi(void);
extern void InitSysCtrl(void);
extern void InitXintf(void);
extern void InitXIntrupt(void);
extern void InitPll(Uint16 val);
extern void InitPeripheralClocks(void);


// Watchdog functions
// DSP28_SysCtrl.c
extern void KickDog(void);
extern void DisableDog(void);

// DSP28_DBGIER.asm
extern void SetDBGIER(Uint16 dbgier);




//                 CAUTION
// This function MUST be executed out of RAM. Executing it
// out of OTP/Flash will yield unpredictable results
extern void InitFlash(void);


void MemCopy(Uint16 *SourceAddr, Uint16* SourceEndAddr, Uint16* DestAddr);


//---------------------------------------------------------------------------
// External symbols created by the linker cmd file
// DSP28 examples will use these to relocate code from one LOAD location 
// in either Flash or XINTF to a different RUN location in internal
// RAM
extern Uint16 RamfuncsLoadStart;
extern Uint16 RamfuncsLoadEnd;
extern Uint16 RamfuncsRunStart;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif   // - end of DSP281x_GLOBALPROTOTYPES_H

