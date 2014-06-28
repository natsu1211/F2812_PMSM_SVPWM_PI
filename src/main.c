#include "DSP281x_Device.h"     // DSP281x Headerfile Include File
#include "DSP281x_Examples.h"   // DSP281x Examples Include File
#include "pi.h"

#define ThreeDivide2Q14 0x6000    // 1.5       in 1Q14
#define Sqrt3Divide2Q14 0x376C    // sqrt(3)/2 in 1Q14
#define Sqrt3Q14        0x6ED9    // sqrt(3)   in 1Q14
#define thita_ref   0x1800
///////初始化及给定///////
int T1_PR=0;
int  motor_OK=1,shan_qu=0;
const int ED  =2600;//20*128
long IsQ_ref=1000;//200;//10000//17000;//100;// //1500   Q9
long IsD_ref= 0;//6000//15000;//200;////1021;//720  Q9  17500
long Speed_Cal=0,speed_now=0,speed_now1,Place_now=0,Time_Count=0,Pulse_Count=0,Place_ref=28000;
//////SVPWM和坐标变换//////
float Iv_result,Iw_result,Iu_result;
long IsAlpha,IsBeta,IsD,IsQ,Isa,Isb,Isc;
int CosThita=0;
int SinThita=0,rec_data=0;
long Ud;
long Uq;
unsigned long   TXX=0,UX_Tmep_value1, UX_Tmep_value2;
unsigned int Us_Tmep_value1;
unsigned int Us_Tmep_value2,Ud_Tmep_value1,Uq_Tmep_value2;
int Thita_in_sector=0;
long thita=0;
int  Thita_dq=0;
long Us_value;
long Thita;
unsigned int Sector=0;
unsigned int Sin_value1=0;
unsigned int Sin_value2=0;
unsigned int Int_Tmep_value1=0;
unsigned int Int_Tmep_value2=0;
unsigned int MD=0;
unsigned int Tl=0;
unsigned int Tm=0;
unsigned long TA=0;
unsigned long TB=0;
unsigned long TC=0;
unsigned long TA1=0;
unsigned long TB1=0;
unsigned long TC1=0;
///////计数模块中间变量///////
unsigned int extent_temp=0, extent_temp1=0, extent_temp2=0,count_zero=0;
long extent_D=0,extent_zero=0;
long temp=0,temp1=0,temp2=0 ;
/////////////////da及观测数组//////////////////////////////
int count_a=0,rec_dataa=0,rec_datab=0,count_b=0,rec_step=0,para_low=0,para_high=0,para_number=0,para_read_addr=0,send_datab_low=0,send_datab_high=0;
int check_read=0,check_sent=0,wucha=20;
unsigned long int a;//delay中变量
unsigned int Iq_da=0;//数据发送参数
unsigned int Id_da=0;//数据发送参数
int read_datal=0,read_datah=0;
/////////////////da及观测数组//////////////////////////////
///////////////////各种常数////////////////
const int Degree0=0x0000;
const int Degree45=0x600;
const int Degree90=0x0C00;
const int Degree135=0x1200;
const int Degree180=0x1800;
const int Degree225=0x1E00;
const int Degree270=0x2400;
const int Degree315=0x2A00;
extern const int Degree360=0x3000;
const int Degree60=0x0800;
const long Degree360_long=0x30000000;//2^16*12288,其中12288表示360度
const int SQRT2=0x05A8;
extern const int  SqrtTable[2048];
extern const int  ArcTanTable[2048];
extern const int  SinTable[3072];//3072表示90度
TPI ACMR;
TPI ACTR;
TPI ASR;
TPI ASP;
////////////////////////////////函数初始化////////////////////////////////////////////////////////////////
long PI_Controller(TPI * PI, long Geiding, long FeedBack,long * Result);
void Init_ADC(void);
void Delay(void);
void Delays(int m);
void RP_transformation(void);
void Svpwm(void);
void init_ev(void);
void eva_timer1_isr(void);
void motor_init(void);
void CAPINT3(void);
void MY_T3PINT_ISR(void);
void Gpio_select(void);
void SCIARX_ISR();
void SCIATX_ISR();
void SCIBRX_ISR();
void SCIBTX_ISR();
int input1_last=0,input2_last=0,Iamax=2370,Iamin=2370,Ibmax=2370,Ibmin=2370,zero_init=2000;
int count_mm=0,countmax[100]=0,countmin[100]=0,imax=0;
int max(int input1);
int min(int input2);
///////////////////////////////////////////////////main///////////////////////////////////////////
void main(void)
{
     /*初始化系统*/
	 InitSysCtrl();
	 InitSci();
	 Init_ADC();
     EALLOW;
	 GpioMuxRegs.GPAMUX.all =0x077F;//0x073F ; // EVA PWM 1-6  pins cap1,2,3 pins  0x07FF
     GpioMuxRegs.GPAQUAL.all=0x0000;
     GpioMuxRegs.GPADIR.all|=0xe77F;//0xE07F;0xFFFF

	 GpioMuxRegs.GPFMUX.all = 0x0030;//0011 0000
	 GpioMuxRegs.GPFDIR.all = 0x0010;//0001 0000

	 GpioMuxRegs.GPBMUX.all &=0x98FF;//0x073F ; // qep 3 4 12作为IO  13 14  eeprom
     GpioMuxRegs.GPBQUAL.all=0x0000;
     GpioMuxRegs.GPBDIR.all|=0xF8FF;//hall设置为输入

	 GpioMuxRegs.GPGMUX.all |= 0x0030;//0011 0000
	 GpioMuxRegs.GPGDIR.all |= 0x0010;//0001 0000

	 EDIS;
	 DINT;
	 InitPieCtrl();
	 IER = 0x0000;//关闭中断
	 IFR = 0x0000;//清中断标志
	 EALLOW;  // This is needed to write to EALLOW protected registers
     PieVectTable.T1UFINT = &T1UFINT_ISR;//赋予地址,中断发生时,自动跳转
     PieVectTable.CAPINT3 = &CAPINT3_ISR;
   	 PieVectTable.T3PINT = &MY_T3PINT_ISR;   //TIMER3比较中断
	 PieVectTable.RXBINT = &SCIARX_ISR;
	 PieVectTable.TXBINT = &SCIATX_ISR;
     EDIS;
  	 /*初始化PIE中断矢量表*/
	 InitPieVectTable();
	 EvaRegs.T1CON.all=0x0000;
	 EvaRegs.T2CON.all=0x0000;
	 EvbRegs.T4CON.all=0x0000;
     motor_init();//电机转子初始位置判断
     init_ev();

	 ACMR.Kp  =8000;//Id
     ACMR.Ki  =30.0;//
     ACMR.Saturation =0xA000000;//A0
     ACMR.IntK = 0;

     ACTR.Kp  =8000;//Iq
     ACTR.Ki  =30.0;//
     ACTR.Saturation =0xA000000;//20*128*65535
     ACTR.IntK = 0;

	 ASR.Kp  =9635500;//速度
     ASR.Ki  =930.0; //
     ASR.Saturation =0xfCFfc18;//2000*65535
     ASR.IntK = 0;

	 ASP.Kp  =10000;//位置（POSITION）
     ASP.Ki  =0.1; //
     ASP.Saturation =0x45FFBA;//70*65535
     ASP.IntK = 0;

     PieCtrlRegs.PIEIER2.bit.INTx6 = 1;//下溢中断向量允许
     PieCtrlRegs.PIEIER3.bit.INTx7 = 1; //捕获3中断
     PieCtrlRegs.PIEIER4.bit.INTx4 = 1;//T3周期中断
     PieCtrlRegs.PIEIER9.bit.INTx2 = 1;
	 PieCtrlRegs.PIEIER9.bit.INTx1 = 1;
     PieCtrlRegs.PIEIER9.bit.INTx3 = 1;
	 PieCtrlRegs.PIEIER9.bit.INTx4 = 1;

     IER |= (M_INT2|M_INT3|M_INT4|M_INT9);//中断允许
	 EINT;   // Enable Global interrupt INTM使能全局中断
     ERTM;   // Enable Global realtime interrupt DBGM使能实时中断

	 EvaRegs.EVAIMRA.bit.T1UFINT = 1; //下溢中断允许
     EvaRegs.EVAIFRA.bit.T1UFINT = 1; //清除下溢中断标志位
	 EvaRegs.EVAIMRC.bit.CAP3INT = 1;
	 EvaRegs.EVAIFRC.bit.CAP3INT = 1;
     EvbRegs.EVBIMRA.bit.T3PINT = 1;
     EvbRegs.EVBIFRA.bit.T3PINT = 1;
	 SciaRegs.SCICTL2.bit.RXBKINTENA = 1; //使能
	 SciaRegs.SCICTL2.bit.TXINTENA = 1; //使能
	 ScibRegs.SCICTL2.bit.RXBKINTENA = 1; //使能
	 ScibRegs.SCICTL2.bit.TXINTENA = 1; //使能
     T1_PR=EvaRegs.T1PR;
//	Write24Cxx(22,1,1);
 	 for(;;)
	 {
	   if(rec_step==253)
		{
			read_datal=	Read24Cxx(3,1);//sudu
			read_datah=	Read24Cxx(4,1);//sudu
			Speed_Cal=read_datah*100+read_datal;
			rec_step=0;
		}
		if(rec_step==252)
		{
			Speed_Cal=0;
			rec_step=0;
		}
		if(rec_step==251)
		{
			read_datal=	Read24Cxx(1,1);//sudu
			read_datah=	Read24Cxx(2,1);//sudu
			SciaRegs.SCITXBUF=speed_now;
			Speed_Cal=read_datah*100+read_datal;
			rec_step=0;
		}
		if(rec_step==255)
		{
				Write24Cxx(para_low,(para_number*2+1),1);
				Write24Cxx(para_high,(para_number*2+2),1);
				ScibRegs.SCITXBUF=0x88;
				Delays(12);
				ScibRegs.SCITXBUF=0x01;
				Delays(12);
				ScibRegs.SCITXBUF=para_number;
				Delays(12);
				ScibRegs.SCITXBUF=0x01;//成功
				Delays(12);
				ScibRegs.SCITXBUF=0x88^0x01^para_number^0x01;//check
				Delays(12);
				ScibRegs.SCITXBUF=0x44;
				Delays(12);
				rec_step=0;
		}
		else if(rec_step==254)
		{
			    send_datab_low =Read24Cxx(para_read_addr*2+1,1);
				send_datab_high=Read24Cxx(para_read_addr*2+2,1);
				ScibRegs.SCITXBUF=0x99;
				Delays(12);
				ScibRegs.SCITXBUF=0x00;
				Delays(12);
				ScibRegs.SCITXBUF=send_datab_low;
				Delays(12);
				ScibRegs.SCITXBUF=send_datab_high;
				Delays(12);
				ScibRegs.SCITXBUF=0x99^0x00^send_datab_low^send_datab_high;
				Delays(12);
				ScibRegs.SCITXBUF=0xbb;
				Delays(12);
				rec_step=0;
		}


	 }
}
void SCIARX_ISR()
{			count_a++;
	 	SciaRegs.SCICTL2.bit.RXBKINTENA = 0; //使能
		rec_dataa= SciaRegs.SCIRXBUF.all;
		SciaRegs.SCICTL2.bit.RXBKINTENA = 1; //使能
  		PieCtrlRegs.PIEACK.bit.ACK9 = 1;
	    EINT;   // Enable Global interrupt INTM使能全局中断
}
void SCIATX_ISR()
{

		SciaRegs.SCICTL2.bit.TXINTENA = 0; //使	if(feedback==1)
	    SciaRegs.SCICTL2.bit.TXINTENA = 1; //使能
  		PieCtrlRegs.PIEACK.bit.ACK9 = 1;
	    EINT;   // Enable Global interrupt INTM使能全局中断
}
void SCIBRX_ISR()
{
		count_b++;
	 	ScibRegs.SCICTL2.bit.RXBKINTENA = 0; //使能
		rec_datab= ScibRegs.SCIRXBUF.all;
		switch(rec_step)
		{
			case 0:
				if(rec_datab==0x88)
				{
					rec_step=1;
				}
				else if(rec_datab==0x99)
				{
					rec_step=7;
				}
				else if(rec_datab==0xcc)
				{
					rec_step=253;//jog
				}
				else if(rec_datab==0xbb)
				{
					rec_step=252;//stop jog
				}
				else if(rec_datab==0xaa)
				{
					rec_step=251;								//run
				}
				else if(rec_datab==0xdd)
				{
					rec_step=252;//stop jog //stop
				}
			break;
			case 1:
						if(rec_datab==0x01)
						{
							rec_step=2;
						}
					break;
			case 2:
						para_number=rec_datab;
						rec_step=3;

					break;
			case 3:
						para_high=rec_datab;//
						rec_step=4;

					break;
			case 4:
					para_low=rec_datab;//
					rec_step=5;
					break;
			case 5:
					check_sent=(0x88^0x01)^para_number^para_high^para_low;
					if(rec_datab==check_sent)
					rec_step=6;
					break;
			case 6:
					if(rec_datab==0x44)
					rec_step=255;//写帧结束
					break;
			case 7://读取帧开始
					if(rec_datab==0x00)
					{
					rec_step=8;
					}
					break;
			case 8:
					para_read_addr=rec_datab;
					rec_step=9;
					break;
			case 9:
					check_read=0x99^0x00^para_read_addr;
					if(rec_datab==check_read)
					{
					  rec_step=10;
					}
					break;
			case 10:
					if(rec_datab==0xaa)
					{
					  rec_step=254;//读取帧结束
					}
					break;
		}

		ScibRegs.SCICTL2.bit.RXBKINTENA = 1; //使能
  		PieCtrlRegs.PIEACK.bit.ACK9 = 1;
	    EINT;   // Enable Global interrupt INTM使能全局中断
}
void SCIBTX_ISR()
{

		ScibRegs.SCICTL2.bit.TXINTENA = 0; //使	if(feedback==1)
	    ScibRegs.SCICTL2.bit.TXINTENA = 1; //使能
  		PieCtrlRegs.PIEACK.bit.ACK9 = 1;
	    EINT;   // Enable Global interrupt INTM使能全局中断
}


