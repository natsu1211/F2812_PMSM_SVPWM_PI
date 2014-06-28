//###########################################################################
//
// FILE:	DSP281x_Ev.h
//
// TITLE:	DSP281x Device Event Manager Register Definitions.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  1.00| 11 Sep 2003 | L.H. | Changes since previous version (v.58 Alpha)
//      |             |      | CAPCON, EXTCON and CAPFIFO register for EVA renamed CAPCONA
//      |             |      |    EXTCONA and CAPFIFOA.  This is to be consistant
//      |             |      |    with other documentation. EVB was already correct.
//      |             |      | Corrected bit definitions for GPTCONA & GPTCONB registers
//      |             |      | T1CON and T2CON were using the same bit definitions.  Split
//      |             |      |    this so the reserved bits in T1CON would be correct
//      |             |      | T3CON and T4CON were using the same bit definitions.  Split
//      |             |      |    this so the reserved bits in T3CON would be correct
//      |             |      | Changed QEPIQEL to QEPIQUAL in EXTCONA/EXTCONB registers
//      |             |      | Added bits that are active only when EXTCONA.0 = 1 
//      |             |      |    to the COMCONA and COMCONB registers. 
//      |             |      | Changed CAPQEPN to CAP12EN in the CAPCONA register
//      |             |      | Changed CAPQEPN to CAP45EN in the CAPCONB register
//###########################################################################

#ifndef DSP281x_EV_H
#define DSP281x_EV_H


