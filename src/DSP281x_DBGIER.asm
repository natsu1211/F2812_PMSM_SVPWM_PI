;//###########################################################################
;//
;// FILE:  DSP281x_DBGIER.asm
;//
;// TITLE: Set the DBGIER register
;//
;// DESCRIPTION:
;//  
;//  Function to set the DBGIER register (for realtime emulation).
;//  Function Prototype: void SetDBGIER(Uint16)
;//  Useage: SetDBGIER(value);
;//  Input Parameters: Uint16 value = value to put in DBGIER register. 
;//  Return Value: none          
;//
;//###########################################################################
;//
;//  Ver | dd mmm yyyy | Who  | Description of changes
;// =====|=============|======|===============================================
;//  1.00| 11 Sep 2003 | L.H. | No changes since v.58
;//########################################################################### 	
		.global _SetDBGIER
		.text
		
_SetDBGIER:
		MOV 	*SP++,AL
		POP 	DBGIER
		LRETR
		