//
//      TMDX ALPHA RELEASE
//      Intended for product evaluation purposes
//
//###########################################################################
//
// FILE:	DSP28_Adc.h
//
// TITLE:	DSP28 Device ADC Register Definitions.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  0.55| 06 May 2002 | L.H. | EzDSP Alpha Release
//  0.56| 20 May 2002 | L.H. | No change
//  0.57| 27 May 2002 | L.H. | No change
//###########################################################################

#ifndef DSP28_ADC_H
#define DSP28_ADC_H

//---------------------------------------------------------------------------
// ADC Individual Register Bit Definitions:

struct ADCTRL1_BITS {     // bits  description
    Uint16  rsvd1:4;      // 3:0   reserved
    Uint16  SEQ_CASC:1;   // 4     Cascaded sequencer mode
    Uint16  rsvd2:1;      // 5     reserved
    Uint16  CONT_RUN:1;   // 6     Continuous run
    Uint16  CPS:1;        // 7     ADC core clock prescaler
    Uint16  ACQ_PS:4;     // 11:8  Acquisition window size
    Uint16  SUSMOD:2;     // 13:12 Emulation suspend mode
    Uint16  RESET:1;      // 14    ADC reset
    Uint16  rsvd3:1;      // 15    reserved
};


union ADCTRL1_REG {
   Uint16             all;
   struct ADCTRL1_BITS  bit;
};


struct ADCTRL2_BITS {        // bits  description
    Uint16  EVB_SOC_SEQ2:1;   // 0    Event manager B SOC mask for SEQ2
    Uint16  rsvd1:1;          // 1    reserved
    Uint16  INT_MOD_SEQ2:1;   // 2    SEQ2 Interrupt mode
    Uint16  INT_ENA_SEQ2:1;   // 3    SEQ2 Interrupt enable
    Uint16  rsvd2:1;          // 4    reserved
    Uint16  SOC_SEQ2:1;       // 5    Start of conversion for SEQ2
    Uint16  RST_SEQ2:1;       // 6    Reset SEQ2
    Uint16  EXT_SOC_SEQ1:1;   // 7    External start of conversion for SEQ1
    Uint16  EVA_SOC_SEQ1:1;   // 8    Event manager A SOC mask for SEQ1
    Uint16  rsvd3:1;          // 9    reserved
    Uint16  INT_MOD_SEQ1:1;   // 10   SEQ1 Interrupt mode
    Uint16  INT_ENA_SEQ1:1;   // 11   SEQ1 Interrupt enable
    Uint16  rsvd4:1;          // 12   reserved
    Uint16  SOC_SEQ1:1;       // 13   Start of conversion trigger for SEQ1
    Uint16  RST_SEQ1:1;       // 14   Restart sequencer 1   
    Uint16  EVB_SOC_SEQ:1;    // 15   EVB SOC enable
};


union ADCTRL2_REG {
   Uint16             all;
   struct ADCTRL2_BITS  bit;
};


struct AUTO_SEQ_SR_BITS {     // bits  description
    Uint16  SEQ1_STATE:4;     // 3:0    SEQ1 state
    Uint16  SEQ2_STATE:3;     // 6:2    SEQ2 state
    Uint16  rsvd1:1;          // 7      resverved
    Uint16  SEQ_CNTR:4;       // 11:8   Sequencing counter status 
    Uint16  rsvd2:4;          // 15:12  reserved  
};

union AUTO_SEQ_SR_REG {
   Uint16             all;
   struct AUTO_SEQ_SR_BITS  bit;
};


struct MAX_CONV_BITS {
    Uint16  MAX_CONV:7;          // 6:0   Max number of conversions
    Uint16  rsvd1:9;             // 15:7  reserved 
};

union MAX_CONV_REG {
   Uint16             all;
   struct MAX_CONV_BITS  bit;
};


struct CHSELSEQ1_BITS {
    Uint16  CONV00:4;
    Uint16  CONV01:4;
    Uint16  CONV02:4;
    Uint16  CONV03:4;
};

