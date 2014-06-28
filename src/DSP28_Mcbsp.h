//
//      TMDX ALPHA RELEASE
//      Intended for product evaluation purposes
//
//###########################################################################
//
// FILE:	DSP28_Mcbsp.h
//
// TITLE:	DSP28 Device McBSP Register Definitions.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  0.55| 06 May 2002 | L.H. | EzDSP Alpha Release
//  0.56| 20 May 2002 | L.H. | No change
//  0.57| 27 May 2002 | L.H. | No change
//###########################################################################

#ifndef DSP28_MCBSP_H
#define DSP28_MCBSP_H

//---------------------------------------------------------------------------
// McBSP Individual Register Bit Definitions:
//
// McBSP DRR2 register bit definitions:
struct  DRR2_BITS {     // bit   description
   Uint16     HWLB:8;     // 16:23 High word low byte
   Uint16     HWHB:8;     // 24:31 High word high byte
};                                                                 

union DRR2_REG {
   Uint16              all;
   struct DRR2_BITS  bit;
};

// McBSP DRR1 register bit definitions:
struct  DRR1_BITS {     // bit   description
   Uint16     LWLB:8;     // 16:23 Low word low byte
   Uint16     LWHB:8;     // 24:31 low word high byte
};

union DRR1_REG {
   Uint16              all;
   struct DRR1_BITS  bit;
};

// McBSP DXR2 register bit definitions:
struct  DXR2_BITS {     // bit   description
   Uint16     HWLB:8;     // 16:23 High word low byte
   Uint16     HWHB:8;     // 24:31 High word high byte
};

union DXR2_REG {
   Uint16              all;
   struct DXR2_BITS  bit;
};

// McBSP DXR1 register bit definitions:
struct  DXR1_BITS {     // bit   description
   Uint16     LWLB:8;     // 16:23 Low word low byte
   Uint16     LWHB:8;     // 24:31 low word high byte
};               

union DXR1_REG {
   Uint16              all;
   struct DXR1_BITS  bit;
};

// SPCR2 control register bit definitions:
struct  SPCR2_BITS {     // bit   description
   Uint16     XRST:1;      // 0     transmit reset
   Uint16     XRDY:1;      // 1     transmit ready
   Uint16     XEMPTY:1;    // 2     Transmit empty    
   Uint16     XSYNCERR:1;  // 3     Transmit syn errorINT flag
   Uint16     XINTM:2;     // 5:4   Transmit interrupt types
   Uint16     GRST:1;      // 6     CLKG reset     
   Uint16     FRST:1;      // 7     Frame sync reset
   Uint16     SOFT:1;      // 8     SOFT bit
   Uint16     FREE:1;      // 9     FREE bit
   Uint16     rsvd:6;      // 15:10 reserved
}; 

union SPCR2_REG {
   Uint16               all;
   struct SPCR2_BITS  bit;
};
         
// SPCR1 control register bit definitions:
struct  SPCR1_BITS {     // bit   description
   Uint16     RRST:1;      // 0     Receive reset
   Uint16     RRDY:1;      // 1     Receive  ready
   Uint16     REMPTY:1;    // 2     Receive  empty    
   Uint16     RSYNCERR:1;  // 7     Receive  syn errorINT flag
   Uint16     RINTM:2;     // 5:4   Receive  interrupt types
   Uint16     ABIS:1;      // 6     ABIS mode select     
   Uint16     DXENA:1;     // 7     DX hi-z enable     
   Uint16     rsvd:3;      // 10:8  reserved  
   Uint16     CLKSTP:2;    // 12:11 CLKSTOP mode bit
   Uint16     RJUST:2;     // 13:14 Right justified
   Uint16     DLB:1;       // 15    Digital loop back    reserved
}; 

union SPCR1_REG {
   Uint16              all;
   struct SPCR1_BITS bit;
};                                                               

// RCR2 control register bit definitions:
struct  RCR2_BITS {       // bit    description
   Uint16     RDATDLY:2;    // 1:0    Receive data delay
   Uint16     RFIG:1;       // 2      Receive  frame sync ignore
   Uint16     RCOMPAND:2;   // 4:3    Receive  Companding Mode selects
   Uint16     RWDLEN2:3;    // 7:5    Receive  word length   
   Uint16     RFRLEN2:7;    // 14:8   Receive  Frame sync
   Uint16     RPHASE:1;     // 15     Receive Phase
}; 

union RCR2_REG {
   Uint16             all;
   struct RCR2_BITS bit;
};
     
// RCR1 control register bit definitions:
struct  RCR1_BITS {       // bit   description
   Uint16     rsvd1:5;      // 4:0   reserved  
   Uint16     RWDLEN1:3;    // 7:5   Receive  word length   
   Uint16     RFRLEN1:7;    // 14:8  Receive  Frame sync    
   Uint16     rsvd2:1;      // 15    reserved  
}; 

union RCR1_REG {
   Uint16             all;
   struct RCR1_BITS bit;
};    

