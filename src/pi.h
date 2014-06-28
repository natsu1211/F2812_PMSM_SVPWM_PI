#ifndef PI_H
#define PI_H

//****************************************************************************
// @Typedefs
//****************************************************************************

typedef struct
{
  //int Ref;
  long Kp;               /* gain proportionnal Q16.0 */
  float Ki;               /* gain integral Q16.0 */
  long KiTsam;           /* 积分*采样时间 */

  long  Saturation;  /* limit of the output -> saturation */
  long  IntK;        /* 积分记录*/
} TPI;

//****************************************************************************
// @Global Variables
//****************************************************************************



//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

long PI_Controller(TPI * PI, long Geiding, long FeedBack,long * Result);

#endif  // ifndef PI.H
