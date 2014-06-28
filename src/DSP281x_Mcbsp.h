//###########################################################################
//
// FILE:   DSP281x_Mcbsp.h
//
// TITLE:  DSP281x Device McBSP Register Definitions.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  1.00| 11 Sep 2003 | L.H. | Changes since previous version (v.58 Alpha)
//      |             |      | Changed the name of PCR1 register to PCR
//      |             |      | Fixed name of GSYNC bit (was GYSNC)
//      |             |      | Changed bit 14 of SRGR2 to reserved
//      |             |      | RFULL bit in SPCR1 was mislabled (was REMPTY)
//      |             |      | XCERA register bits changed from XCEAn to XCERAn   
//      |             |      | XCERB register bits changed from XCEBn to XCERBn
//      |             |      | XCERC register bits changed from XCECn to XCERCn
//      |             |      | XCERD register bits changed from XCEDn to XCERDn
//      |             |      | XCERE register bits changed from XCEEn to XCEREn
//      |             |      | XCERF register bits changed from XCEFn to XCERFn
//      |             |      | XCERG register bits changed from XCEGn to XCERGn
//      |             |      | MFFTX register bits change to align with user's guide
//      |             |      | MFFRX register bits change to align with user's guide
//###########################################################################

#ifndef DSP281x_MCBSP_H
#define DSP281x_MCBSP_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// McBSP Individual Register Bit Definitions:
//
// McBSP DRR2 register bit definitions:
struct  DRR2_BITS {       // bit   description
   Uint16     HWLB:8;     // 16:23 High word low byte
   Uint16     HWHB:8;     // 24:31 High word high byte
};                                                                 

union DRR2_REG {
   Uint16            all;
   struct DRR2_BITS  bit;
};

// McBSP DRR1 register bit definitions:
struct  DRR1_BITS {       // bit   description
   Uint16     LWLB:8;     // 16:23 Low word low byte
   Uint16     LWHB:8;     // 24:31 low word high byte
};

union DRR1_REG {
   Uint16            all;
   struct DRR1_BITS  bit;
};

// McBSP DXR2 register bit definitions:
struct  DXR2_BITS {       // bit   description
   Uint16     HWLB:8;     // 16:23 High word low byte
   Uint16     HWHB:8;     // 24:31 High word high byte
};

union DXR2_REG {
   Uint16            all;
   struct DXR2_BITS  bit;
};

// McBSP DXR1 register bit definitions:
struct  DXR1_BITS {       // bit   description
   Uint16     LWLB:8;     // 16:23 Low word low byte
   Uint16     LWHB:8;     // 24:31 low word high byte
};               

union DXR1_REG {
   Uint16              all;
   struct DXR1_BITS  bit;
};