// XCR2 control register bit definitions:

struct  XCR2_BITS {       // bit    description
   Uint16     XDATDLY:2;    // 1:0    Transmit data delay
   Uint16     XFIG:1;       // 2      Transmit frame sync ignore
   Uint16     XCOMPAND:2;   // 4:3    Transmit Companding Mode selects
   Uint16     XWDLEN2:3;    // 7:5    Transmit  word length   
   Uint16     XFRLEN2:7;    // 14:8   Transmit  Frame sync
   Uint16     XPHASE:1;     // 15     Transmit Phase
}; 

union XCR2_REG {
   Uint16             all;
   struct XCR2_BITS bit;
};
     
// XCR1 control register bit definitions:
struct  XCR1_BITS {       // bit   description
   Uint16     rsvd1:5;      // 4:0   reserved      
   Uint16     XWDLEN1:3;    // 7:5   Transmit word length    
   Uint16     XFRLEN1:7;    // 14:8  Transmit  Frame sync    
   Uint16     rsvd2:1;      // 15    reserved  
}; 

union XCR1_REG {
   Uint16             all;
   struct XCR1_BITS bit;
};         

// SRGR2 Sample rate generator control register bit definitions:
struct  SRGR2_BITS {      // bit  description
   Uint16     FPER:12;      // 11:0 Frame period
   Uint16     FSGM:1;       // 12   Frame sync generator mode 
   Uint16     CLKSM:1;      // 13   Sample rate generator mode
   Uint16     CLKSP:1;      // 14   Reserved in this McBSP  
   Uint16     GYSNC:1;      // 15   CLKG sync   
}; 

union  SRGR2_REG {
   Uint16                all;
   struct  SRGR2_BITS  bit;
};

// SRGR1 control register bit definitions:
struct  SRGR1_BITS {      // bit   description
   Uint16     CLKGDV:8;     // 7:0   CLKG divider 
   Uint16     FWID:8;       // 15:8  Frame width
}; 

union  SRGR1_REG {
   Uint16                all;
   struct  SRGR1_BITS  bit;
};

// MCR2 Multichannel control register bit definitions:
struct  MCR2_BITS {       // bit   description
   Uint16     XMCM:2;       // 1:0   Transmit multichannel mode      
   Uint16     XCBLK:3;      // 2:4   Transmit current block    
   Uint16     XPABLK:2;     // 5:6   Transmit partition A Block 
   Uint16     XPBBLK:2;     // 7:8   Transmit partition B Block 
   Uint16     XMCME:1;      // 9     Transmit multi-channel enhance mode 
   Uint16     rsvd:6;       // 15:10 reserved  
}; 

union  MCR2_REG {
   Uint16               all;
   struct  MCR2_BITS  bit;
};
      
// MCR1 Multichannel control register bit definitions:
struct  MCR1_BITS {       // bit   description
   Uint16     RMCM:1;       // 0     Receive multichannel mode  
   Uint16     rsvd:1;       // 1     reserved     
   Uint16     RCBLK:3;      // 4:2   Receive current block    
   Uint16     RPABLK:2;     // 6:5   Receive partition A Block 
   Uint16     RPBBLK:2;     // 7:8   Receive partition B Block 
   Uint16     RMCME:1;      // 9     Receive multi-channel enhance mode 
   Uint16     rsvd1:6;      // 15:10 reserved   
}; 

union  MCR1_REG {
   Uint16               all;
   struct  MCR1_BITS  bit;
};
 
// RCERA control register bit definitions:
struct  RCERA_BITS {       // bit description
   Uint16     RCEA0:1;       // 0   Receive Channel enable bit  
   Uint16     RCEA1:1;       // 1   Receive Channel enable bit  
   Uint16     RCEA2:1;       // 2   Receive Channel enable bit  
   Uint16     RCEA3:1;       // 3   Receive Channel enable bit   
   Uint16     RCEA4:1;       // 4   Receive Channel enable bit  
   Uint16     RCEA5:1;       // 5   Receive Channel enable bit  
   Uint16     RCEA6:1;       // 6   Receive Channel enable bit  
   Uint16     RCEA7:1;       // 7   Receive Channel enable bit 
   Uint16     RCEA8:1;       // 8   Receive Channel enable bit  
   Uint16     RCEA9:1;       // 9   Receive Channel enable bit  
   Uint16     RCEA10:1;      // 10  Receive Channel enable bit  
   Uint16     RCEA11:1;      // 11  Receive Channel enable bit 
   Uint16     RCEA12:1;      // 12  Receive Channel enable bit  
   Uint16     RCEA13:1;      // 13  Receive Channel enable bit  
   Uint16     RCEA14:1;      // 14  Receive Channel enable bit  
   Uint16     RCEA15:1;      // 15  Receive Channel enable bit 
}; 

union RCERA_REG {
   Uint16                all;
   struct  RCERA_BITS  bit;
};  