union  CHSELSEQ1_REG{
   Uint16             all;
   struct CHSELSEQ1_BITS  bit;
};

struct CHSELSEQ2_BITS {
    Uint16  CONV04:4;
    Uint16  CONV05:4;
    Uint16  CONV06:4;
    Uint16  CONV07:4;
};

union  CHSELSEQ2_REG{
   Uint16             all;
   struct CHSELSEQ2_BITS  bit;
};

struct CHSELSEQ3_BITS {
    Uint16  CONV08:4;
    Uint16  CONV09:4;
    Uint16  CONV10:4;
    Uint16  CONV11:4;
};

union  CHSELSEQ3_REG{
   Uint16             all;
   struct CHSELSEQ3_BITS  bit;
};

struct CHSELSEQ4_BITS {
    Uint16  CONV12:4;
    Uint16  CONV13:4;
    Uint16  CONV14:4;
    Uint16  CONV15:4;
};

union  CHSELSEQ4_REG {
   Uint16             all;
   struct CHSELSEQ4_BITS  bit;
};

struct ADCTRL3_BITS {
    Uint16   SMODE_SEL:1;          // 0     Sampling mode select
    Uint16   ADCCLKPS:4;           // 4:1   ADC core clock divider
    Uint16   ADCPWDN:1;            // 5     ADC powerdown
    Uint16   ADCBGRFDN:2;          // 7:6   ADC bandgap/ref power down
    Uint16   rsvd1:8;              // 15:8 reserved
}; 

union  ADCTRL3_REG {
   Uint16             all;
   struct ADCTRL3_BITS  bit;
};


struct ADC_ST_FLG_BITS {
    Uint16   INT_SEQ1:1;            // 0  SEQ1 Interrupt flag  
    Uint16   INT_SEQ2:1;            // 1  SEQ2 Interrupt flag
    Uint16   SEQ1_BSY:1;            // 2  SEQ1 busy status
    Uint16   SEQ2_BSY:1;            // 3  SEQ2 busy status
    Uint16   INT_SEQ1_CLR:1;        // 4  SEQ1 Interrupt clear
    Uint16   INT_SEQ2_CLR:1;        // 5  SEQ2 Interrupt clear
    Uint16   EOS_BUF1:1;            // 6  End of sequence buffer1
    Uint16   EOS_BUF2:1;            // 7  End of sequence buffer2
    Uint16   rsvd1:8;               // 15:8
};


union  ADC_ST_FLG_REG {
   Uint16             all;
   struct ADC_ST_FLG_BITS  bit;
};


struct ADC_REGS {
    union ADCTRL1_REG ADCTRL1;      // ADC Control 1
    union ADCTRL2_REG ADCTRL2;      // ADC Control 2
    union MAX_CONV_REG MAX_CONV;    // Max conversions
    union CHSELSEQ1_REG CHSELSEQ1;  // Channel select sequencing control
    union CHSELSEQ2_REG CHSELSEQ2;
    union CHSELSEQ3_REG CHSELSEQ3;
    union CHSELSEQ4_REG CHSELSEQ4;
    union AUTO_SEQ_SR_REG AUTO_SEQ_SR; // Autosequence status register
    Uint16 RESULT0;
    Uint16 RESULT1;
    Uint16 RESULT2;
    Uint16 RESULT3;
    Uint16 RESULT4;
    Uint16 RESULT5;
    Uint16 RESULT6;
    Uint16 RESULT7;
    Uint16 RESULT8;
    Uint16 RESULT9;
    Uint16 RESULT10;
    Uint16 RESULT11;
    Uint16 RESULT12;
    Uint16 RESULT13;
    Uint16 RESULT14;
    Uint16 RESULT15;
    union ADCTRL3_REG ADCTRL3;
    union ADC_ST_FLG_REG ADC_ST_FLAG;
};


//---------------------------------------------------------------------------
// ADC External References & Function Declarations:
//
extern volatile struct ADC_REGS AdcRegs;

#endif  // end of DSP28_ADC_H definition

//===========================================================================
// No more.
//===========================================================================