#ifdef __cplusplus
extern "C" {
#endif

/* --------------------------------------------------- */
/* F2810/12 Event Manager (EV) GP Timer Registers      */
/*                                                     */
/* ----------------------------------------------------*/

/* Overall Timer Control Register */

struct GPTCONA_BITS  {
   Uint16 T1PIN:2;         // 1:0   Polarity of GP timer 1 compare
   Uint16 T2PIN:2;         // 3:2   Polarity of GP timer 2 compare
   Uint16 T1CMPOE:1;       // 4     Timer1 compare output
   Uint16 T2CMPOE:1;       // 5     Timer2 compare output 
   Uint16 TCMPOE:1;        // 6     Compare output enable
   Uint16 T1TOADC:2;       // 8:7   Start ADC with timer 1 event
   Uint16 T2TOADC:2;       // 10:9  Start ADC with timer 2 event
   Uint16 T1CTRIPE:1;      // 11    Enable Timer 1 compare trip
   Uint16 T2CTRIPE:1;      // 12    Enable Timer 2 compare trip
   Uint16 T1STAT:1;        // 13    GP Timer 1 status (read only)
   Uint16 T2STAT:1;        // 14    GP Timer 2 status (read only)
   Uint16 rsvd:1;          // 15    reserved
};

/* Allow access to the bit fields or entire register */
union GPTCONA_REG {
   Uint16        all;
   struct  GPTCONA_BITS bit;
};

struct GPTCONB_BITS  {
   Uint16 T3PIN:2;         // 1:0   Polarity of GP timer 3 compare
   Uint16 T4PIN:2;         // 3:2   Polarity of GP timer 4 compare
   Uint16 T3CMPOE:1;       // 4     Timer3 compare output
   Uint16 T4CMPOE:1;       // 5     Timer4 compare output 
   Uint16 TCMPOE:1;        // 6     Compare output enable
   Uint16 T3TOADC:2;       // 8:7   Start ADC with timer 3 event
   Uint16 T4TOADC:2;       // 10:9  Start ADC with timer 4 event
   Uint16 T3CTRIPE:1;      // 11    Timer 3 trip enable
   Uint16 T4CTRIPE:1;      // 12    Timer 4 trip enable
   Uint16 T3STAT:1;        // 13    GP Timer 3 status (read only)
   Uint16 T4STAT:1;        // 14    GP Timer 4 status (read only)
   Uint16 rsvd2:1;         // 15    reserved
};

/* Allow access to the bit fields or entire register */
union GPTCONB_REG {
   Uint16        all;
   struct  GPTCONB_BITS bit;
};

/* Timer 1 Control Register bit defintions */
struct T1CON_BITS  {
   Uint16  rsvd1:1;         // 0     reserved
   Uint16  TECMPR:1;        // 1     Timer compare enable
   Uint16  TCLD10:2;        // 3:2   Timer copare register reload
   Uint16  TCLKS10:2;       // 5:4   Clock source select
   Uint16  TENABLE:1;       // 6     Timer enable
   Uint16  rsvd2:1;         // 7     reserved
   Uint16  TPS:3;           // 10:8  Input clock prescaler
   Uint16  TMODE:2;         // 12:11 Count mode selection
   Uint16  rsvd:1;          // 13    reserved
   Uint16  FREE:1;          // 14    Free emulation control
   Uint16  SOFT:1;          // 15    Soft emulation control
};      

/* Allow access to the bit fields or entire register */
union T1CON_REG {
   Uint16             all;
   struct  T1CON_BITS bit;
};


/* Timer 2 Control Register bit defintions */
struct T2CON_BITS  {
   Uint16  SET1PR:1;        // 0     Period register select
   Uint16  TECMPR:1;        // 1     Timer compare enable
   Uint16  TCLD10:2;        // 3:2   Timer copare register reload
   Uint16  TCLKS10:2;       // 5:4   Clock source select
   Uint16  TENABLE:1;       // 6     Timer enable
   Uint16  T2SWT1:1;        // 7     Start GP timer 2 with GP timer 1's enable
   Uint16  TPS:3;           // 10:8  Input clock prescaler
   Uint16  TMODE:2;         // 12:11 Count mode selection
   Uint16  rsvd:1;          // 13    reserved
   Uint16  FREE:1;          // 14    Free emulation control
   Uint16  SOFT:1;          // 15    Soft emulation control
};      

/* Allow access to the bit fields or entire register */
union T2CON_REG {
   Uint16             all;
   struct  T2CON_BITS bit;
};

/* Timer 3 Control Register bit defintions */
struct T3CON_BITS  {
   Uint16  rsvd1:1;         // 0     reserved
   Uint16  TECMPR:1;        // 1     Timer compare enable
   Uint16  TCLD10:2;        // 3:2   Timer copare register reload
   Uint16  TCLKS10:2;       // 5:4   Clock source select
   Uint16  TENABLE:1;       // 6     Timer enable
   Uint16  rsvd2:1;         // 7     reserved
   Uint16  TPS:3;           // 10:8  Input clock prescaler
   Uint16  TMODE:2;         // 12:11 Count mode selection
   Uint16  rsvd:1;          // 13    reserved
   Uint16  FREE:1;          // 14    Free emulation control
   Uint16  SOFT:1;          // 15    Soft emulation control
};      

/* Allow access to the bit fields or entire register */
union T3CON_REG {
   Uint16             all;
   struct  T3CON_BITS bit;
};

/* Timer 4 Control Register bit defintions */
struct T4CON_BITS  {
   Uint16  SET3PR:1;        // 0     Period register select
   Uint16  TECMPR:1;        // 1     Timer compare enable
   Uint16  TCLD10:2;        // 3:2   Timer copare register reload
   Uint16  TCLKS10:2;       // 5:4   Clock source select
   Uint16  TENABLE:1;       // 6     Timer enable
   Uint16  T4SWT3:1;        // 7     Start GP timer 2 with GP timer 1's enable
   Uint16  TPS:3;           // 10:8  Input clock prescaler
   Uint16  TMODE:2;         // 12:11 Count mode selection
   Uint16  rsvd:1;          // 13    reserved
   Uint16  FREE:1;          // 14    Free emulation control
   Uint16  SOFT:1;          // 15    Soft emulation control
};      

/* Allow access to the bit fields or entire register */
union T4CON_REG {
   Uint16             all;
   struct  T4CON_BITS bit;
};


struct EXTCONA_BITS {
   Uint16   INDCOE:1;        // 0      Independant compare output
   Uint16   QEPIQUAL:1;      // 1      QEP/CAP3 Index Qual Mode
   Uint16   QEPIE:1;         // 2      QEP index enable
   Uint16   EVSOCE:1;        // 3      EvA start of conversion output enable
   Uint16   rsvd:12;         // 15:4   reserved
};

/* Allow access to the bit fields or entire register */
union EXTCONA_REG {
   Uint16        all;
   struct  EXTCONA_BITS bit;
};


struct EXTCONB_BITS {
   Uint16   INDCOE:1;        // 0      Independant compare output
   Uint16   QEPIQUAL:1;      // 1      QEP/CAP3 Index Qual Mode
   Uint16   QEPIE:1;         // 2      QEP index enable
   Uint16   EVSOCE:1;        // 3      EvB start of conversion output enable
   Uint16   rsvd:12;         // 15:4   reserved
};

/* Allow access to the bit fields or entire register */
union EXTCONB_REG {
   Uint16               all;
   struct  EXTCONA_BITS bit;
};



/* Compare Control Register */
struct COMCONA_BITS {
   Uint16   C1TRIPE:1;      // 0      C1TRIP enable
   Uint16   C2TRIPE:1;      // 1      C2TRIP enable
   Uint16   C3TRIPE:1;      // 2      C3TRIP eanble
   Uint16   rsvd:2;         // 4:3    reserved
   Uint16   FCMP1OE:1;      // 5      Full compare 1 output enable
   Uint16   FCMP2OE:1;      // 6      Full compare 2 output enable
   Uint16   FCMP3OE:1;      // 7      Full compare 3 output enable
   Uint16   PDPINTASTATUS:1;// 8      Current status of the PDPINTA pin
   Uint16   FCOMPOE:1;      // 9      Compare output enable
   Uint16   ACTRLD:2;       // 11:10  Action control register reload
   Uint16   SVENABLE:1;     // 12     Space vector PWM Mode enable
   Uint16   CLD:2;          // 14:13  Compare register reload condition
   Uint16   CENABLE:1;      // 15     Compare enable
}; 

/* Allow access to the bit fields or entire register */
union COMCONA_REG {
   Uint16               all;
   struct  COMCONA_BITS bit;
};

struct COMCONB_BITS {
   Uint16   C4TRIPE:1;      // 0      C4TRIP enable
   Uint16   C5TRIPE:1;      // 1      C5TRIP enable
   Uint16   C6TRIPE:1;      // 2      C6TRIP eanble
   Uint16   rsvd:2;         // 4:3    reserved
   Uint16   FCMP4OE:1;      // 5      Full compare 4 output enable
   Uint16   FCMP5OE:1;      // 6      Full compare 5 output enable
   Uint16   FCMP6OE:1;      // 7      Full compare 6 output enable
   Uint16   PDPINTBSTATUS:1;// 8      Current status of the PDPINTB pin
   Uint16   FCOMPOE:1;      // 9      Compare output enable
   Uint16   ACTRLD:2;       // 11:10  Action control register reload
   Uint16   SVENABLE:1;     // 12     Space vector PWM Mode enable
   Uint16   CLD:2;          // 14:13  Compare register reload condition
   Uint16   CENABLE:1;      // 15     Compare enable
}; 

/* Allow access to the bit fields or entire register */
union COMCONB_REG {
   Uint16               all;
   struct  COMCONB_BITS bit;
};

/* Compare Action Control Register bit definitions */

struct ACTRA_BITS {
   Uint16   CMP1ACT:2;     // 1:0    Action on compare output pin 1 CMP1
   Uint16   CMP2ACT:2;     // 3:2    Action on compare output pin 2 CMP2
   Uint16   CMP3ACT:2;     // 5:4    Action on compare output pin 3 CMP3
   Uint16   CMP4ACT:2;     // 7:6    Action on compare output pin 4 CMP4
   Uint16   CMP5ACT:2;     // 9:8    Action on compare output pin 5 CMP5
   Uint16   CMP6ACT:2;     // 11:10  Action on compare output pin 6 CMP6
   Uint16   D:3;           // 14:12  Basic vector bits
   Uint16   SVRDIR:1;      // 15     Space vecor PWM rotation dir
};

/* Allow access to the bit fields or entire register */
union ACTRA_REG {
   Uint16             all;
   struct  ACTRA_BITS bit;
};

struct ACTRB_BITS {
   Uint16   CMP7ACT:2;     // 1:0    Action on compare output pin 7 CMP7
   Uint16   CMP8ACT:2;     // 3:2    Action on compare output pin 8 CMP8
   Uint16   CMP9ACT:2;     // 5:4    Action on compare output pin 9 CMP9
   Uint16   CMP10ACT:2;    // 7:6    Action on compare output pin 10 CMP10
   Uint16   CMP11ACT:2;    // 9:8    Action on compare output pin 11 CMP11
   Uint16   CMP12ACT:2;    // 11:10  Action on compare output pin 12 CMP12
   Uint16   D:3;           // 14:12  Basic vector bits
   Uint16   SVRDIR:1;      // 15     Space vecor PWM rotation dir
};

/* Allow access to the bit fields or entire register */
union ACTRB_REG {
   Uint16        all;
   struct  ACTRB_BITS bit;
};

/* Dead-Band Timer Control register bit definitions */
struct DBTCON_BITS {
   Uint16   rsvd1:2;       // 1:0    reserved
   Uint16   DBTPS:3;       // 4:2    Dead-Band timer prescaler
   Uint16   EDBT1:1;       // 5      Dead-Band timer 1 enable
   Uint16   EDBT2:1;       // 6      Dead-Band timer 2 enable
   Uint16   EDBT3:1;       // 7      Dead-Band timer 3 enable
   Uint16   DBT:4;         // 11:8   Dead-Band timer period
   Uint16   rsvd2:4;       // 15:12  reserved   
};

/* Allow access to the bit fields or entire register */
union DBTCON_REG {
   Uint16        all;
   struct  DBTCON_BITS bit;
};


/* Capture Control register bit definitions */
struct CAPCONA_BITS {
   Uint16  rsvd1:2;         // 1:0   reserved
   Uint16  CAP3EDGE:2;      // 3:2   Edge Detection for Unit 3
   Uint16  CAP2EDGE:2;      // 5:4   Edge Detection for Unit 2
   Uint16  CAP1EDGE:2;      // 7:6   Edge Detection for Unit 1
   Uint16  CAP3TOADC:1;     // 8     Unit 3 starts the ADC
   Uint16  CAP12TSEL:1;     // 9     GP Timer selection for Units 1 and 2
   Uint16  CAP3TSEL:1;      // 10    GP Timer selection for Unit 3
   Uint16  rsvd2:1;         // 11    reserved
   Uint16  CAP3EN:1;        // 12    Capture Unit 3 enable
   Uint16  CAP12EN:2;       // 14:13 Capture Unit 1 and 2 enable
   Uint16  CAPRES:1;        // 15    Capture reset (always reads 0)
};

/* Allow access to the bit fields or entire register */
union CAPCONA_REG {
   Uint16        all;
   struct  CAPCONA_BITS bit;
};  


/* Control register bit definitions */
struct CAPCONB_BITS {
   Uint16  rsvd1:2;         // 1:0   reserved
   Uint16  CAP6EDGE:2;      // 3:2   Edge Detection for Unit 6
   Uint16  CAP5EDGE:2;      // 5:4   Edge Detection for Unit 5
   Uint16  CAP4EDGE:2;      // 7:6   Edge Detection for Unit 4
   Uint16  CAP6TOADC:1;     // 8     Unit 6 starts the ADC
   Uint16  CAP45TSEL:1;     // 9     GP Timer selection for Units 4 and 5
   Uint16  CAP6TSEL:1;      // 10    GP Timer selection for Unit 6
   Uint16  rsvd2:1;         // 11    reserved
   Uint16  CAP6EN:1;        // 12    Capture Unit 6 control
   Uint16  CAP45EN:2;       // 14:13 Capture Unit 4 and 5 control
   Uint16  CAPRES:1;        // 15    Capture reset (always reads 0)
};

/* Allow access to the bit fields or entire register */
union CAPCONB_REG {
   Uint16        all;
   struct  CAPCONB_BITS bit;
}; 

/* Capture FIFO Status Register bit definitions */
struct CAPFIFOA_BITS  {
   Uint16 rsvd1:8;           // 7:0   reserved
   Uint16 CAP1FIFO:2;        // 9:8   CAP1 FIFO status
   Uint16 CAP2FIFO:2;        // 11:10 CAP2 FIFO status
   Uint16 CAP3FIFO:2;        // 13:12 CAP2 FIFO status
   Uint16 rsvd2:2;           // 15:14 reserved
}; 

/* Allow access to the bit fields or entire register */
union CAPFIFOA_REG {
   Uint16        all;
   struct  CAPFIFOA_BITS bit;
}; 

/* Capture FIFO Status Register bit definitions */
struct CAPFIFOB_BITS  {
   Uint16 rsvd1:8;           // 7:0   reserved
   Uint16 CAP4FIFO:2;        // 9:8   CAP4 FIFO status
   Uint16 CAP5FIFO:2;        // 11:10 CAP5 FIFO status
   Uint16 CAP6FIFO:2;        // 13:12 CAP6 FIFO status
   Uint16 rsvd2:2;           // 15:14 reserved
}; 

/* Allow access to the bit fields or entire register */
union CAPFIFOB_REG {
   Uint16        all;
   struct  CAPFIFOB_BITS bit;
};

/* Interrupt Mask Register bit definitions */
struct EVAIMRA_BITS {
    Uint16  PDPINTA:1;      // 0       Enable PDPINTA
    Uint16  CMP1INT:1;      // 1       Enable
    Uint16  CMP2INT:1;      // 2       Enable
    Uint16  CMP3INT:1;      // 3       Enable
    Uint16  rsvd1:3;        // 6:4     reserved
    Uint16  T1PINT:1;       // 7       Enable
    Uint16  T1CINT:1;       // 8       Enable
    Uint16  T1UFINT:1;      // 9       Enable
    Uint16  T1OFINT:1;      // 10      Enable
    Uint16  rsvd2:5;        // 15:11   reserved
};
   
/* Allow access to the bit fields or entire register */
union EVAIMRA_REG {
   Uint16         all;
   struct  EVAIMRA_BITS bit;
};

/* Interrupt Mask Register bit definitions */
struct EVBIMRA_BITS {
    Uint16  PDPINTB:1;      // 0       Enable PDPINTB
    Uint16  CMP4INT:1;      // 1       Enable
    Uint16  CMP5INT:1;      // 2       Enable
    Uint16  CMP6INT:1;      // 3       Enable
    Uint16  rsvd1:3;        // 6:4     reserved
    Uint16  T3PINT:1;       // 7       Enable
    Uint16  T3CINT:1;       // 8       Enable
    Uint16  T3UFINT:1;      // 9       Enable
    Uint16  T3OFINT:1;      // 10      Enable
    Uint16  rsvd2:5;        // 15:11   reserved
};
   
/* Allow access to the bit fields or entire register */
union EVBIMRA_REG {
   Uint16         all;
   struct  EVBIMRA_BITS bit;
};

struct EVAIMRB_BITS {
   Uint16   T2PINT:1;       // 0       Enable
   Uint16   T2CINT:1;       // 1       Enable
   Uint16   T2UFINT:1;      // 2       Enable
   Uint16   T2OFINT:1;      // 3       Enable
   Uint16   rsvd1:12;       // 15:4    reserved
};

/* Allow access to the bit fields or entire register */
union EVAIMRB_REG {
   Uint16         all;
   struct  EVAIMRB_BITS bit;
};

struct EVBIMRB_BITS {
   Uint16   T4PINT:1;       // 0       Enable
   Uint16   T4CINT:1;       // 1       Enable
   Uint16   T4UFINT:1;      // 2       Enable
   Uint16   T4OFINT:1;      // 3       Enable
   Uint16   rsvd1:12;       // 15:4    reserved
};

/* Allow access to the bit fields or entire register */
union EVBIMRB_REG {
   Uint16         all;
   struct  EVBIMRB_BITS bit;
};

struct EVAIMRC_BITS {
    Uint16   CAP1INT:1;     // 0        Enable
    Uint16   CAP2INT:1;     // 1        Enable
    Uint16   CAP3INT:1;     // 2        Enable
    Uint16   rsvd1:13;      // 15:3     reserved
};

/* Allow access to the bit fields or entire register */
union EVAIMRC_REG {
   Uint16         all;
   struct  EVAIMRC_BITS bit;
};

struct EVBIMRC_BITS {
    Uint16   CAP4INT:1;     // 0        Enable
    Uint16   CAP5INT:1;     // 1        Enable
    Uint16   CAP6INT:1;     // 2        Enable
    Uint16   rsvd1:13;      // 15:3     reserved
};

/* Allow access to the bit fields or entire register */
union EVBIMRC_REG {
   Uint16         all;
   struct  EVBIMRC_BITS bit;
};

/* Interrupt Flag Register bit definitions */
struct EVAIFRA_BITS {
    Uint16  PDPINTA:1;      // 0       Flag PDPINTA
    Uint16  CMP1INT:1;      // 1       Flag
    Uint16  CMP2INT:1;      // 2       Flag
    Uint16  CMP3INT:1;      // 3       Flag
    Uint16  rsvd1:3;        // 6:4     reserved
    Uint16  T1PINT:1;       // 7       Flag
    Uint16  T1CINT:1;       // 8       Flag
    Uint16  T1UFINT:1;      // 9       Flag
    Uint16  T1OFINT:1;      // 10      Flag
    Uint16  rsvd2:5;        // 15:11   reserved
};
   
/* Allow access to the bit fields or entire register */
union EVAIFRA_REG {
   Uint16         all;
   struct  EVAIMRA_BITS bit;
};

/* Interrupt Mask Register bit definitions */
struct EVBIFRA_BITS {
    Uint16  PDPINTB:1;      // 0       Flag PDPINTB
    Uint16  CMP4INT:1;      // 1       Flag
    Uint16  CMP5INT:1;      // 2       Flag
    Uint16  CMP6INT:1;      // 3       Flag
    Uint16  rsvd1:3;        // 6:4     reserved
    Uint16  T3PINT:1;       // 7       Flag
    Uint16  T3CINT:1;       // 8       Flag
    Uint16  T3UFINT:1;      // 9       Flag
    Uint16  T3OFINT:1;      // 10      Flag
    Uint16  rsvd2:5;        // 15:11   reserved
};
   
/* Allow access to the bit fields or entire register */
union EVBIFRA_REG {
   Uint16         all;
   struct  EVBIFRA_BITS bit;
};

struct EVAIFRB_BITS {
   Uint16   T2PINT:1;       // 0       Flag
   Uint16   T2CINT:1;       // 1       Flag
   Uint16   T2UFINT:1;      // 2       Flag
   Uint16   T2OFINT:1;      // 3       Flag
   Uint16   rsvd1:12;       // 15:4    reserved
};

/* Allow access to the bit fields or entire register */
union EVAIFRB_REG {
   Uint16         all;
   struct  EVAIFRB_BITS bit;
};

struct EVBIFRB_BITS {
   Uint16   T4PINT:1;       // 0       Flag
   Uint16   T4CINT:1;       // 1       Flag
   Uint16   T4UFINT:1;      // 2       Flag
   Uint16   T4OFINT:1;      // 3       Flag
   Uint16   rsvd1:12;       // 15:4    reserved
};

/* Allow access to the bit fields or entire register */
union EVBIFRB_REG {
   Uint16         all;
   struct  EVBIFRB_BITS bit;
};

struct EVAIFRC_BITS {
    Uint16   CAP1INT:1;     // 0        Flag
    Uint16   CAP2INT:1;     // 1        Flag
    Uint16   CAP3INT:1;     // 2        Flag
    Uint16   rsvd1:13;      // 15:3     reserved
};

/* Allow access to the bit fields or entire register */
union EVAIFRC_REG {
   Uint16         all;
   struct  EVAIFRC_BITS bit;
};

struct EVBIFRC_BITS {
    Uint16   CAP4INT:1;     // 0        Flag
    Uint16   CAP5INT:1;     // 1        Flag
    Uint16   CAP6INT:1;     // 2        Flag
    Uint16   rsvd1:13;      // 15:3     reserved
};

/* Allow access to the bit fields or entire register */
union EVBIFRC_REG {
   Uint16         all;
   struct  EVBIFRC_BITS bit;
};

/* EVA Register File */

struct EVA_REGS  {
  union GPTCONA_REG  GPTCONA;   //0x7400
  Uint16             T1CNT;     //0x7401
  Uint16             T1CMPR;    //0x7402
  Uint16             T1PR;      //0x7403
  union T1CON_REG    T1CON;     //0x7404
  Uint16             T2CNT;     //0x7405
  Uint16             T2CMPR;    //0x7406
  Uint16             T2PR;      //0x7407
  union T2CON_REG    T2CON;     //0x7408
  union EXTCONA_REG  EXTCONA;   //0x7409
  Uint16             rsvd1[7];  //0x740A-10
  union COMCONA_REG  COMCONA;	//0x7411
  Uint16             rsvd2;     //0x7412
  union ACTRA_REG    ACTRA;     //0x7413
  Uint16             rsvd3;     //0x7414
  union DBTCON_REG   DBTCONA;   //0x7415
  Uint16             rsvd4;     //0x7416
  Uint16             CMPR1;     //0x7417
  Uint16             CMPR2;     //0x7418
  Uint16             CMPR3;     //0x7419
  Uint16             rsvd5[6];  //0x741A-F
  union CAPCONA_REG  CAPCONA;	//0x7420
  Uint16             rsvd6;     //0x7421
  union CAPFIFOA_REG CAPFIFOA;  //0x7422
  Uint16             CAP1FIFO;  //0x7423
  Uint16             CAP2FIFO;  //0x7424
  Uint16             CAP3FIFO;  //0x7425
  Uint16             rsvd7;     //0x7426
  Uint16             CAP1FBOT;  //0x7427
  Uint16             CAP2FBOT;  //0x7428
  Uint16             CAP3FBOT;  //0x7429
  Uint16             rsvd8[2];  //0x742A-B
  union EVAIMRA_REG  EVAIMRA;	//0x742C
  union EVAIMRB_REG  EVAIMRB;	//0x742D
  union EVAIMRC_REG  EVAIMRC;	//0x742E
  union EVAIFRA_REG  EVAIFRA;	//0x742F
  union EVAIFRB_REG  EVAIFRB;	//0x7430
  union EVAIFRC_REG  EVAIFRC;	//0x7431
};


/* EVB Register File */

struct EVB_REGS  {
  union GPTCONB_REG  GPTCONB;	//0x7500
  Uint16             T3CNT;     //0x7501
  Uint16             T3CMPR;    //0x7502
  Uint16             T3PR;      //0x7503
  union T3CON_REG    T3CON;     //0x7504
  Uint16             T4CNT;     //0x7505
  Uint16             T4CMPR;    //0x7506
  Uint16             T4PR;      //0x7507
  union T4CON_REG    T4CON;     //0x7508
  union EXTCONB_REG  EXTCONB;   //0x7509
  Uint16             rsvd1[7];  //0x750A-10
  union COMCONB_REG  COMCONB;   //0x7511
  Uint16             rsvd2;     //0x7512
  union ACTRB_REG    ACTRB;     //0x7513
  Uint16             rsvd3;     //0x7514
  union DBTCON_REG   DBTCONB;   //0x7515
  Uint16             rsvd4;     //0x7516
  Uint16             CMPR4;     //0x7517
  Uint16             CMPR5;     //0x7518
  Uint16             CMPR6;     //0x7519
  Uint16             rsvd5[6];  //0x751A-F
  union CAPCONB_REG  CAPCONB;   //0x7520
  Uint16             rsvd6;     //0x7521
  union CAPFIFOB_REG CAPFIFOB;  //0x7522
  Uint16             CAP4FIFO;  //0x7523
  Uint16             CAP5FIFO;  //0x7524
  Uint16             CAP6FIFO;  //0x7525
  Uint16             rsvd7;     //0x7526
  Uint16             CAP4FBOT;  //0x7527
  Uint16             CAP5FBOT;  //0x7528
  Uint16             CAP6FBOT;  //0x7529
  Uint16             rsvd8[2];  //0x752A-B
  union EVBIMRA_REG  EVBIMRA;   //0x752C
  union EVBIMRB_REG  EVBIMRB;   //0x752D
  union EVBIMRC_REG  EVBIMRC;   //0x752E
  union EVBIFRA_REG  EVBIFRA;   //0x752F
  union EVBIFRB_REG  EVBIFRB;   //0x7530
  union EVBIFRC_REG  EVBIFRC;   //0x7531
};                              



//---------------------------------------------------------------------------
// Function prototypes and external definitions:
//

extern volatile struct EVA_REGS EvaRegs;
extern volatile struct EVB_REGS EvbRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP281x_EV.H definition


//===========================================================================
// No more.
//===========================================================================