// RCERB control register bit definitions:
struct  RCERB_BITS {       // bit description
   Uint16     RCEB0:1;       // 0   Receive Channel enable bit  
   Uint16     RCEB1:1;       // 1   Receive Channel enable bit  
   Uint16     RCEB2:1;       // 2   Receive Channel enable bit  
   Uint16     RCEB3:1;       // 3   Receive Channel enable bit   
   Uint16     RCEB4:1;       // 4   Receive Channel enable bit  
   Uint16     RCEB5:1;       // 5   Receive Channel enable bit  
   Uint16     RCEB6:1;       // 6   Receive Channel enable bit  
   Uint16     RCEB7:1;       // 7   Receive Channel enable bit 
   Uint16     RCEB8:1;       // 8   Receive Channel enable bit  
   Uint16     RCEB9:1;       // 9   Receive Channel enable bit  
   Uint16     RCEB10:1;      // 10  Receive Channel enable bit  
   Uint16     RCEB11:1;      // 11  Receive Channel enable bit 
   Uint16     RCEB12:1;      // 12  Receive Channel enable bit  
   Uint16     RCEB13:1;      // 13  Receive Channel enable bit  
   Uint16     RCEB14:1;      // 14  Receive Channel enable bit  
   Uint16     RCEB15:1;      // 15  Receive Channel enable bit   
}; 

union RCERB_REG {
   Uint16                all;
   struct  RCERB_BITS  bit;
};

// XCERA control register bit definitions:
struct  XCERA_BITS {       // bit description
   Uint16     XCEA0:1;       // 0   Receive Channel enable bit  
   Uint16     XCEA1:1;       // 1   Receive Channel enable bit  
   Uint16     XCEA2:1;       // 2   Receive Channel enable bit  
   Uint16     XCEA3:1;       // 3   Receive Channel enable bit   
   Uint16     XCEA4:1;       // 4   Receive Channel enable bit  
   Uint16     XCEA5:1;       // 5   Receive Channel enable bit  
   Uint16     XCEA6:1;       // 6   Receive Channel enable bit  
   Uint16     XCEA7:1;       // 7   Receive Channel enable bit 
   Uint16     XCEA8:1;       // 8   Receive Channel enable bit  
   Uint16     XCEA9:1;       // 9   Receive Channel enable bit  
   Uint16     XCEA10:1;      // 10  Receive Channel enable bit  
   Uint16     XCEA11:1;      // 11  Receive Channel enable bit 
   Uint16     XCEA12:1;      // 12  Receive Channel enable bit  
   Uint16     XCEA13:1;      // 13  Receive Channel enable bit  
   Uint16     XCEA14:1;      // 14  Receive Channel enable bit  
   Uint16     XCEA15:1;      // 15  Receive Channel enable bit 
}; 

union XCERA_REG {
   Uint16                all;
   struct  XCERA_BITS  bit;
};  

// XCERB control register bit definitions:
struct  XCERB_BITS {       // bit description
   Uint16     XCEB0:1;       // 0   Receive Channel enable bit  
   Uint16     XCEB1:1;       // 1   Receive Channel enable bit  
   Uint16     XCEB2:1;       // 2   Receive Channel enable bit  
   Uint16     XCEB3:1;       // 3   Receive Channel enable bit   
   Uint16     XCEB4:1;       // 4   Receive Channel enable bit  
   Uint16     XCEB5:1;       // 5   Receive Channel enable bit  
   Uint16     XCEB6:1;       // 6   Receive Channel enable bit  
   Uint16     XCEB7:1;       // 7   Receive Channel enable bit 
   Uint16     XCEB8:1;       // 8   Receive Channel enable bit  
   Uint16     XCEB9:1;       // 9   Receive Channel enable bit  
   Uint16     XCEB10:1;      // 10  Receive Channel enable bit  
   Uint16     XCEB11:1;      // 11  Receive Channel enable bit 
   Uint16     XCEB12:1;      // 12  Receive Channel enable bit  
   Uint16     XCEB13:1;      // 13  Receive Channel enable bit  
   Uint16     XCEB14:1;      // 14  Receive Channel enable bit  
   Uint16     XCEB15:1;      // 15  Receive Channel enable bit 
}; 

union XCERB_REG {
   Uint16                all;
   struct  XCERB_BITS  bit;
};
  
