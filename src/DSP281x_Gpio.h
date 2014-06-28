//###########################################################################
//
// FILE:   DSP281x_Gpio.h
//
// TITLE:  DSP281x General Purpose I/O Definitions.
//
//###########################################################################
//
//  Ver | dd mmm yyyy | Who  | Description of changes
// =====|=============|======|===============================================
//  1.00| 11 Sep 2003 | L.H. | Changes since previous version (v.58 Alpha)
//      |             |      | Corrected union definitions that had BIT instead
//      |             |      | of bit
//###########################################################################

#ifndef DSP281x_GPIO_H
#define DSP281x_GPIO_H


#ifdef __cplusplus
extern "C" {
#endif


//----------------------------------------------------
// General purpose I/O (GPIO) Register Bit Definitions                                               

//----------------------------------------------------
// GPIO A mux control register bit definitions */                                    
// 
//
struct GPAMUX_BITS  {        // bits   description
   Uint16 PWM1_GPIOA0:1;     // 0  
   Uint16 PWM2_GPIOA1:1;     // 1 
   Uint16 PWM3_GPIOA2:1;     // 2  
   Uint16 PWM4_GPIOA3:1;     // 3  
   Uint16 PWM5_GPIOA4:1;     // 4  
   Uint16 PWM6_GPIOA5:1;     // 5
   Uint16 T1PWM_GPIOA6:1;    // 6  
   Uint16 T2PWM_GPIOA7:1;    // 7        
   Uint16 CAP1Q1_GPIOA8:1;   // 8 
   Uint16 CAP2Q2_GPIOA9:1;   // 9 
   Uint16 CAP3QI1_GPIOA10:1; // 10
   Uint16 TDIRA_GPIOA11:1;   // 11
   Uint16 TCLKINA_GPIOA12:1; // 12
   Uint16 C1TRIP_GPIOA13:1;  // 13  
   Uint16 C2TRIP_GPIOA14:1;  // 14  
   Uint16 C3TRIP_GPIOA15:1;  // 15   
         
};

union GPAMUX_REG {
   Uint16             all;
   struct GPAMUX_BITS bit;
};



//---------------------------------------------------------------------------------------
// GPIO A Direction control register bit definitions                                    
// 
//
struct GPADIR_BITS  {      // bits   description
   Uint16 GPIOA0:1;          // 0  
   Uint16 GPIOA1:1;          // 1 
   Uint16 GPIOA2:1;          // 2  
   Uint16 GPIOA3:1;          // 3  
   Uint16 GPIOA4:1;          // 4  
   Uint16 GPIOA5:1;          // 5
   Uint16 GPIOA6:1;          // 6  
   Uint16 GPIOA7:1;          // 7        
   Uint16 GPIOA8:1;          // 8 
   Uint16 GPIOA9:1;          // 9 
   Uint16 GPIOA10:1;         // 10
   Uint16 GPIOA11:1;         // 11
   Uint16 GPIOA12:1;         // 12
   Uint16 GPIOA13:1;         // 13  
   Uint16 GPIOA14:1;         // 14  
   Uint16 GPIOA15:1;         // 15   
         
};

union GPADIR_REG {
   Uint16             all;
   struct GPADIR_BITS bit;
};

//----------------------------------
// GPA Qualregister bit definitions
// 
//

struct GPAQUAL_BITS {    // bits   description
   Uint16 QUALPRD:8;     // 0:7    Qualification Sampling Period
   Uint16 rsvd1:8;       // 15:8   reserved
}; 

union GPAQUAL_REG {
   Uint16              all;
   struct GPAQUAL_BITS bit;
};          


//---------------------------------------------------------------------------------------
// GPIO A Data register bit definitions                                    
// 
//
struct GPADAT_BITS  {      // bits   description
   Uint16 GPIOA0:1;          // 0  
   Uint16 GPIOA1:1;          // 1 
   Uint16 GPIOA2:1;          // 2  
   Uint16 GPIOA3:1;          // 3  
   Uint16 GPIOA4:1;          // 4  
   Uint16 GPIOA5:1;          // 5
   Uint16 GPIOA6:1;          // 6  
   Uint16 GPIOA7:1;          // 7        
   Uint16 GPIOA8:1;          // 8 
   Uint16 GPIOA9:1;          // 9 
   Uint16 GPIOA10:1;         // 10
   Uint16 GPIOA11:1;         // 11
   Uint16 GPIOA12:1;         // 12
   Uint16 GPIOA13:1;         // 13  
   Uint16 GPIOA14:1;         // 14  
   Uint16 GPIOA15:1;         // 15   
         
};

union GPADAT_REG {
   Uint16             all;
   struct GPADAT_BITS bit;
};


//---------------------------------------------------------------------------------------
// GPIO A Data set bit definitions                                    
// 
//
struct GPASET_BITS  {      // bits   description
   Uint16 GPIOA0:1;          // 0  
   Uint16 GPIOA1:1;          // 1 
   Uint16 GPIOA2:1;          // 2  
   Uint16 GPIOA3:1;          // 3  
   Uint16 GPIOA4:1;          // 4  
   Uint16 GPIOA5:1;          // 5
   Uint16 GPIOA6:1;          // 6  
   Uint16 GPIOA7:1;          // 7        
   Uint16 GPIOA8:1;          // 8 
   Uint16 GPIOA9:1;          // 9 
   Uint16 GPIOA10:1;         // 10
   Uint16 GPIOA11:1;         // 11
   Uint16 GPIOA12:1;         // 12
   Uint16 GPIOA13:1;         // 13  
   Uint16 GPIOA14:1;         // 14  
   Uint16 GPIOA15:1;         // 15   
         
};

union GPASET_REG {
   Uint16             all;
   struct GPASET_BITS bit;
};



//---------------------------------------------------------------------------------------
// GPIO A Data clear register bit definitions                                    
// 
//
struct GPACLEAR_BITS  {    // bits   description
   Uint16 GPIOA0:1;          // 0  
   Uint16 GPIOA1:1;          // 1 
   Uint16 GPIOA2:1;          // 2  
   Uint16 GPIOA3:1;          // 3  
   Uint16 GPIOA4:1;          // 4  
   Uint16 GPIOA5:1;          // 5
   Uint16 GPIOA6:1;          // 6  
   Uint16 GPIOA7:1;          // 7        
   Uint16 GPIOA8:1;          // 8 
   Uint16 GPIOA9:1;          // 9 
   Uint16 GPIOA10:1;         // 10
   Uint16 GPIOA11:1;         // 11
   Uint16 GPIOA12:1;         // 12
   Uint16 GPIOA13:1;         // 13  
   Uint16 GPIOA14:1;         // 14  
   Uint16 GPIOA15:1;         // 15   
         
};

union GPACLEAR_REG {
   Uint16               all;
   struct GPACLEAR_BITS bit;
};

//---------------------------------------------------------------------------------------
// GPIO A Data toggle register bit definitions                                    
// 
//
struct GPATOGGLE_BITS  {   // bits   description
   Uint16 GPIOA0:1;          // 0  
   Uint16 GPIOA1:1;          // 1 
   Uint16 GPIOA2:1;          // 2  
   Uint16 GPIOA3:1;          // 3  
   Uint16 GPIOA4:1;          // 4  
   Uint16 GPIOA5:1;          // 5
   Uint16 GPIOA6:1;          // 6  
   Uint16 GPIOA7:1;          // 7        
   Uint16 GPIOA8:1;          // 8 
   Uint16 GPIOA9:1;          // 9 
   Uint16 GPIOA10:1;         // 10
   Uint16 GPIOA11:1;         // 11
   Uint16 GPIOA12:1;         // 12
   Uint16 GPIOA13:1;         // 13  
   Uint16 GPIOA14:1;         // 14  
   Uint16 GPIOA15:1;         // 15   
         
};

union GPATOGGLE_REG {
   Uint16                all;
   struct GPATOGGLE_BITS bit;
};



//---------------------------------------------------------------------------------
// GPIO B mux control register bit definitions                                    
// 
//
struct GPBMUX_BITS  {      // bits   description
   Uint16 PWM7_GPIOB0:1;     // 0  
   Uint16 PWM8_GPIOB1:1;     // 1 
   Uint16 PWM9_GPIOB2:1;     // 2  
   Uint16 PWM10_GPIOB3:1;    // 3  
   Uint16 PWM11_GPIOB4:1;    // 4  
   Uint16 PWM12_GPIOB5:1;    // 5
   Uint16 T3PWM_GPIOB6:1;    // 6  
   Uint16 T4PWM_GPIOB7:1;    // 7        
   Uint16 CAP4Q1_GPIOB8:1;   // 8 
   Uint16 CAP5Q2_GPIOB9:1;   // 9 
   Uint16 CAP6QI2_GPIOB10:1; // 10
   Uint16 TDIRB_GPIOB11:1;   // 11
   Uint16 TCLKINB_GPIOB12:1; // 12
   Uint16 C4TRIP_GPIOB13:1;  // 13  
   Uint16 C5TRIP_GPIOB14:1;  // 14  
   Uint16 C6TRIP_GPIOB15:1;  // 15   
         
};

union GPBMUX_REG {
   Uint16             all;
   struct GPBMUX_BITS bit;
};

//---------------------------------------------------------------------------------------
// GPIO B Direction control register bit definitions                                    
// 
//
struct GPBDIR_BITS  {        // bits  description
   Uint16 GPIOB0:1;          // 0  
   Uint16 GPIOB1:1;          // 1 
   Uint16 GPIOB2:1;          // 2  
   Uint16 GPIOB3:1;          // 3  
   Uint16 GPIOB4:1;          // 4  
   Uint16 GPIOB5:1;          // 5
   Uint16 GPIOB6:1;          // 6  
   Uint16 GPIOB7:1;          // 7        
   Uint16 GPIOB8:1;          // 8 
   Uint16 GPIOB9:1;          // 9 
   Uint16 GPIOB10:1;         // 10
   Uint16 GPIOB11:1;         // 11
   Uint16 GPIOB12:1;         // 12
   Uint16 GPIOB13:1;         // 13  
   Uint16 GPIOB14:1;         // 14  
   Uint16 GPIOB15:1;         // 15   
         
};

union GPBDIR_REG {
   Uint16             all;
   struct GPBDIR_BITS bit;
};

//-----------------------------------
// GPB Qualregister bit definitions 
// 
//

struct GPBQUAL_BITS {    // bits   description
   Uint16 QUALPRD:8;     // 0:7    Qualification Sampling Period
   Uint16 rsvd1:8;       // 15:8   reserved
};

union GPBQUAL_REG {
   Uint16              all;
   struct GPBQUAL_BITS bit;
};           


//---------------------------------------------------------------------------------------
// GPIO B data register bit definitions                                    
// 
//
struct GPBDAT_BITS  {      // bits  description
   Uint16 GPIOB0:1;          // 0  
   Uint16 GPIOB1:1;          // 1 
   Uint16 GPIOB2:1;          // 2  
   Uint16 GPIOB3:1;          // 3  
   Uint16 GPIOB4:1;          // 4  
   Uint16 GPIOB5:1;          // 5
   Uint16 GPIOB6:1;          // 6  
   Uint16 GPIOB7:1;          // 7        
   Uint16 GPIOB8:1;          // 8 
   Uint16 GPIOB9:1;          // 9 
   Uint16 GPIOB10:1;         // 10
   Uint16 GPIOB11:1;         // 11
   Uint16 GPIOB12:1;         // 12
   Uint16 GPIOB13:1;         // 13  
   Uint16 GPIOB14:1;         // 14  
   Uint16 GPIOB15:1;         // 15   
         
};

union GPBDAT_REG {
   Uint16             all;
   struct GPBDAT_BITS bit;
};



//---------------------------------------------------------------------------------------
// GPIO B data set register bit definitions                                    
// 
//
struct GPBSET_BITS  {        // bits  description
   Uint16 GPIOB0:1;          // 0  
   Uint16 GPIOB1:1;          // 1 
   Uint16 GPIOB2:1;          // 2  
   Uint16 GPIOB3:1;          // 3  
   Uint16 GPIOB4:1;          // 4  
   Uint16 GPIOB5:1;          // 5
   Uint16 GPIOB6:1;          // 6  
   Uint16 GPIOB7:1;          // 7        
   Uint16 GPIOB8:1;          // 8 
   Uint16 GPIOB9:1;          // 9 
   Uint16 GPIOB10:1;         // 10
   Uint16 GPIOB11:1;         // 11
   Uint16 GPIOB12:1;         // 12
   Uint16 GPIOB13:1;         // 13  
   Uint16 GPIOB14:1;         // 14  
   Uint16 GPIOB15:1;         // 15   
         
};


union GPBSET_REG {
   Uint16             all;
   struct GPBSET_BITS bit;
};


//---------------------------------------------------------------------------------------
// GPIO B data clear register bit definitions                                    
// 
//
struct GPBCLEAR_BITS  {      // bits  description
   Uint16 GPIOB0:1;          // 0  
   Uint16 GPIOB1:1;          // 1 
   Uint16 GPIOB2:1;          // 2  
   Uint16 GPIOB3:1;          // 3  
   Uint16 GPIOB4:1;          // 4  
   Uint16 GPIOB5:1;          // 5
   Uint16 GPIOB6:1;          // 6  
   Uint16 GPIOB7:1;          // 7        
   Uint16 GPIOB8:1;          // 8 
   Uint16 GPIOB9:1;          // 9 
   Uint16 GPIOB10:1;         // 10
   Uint16 GPIOB11:1;         // 11
   Uint16 GPIOB12:1;         // 12
   Uint16 GPIOB13:1;         // 13  
   Uint16 GPIOB14:1;         // 14  
   Uint16 GPIOB15:1;         // 15   
         
};

union GPBCLEAR_REG {
   Uint16               all;
   struct GPBCLEAR_BITS bit;
};



//---------------------------------------------------------------------------------------
// GPIO B data toggle register bit definitions                                    
// 
//
struct GPBTOGGLE_BITS  {     // bits  description
   Uint16 GPIOB0:1;          // 0  
   Uint16 GPIOB1:1;          // 1 
   Uint16 GPIOB2:1;          // 2  
   Uint16 GPIOB3:1;          // 3  
   Uint16 GPIOB4:1;          // 4  
   Uint16 GPIOB5:1;          // 5
   Uint16 GPIOB6:1;          // 6  
   Uint16 GPIOB7:1;          // 7        
   Uint16 GPIOB8:1;          // 8 
   Uint16 GPIOB9:1;          // 9 
   Uint16 GPIOB10:1;         // 10
   Uint16 GPIOB11:1;         // 11
   Uint16 GPIOB12:1;         // 12
   Uint16 GPIOB13:1;         // 13  
   Uint16 GPIOB14:1;         // 14  
   Uint16 GPIOB15:1;         // 15   
         
};

union GPBTOGGLE_REG {
   Uint16                all;
   struct GPBTOGGLE_BITS bit;
};


//---------------------------------------------------------------------------------
// GPIO D mux control register bit definitions                                    
// 
//
struct GPDMUX_BITS  {                  // bits  description
   Uint16 T1CTRIP_PDPA_GPIOD0:1;       // 0  
   Uint16 T2CTRIP_SOCA_GPIOD1:1;       // 1   
   Uint16 rsvd1:3;                     // 4:2  
   Uint16 T3CTRIP_PDPB_GPIOD5:1;       // 5  
   Uint16 T4CTRIP_SOCB_GPIOD6:1;       // 6   
   Uint16 rsvd2:9;                     // 15:7  
            
};

union GPDMUX_REG {
   Uint16             all;
   struct GPDMUX_BITS bit;
};

//----------------------------------------------------
// GPIO D Direction control register bit definitions 
//                                     
//
struct GPDDIR_BITS  {      // bits   description
   Uint16 GPIOD0:1;          // 0  
   Uint16 GPIOD1:1;          // 1 
   Uint16 rsvd1:3;           // 4:2  
   Uint16 GPIOD5:1;          // 5
   Uint16 GPIOD6:1;          // 6  
   Uint16 rsvd2:9;           // 15:7
};

union GPDDIR_REG {
   Uint16             all;
   struct GPDDIR_BITS bit;
};


//----------------------------------------------------
// GPIO D data register bit definitions 
//                                     
//
struct GPDDAT_BITS  {      // bits   description
   Uint16 GPIOD0:1;          // 0  
   Uint16 GPIOD1:1;          // 1 
   Uint16 rsvd1:3;           // 4:2  
   Uint16 GPIOD5:1;          // 5
   Uint16 GPIOD6:1;          // 6  
   Uint16 rsvd2:9;           // 15:7
};           

union GPDDAT_REG {
   Uint16             all;
   struct GPDDAT_BITS bit;
};


//----------------------------------------------------
// GPIO D data set register bit definitions 
//                                     
//
struct GPDSET_BITS  {        // bits   description
   Uint16 GPIOD0:1;          // 0  
   Uint16 GPIOD1:1;          // 1 
   Uint16 rsvd1:3;           // 4:2  
   Uint16 GPIOD5:1;          // 5
   Uint16 GPIOD6:1;          // 6  
   Uint16 rsvd2:9;           // 15:7
};

union GPDSET_REG {
   Uint16             all;
   struct GPDSET_BITS bit;
};


//----------------------------------------------------
// GPIO D data clear register bit definitions 
//                                     
//
struct GPDCLEAR_BITS  {      // bits   description
   Uint16 GPIOD0:1;          // 0  
   Uint16 GPIOD1:1;          // 1 
   Uint16 rsvd1:3;           // 4:2  
   Uint16 GPIOD5:1;          // 5
   Uint16 GPIOD6:1;          // 6  
   Uint16 rsvd2:9;           // 15:7
};

union GPDCLEAR_REG {
   Uint16               all;
   struct GPDCLEAR_BITS bit;
};



//----------------------------------------------------
// GPIO D data toggle register bit definitions 
//                                     
//
struct GPDTOGGLE_BITS  {     // bits   description
   Uint16 GPIOD0:1;          // 0  
   Uint16 GPIOD1:1;          // 1 
   Uint16 rsvd1:3;           // 4:2  
   Uint16 GPIOD5:1;          // 5
   Uint16 GPIOD6:1;          // 6  
   Uint16 rsvd2:9;           // 15:7
};

union GPDTOGGLE_REG {
   Uint16                all;
   struct GPDTOGGLE_BITS bit;
};



//----------------------------------
// GPIOD Qualregister bit definitions
// 
//
struct GPDQUAL_BITS {    // bits   description
   Uint16 QUALPRD:8;     // 0:7    Qualification Sampling Period
   Uint16 rsvd1:8;       // 15:8   reserved
};    

union GPDQUAL_REG {
   Uint16              all;
   struct GPDQUAL_BITS bit;
};       


//---------------------------------------------
// GPIO E mux control register bit definitions
//                                     
//
struct GPEMUX_BITS  {                // bits  description
   Uint16 XINT1_XBIO_GPIOE0:1;       // 0  
   Uint16 XINT2_ADCSOC_GPIOE1:1;     // 1  
   Uint16 XNMI_XINT13_GPIOE2:1;      // 2 
   Uint16 rsvd1:12;                  // 15:3  
               
};

union GPEMUX_REG {
   Uint16             all;
   struct GPEMUX_BITS bit;
};

//---------------------------------------------------
// GPIO E Direction control register bit definitions
//                                     
//
struct GPEDIR_BITS  {        // bits   description
   Uint16 GPIOE0:1;          // 0 
   Uint16 GPIOE1:1;          // 1 
   Uint16 GPIOE2:1;          // 2 
   Uint16 rsvd1:12;          // 15:3        
};

union GPEDIR_REG {
   Uint16             all;
   struct GPEDIR_BITS bit;
};

//---------------------------------------------------
// GPIO E data register bit definitions
//                                     
//
struct GPEDAT_BITS  {        // bits   description
   Uint16 GPIOE0:1;          // 0 
   Uint16 GPIOE1:1;          // 1 
   Uint16 GPIOE2:1;          // 2 
   Uint16 rsvd1:12;          // 15:3        
};

union GPEDAT_REG {
   Uint16             all;
   struct GPEDAT_BITS bit;
};



//---------------------------------------------------
// GPIO E data set register bit definitions
//                                     
//
struct GPESET_BITS  {        // bits   description
   Uint16 GPIOE0:1;          // 0 
   Uint16 GPIOE1:1;          // 1 
   Uint16 GPIOE2:1;          // 2 
   Uint16 rsvd1:12;          // 15:3        
};

union GPESET_REG {
   Uint16             all;
   struct GPESET_BITS bit;
};


//---------------------------------------------------
// GPIO E data clear register bit definitions
//                                     
//
struct GPECLEAR_BITS  {      // bits   description
   Uint16 GPIOE0:1;          // 0 
   Uint16 GPIOE1:1;          // 1 
   Uint16 GPIOE2:1;          // 2 
   Uint16 rsvd1:12;          // 15:3        
};

union GPECLEAR_REG {
   Uint16               all;
   struct GPECLEAR_BITS bit;
};


//---------------------------------------------------
// GPIO E data toggle register bit definitions
//                                     
//
struct GPETOGGLE_BITS  {     // bits   description
   Uint16 GPIOE0:1;          // 0 
   Uint16 GPIOE1:1;          // 1 
   Uint16 GPIOE2:1;          // 2 
   Uint16 rsvd1:12;          // 15:3        
};

union GPETOGGLE_REG {
   Uint16                all;
   struct GPETOGGLE_BITS bit;
};



//-----------------------------------
// GPIOE Qualregister bit definitions 
// 
//
struct GPEQUAL_BITS {        // bits   description
   Uint16     QUALPRD:8;     // 0:7    Qualification Sampling Period
   Uint16 rsvd1:8;           // 15:8   reserved
};     

union GPEQUAL_REG {
   Uint16              all;
   struct GPEQUAL_BITS bit;
};      


//----------------------------------------------
//  GPIO F mux control register bit definitions
// 
//
struct GPFMUX_BITS  {      // bits   description
   Uint16 SPISIMOA_GPIOF0:1; // 0 
   Uint16 SPISOMIA_GPIOF1:1; // 1 
   Uint16 SPICLKA_GPIOF2:1;  // 2 
   Uint16 SPISTEA_GPIOF3:1;  // 3 
   Uint16 SCITXDA_GPIOF4:1;  // 4 
   Uint16 SCIRXDA_GPIOF5:1;  // 5 
   Uint16 CANTXA_GPIOF6:1;   // 6 
   Uint16 CANRXA_GPIOF7:1;   // 7 
   Uint16 MCLKXA_GPIOF8:1;   // 8 
   Uint16 MCLKRA_GPIOF9:1;   // 9 
   Uint16 MFSXA_GPIOF10:1;   // 10
   Uint16 MFSRA_GPIOF11:1;   // 11
   Uint16 MDXA_GPIOF12:1;    // 12
   Uint16 MDRA_GPIOF13:1;    // 13
   Uint16 XF_GPIOF14:1;      // 14
   Uint16 spare_GPIOF15:1;   // 15
         
};

/* Allow access to the bit fields or entire register */
union GPFMUX_REG {
   Uint16             all;
   struct GPFMUX_BITS bit;
};

//---------------------------------------------------
// GPIO F Direction control register bit definitions
//                                     
//
                                          
struct GPFDIR_BITS  {      // bits   description
   Uint16 GPIOF0:1;          // 0 
   Uint16 GPIOF1:1;          // 1 
   Uint16 GPIOF2:1;          // 2 
   Uint16 GPIOF3:1;          // 3 
   Uint16 GPIOF4:1;          // 4 
   Uint16 GPIOF5:1;          // 5 
   Uint16 GPIOF6:1;          // 6 
   Uint16 GPIOF7:1;          // 7 
   Uint16 GPIOF8:1;          // 8 
   Uint16 GPIOF9:1;          // 9 
   Uint16 GPIOF10:1;         // 10
   Uint16 GPIOF11:1;         // 11
   Uint16 GPIOF12:1;         // 12
   Uint16 GPIOF13:1;         // 13
   Uint16 GPIOF14:1;         // 14
   Uint16 GPIOF15:1;         // 15

};

union GPFDIR_REG {
   Uint16             all;
   struct GPFDIR_BITS bit;
};

//---------------------------------------------------
// GPIO F data register bit definitions
//                                     
//
                                          
struct GPFDAT_BITS  {      // bits   description
   Uint16 GPIOF0:1;          // 0 
   Uint16 GPIOF1:1;          // 1 
   Uint16 GPIOF2:1;          // 2 
   Uint16 GPIOF3:1;          // 3 
   Uint16 GPIOF4:1;          // 4 
   Uint16 GPIOF5:1;          // 5 
   Uint16 GPIOF6:1;          // 6 
   Uint16 GPIOF7:1;          // 7 
   Uint16 GPIOF8:1;          // 8 
   Uint16 GPIOF9:1;          // 9 
   Uint16 GPIOF10:1;         // 10
   Uint16 GPIOF11:1;         // 11
   Uint16 GPIOF12:1;         // 12
   Uint16 GPIOF13:1;         // 13
   Uint16 GPIOF14:1;         // 14
   Uint16 GPIOF15:1;         // 15

};

union GPFDAT_REG {
   Uint16             all;
   struct GPFDAT_BITS bit;
};


//---------------------------------------------------
// GPIO F data set register bit definitions
//                                     
//
                                          
struct GPFSET_BITS  {      // bits   description
   Uint16 GPIOF0:1;          // 0 
   Uint16 GPIOF1:1;          // 1 
   Uint16 GPIOF2:1;          // 2 
   Uint16 GPIOF3:1;          // 3 
   Uint16 GPIOF4:1;          // 4 
   Uint16 GPIOF5:1;          // 5 
   Uint16 GPIOF6:1;          // 6 
   Uint16 GPIOF7:1;          // 7 
   Uint16 GPIOF8:1;          // 8 
   Uint16 GPIOF9:1;          // 9 
   Uint16 GPIOF10:1;         // 10
   Uint16 GPIOF11:1;         // 11
   Uint16 GPIOF12:1;         // 12
   Uint16 GPIOF13:1;         // 13
   Uint16 GPIOF14:1;         // 14
   Uint16 GPIOF15:1;         // 15

};

union GPFSET_REG {
   Uint16             all;
   struct GPFSET_BITS bit;
};


//---------------------------------------------------
// GPIO F data clear register bit definitions
//                                     
//
                                          
struct GPFCLEAR_BITS  {    // bits   description
   Uint16 GPIOF0:1;          // 0 
   Uint16 GPIOF1:1;          // 1 
   Uint16 GPIOF2:1;          // 2 
   Uint16 GPIOF3:1;          // 3 
   Uint16 GPIOF4:1;          // 4 
   Uint16 GPIOF5:1;          // 5 
   Uint16 GPIOF6:1;          // 6 
   Uint16 GPIOF7:1;          // 7 
   Uint16 GPIOF8:1;          // 8 
   Uint16 GPIOF9:1;          // 9 
   Uint16 GPIOF10:1;         // 10
   Uint16 GPIOF11:1;         // 11
   Uint16 GPIOF12:1;         // 12
   Uint16 GPIOF13:1;         // 13
   Uint16 GPIOF14:1;         // 14
   Uint16 GPIOF15:1;         // 15

};

union GPFCLEAR_REG {
   Uint16               all;
   struct GPFCLEAR_BITS bit;
};


//---------------------------------------------------
// GPIO F data toggle register bit definitions
//                                     
//
                                          
struct GPFTOGGLE_BITS  {   // bits   description
   Uint16 GPIOF0:1;          // 0 
   Uint16 GPIOF1:1;          // 1 
   Uint16 GPIOF2:1;          // 2 
   Uint16 GPIOF3:1;          // 3 
   Uint16 GPIOF4:1;          // 4 
   Uint16 GPIOF5:1;          // 5 
   Uint16 GPIOF6:1;          // 6 
   Uint16 GPIOF7:1;          // 7 
   Uint16 GPIOF8:1;          // 8 
   Uint16 GPIOF9:1;          // 9 
   Uint16 GPIOF10:1;         // 10
   Uint16 GPIOF11:1;         // 11
   Uint16 GPIOF12:1;         // 12
   Uint16 GPIOF13:1;         // 13
   Uint16 GPIOF14:1;         // 14
   Uint16 GPIOF15:1;         // 15

};

union GPFTOGGLE_REG {
   Uint16                all;
   struct GPFTOGGLE_BITS bit;
};

//----------------------------------------------
//  GPIO G mux control register bit definitions
// 
//
struct GPGMUX_BITS  {      // bits   description
   Uint16 rsvd1:4;           // 3:0
   Uint16 SCITXDB_GPIOG4:1;  // 4 
   Uint16 SCIRXDB_GPIOG5:1;  // 5 
   Uint16 rsvd2:10;          // 15:6

};


/* Allow access to the bit fields or entire register */
union GPGMUX_REG {
   Uint16             all;
   struct GPGMUX_BITS bit;
};

//---------------------------------------------------
// GPIO G Direction control register bit definitions
//                                     
//
                                          
struct GPGDIR_BITS  {      // bits   description
   Uint16 rsvd1:4;           // 3:0
   Uint16 GPIOG4:1;          // 4 
   Uint16 GPIOG5:1;          // 5 
   Uint16 rsvd2:10;          // 15:6

};

union GPGDIR_REG {
   Uint16             all;
   struct GPGDIR_BITS bit;
};

//---------------------------------------------------
// GPIO G data register bit definitions
//                                     
//
                                          
struct GPGDAT_BITS  {      // bits   description
   Uint16 rsvd1:4;           // 3:0
   Uint16 GPIOG4:1;          // 4 
   Uint16 GPIOG5:1;          // 5 
   Uint16 rsvd2:10;          // 15:6

};

union GPGDAT_REG {
   Uint16             all;
   struct GPGDAT_BITS bit;
};


//---------------------------------------------------
// GPIO G data set register bit definitions
//                                     
//
                                          
struct GPGSET_BITS  {        // bits   description
   Uint16 rsvd1:4;           // 3:0
   Uint16 GPIOG4:1;          // 4 
   Uint16 GPIOG5:1;          // 5 
   Uint16 rsvd2:10;          // 15:6

};

union GPGSET_REG {
   Uint16             all;
   struct GPGSET_BITS bit;
};


//---------------------------------------------------
// GPIO G data clear register bit definitions
//                                     
//
                                          
struct GPGCLEAR_BITS  {      // bits   description
   Uint16 rsvd1:4;           // 3:0
   Uint16 GPIOG4:1;          // 4 
   Uint16 GPIOG5:1;          // 5 
   Uint16 rsvd2:10;          // 15:6

};

union GPGCLEAR_REG {
   Uint16               all;
   struct GPGCLEAR_BITS bit;
};


//---------------------------------------------------
// GPIO G data toggle register bit definitions
//                                     
//
                                          
struct GPGTOGGLE_BITS  {     // bits   description
   Uint16 rsvd1:4;           // 3:0
   Uint16 GPIOG4:1;          // 4 
   Uint16 GPIOG5:1;          // 5 
   Uint16 rsvd2:10;          // 15:6

};

union GPGTOGGLE_REG {
   Uint16                all;
   struct GPGTOGGLE_BITS bit;
};


struct GPIO_MUX_REGS {
   union  GPAMUX_REG   GPAMUX;
   union  GPADIR_REG   GPADIR;
   union  GPAQUAL_REG  GPAQUAL;
   Uint16              rsvd1;
   union  GPBMUX_REG   GPBMUX;
   union  GPBDIR_REG   GPBDIR;
   union  GPBQUAL_REG  GPBQUAL;   
   Uint16              rsvd2[5];
   union  GPDMUX_REG   GPDMUX;
   union  GPDDIR_REG   GPDDIR;
   union  GPDQUAL_REG  GPDQUAL;   
   Uint16              rsvd3;
   union  GPEMUX_REG   GPEMUX;
   union  GPEDIR_REG   GPEDIR;
   union  GPEQUAL_REG  GPEQUAL;   
   Uint16              rsvd4;
   union  GPFMUX_REG   GPFMUX;
   union  GPFDIR_REG   GPFDIR;
   Uint16              rsvd5[2];
   union  GPGMUX_REG   GPGMUX;
   union  GPGDIR_REG   GPGDIR;
   Uint16              rsvd6[6];
};

struct GPIO_DATA_REGS {
   union  GPADAT_REG    GPADAT;
   union  GPASET_REG    GPASET;
   union  GPACLEAR_REG  GPACLEAR;
   union  GPATOGGLE_REG GPATOGGLE;
   union  GPBDAT_REG    GPBDAT;
   union  GPBSET_REG    GPBSET;
   union  GPBCLEAR_REG  GPBCLEAR;
   union  GPBTOGGLE_REG GPBTOGGLE;
   Uint16               rsvd1[4];
   union  GPDDAT_REG    GPDDAT;
   union  GPDSET_REG    GPDSET;
   union  GPDCLEAR_REG  GPDCLEAR;
   union  GPDTOGGLE_REG GPDTOGGLE;
   union  GPEDAT_REG    GPEDAT;
   union  GPESET_REG    GPESET;
   union  GPECLEAR_REG  GPECLEAR;
   union  GPETOGGLE_REG GPETOGGLE;
   union  GPFDAT_REG    GPFDAT;
   union  GPFSET_REG    GPFSET;
   union  GPFCLEAR_REG  GPFCLEAR;
   union  GPFTOGGLE_REG GPFTOGGLE;
   union  GPGDAT_REG    GPGDAT;
   union  GPGSET_REG    GPGSET;
   union  GPGCLEAR_REG  GPGCLEAR;
   union  GPGTOGGLE_REG GPGTOGGLE;
   Uint16               rsvd2[4];      
};     
 

//---------------------------------------------------------------------------
// GPI/O External References & Function Declarations:
//
extern volatile struct GPIO_MUX_REGS GpioMuxRegs;
extern volatile struct GPIO_DATA_REGS GpioDataRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP281x_GPIO_H definition

//===========================================================================
// No more.
//===========================================================================