// SPCR2 control register bit definitions:
struct  SPCR2_BITS {       // bit   description
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
struct  SPCR1_BITS {       // bit   description
   Uint16     RRST:1;      // 0     Receive reset
   Uint16     RRDY:1;      // 1     Receive  ready
   Uint16     RFULL:1;     // 2     Receive  full    
   Uint16     RSYNCERR:1;  // 7     Receive  syn error
   Uint16     RINTM:2;     // 5:4   Receive  interrupt types
   Uint16     ABIS:1;      // 6     ABIS mode select     
   Uint16     DXENA:1;     // 7     DX hi-z enable     
   Uint16     rsvd:3;      // 10:8  reserved  
   Uint16     CLKSTP:2;    // 12:11 CLKSTOP mode bit
   Uint16     RJUST:2;     // 13:14 Right justified
   Uint16     DLB:1;       // 15    Digital loop back
}; 

union SPCR1_REG {
   Uint16              all;
   struct SPCR1_BITS bit;
};                                                               

// RCR2 control register bit definitions:
struct  RCR2_BITS {         // bit    description
   Uint16     RDATDLY:2;    // 1:0    Receive data delay
   Uint16     RFIG:1;       // 2      Receive  frame sync ignore
   Uint16     RCOMPAND:2;   // 4:3    Receive  Companding Mode selects
   Uint16     RWDLEN2:3;    // 7:5    Receive  word length   
   Uint16     RFRLEN2:7;    // 14:8   Receive  Frame sync
   Uint16     RPHASE:1;     // 15     Receive Phase
}; 

union RCR2_REG {
   Uint16           all;
   struct RCR2_BITS bit;
};
     
// RCR1 control register bit definitions:
struct  RCR1_BITS {         // bit   description
   Uint16     rsvd1:5;      // 4:0   reserved  
   Uint16     RWDLEN1:3;    // 7:5   Receive word length   
   Uint16     RFRLEN1:7;    // 14:8  Receive frame length    
   Uint16     rsvd2:1;      // 15    reserved  
}; 

union RCR1_REG {
   Uint16           all;
   struct RCR1_BITS bit;
};    

// XCR2 control register bit definitions:

struct  XCR2_BITS {         // bit    description
   Uint16     XDATDLY:2;    // 1:0    Transmit data delay
   Uint16     XFIG:1;       // 2      Transmit frame sync ignore
   Uint16     XCOMPAND:2;   // 4:3    Transmit Companding Mode selects
   Uint16     XWDLEN2:3;    // 7:5    Transmit  word length   
   Uint16     XFRLEN2:7;    // 14:8   Transmit  Frame sync
   Uint16     XPHASE:1;     // 15     Transmit Phase
}; 

union XCR2_REG {
   Uint16           all;
   struct XCR2_BITS bit;
};
     
// XCR1 control register bit definitions:
struct  XCR1_BITS {         // bit   description
   Uint16     rsvd1:5;      // 4:0   reserved      
   Uint16     XWDLEN1:3;    // 7:5   Transmit word length    
   Uint16     XFRLEN1:7;    // 14:8  Transmit frame length    
   Uint16     rsvd2:1;      // 15    reserved  
}; 

union XCR1_REG {
   Uint16             all;
   struct XCR1_BITS bit;
};         

// SRGR2 Sample rate generator control register bit definitions:
struct  SRGR2_BITS {        // bit  description
   Uint16     FPER:12;      // 11:0 Frame period
   Uint16     FSGM:1;       // 12   Frame sync generator mode 
   Uint16     CLKSM:1;      // 13   Sample rate generator mode
   Uint16     rsvd:1;       // 14   reserved 
   Uint16     GSYNC:1;      // 15   CLKG sync   
}; 

union  SRGR2_REG {
   Uint16              all;
   struct  SRGR2_BITS  bit;
};

// SRGR1 control register bit definitions:
struct  SRGR1_BITS {        // bit   description
   Uint16     CLKGDV:8;     // 7:0   CLKG divider 
   Uint16     FWID:8;       // 15:8  Frame width
}; 

union  SRGR1_REG {
   Uint16              all;
   struct  SRGR1_BITS  bit;
};

// MCR2 Multichannel control register bit definitions:
struct  MCR2_BITS {         // bit   description
   Uint16     XMCM:2;       // 1:0   Transmit multichannel mode      
   Uint16     XCBLK:3;      // 2:4   Transmit current block    
   Uint16     XPABLK:2;     // 5:6   Transmit partition A Block 
   Uint16     XPBBLK:2;     // 7:8   Transmit partition B Block 
   Uint16     XMCME:1;      // 9     Transmit multi-channel enhance mode 
   Uint16     rsvd:6;       // 15:10 reserved  
}; 

union  MCR2_REG {
   Uint16             all;
   struct  MCR2_BITS  bit;
};
      
// MCR1 Multichannel control register bit definitions:
struct  MCR1_BITS {         // bit   description
   Uint16     RMCM:1;       // 0     Receive multichannel mode  
   Uint16     rsvd:1;       // 1     reserved     
   Uint16     RCBLK:3;      // 4:2   Receive current block    
   Uint16     RPABLK:2;     // 6:5   Receive partition A Block 
   Uint16     RPBBLK:2;     // 7:8   Receive partition B Block 
   Uint16     RMCME:1;      // 9     Receive multi-channel enhance mode 
   Uint16     rsvd1:6;      // 15:10 reserved   
}; 

union  MCR1_REG {
   Uint16             all;
   struct  MCR1_BITS  bit;
};
 
// RCERA control register bit definitions:
struct  RCERA_BITS {         // bit description
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
   Uint16              all;
   struct  RCERA_BITS  bit;
};  

// RCERB control register bit definitions:
struct  RCERB_BITS {         // bit description
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
   Uint16              all;
   struct  RCERB_BITS  bit;
};

// XCERA control register bit definitions:
struct  XCERA_BITS {         // bit description
   Uint16     XCERA0:1;       // 0   Receive Channel enable bit  
   Uint16     XCERA1:1;       // 1   Receive Channel enable bit  
   Uint16     XCERA2:1;       // 2   Receive Channel enable bit  
   Uint16     XCERA3:1;       // 3   Receive Channel enable bit   
   Uint16     XCERA4:1;       // 4   Receive Channel enable bit  
   Uint16     XCERA5:1;       // 5   Receive Channel enable bit  
   Uint16     XCERA6:1;       // 6   Receive Channel enable bit  
   Uint16     XCERA7:1;       // 7   Receive Channel enable bit 
   Uint16     XCERA8:1;       // 8   Receive Channel enable bit  
   Uint16     XCERA9:1;       // 9   Receive Channel enable bit  
   Uint16     XCERA10:1;      // 10  Receive Channel enable bit  
   Uint16     XCERA11:1;      // 11  Receive Channel enable bit 
   Uint16     XCERA12:1;      // 12  Receive Channel enable bit  
   Uint16     XCERA13:1;      // 13  Receive Channel enable bit  
   Uint16     XCERA14:1;      // 14  Receive Channel enable bit  
   Uint16     XCERA15:1;      // 15  Receive Channel enable bit 
}; 

union XCERA_REG {
   Uint16              all;
   struct  XCERA_BITS  bit;
};  

// XCERB control register bit definitions:
struct  XCERB_BITS {         // bit description
   Uint16     XCERB0:1;       // 0   Receive Channel enable bit  
   Uint16     XCERB1:1;       // 1   Receive Channel enable bit  
   Uint16     XCERB2:1;       // 2   Receive Channel enable bit  
   Uint16     XCERB3:1;       // 3   Receive Channel enable bit   
   Uint16     XCERB4:1;       // 4   Receive Channel enable bit  
   Uint16     XCERB5:1;       // 5   Receive Channel enable bit  
   Uint16     XCERB6:1;       // 6   Receive Channel enable bit  
   Uint16     XCERB7:1;       // 7   Receive Channel enable bit 
   Uint16     XCERB8:1;       // 8   Receive Channel enable bit  
   Uint16     XCERB9:1;       // 9   Receive Channel enable bit  
   Uint16     XCERB10:1;      // 10  Receive Channel enable bit  
   Uint16     XCERB11:1;      // 11  Receive Channel enable bit 
   Uint16     XCERB12:1;      // 12  Receive Channel enable bit  
   Uint16     XCERB13:1;      // 13  Receive Channel enable bit  
   Uint16     XCERB14:1;      // 14  Receive Channel enable bit  
   Uint16     XCERB15:1;      // 15  Receive Channel enable bit 
}; 

union XCERB_REG {
   Uint16              all;
   struct  XCERB_BITS  bit;
};
  
// PCR control register bit definitions:
struct  PCR_BITS {          // bit description
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

union PCR_REG {
   Uint16            all;
   struct  PCR_BITS  bit;
};
  
// RCERC control register bit definitions:
struct  RCERC_BITS {         // bit description
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
   Uint16              all;
   struct  RCERC_BITS  bit;
};  

// RCERD control register bit definitions:
struct  RCERD_BITS {         // bit description
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
   Uint16              all;
   struct  RCERD_BITS  bit;
};

// XCERC control register bit definitions:
struct  XCERC_BITS {         // bit description
   Uint16     XCERC0:1;       // 0   Receive Channel enable bit  
   Uint16     XCERC1:1;       // 1   Receive Channel enable bit  
   Uint16     XCERC2:1;       // 2   Receive Channel enable bit  
   Uint16     XCERC3:1;       // 3   Receive Channel enable bit   
   Uint16     XCERC4:1;       // 4   Receive Channel enable bit  
   Uint16     XCERC5:1;       // 5   Receive Channel enable bit  
   Uint16     XCERC6:1;       // 6   Receive Channel enable bit  
   Uint16     XCERC7:1;       // 7   Receive Channel enable bit 
   Uint16     XCERC8:1;       // 8   Receive Channel enable bit  
   Uint16     XCERC9:1;       // 9   Receive Channel enable bit  
   Uint16     XCERC10:1;      // 10  Receive Channel enable bit  
   Uint16     XCERC11:1;      // 11  Receive Channel enable bit 
   Uint16     XCERC12:1;      // 12  Receive Channel enable bit  
   Uint16     XCERC13:1;      // 13  Receive Channel enable bit  
   Uint16     XCERC14:1;      // 14  Receive Channel enable bit  
   Uint16     XCERC15:1;      // 15  Receive Channel enable bit 
}; 

union XCERC_REG {
   Uint16              all;
   struct  XCERC_BITS  bit;
};  

// XCERD control register bit definitions:
struct  XCERD_BITS {         // bit description
   Uint16     XCERD0:1;       // 0   Receive Channel enable bit  
   Uint16     XCERD1:1;       // 1   Receive Channel enable bit  
   Uint16     XCERD2:1;       // 2   Receive Channel enable bit  
   Uint16     XCERD3:1;       // 3   Receive Channel enable bit   
   Uint16     XCERD4:1;       // 4   Receive Channel enable bit  
   Uint16     XCERD5:1;       // 5   Receive Channel enable bit  
   Uint16     XCERD6:1;       // 6   Receive Channel enable bit  
   Uint16     XCERD7:1;       // 7   Receive Channel enable bit 
   Uint16     XCERD8:1;       // 8   Receive Channel enable bit  
   Uint16     XCERD9:1;       // 9   Receive Channel enable bit  
   Uint16     XCERD10:1;      // 10  Receive Channel enable bit  
   Uint16     XCERD11:1;      // 11  Receive Channel enable bit 
   Uint16     XCERD12:1;      // 12  Receive Channel enable bit  
   Uint16     XCERD13:1;      // 13  Receive Channel enable bit  
   Uint16     XCERD14:1;      // 14  Receive Channel enable bit  
   Uint16     XCERD15:1;      // 15  Receive Channel enable bit 
}; 

union XCERD_REG {
   Uint16              all;
   struct  XCERD_BITS  bit;
};
  
// RCERE control register bit definitions:
struct  RCERE_BITS {         // bit description
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
   Uint16              all;
   struct  RCERE_BITS  bit;
};  

// RCERF control register bit definitions:
struct  RCERF_BITS {         // bit   description
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
   Uint16              all;
   struct  RCERF_BITS  bit;
};

// XCERE control register bit definitions:
struct  XCERE_BITS {         // bit description
   Uint16     XCERE0:1;       // 0   Receive Channel enable bit  
   Uint16     XCERE1:1;       // 1   Receive Channel enable bit  
   Uint16     XCERE2:1;       // 2   Receive Channel enable bit  
   Uint16     XCERE3:1;       // 3   Receive Channel enable bit   
   Uint16     XCERE4:1;       // 4   Receive Channel enable bit  
   Uint16     XCERE5:1;       // 5   Receive Channel enable bit  
   Uint16     XCERE6:1;       // 6   Receive Channel enable bit  
   Uint16     XCERE7:1;       // 7   Receive Channel enable bit 
   Uint16     XCERE8:1;       // 8   Receive Channel enable bit  
   Uint16     XCERE9:1;       // 9   Receive Channel enable bit  
   Uint16     XCERE10:1;      // 10  Receive Channel enable bit  
   Uint16     XCERE11:1;      // 11  Receive Channel enable bit 
   Uint16     XCERE12:1;      // 12  Receive Channel enable bit  
   Uint16     XCERE13:1;      // 13  Receive Channel enable bit  
   Uint16     XCERE14:1;      // 14  Receive Channel enable bit  
   Uint16     XCERE15:1;      // 15  Receive Channel enable bit 
}; 

union XCERE_REG {
   Uint16              all;
   struct  XCERE_BITS  bit;
};  

// XCERF control register bit definitions:
struct  XCERF_BITS {         // bit description
   Uint16     XCERF0:1;       // 0   Receive Channel enable bit  
   Uint16     XCERF1:1;       // 1   Receive Channel enable bit  
   Uint16     XCERF2:1;       // 2   Receive Channel enable bit  
   Uint16     XCERF3:1;       // 3   Receive Channel enable bit   
   Uint16     XCERF4:1;       // 4   Receive Channel enable bit  
   Uint16     XCERF5:1;       // 5   Receive Channel enable bit  
   Uint16     XCERF6:1;       // 6   Receive Channel enable bit  
   Uint16     XCERF7:1;       // 7   Receive Channel enable bit 
   Uint16     XCERF8:1;       // 8   Receive Channel enable bit  
   Uint16     XCERF9:1;       // 9   Receive Channel enable bit  
   Uint16     XCERF10:1;      // 10  Receive Channel enable bit  
   Uint16     XCERF11:1;      // 11  Receive Channel enable bit 
   Uint16     XCERF12:1;      // 12  Receive Channel enable bit  
   Uint16     XCERF13:1;      // 13  Receive Channel enable bit  
   Uint16     XCERF14:1;      // 14  Receive Channel enable bit  
   Uint16     XCERF15:1;      // 15  Receive Channel enable bit 
}; 

union XCERF_REG {
   Uint16              all;
   struct  XCERF_BITS  bit;
};                   

// RCERG control register bit definitions:
struct  RCERG_BITS {         // bit description
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
   Uint16              all;
   struct  RCERG_BITS  bit;
};  

// RCERH control register bit definitions:
struct  RCERH_BITS {         // bit description
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
   Uint16              all;
   struct  RCERH_BITS  bit;
};

// XCERG control register bit definitions:
struct  XCERG_BITS {         // bit description
   Uint16     XCERG0:1;       // 0   Receive Channel enable bit  
   Uint16     XCERG1:1;       // 1   Receive Channel enable bit  
   Uint16     XCERG2:1;       // 2   Receive Channel enable bit  
   Uint16     XCERG3:1;       // 3   Receive Channel enable bit   
   Uint16     XCERG4:1;       // 4   Receive Channel enable bit  
   Uint16     XCERG5:1;       // 5   Receive Channel enable bit  
   Uint16     XCERG6:1;       // 6   Receive Channel enable bit  
   Uint16     XCERG7:1;       // 7   Receive Channel enable bit 
   Uint16     XCERG8:1;       // 8   Receive Channel enable bit  
   Uint16     XCERG9:1;       // 9   Receive Channel enable bit  
   Uint16     XCERG10:1;      // 10  Receive Channel enable bit  
   Uint16     XCERG11:1;      // 11  Receive Channel enable bit 
   Uint16     XCERG12:1;      // 12  Receive Channel enable bit  
   Uint16     XCERG13:1;      // 13  Receive Channel enable bit  
   Uint16     XCERG14:1;      // 14  Receive Channel enable bit  
   Uint16     XCERG15:1;      // 15  Receive Channel enable bit 
}; 

union XCERG_REG {
   Uint16              all;
   struct  XCERG_BITS  bit;
};  

// XCERH control register bit definitions:
struct  XCERH_BITS {         // bit description
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
   Uint16              all;
   struct  XCERH_BITS  bit;
};

// McBSP FIFO Transmit register bit definitions:
struct  MFFTX_BITS {            // bit   description
   Uint16     TXFFIL:5;         // 4:0   Interrupt level
   Uint16     TXFFIENA:1;       // 5     Interrupt enable
   Uint16     TXFFINT_CLEAR:1;  // 6     Clear INT flag
   Uint16     TXFFINT_FLAG:1;   // 7     INT flag
   Uint16     TXFFST:5;         // 12:8  FIFO status
   Uint16     TXFIFO_RESET:1;   // 13    FIFO reset
   Uint16     MFFENA:1;         // 14    Enhancement enable
   Uint16     rsvd:1;           // 15    reserved
}; 

union MFFTX_REG {
   Uint16            all;
   struct MFFTX_BITS bit;
};

// McBSP FIFO recieve register bit definitions:
struct  MFFRX_BITS {        // bits  description
   Uint16 RXFFIL:5;         // 4:0   Interrupt level
   Uint16 RXFFIENA:1;       // 5     Interrupt enable
   Uint16 RXFFINT_CLEAR:1;  // 6     Clear INT flag
   Uint16 RXFFINT_FLAG:1;   // 7     INT flag
   Uint16 RXFFST:5;         // 12:8  FIFO status
   Uint16 RXFIFO_RESET:1;   // 13    FIFO reset
   Uint16 RXFFOVF_CLEAR:1;  // 14    Clear overflow
   Uint16 RXFFOVF_FLAG:1;   // 15    FIFO overflow
}; 

union MFFRX_REG {
   Uint16            all;
   struct MFFRX_BITS bit;
};

// McBSP FIFO control register bit definitions:
struct  MFFCT_BITS {        // bits  description
    Uint16 FFTXTXDLY:8;     // 7:0   FIFO transmit delay
    Uint16 rsvd:7;          // 15:7  reserved
    Uint16 IACKM:1;         // 15    is IACK mode enable bit
};

union MFFCT_REG {
   Uint16             all;
   struct MFFCT_BITS  bit;
};
   
// McBSP FIFO INTERRUPT control register bit definitions:
struct  MFFINT_BITS {       // bits description
    Uint16     XINT:1;      // 0    XINT  interrupt enable
    Uint16     XEVTA:1;     // 1    XEVTA interrupt enable
    Uint16     RINT:1;      // 2    RINT  interrupt enable
    Uint16     REVTA:1;     // 3    REVTA interrupt enable
    Uint16     rsvd:12;     // 15:4 reserved
};

union MFFINT_REG {
   Uint16              all;
   struct MFFINT_BITS  bit;
};

// McBSP FIFO INTERRUPT status  register bit definitions:
struct  MFFST_BITS {       // bits description
    Uint16     EOBX:1;     // 0    EOBX flag
    Uint16     FSX:1;      // 1    FSX flag
    Uint16     EOBR:1;     // 2    EOBR flag
    Uint16     FSR:1;      // 3    FSR flag
    Uint16     rsvd:12;    // 15:4 reserved
};

union MFFST_REG {
   Uint16            all;
   struct MFFST_BITS bit;
};


//---------------------------------------------------------------------------
// McBSP Register File:
//
struct  MCBSP_REGS {      
   union DRR2_REG    DRR2;   // 0x7800, MCBSP Data receive register bits 31-16 
   union DRR1_REG    DRR1;   // 0x7801, MCBSP Data receive register bits 15-0 
   union DXR2_REG    DXR2;   // 0x7802, MCBSP Data transmit register bits 31-16 
   union DXR1_REG    DXR1;   // 0x7803, MCBSP Data transmit register bits 15-0 
   union SPCR2_REG   SPCR2;  // 0x7804, MCBSP control register bits 31-16 
   union SPCR1_REG   SPCR1;  // 0x7805, MCBSP control register bits 15-0 
   union RCR2_REG    RCR2;   // 0x7806, MCBSP receive control register bits 31-16 
   union RCR1_REG    RCR1;   // 0x7807, MCBSP receive control register bits 15-0 
   union XCR2_REG    XCR2;   // 0x7808, MCBSP transmit control register bits 31-16 
   union XCR1_REG    XCR1;   // 0x7809, MCBSP transmit control register bits 15-0 
   union SRGR2_REG   SRGR2;  // 0x7810, MCBSP sample rate gen register bits 31-16 
   union SRGR1_REG   SRGR1;  // 0x7811, MCBSP sample rate gen register bits 15-0  
   union MCR2_REG    MCR2;   // 0x7812, MCBSP multichannel register bits 31-16 
   union MCR1_REG    MCR1;   // 0x7813, MCBSP multichannel register bits 15-0    
   union RCERA_REG   RCERA;  // 0x7814, MCBSP Receive channel enable partition A 
   union RCERB_REG   RCERB;  // 0x7815, MCBSP Receive channel enable partition B 
   union XCERA_REG   XCERA;  // 0x7816, MCBSP Transmit channel enable partition A 
   union XCERB_REG   XCERB;  // 0x7817, MCBSP Transmit channel enable partition B            
   union PCR_REG     PCR;    // 0x7818, MCBSP Pin control register bits 15-0  
   union RCERC_REG   RCERC;  // 0x7819, MCBSP Receive channel enable partition C 
   union RCERD_REG   RCERD;  // 0x7820, MCBSP Receive channel enable partition D
   union XCERC_REG   XCERC;  // 0x7821, MCBSP Transmit channel enable partition C 
   union XCERD_REG   XCERD;  // 0x7823, MCBSP Transmit channel enable partition D             
   union RCERE_REG   RCERE;  // 0x7824, MCBSP Receive channel enable partition E 
   union RCERF_REG   RCERF;  // 0x7825, MCBSP Receive channel enable partition F
   union XCERE_REG   XCERE;  // 0x7826, MCBSP Transmit channel enable partition E
   union XCERF_REG   XCERF;  // 0x7827, MCBSP Transmit channel enable partition F            
   union RCERG_REG   RCERG;  // 0x7828, MCBSP Receive channel enable partition G
   union RCERH_REG   RCERH;  // 0x7829, MCBSP Receive channel enable partition H
   union XCERG_REG   XCERG;  // 0x7830, MCBSP Transmit channel enable partition G 
   union XCERH_REG   XCERH;  // 0x7831, MCBSP Transmit channel enable partition H             
   Uint16            rsvd1;  // 0x7832, reserved             
   union MFFTX_REG   MFFTX;  // 0x7833, MCBSP Transmit FIFO register bits  
   union MFFRX_REG   MFFRX;  // 0x7834, MCBSP Receive FIFO register bits
   union MFFCT_REG   MFFCT;  // 0x7835, MCBSP FIFO control register bits    
   union MFFINT_REG  MFFINT; // 0x7836, MCBSP Interrupt register bits  
   union MFFST_REG   MFFST;  // 0x7837, MCBSP Status register bits 
};

//---------------------------------------------------------------------------
// McBSP External References & Function Declarations:
//
extern volatile struct MCBSP_REGS McbspaRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP281x_MCBSP_H definition

//===========================================================================
// No more.
//===========================================================================