// PCR1 control register bit definitions:
struct  PCR1_BITS {        // bit description
   Uint16     CLKRP:1;       // 0   Receive Clock polarity
   Uint16     CLKXP:1;       // 1   Transmit clock polarity  
   Uint16     FSRP:1;        // 2   Receive Frame synchronization polarity  
   Uint16     FSXP:1;        // 3   Transmit Frame synchronization polarity   
   Uint16     DR_STAT:1;     // 4   DR pin status - reserved for this McBSP  
   Uint16     DX_STAT:1;     // 5   DX pin status - reserved for this McBSP  
   Uint16     CLKS_STAT:1;   // 6   CLKS pin status - reserved for 28x -McBSP  
   Uint16     SCLKME:1;      // 7   Enhanced sample clock mode selection bit.
   Uint16     CLKRM:1;       // 8   Receiver Clock Mode 
   Uint16     CLKXM:1;       // 9   Transmitter Clock Mode.  
   Uint16     FSRM:1;        // 10  Receive Frame Synchronization Mode  
   Uint16     FSXM:1;        // 11  Transmit Frame Synchronization Mode
   Uint16     RIOEN:1;       // 12  General Purpose I/O Mode - reserved in this 28x-McBSP    
   Uint16     XIOEN:1;       // 13  General Purpose I/O Mode - reserved in this 28x-McBSP
   Uint16     IDEL_EN:1;     // 14  reserved in this 28x-McBSP
   Uint16     rsvd:1  ;      // 15  reserved
}; 

union PCR1_REG {
   Uint16               all;
   struct  PCR1_BITS  bit;
};
  
// RCERC control register bit definitions:
struct  RCERC_BITS {       // bit description
   Uint16     RCEC0:1;       // 0   Receive Channel enable bit  
   Uint16     RCEC1:1;       // 1   Receive Channel enable bit  
   Uint16     RCEC2:1;       // 2   Receive Channel enable bit  
   Uint16     RCEC3:1;       // 3   Receive Channel enable bit   
   Uint16     RCEC4:1;       // 4   Receive Channel enable bit  
   Uint16     RCEC5:1;       // 5   Receive Channel enable bit  
   Uint16     RCEC6:1;       // 6   Receive Channel enable bit  
   Uint16     RCEC7:1;       // 7   Receive Channel enable bit 
   Uint16     RCEC8:1;       // 8   Receive Channel enable bit  
   Uint16     RCEC9:1;       // 9   Receive Channel enable bit  
   Uint16     RCEC10:1;      // 10  Receive Channel enable bit  
   Uint16     RCEC11:1;      // 11  Receive Channel enable bit 
   Uint16     RCEC12:1;      // 12  Receive Channel enable bit  
   Uint16     RCEC13:1;      // 13  Receive Channel enable bit  
   Uint16     RCEC14:1;      // 14  Receive Channel enable bit  
   Uint16     RCEC15:1;      // 15  Receive Channel enable bit 
}; 

union RCERC_REG {
   Uint16                all;
   struct  RCERC_BITS  bit;
};  

// RCERD control register bit definitions:
struct  RCERD_BITS {       // bit description
   Uint16     RCED0:1;       // 0   Receive Channel enable bit  
   Uint16     RCED1:1;       // 1   Receive Channel enable bit  
   Uint16     RCED2:1;       // 2   Receive Channel enable bit  
   Uint16     RCED3:1;       // 3   Receive Channel enable bit   
   Uint16     RCED4:1;       // 4   Receive Channel enable bit  
   Uint16     RCED5:1;       // 5   Receive Channel enable bit  
   Uint16     RCED6:1;       // 6   Receive Channel enable bit  
   Uint16     RCED7:1;       // 7   Receive Channel enable bit 
   Uint16     RCED8:1;       // 8   Receive Channel enable bit  
   Uint16     RCED9:1;       // 9   Receive Channel enable bit  
   Uint16     RCED10:1;      // 10  Receive Channel enable bit  
   Uint16     RCED11:1;      // 11  Receive Channel enable bit 
   Uint16     RCED12:1;      // 12  Receive Channel enable bit  
   Uint16     RCED13:1;      // 13  Receive Channel enable bit  
   Uint16     RCED14:1;      // 14  Receive Channel enable bit  
   Uint16     RCED15:1;      // 15  Receive Channel enable bit 
}; 

union RCERD_REG {
   Uint16                all;
   struct  RCERD_BITS  bit;
};

// XCERC control register bit definitions:
struct  XCERC_BITS {       // bit description
   Uint16     XCEC0:1;       // 0   Receive Channel enable bit  
   Uint16     XCEC1:1;       // 1   Receive Channel enable bit  
   Uint16     XCEC2:1;       // 2   Receive Channel enable bit  
   Uint16     XCEC3:1;       // 3   Receive Channel enable bit   
   Uint16     XCEC4:1;       // 4   Receive Channel enable bit  
   Uint16     XCEC5:1;       // 5   Receive Channel enable bit  
   Uint16     XCEC6:1;       // 6   Receive Channel enable bit  
   Uint16     XCEC7:1;       // 7   Receive Channel enable bit 
   Uint16     XCEC8:1;       // 8   Receive Channel enable bit  
   Uint16     XCEC9:1;       // 9   Receive Channel enable bit  
   Uint16     XCEC10:1;      // 10  Receive Channel enable bit  
   Uint16     XCEC11:1;      // 11  Receive Channel enable bit 
   Uint16     XCEC12:1;      // 12  Receive Channel enable bit  
   Uint16     XCEC13:1;      // 13  Receive Channel enable bit  
   Uint16     XCEC14:1;      // 14  Receive Channel enable bit  
   Uint16     XCEC15:1;      // 15  Receive Channel enable bit 
}; 

