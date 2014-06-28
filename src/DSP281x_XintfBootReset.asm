;//###########################################################################
;//
;// FILE:  DSP281x_XintfBootReset.asm
;//
;// TITLE: Boot from XINTF Zone 7
;//
;// DESCRIPTION:
;//  
;// This file includes the required setup for booting from XINTF Zone 7.
;// 
;// The reset vector located at 0x3FFFC0 is set to either the watchdog
;// disable function or the entry point to the C routine. 
;//
;// Use the linker file F2812_XintfBoot.cmd to properly map the reset vector.
;// 
;// This file assumes the device is set to "boot from XINTF zone 7" and the 
;// MP/MC pin is pulled high.           
;//
;//###########################################################################
;//
;// Based on source from D.A.
;//
;//  Ver | dd mmm yyyy | Who  | Description of changes
;// =====|=============|======|===============================================
;//  1.00| 11 Sep 03   | L.H. | First release
;//########################################################################### 	

WD_DISABLE	.set	1		;set to 1 to disable WD, else set to 0

    .ref _c_int00

***********************************************************************
* Function: Reset vector for XINTF boot
*
***********************************************************************

    .sect "reset_vec"  

reset_vec:
    .if WD_DISABLE == 1
        .long wd_disable       ;Point reset to watchdog disable code
    .else
        .long _c_int00         ;Point reset to start of boot.asm in RTS library
    .endif

;end codestart section


***********************************************************************
* Function: wd_disable
*
* Description: Disables the watchdog timer
***********************************************************************
    .if WD_DISABLE == 1

    .text
wd_disable:
    SETC OBJMODE        ;Set 28x OBJECTMODE
    EALLOW              ;Enable EALLOW protected register access
    MOVZ DP, #7029h>>6  ;Set data page for WDCR register
    MOV @7029h, #0068h  ;Set WDDIS bit in WDCR to disable WD
    EDIS                ;Disable EALLOW protected register access
    LB _c_int00         ;Branch to start of boot.asm in RTS library

    .endif

;end wd_disable



	.end
	
; end of file XintfBootReset.asm