/*******************************************************************************
Name：void MY_T3PINT_ISR(void)
Function：T3 INTERUPT
Calculate speed
*******************************************************************************/
void MY_T3PINT_ISR(void)
{
count_mm++;
if(count_mm==1000)
{
count_mm=0;
imax++;
countmax[imax]=Iamax;
countmin[imax]=Ibmin;
zero_init=(Iamax+Iamin)>>1;
if(imax==100)
{
	imax=0;
}
}
if(count_mm==0)
{
input1_last=2370;
input2_last=2370;
}

         EvbRegs.T3CNT=0;//从载计数器值EVB
     temp1 = EvaRegs.T2CNT;
     if((temp1-temp2)>=50000)
      {
         temp=65536-temp1+temp2;
         temp = -temp;
	  }//电机(反转)过峰值

      else if((temp2-temp1)>=50000)
      {
         temp=65536-temp2+temp1;
      }

      else if(temp1 >= temp2)
      {
      	temp=temp1-temp2;
      }//电机(正转)
      else
      {
        temp=temp2-temp1;
        temp = -temp;
      }
      temp2 = temp1;
	  speed_now1 = (60*temp)*105;//get the speed use the M method
	  speed_now=speed_now1>>10;//化成弧度    *0.1
  	  PI_Controller(&ASR, Speed_Cal,speed_now, &IsQ_ref); //speed circular
      PieCtrlRegs.PIEACK.bit.ACK4=1;//release the interrupt
      EvbRegs.EVBIMRA.bit.T3PINT=1;
      EvbRegs.EVBIFRA.bit.T3PINT=1;
	  EINT;
}
/*******************************************************************************
Name：void eva_timer1_isr(void)
Function：T1 INTERRUPT
Calculate current, output PWM
*******************************************************************************/
void eva_timer1_isr(void)
{
      extent_temp1=EvaRegs.T2CNT;
      if((extent_temp1-extent_temp2)>=62000)  //
       {
         extent_temp= 65536 - extent_temp1 + extent_temp2; extent_D-= extent_temp;
       }
      else if((extent_temp2-extent_temp1)>=62000) //电机正传
       {
       	 extent_temp= 65536 - extent_temp2 + extent_temp1; extent_D+= extent_temp;
       }
      else if(extent_temp1 >= extent_temp2)  //
       {
         extent_temp= extent_temp1 - extent_temp2; extent_D+= extent_temp;
       }
      else //电机反转
       {
         extent_temp= extent_temp2 - extent_temp1; extent_D-= extent_temp;
       }
      extent_temp2= extent_temp1;
      if(extent_D < 0)
	  {
	     extent_D = 2000 + extent_D;  //保证extent_D不超过4000
	  }
      if(extent_D >2000)
	  {
		 extent_D = extent_D - 2000; //  extent_D = extent_D - 10000;
	  }
	  thita = extent_D * 6291;  //与sin表对应起来0~2000对应0~12288
	  thita = thita>>10;       //
      Iu_result=AdcRegs.ADCRESULT0>>4;//obtain the AD result of the Current
      Iv_result=AdcRegs.ADCRESULT1>>4;
      Isa = Iu_result - zero_init;//Clark and Park
      Isb =Iv_result - zero_init;
      if((Iu_result>100||Iv_result>100)&&(Iu_result<4000||Iv_result<4000))
		Iamax=max(Iu_result);
		Ibmax=max(Iv_result);
		Iamin=min(Iu_result);
		Ibmin=min(Iv_result);

	  Isc=-Isa-Isb;
      IsAlpha = (long)Isa*(long)ThreeDivide2Q14 >> 14;
      IsBeta  = (long)Isa * (long)Sqrt3Divide2Q14 + (long)Isb * (long)Sqrt3Q14 >> 14;
      if(thita<3072) //correspond to the sin and cos table precisely
  	  {
   		SinThita = SinTable[thita];         // 值域 0--3071                 //---------------------------
    	CosThita = SinTable[3071-thita];    // Thita位于第一象限            //  0---0
      }                                                                     //  90---3072
  	  else if(thita<6144)                                                   //  180--6144
  	  {                                                                     //  270--9216
    	SinThita =  SinTable[6143-thita];   // Thita位于第二象限            //  360--12288
    	CosThita = -SinTable[thita-3072];   // 值域 3072--6143              //
  	  }                                                                     //
  	  else if(thita<9216)                                                   //
  	  {                                                                     //
   		SinThita = -SinTable[thita-6144];   // Thita位于礪三象限            //
    	CosThita = -SinTable[9215-thita];   // 值域 6144--9215              //
  	  }                                                                     //
      else //Thita<12288                                                    //
  	  {                                                                     //
    	SinThita = -SinTable[12287-thita];   // Thita位于第四象限           //
    	CosThita =  SinTable[thita-9216];    // 值域 9216--12287            //-----------------------------
  	  }
     IsD =  ((long)IsAlpha * (long)CosThita + (long)IsBeta * (long)SinThita) >> 15;
     IsQ =( -(long)IsAlpha * (long)SinThita + (long)IsBeta * (long)CosThita) >> 15;
     PI_Controller(&ACMR, IsD_ref,IsD, &Ud);//Current circular
     PI_Controller(&ACTR, IsQ_ref,IsQ, &Uq);
     RP_transformation();//
     Thita =thita +Thita_dq ;// + Thita_dq;//Thita+80;
	 if(Thita>=Degree360)// in case of spilling
	 {
	    Thita = Thita-Degree360;
	 }
	 else if(Thita<0)
	 {
	    extent_zero=Thita;
	  	Thita = Thita+Degree360;
	 }
     Svpwm();
     EvaRegs.EVAIMRA.bit.T1UFINT = 1; //下溢中断允许
     EvaRegs.EVAIFRA.bit.T1UFINT = 1; //清除下溢中断标志位
     PieCtrlRegs.PIEACK.all = PIEACK_GROUP2;//响应同组中断
     EINT;//开全局中断
}
/*******************************************************************************
Name：void Svpwm()
Function：Output PWM
*******************************************************************************/
void Svpwm()//SVPWM module
{
     MD=(long)Us_value*(long)4096/(long)ED;// Q12(long)Us_value///////////
     Sector=Thita>>11;// 确定扇区
     Thita_in_sector=Thita%Degree60;
     Sin_value1=SinTable[Thita_in_sector];
     Int_Tmep_value1=Degree60-Thita_in_sector;
     Sin_value2=SinTable[Int_Tmep_value1];
     if(MD>4096)
     {
        MD=4096;
     }
     Tm=(long)MD*(long)Sin_value1  >>15;
     Tl=(long)MD*(long)Sin_value2  >>15;
     Tm=(long)T1_PR*(long)Tm      >>12;//t2   实际为1/2 T2
     Tl=(long)T1_PR*(long)Tl      >>12;//t1
     switch (Sector)
  	 {
    	case  0:
      		TA=T1_PR-Tl-Tm >>1;
      		TB=TA+Tl;
      		TC=TB+Tm;
      		break;
    	case  1:
     		 TB=T1_PR-Tl-Tm >>1;
     		 TA=TB+Tm;
      		TC=TA+Tl;
     		 break;
    	case  2:
     		 TB=T1_PR-Tl-Tm >>1;
     		 TC=TB+Tl;
     		 TA=TC+Tm;
      		break;
   		case  3:
      		TC=T1_PR-Tl-Tm >>1;
      		TB=TC+Tm;
      		TA=TB+Tl;
      		break;
    	case  4:
     		 TC=T1_PR-Tl-Tm >>1;
    		 TA=TC+Tl;
     		 TB=TA+Tm;
    		  break;
    	case  5:
      		TA=T1_PR-Tl-Tm >>1;
      		TC=TA+Tm;
      		TB=TC+Tl;
      		break;
  	 }


if(Isa>=30)
	{
		TA1=TA-20;
	}
	else  if(Isa<-30)
	{
		TA1=TA+20;
	}
	else
	{
		TA1=TA;
	}
	if(Isb>=30)
	{
		TB1=TB-20;
	}
	else  if(Isb<-30)
	{
		TB1=TB+20;
	}
	else
	{
		TB1=TB;
	}
	if(Isc>=30)
	{
		TC1=TC-20;
	}
	else  if(Isc<-30)
	{
		TC1=TC+20;
	}
	else
	{
		TC1=TC;
	}
  	if(TA1>T1_PR)
  	{
  		TA1=T1_PR;
  	}
	else if(TA1<0)
	{
		TA1=0;
	}
	if(TB1>T1_PR)
  	{
  		TB1=T1_PR;
  	}
	else if(TB1<0)
	{
		TB1=0;
	}
	if(TC1>T1_PR)
  	{
  		TC1=T1_PR;
  	}
	else if(TC1<0)
	{
		TC1=0;
	}

    EvaRegs.CMPR1=TA1;
    EvaRegs.CMPR2=TB1;
    EvaRegs.CMPR3=TC1;

}
void Delay()
{
    Uint16 i=0;
	Uint16 j=0;
    for(i=0;i<2000;i++)
	{
		for(j=0;j<100;j++)
		{
			;
	    }
    }
}
void Delays(int m)
{
    Uint16 i=0;
	Uint16 j=0;
    for(i=0;i<1000;i++)
	{
		for(j=0;j<m;j++)
		{
			;
	    }
    }
}
/*******************************************************************************
Name：void init_ev(void)
Function：Initial EV
for timer, capture
*******************************************************************************/
void init_ev(void)
{
   	EvaRegs.T1PR = 5000; //10000
   	EvaRegs.T1CNT = 0;      // Timer1 counter
   	EvaRegs.ACTRA.all  =0x0999; // 999 SV正转, PWM 2 4 6高有效 & pWM 1 3 5低有效;
  	EvaRegs.EVAIMRA.all=0x0200; //EVAIMRA(EVA的中断屏蔽寄存器A).T1PINT(通用定时器1的周期中断使能)
  	EvaRegs.EVAIMRB.all=0x0000;
    EvaRegs.EVAIMRC.all=0x0000;
    EvaRegs.EVAIFRA.all=0xffff;//EVAIFRA(EVA的中断标志寄存器.T1PINT(通用定时器1的周期中断标志)
    EvaRegs.EVAIFRB.all=0xffff;//
    EvaRegs.EVAIFRC.all=0xffff;
    EvaRegs.CMPR1 = 0;
    EvaRegs.CMPR2 = 0;
    EvaRegs.CMPR3 = 0;
    EvaRegs.COMCONA.all = 0x8200;//使能比较操作, 软件法不使能SVPWM模式, T0下溢重载, PWM比较输出使能
    EvaRegs.T1CON.all = 0x0842;//连续增减，一分频， 使能，比较使能,立即重载
    EvaRegs.DBTCONA.all = 0x0FF4;
    //初始计数器2,用于QEP电路计数
    EvaRegs.T2CON.all = 0x1870;//定向增减模式,预定标1,使能,QEP作为时钟源,禁止比较
    EvaRegs.T2CNT = 0x0000;
    EvaRegs.T2PR = 0xffff;

    EvaRegs.CAPCONA.all=0xF0F4;
    EvaRegs.CAPFIFOA.all=0x1000;

    EvbRegs.T3PR= 2344;   //9375是一毫秒
    EvbRegs.T3CNT = 0x0000;
    EvbRegs.T3CON.all=0x1340;    //8分频
}
/*******************************************************************************
名称：void CAPINT3(void)
功能：Capture Interrupt
for error correction
*******************************************************************************/
void CAPINT3(void)
{
	extent_D=1080;
	EvaRegs.EVAIMRC.bit.CAP3INT=1;//捕获中断允许3
	EvaRegs.EVAIFRC.bit.CAP3INT=1;//清楚捕获2中断
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;//响应同组中断
    EINT;//开全局中断
}
/*******************************************************************************
名称：void Init_ADC(void)
功能：AD初始化
参数：void
时间：2013.1.14
版本：1.0
注意：AD初始化 连续级联方式，最简单的方式
*******************************************************************************/
void Init_ADC(void)
{
    AdcRegs.ADCTRL3.bit.ADCBGRFDN = 3;//电源控制
    Delay();
    AdcRegs.ADCTRL3.bit.ADCPWDN = 1;
    Delay();
    AdcRegs.ADCTRL3.bit.SMODE_SEL=0; //连续采样方式配置
    AdcRegs.ADCTRL1.bit.SEQ_CASC=1; //级联绞脚?
    AdcRegs.ADCTRL1.bit.CONT_RUN = 1; //连续运行；
    AdcRegs.ADCTRL1.bit.CPS = 0;//不对HSPCLK分频
    AdcRegs.ADCTRL3.bit.ADCCLKPS = 3; //25MHZ
    AdcRegs.ADCMAXCONV.all = 15;//设置4个变换
    AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0;
    AdcRegs.ADCCHSELSEQ1.bit.CONV01 = 1;
    AdcRegs.ADCCHSELSEQ1.bit.CONV02 = 2;
    AdcRegs.ADCCHSELSEQ1.bit.CONV03 = 3;
    AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1;//
}
/*******************************************************************************
Name：void PI_Controller(TPI * PI, long Geiding, long FeedBack,long * Result)
Function：Initial PI Controller
*******************************************************************************/
long PI_Controller(TPI * PI, long Geiding, long FeedBack,long * Result)
{
   long error;
   long long Temp;
   error = Geiding - FeedBack;

   Temp  = (long)((PI->Ki) *(float) error);   //-----------------
   PI->IntK = Temp + PI->IntK;                 //求积分值
   if(PI->IntK > PI->Saturation)               //-----------------
   {                                           //
     PI->IntK =  PI->Saturation;               // 积
   }                                           // 分
   else if(PI->IntK <-(PI->Saturation) )       // 限
   {
    extent_zero=2;                                   // ?
    PI->IntK = -(PI->Saturation);             //                                          //-----------------
   }

   Temp = (long)(PI->Kp) * (long)error;
   Temp = Temp + PI->IntK;  //proportion plua integral
   if(Temp > PI->Saturation)                   //-----------------
   {                                           //
     Temp =  PI->Saturation;                   //  输
   }                                           //  出
   else if(Temp <-(PI->Saturation) )           //  限
   {
     extent_zero=1;                                        //  幅
     Temp = -(PI->Saturation);                 //
   }                                           //-----------------
   *Result = Temp>>16;
}
/*******************************************************************************
名称：void motor_init(void)
功能：初始定位
参数：无
时间：2013.1.14
版本：1.0
注意：开环通不同US，测试霍尔信号得到
*******************************************************************************/
void motor_init(void)
{
    switch(GpioDataRegs.GPBDAT.all & 0x0700)
    {
		case 0x0300: shan_qu=0; break;
        case 0x0200: shan_qu=1; break;
        case 0x0600: shan_qu=2; break;
        case 0x0400: shan_qu=3; break;
        case 0x0500: shan_qu=4; break;
        case 0x0100: shan_qu=5; break;
		default: motor_OK = 0; break;
    }

	extent_D =333 * shan_qu + 167 ;	//2极对，一圈4000个脉冲，则走180度机械角（2000）度对应电角度360度，一个扇区的对应电角度60度，对应为2000/6=333.33.

}
/*******************************************************************************
名称：void RP_transformation()
功能：初始定位
参数：无
时间：2013.1.14
版本：1.0
注意：
*******************************************************************************/
void RP_transformation()
{
   Us_Tmep_value1=abs(Ud);
   Us_Tmep_value2=abs(Uq);
   if(Ud==0)
   {
    if(Uq==0)
    {
      Us_value=0; //位于坐标原点
      Thita_dq=0;
    }
    else if(Uq>0)
    {
      Us_value=Us_Tmep_value2;  //位于Y轴正半轴
      Thita_dq=Degree90;
    }
    else
    {
      Us_value=Us_Tmep_value2;   //位赮轴负半轴
      Thita_dq=Degree270;
    }
  }
  else if(Ud>0)
  {

    if(Uq==0)
    {
      Us_value=Us_Tmep_value1;    //位于X轴正半轴
      Thita_dq=Degree0;
    }
    else if(Uq>0)
    {
      if(Us_Tmep_value1==Us_Tmep_value2)
      {
        Us_value=(long)Us_Tmep_value2*(long)SQRT2>>10;
        Thita_dq=Degree45;
      }
      else if(Us_Tmep_value1<Us_Tmep_value2)
      {
        TXX=(long)Us_Tmep_value1*2048;//<<11;
        Ud_Tmep_value1=TXX/(long)Us_Tmep_value2;    //45～90之间
        UX_Tmep_value1=(long)Ud_Tmep_value1*(long)Ud_Tmep_value1>>11;
        Us_value=(long)Us_Tmep_value2*(long)SqrtTable[UX_Tmep_value1]>>13;
        //Us_value=Us_value*(long)Int_Tmep_value2;
        Thita_dq=Degree90-ArcTanTable[Ud_Tmep_value1];
      }
      else
      {
       TXX=(long)Us_Tmep_value2*2048;//<<11;
        Uq_Tmep_value2=TXX/(long)Us_Tmep_value1;
        UX_Tmep_value2=(long)Uq_Tmep_value2*(long)Uq_Tmep_value2>>11;
        Us_value=(long)Us_Tmep_value1*(long)SqrtTable[UX_Tmep_value2]>>13;   //位于0～45之间
        Thita_dq=ArcTanTable[Uq_Tmep_value2];
      }
    }
    else
    {
      if(Us_Tmep_value1==Us_Tmep_value2)
      {
        Us_value=(long)Us_Tmep_value2*(long)SQRT2>>10;
        Thita_dq=Degree315;
      }
      else if(Us_Tmep_value1<Us_Tmep_value2)
      {
        TXX=(long)Us_Tmep_value1*2048;
        Ud_Tmep_value1=TXX/(long)Us_Tmep_value2;    //位于270～315之间
		UX_Tmep_value1=(long)Ud_Tmep_value1*(long)Ud_Tmep_value1>>11;
        Us_value=(long)Us_Tmep_value2*(long)SqrtTable[UX_Tmep_value1]>>13;
        Thita_dq=Degree270+ArcTanTable[Ud_Tmep_value1];
      }
      else
      {
        TXX=(long)Us_Tmep_value2*2048;//<<11;
        Uq_Tmep_value2=TXX/(long)Us_Tmep_value1;   //位于315～360之间
		UX_Tmep_value2=(long)Uq_Tmep_value2*(long)Uq_Tmep_value2>>11;
        Us_value=(long)Us_Tmep_value1*(long)SqrtTable[UX_Tmep_value2]>>13;
        Thita_dq=Degree360-ArcTanTable[Uq_Tmep_value2];
      }
    }
  }
  else
  {
    if(Uq==0)
    {
      Us_value=Us_Tmep_value1;    //位于X轴负半轴
      Thita_dq=Degree180;
    }
    else if(Uq>0)
    {
      if(Us_Tmep_value1==Us_Tmep_value2)
      {
        Us_value=(long)Us_Tmep_value2*(long)SQRT2>>10;
        Thita_dq=Degree135;
      }
      else if(Us_Tmep_value1<Us_Tmep_value2)
      {
        TXX=(long)Us_Tmep_value1*2048;//<<11;
        Ud_Tmep_value1=TXX/(long)Us_Tmep_value2;     //位于90～135之间
		UX_Tmep_value1=(long)Ud_Tmep_value1*(long)Ud_Tmep_value1>>11;
        Us_value=(long)Us_Tmep_value2*(long)SqrtTable[UX_Tmep_value1]>>13;
        Thita_dq=Degree90+ArcTanTable[Ud_Tmep_value1];
      }
      else
      {
        TXX=(long)Us_Tmep_value2*2048;//<<11;
        Uq_Tmep_value2=TXX/(long)Us_Tmep_value1;     //位于135～90之间
		UX_Tmep_value2=(long)Uq_Tmep_value2*(long)Uq_Tmep_value2>>11;
        Us_value=(long)Us_Tmep_value1*(long)SqrtTable[UX_Tmep_value2]>>13;
        Thita_dq=Degree180-ArcTanTable[Uq_Tmep_value2];
      }
    }
    else
    {
      if(Us_Tmep_value1==Us_Tmep_value2)
      {
        Us_value=(long)Us_Tmep_value2*(long)SQRT2>>10;
        Thita_dq=Degree225;
      }
      else if(Us_Tmep_value1<Us_Tmep_value2)
      {
        TXX=(long)Us_Tmep_value1*2048;//<<11;
        Ud_Tmep_value1=TXX/(long)Us_Tmep_value2;     //位于225～270之间
		UX_Tmep_value1=(long)Ud_Tmep_value1*(long)Ud_Tmep_value1>>11;
        Us_value=(long)Us_Tmep_value2*(long)SqrtTable[UX_Tmep_value1]>>13;
        Thita_dq=Degree270-ArcTanTable[Ud_Tmep_value1];
      }
      else
      {
        TXX=(long)Us_Tmep_value2*2048;//<<11;
        Uq_Tmep_value2=TXX/(long)Us_Tmep_value1;
        UX_Tmep_value2=(long)Uq_Tmep_value2*(long)Uq_Tmep_value2>>11;
        Us_value=(long)Us_Tmep_value1*(long)SqrtTable[UX_Tmep_value2]>>13; //位于180～225之间
        Thita_dq=Degree180+ArcTanTable[Uq_Tmep_value2];
      }
    }
  }
}
int max(int input1)
{
	if(input1>=input1_last)
	{
		input1_last=input1;
		return input1;
	}
	else
	{
		return input1_last;
	}
}

int min(int input2)
{
	if(input2<=input2_last)
	{
		input2_last=input2;
		return input2;
	}
	else
	{
		return input2_last;
	}
}