union XCERC_REG {
   Uint16                all;
   struct  XCERC_BITS  bit;
};  

// XCERD control register bit definitions:
struct  XCERD_BITS {       // bit description
   Uint16     XCED0:1;       // 0   Receive Channel enable bit  
   Uint16     XCED1:1;       // 1   Receive Channel enable bit  
   Uint16     XCED2:1;       // 2   Receive Channel enable bit  
   Uint16     XCED3:1;       // 3   Receive Channel enable bit   
   Uint16     XCED4:1;       // 4   Receive Channel enable bit  
   Uint16     XCED5:1;       // 5   Receive Channel enable bit  
   Uint16     XCED6:1;       // 6   Receive Channel enable bit  
   Uint16     XCED7:1;       // 7   Receive Channel enable bit 
   Uint16     XCED8:1;       // 8   Receive Channel enable bit  
   Uint16     XCED9:1;       // 9   Receive Channel enable bit  
   Uint16     XCED10:1;      // 10  Receive Channel enable bit  
   Uint16     XCED11:1;      // 11  Receive Channel enable bit 
   Uint16     XCED12:1;      // 12  Receive Channel enable bit  
   Uint16     XCED13:1;      // 13  Receive Channel enable bit  
   Uint16     XCED14:1;      // 14  Receive Channel enable bit  
   Uint16     XCED15:1;      // 15  Receive Channel enable bit 
}; 

union XCERD_REG {
   Uint16                all;
   struct  XCERD_BITS  bit;
};
  
// RCERE control register bit definitions:
struct  RCERE_BITS {       // bit description
   Uint16     RCEE0:1;       // 0   Receive Channel enable bit  
   Uint16     RCEE1:1;       // 1   Receive Channel enable bit  
   Uint16     RCEE2:1;       // 2   Receive Channel enable bit  
   Uint16     RCEE3:1;       // 3   Receive Channel enable bit   
   Uint16     RCEE4:1;       // 4   Receive Channel enable bit  
   Uint16     RCEE5:1;       // 5   Receive Channel enable bit  
   Uint16     RCEE6:1;       // 6   Receive Channel enable bit  
   Uint16     RCEE7:1;       // 7   Receive Channel enable bit 
   Uint16     RCEE8:1;       // 8   Receive Channel enable bit  
   Uint16     RCEE9:1;       // 9   Receive Channel enable bit  
   Uint16     RCEE10:1;      // 10  Receive Channel enable bit  
   Uint16     RCEE11:1;      // 11  Receive Channel enable bit 
   Uint16     RCEE12:1;      // 12  Receive Channel enable bit  
   Uint16     RCEE13:1;      // 13  Receive Channel enable bit  
   Uint16     RCEE14:1;      // 14  Receive Channel enable bit  
   Uint16     RCEE15:1;      // 15  Receive Channel enable bit 
}; 

union RCERE_REG {
   Uint16                all;
   struct  RCERE_BITS  bit;
};  

// RCERF control register bit definitions:
struct  RCERF_BITS {       // bit   description
   Uint16     RCEF0:1;       // 0   Receive Channel enable bit  
   Uint16     RCEF1:1;       // 1   Receive Channel enable bit  
   Uint16     RCEF2:1;       // 2   Receive Channel enable bit  
   Uint16     RCEF3:1;       // 3   Receive Channel enable bit   
   Uint16     RCEF4:1;       // 4   Receive Channel enable bit  
   Uint16     RCEF5:1;       // 5   Receive Channel enable bit  
   Uint16     RCEF6:1;       // 6   Receive Channel enable bit  
   Uint16     RCEF7:1;       // 7   Receive Channel enable bit 
   Uint16     RCEF8:1;       // 8   Receive Channel enable bit  
   Uint16     RCEF9:1;       // 9   Receive Channel enable bit  
   Uint16     RCEF10:1;      // 10  Receive Channel enable bit  
   Uint16     RCEF11:1;      // 11  Receive Channel enable bit 
   Uint16     RCEF12:1;      // 12  Receive Channel enable bit  
   Uint16     RCEF13:1;      // 13  Receive Channel enable bit  
   Uint16     RCEF14:1;      // 14  Receive Channel enable bit  
   Uint16     RCEF15:1;      // 15  Receive Channel enable bit 
}; 

union RCERF_REG {
   Uint16                all;
   struct  RCERF_BITS  bit;
};

// XCERE control register bit definitions:
struct  XCERE_BITS {       // bit description
   Uint16     XCEE0:1;       // 0   Receive Channel enable bit  
   Uint16     XCEE1:1;       // 1   Receive Channel enable bit  
   Uint16     XCEE2:1;       // 2   Receive Channel enable bit  
   Uint16     XCEE3:1;       // 3   Receive Channel enable bit   
   Uint16     XCEE4:1;       // 4   Receive Channel enable bit  
   Uint16     XCEE5:1;       // 5   Receive Channel enable bit  
   Uint16     XCEE6:1;       // 6   Receive Channel enable bit  
   Uint16     XCEE7:1;       // 7   Receive Channel enable bit 
   Uint16     XCEE8:1;       // 8   Receive Channel enable bit  
   Uint16     XCEE9:1;       // 9   Receive Channel enable bit  
   Uint16     XCEE10:1;      // 10  Receive Channel enable bit  
   Uint16     XCEE11:1;      // 11  Receive Channel enable bit 
   Uint16     XCEE12:1;      // 12  Receive Channel enable bit  
   Uint16     XCEE13:1;      // 13  Receive Channel enable bit  
   Uint16     XCEE14:1;      // 14  Receive Channel enable bit  
   Uint16     XCEE15:1;      // 15  Receive Channel enable bit 
}; 

union XCERE_REG {
   Uint16                all;
   struct  XCERE_BITS  bit;
};  

// XCERF control register bit definitions:
struct  XCERF_BITS {       // bit description
   Uint16     XCEF0:1;       // 0   Receive Channel enable bit  
   Uint16     XCEF1:1;       // 1   Receive Channel enable bit  
   Uint16     XCEF2:1;       // 2   Receive Channel enable bit  
   Uint16     XCEF3:1;       // 3   Receive Channel enable bit   
   Uint16     XCEF4:1;       // 4   Receive Channel enable bit  
   Uint16     XCEF5:1;       // 5   Receive Channel enable bit  
   Uint16     XCEF6:1;       // 6   Receive Channel enable bit  
   Uint16     XCEF7:1;       // 7   Receive Channel enable bit 
   Uint16     XCEF8:1;       // 8   Receive Channel enable bit  
   Uint16     XCEF9:1;       // 9   Receive Channel enable bit  
   Uint16     XCEF10:1;      // 10  Receive Channel enable bit  
   Uint16     XCEF11:1;      // 11  Receive Channel enable bit 
   Uint16     XCEF12:1;      // 12  Receive Channel enable bit  
   Uint16     XCEF13:1;      // 13  Receive Channel enable bit  
   Uint16     XCEF14:1;      // 14  Receive Channel enable bit  
   Uint16     XCEF15:1;      // 15  Receive Channel enable bit 
}; 

union XCERF_REG {
   Uint16                all;
   struct  XCERF_BITS  bit;
};                   

// RCERG control register bit definitions:
struct  RCERG_BITS {       // bit description
   Uint16     RCEG0:1;       // 0   Receive Channel enable bit  
   Uint16     RCEG1:1;       // 1   Receive Channel enable bit  
   Uint16     RCEG2:1;       // 2   Receive Channel enable bit  
   Uint16     RCEG3:1;       // 3   Receive Channel enable bit   
   Uint16     RCEG4:1;       // 4   Receive Channel enable bit  
   Uint16     RCEG5:1;       // 5   Receive Channel enable bit  
   Uint16     RCEG6:1;       // 6   Receive Channel enable bit  
   Uint16     RCEG7:1;       // 7   Receive Channel enable bit 
   Uint16     RCEG8:1;       // 8   Receive Channel enable bit  
   Uint16     RCEG9:1;       // 9   Receive Channel enable bit  
   Uint16     RCEG10:1;      // 10  Receive Channel enable bit  
   Uint16     RCEG11:1;      // 11  Receive Channel enable bit 
   Uint16     RCEG12:1;      // 12  Receive Channel enable bit  
   Uint16     RCEG13:1;      // 13  Receive Channel enable bit  
   Uint16     RCEG14:1;      // 14  Receive Channel enable bit  
   Uint16     RCEG15:1;      // 15  Receive Channel enable bit 
}; 

union RCERG_REG {
   Uint16                all;
   struct  RCERG_BITS  bit;
};  

// RCERH control register bit definitions:
struct  RCERH_BITS {       // bit description
   Uint16     RCEH0:1;       // 0   Receive Channel enable bit  
   Uint16     RCEH1:1;       // 1   Receive Channel enable bit  
   Uint16     RCEH2:1;       // 2   Receive Channel enable bit  
   Uint16     RCEH3:1;       // 3   Receive Channel enable bit   
   Uint16     RCEH4:1;       // 4   Receive Channel enable bit  
   Uint16     RCEH5:1;       // 5   Receive Channel enable bit  
   Uint16     RCEH6:1;       // 6   Receive Channel enable bit  
   Uint16     RCEH7:1;       // 7   Receive Channel enable bit 
   Uint16     RCEH8:1;       // 8   Receive Channel enable bit  
   Uint16     RCEH9:1;       // 9   Receive Channel enable bit  
   Uint16     RCEH10:1;      // 10  Receive Channel enable bit  
   Uint16     RCEH11:1;      // 11  Receive Channel enable bit 
   Uint16     RCEH12:1;      // 12  Receive Channel enable bit  
   Uint16     RCEH13:1;      // 13  Receive Channel enable bit  
   Uint16     RCEH14:1;      // 14  Receive Channel enable bit  
   Uint16     RCEH15:1;      // 15  Receive Channel enable bit 
}; 

union RCERH_REG {
   Uint16                all;
   struct  RCERH_BITS  bit;
};

// XCERG control register bit definitions:
struct  XCERG_BITS {       // bit description
   Uint16     XCEG0:1;       // 0   Receive Channel enable bit  
   Uint16     XCEG1:1;       // 1   Receive Channel enable bit  
   Uint16     XCEG2:1;       // 2   Receive Channel enable bit  
   Uint16     XCEG3:1;       // 3   Receive Channel enable bit   
   Uint16     XCEG4:1;       // 4   Receive Channel enable bit  
   Uint16     XCEG5:1;       // 5   Receive Channel enable bit  
   Uint16     XCEG6:1;       // 6   Receive Channel enable bit  
   Uint16     XCEG7:1;       // 7   Receive Channel enable bit 
   Uint16     XCEG8:1;       // 8   Receive Channel enable bit  
   Uint16     XCEG9:1;       // 9   Receive Channel enable bit  
   Uint16     XCEG10:1;      // 10  Receive Channel enable bit  
   Uint16     XCEG11:1;      // 11  Receive Channel enable bit 
   Uint16     XCEG12:1;      // 12  Receive Channel enable bit  
   Uint16     XCEG13:1;      // 13  Receive Channel enable bit  
   Uint16     XCEG14:1;      // 14  Receive Channel enable bit  
   Uint16     XCEG15:1;      // 15  Receive Channel enable bit 
}; 

union XCERG_REG {
   Uint16                all;
   struct  XCERG_BITS  bit;
};  

// XCERH control register bit definitions:
struct  XCERH_BITS {       // bit description
   Uint16     XCEH0:1;       // 0   Receive Channel enable bit  
   Uint16     XCEH1:1;       // 1   Receive Channel enable bit  
   Uint16     XCEH2:1;       // 2   Receive Channel enable bit  
   Uint16     XCEH3:1;       // 3   Receive Channel enable bit   
   Uint16     XCEH4:1;       // 4   Receive Channel enable bit  
   Uint16     XCEH5:1;       // 5   Receive Channel enable bit  
   Uint16     XCEH6:1;       // 6   Receive Channel enable bit  
   Uint16     XCEH7:1;       // 7   Receive Channel enable bit 
   Uint16     XCEH8:1;       // 8   Receive Channel enable bit  
   Uint16     XCEH9:1;       // 9   Receive Channel enable bit  
   Uint16     XCEH10:1;      // 10  Receive Channel enable bit  
   Uint16     XCEH11:1;      // 11  Receive Channel enable bit 
   Uint16     XCEH12:1;      // 12  Receive Channel enable bit  
   Uint16     XCEH13:1;      // 13  Receive Channel enable bit  
   Uint16     XCEH14:1;      // 14  Receive Channel enable bit  
   Uint16     XCEH15:1;      // 15  Receive Channel enable bit 
}; 

union XCERH_REG {
   Uint16                all;
   struct  XCERH_BITS  bit;
};

// McBSP FIFO Transmit register bit definitions:
struct  MFFTX_BITS {      // bit   description
   Uint16     IL:5;         // 4:0   Interrupt level
   Uint16     TXFFIENA:1;   // 5     Interrupt enable
   Uint16     INT_CLR:1;    // 6     Clear INT flag
   Uint16     INT:1;        // 7     INT flag
   Uint16     ST:5;         // 12:8  FIFO status
   Uint16     XRESET:1;     // 13    FIFO reset
   Uint16     MFFENA:1;     // 14    Enhancement enable
   Uint16     rsvd:1;       // 15    reserved
}; 

union MFFTX_REG {
   Uint16              all;
   struct MFFTX_BITS bit;
};

// McBSP FIFO recieve register bit definitions:
struct  MFFRX_BITS {      // bits  description
   Uint16 IL:5;             // 4:0   Interrupt level
   Uint16 RXFFIENA:1;       // 5     Interrupt enable
   Uint16 INT_CLR:1;        // 6     Clear INT flag
   Uint16 INT:1;            // 7     INT flag
   Uint16 ST:5;             // 12:8  FIFO status
   Uint16 RRESET:1;         // 13    FIFO reset
   Uint16 OVF_CLR:1;        // 14    Clear overflow
   Uint16 OVF:1;            // 15    FIFO overflow
}; 

union MFFRX_REG {
   Uint16              all;
   struct MFFRX_BITS bit;
};

// McBSP FIFO control register bit definitions:
struct  MFFCT_BITS {      // bits  description
    Uint16 TXDLY:8;         // 7:0   FIFO transmit delay
    Uint16 rsvd:7;          // 15:7  reserved
    Uint16 IACKM:1;         // 15    is IACK mode enable bit
};

union MFFCT_REG {
   Uint16               all;
   struct MFFCT_BITS  bit;
};
   
// McBSP FIFO INTERRUPT control register bit definitions:
struct  MFFINT_BITS {     // bits description
    Uint16     XINT:1;      // 0    XINT  interrupt enable
    Uint16     XEVTA:1;     // 1    XEVTA interrupt enable
    Uint16     RINT:1;      // 2    RINT  interrupt enable
    Uint16     REVTA:1;     // 3    REVTA interrupt enable
    Uint16     rsvd:12;     // 15:4 reserved
};

union MFFINT_REG {
   Uint16                all;
   struct MFFINT_BITS  bit;
};

// McBSP FIFO INTERRUPT status  register bit definitions:
struct  MFFST_BITS {     // bits description
    Uint16     EOBX:1;     // 0    EOBX flag
    Uint16     FSX:1;      // 1    FSX flag
    Uint16     EOBR:1;     // 2    EOBR flag
    Uint16     FSR:1;      // 3    FSR flag
    Uint16     rsvd:12;    // 15:4 reserved
};

union MFFST_REG {
   Uint16              all;
   struct MFFST_BITS bit;
};


//---------------------------------------------------------------------------
// McBSP Register File:
//
struct  MCBSP_REGS {      
   union DRR2_REG    DRR2;     // 0,  MCBSP Data receive register bits 31-16 
   union DRR1_REG    DRR1;     // 1,  MCBSP Data receive register bits 15-0 
   union DXR2_REG    DXR2;     // 2,  MCBSP Data transmit register bits 31-16 
   union DXR1_REG    DXR1;     // 3,  MCBSP Data transmit register bits 15-0 
   union SPCR2_REG   SPCR2;    // 4,  MCBSP control register bits 31-16 
   union SPCR1_REG   SPCR1;    // 5,  MCBSP control register bits 15-0 
   union RCR2_REG    RCR2;     // 6,  MCBSP receive control register bits 31-16 
   union RCR1_REG    RCR1;     // 7,  MCBSP receive control register bits 15-0 
   union XCR2_REG    XCR2;     // 8,  MCBSP transmit control register bits 31-16 
   union XCR1_REG    XCR1;     // 9,  MCBSP transmit control register bits 15-0 
   union SRGR2_REG   SRGR2;    // 10, MCBSP sample rate gen register bits 31-16 
   union SRGR1_REG   SRGR1;    // 11, MCBSP sample rate gen register bits 15-0  
   union MCR2_REG    MCR2;     // 12, MCBSP multichannel register bits 31-16 
   union MCR1_REG    MCR1;     // 13, MCBSP multichannel register bits 15-0    
   union RCERA_REG   RCERA;    // 14, MCBSP Receive channel enable partition A 
   union RCERB_REG   RCERB;    // 15, MCBSP Receive channel enable partition B 
   union XCERA_REG   XCERA;    // 16, MCBSP Transmit channel enable partition A 
   union XCERB_REG   XCERB;    // 17, MCBSP Transmit channel enable partition B            
   union PCR1_REG    PCR1;     // 18, MCBSP Pin control register bits 15-0  
   union RCERC_REG   RCERC;    // 19, MCBSP Receive channel enable partition C 
   union RCERD_REG   RCERD;    // 20, MCBSP Receive channel enable partition D
   union XCERC_REG   XCERC;    // 21, MCBSP Transmit channel enable partition C 
   union XCERD_REG   XCERD;    // 23, MCBSP Transmit channel enable partition D             
   union RCERE_REG   RCERE;    // 24, MCBSP Receive channel enable partition E 
   union RCERF_REG   RCERF;    // 25, MCBSP Receive channel enable partition F
   union XCERE_REG   XCERE;    // 26, MCBSP Transmit channel enable partition E
   union XCERF_REG   XCERF;    // 27, MCBSP Transmit channel enable partition F            
   union RCERG_REG   RCERG;    // 28, MCBSP Receive channel enable partition G
   union RCERH_REG   RCERH;    // 29, MCBSP Receive channel enable partition H
   union XCERG_REG   XCERG;    // 30, MCBSP Transmit channel enable partition G 
   union XCERH_REG   XCERH;    // 31, MCBSP Transmit channel enable partition H             
   Uint16  rsvd1;                // 32, reserved             
   union MFFTX_REG   MFFTX;    // 33, MCBSP Transmit FIFO register bits  
   union MFFRX_REG   MFFRX;    // 34, MCBSP Receive FIFO register bits
   union MFFCT_REG   MFFCT;    // 35, MCBSP FIFO control register bits    
   union MFFINT_REG  MFFINT;   // 36, MCBSP Interrupt register bits  
   union MFFST_REG   MFFST;    // 37, MCBSP Status register bits 
};

//---------------------------------------------------------------------------
// McBSP External References & Function Declarations:
//
extern volatile struct MCBSP_REGS McbspRegs;

#endif  // end of DSP28_MCBSP_H definition

//===========================================================================
// No more.
//===========================================================================
