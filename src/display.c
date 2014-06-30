
#include "DSP281x_Device.h"     // DSP281x Headerfile Include File

#include "DSP281x_Examples.h"   // DSP281x Examples Include File


#define Initclkoport  GpioMuxRegs.GPBDIR.bit.GPIOB11=1//Initial clk as output port
#define Setclkhigh    GpioDataRegs.GPBSET.bit.GPIOB11=1

#define Setclklow     GpioDataRegs.GPBCLEAR.bit.GPIOB11=1
#define Setdatiport   GpioMuxRegs.GPDDIR.bit.GPIOD6=0//Initial clk as input port
#define Setdatoport   GpioMuxRegs.GPDDIR.bit.GPIOD6=1//Initial clk as output port
#define Readdat       GpioDataRegs.GPDDAT.bit.GPIOD6
#define Setdathigh    GpioDataRegs.GPDSET.bit.GPIOD6=1
#define Setdatlow     GpioDataRegs.GPDCLEAR.bit.GPIOD6=1


void BC7281SendByte(unsigned char);
void Delay(unsigned char);
void LedLetterDisplay(unsigned char addr,unsigned char letter);

void ClearLedDisplay();
void BC7281Flash(unsigned char addr);
void BC7281Write(unsigned char reg_add, unsigned char write_data);
unsigned char AddressChange(unsigned char addr);
// int a=0,b=0,c=0,d=0;
long int count=0;
//初始化函数
//初始化程序,将CLK和DAT均置为数字IO，将CLK置为输出高，DAT置为输入
void BC7281Init(void)
{
	EALLOW;
	Initclkoport;
    Setdatiport;
	EDIS;
    Setclkhigh;
	//ClearLedDisplay();
	//Delay(1000);
    BC7281Write(0x12,0x80);// Initial BC728x to 164Mode
    BC7281Write(0x10,0xFF);
    BC7281Write(0x15,0x10);
	BC7281Write(0x15,0x00);
    BC7281Write(0x15,0x20);
	BC7281Write(0x15,0x30);

}
void Delay(unsigned char delay_time)
{
	unsigned char temp;
	for(temp = 0; temp < (delay_time*20 ); temp++)
	{
		asm("	nop");	asm("	nop");	asm("	nop");	asm("	nop");	asm("	nop");
	}
}

//写函数
// ***********************************************************
// * 写入BC728X, 第一个参数为目标寄存器地址, 第二个参数为要写入的数据 *
// ***********************************************************

void BC7281Write(unsigned char reg_add, unsigned char write_data)
{
	//Delay(1000);
	BC7281SendByte(reg_add);		// 发送寄存器地址
//	Delay(1000);
	BC7281SendByte(write_data);		// 发送数据字节
}
//发送一个字节
void BC7281SendByte(unsigned char send_byte)
{
	unsigned char temp,bit_counter;
	EALLOW;
	Setdatiport;
	EDIS;
	Setclklow;//set CLK to output high

	Delay(50);				;//delay 1us
	Setclkhigh;//set CLK to output low

	Delay(50);
//	Setclkhigh;
//	Delay(1);
    do
	{

		temp = Readdat		;   //read DAT  value
	}
	while(temp);//一直等到DAT为低，CLK间隔为1uS
	//重发一组时钟信号,等待DAT重新被拉高
	Setclklow;//set CLK to output low
	//*PEDATDIR = *PEDATDIR & 0x0fffb	; //set CLK to output low
	Delay(5);			;//delay 1us
	Setclkhigh;
	//*PEDATDIR = *PEDATDIR | 0x0404	;// set CLK to output high
	Delay(5);
	temp=0;
	while(temp==0)
	{

		temp =  Readdat 		; //read DAT  value
	}//received the echo DAT value
	//DAT置成输出
	EALLOW;
	Setdatoport;
	EDIS;
//	Setdathigh;
	Delay(5);
	//*PEDATDIR = *PEDATDIR | 0x0808		; //set DAT to output high
	//发送8位数据,CLK间隔20uS
	for(bit_counter = 0; bit_counter < 8; bit_counter++)
	//send 8 bits
	{
		if((send_byte & 0x80) ==0)
		{//dat = 0
			Setdatlow;
			Delay(5);
			//*PEDATDIR = *PEDATDIR & 0x0fff7	; //set DAT to output low
			}
		else //dat = 1
		{
			Setdathigh;
			Delay(5);
			//*PEDATDIR = *PEDATDIR | 0x0808	; //set DAT to output high
		}
		send_byte=send_byte*2;	// send_byte 左移一位
		Setclklow;
		//*PEDATDIR = *PEDATDIR & 0x0fffb	; //set CLK to output low
		Delay(25);			//delay 10us
		Setclkhigh;
		//*PEDATDIR = *PEDATDIR | 0x0404	; //set CLK to output high
		Delay(75);			//delay 10us
	}
	Setdathigh;
	//*PEDATDIR = *PEDATDIR | 0x0808	; //set DAT to output high

	//*PEDATDIR = *PEDATDIR & 0x0f7ff	; //set IOPE3 to input IO
	Delay(5);
}

void DISPLAYexample()
{
  BC7281Init();

}





//某一个数码管闪烁,addr为0-f的地址
void BC7281Flash(unsigned char addr)
{
	addr=AddressChange(addr);
	if(addr >= 8)
	{
		addr = ~(addr - 8);
		BC7281Write(0x19, addr);
	}
	else
	{
		BC7281Write(0x10, addr);
	}
}
void BC7281FlashSpeed(speed)
{
	BC7281Write(0x11,speed);
}
//显示从0-f的各个数码管的小数点，如果status为1，则表示熄灭，否则表示点亮
void BC7281DotDisplay(unsigned char addr, unsigned char status)
{
	unsigned char addr1;
	addr1=AddressChange(addr);
	addr1 = 0x07 +  (addr1<<3);
	if(status == 0) BC7281Write(0x18,addr1);
	else			BC7281Write(0x18,0x80+addr1);
}


void BC7281LetterDisplay(unsigned char addr, unsigned char letter)
{
 unsigned char addr1;
 addr1=addr<<4;
switch(letter)
 {

 case 'A' : BC7281Write(0x15,addr1+0x0a);break;
 case 'B' : BC7281Write(0x15,addr1+0x0b);break;
 case 'C' : BC7281Write(0x15,addr1+0x0c);break;
 case 'D' : BC7281Write(0x15,addr1+0x0d);break;
 case 'E' : BC7281Write(0x15,addr1+0x0e);break;
 case 'F' : BC7281Write(0x15,addr1+0x0f);break;
 case '-' : BC7281Write(0x14,addr1+0x0a);break;
 case 'H' : BC7281Write(0x14,addr1+0x0c);break;
 case 'L' : BC7281Write(0x14,addr1+0x0d);break;
 case 'P' : BC7281Write(0x14,addr1+0x0e);break;
 case ' ' : BC7281Write(0x14,addr1+0x0f);break;
 case '0' : BC7281Write(0x15,addr1+0x00);break;
 case '1' : BC7281Write(0x15,addr1+0x01);break;
 case '2' : BC7281Write(0x15,addr1+0x02);break;
 case '3' : BC7281Write(0x15,addr1+0x03);break;
 case '4' : BC7281Write(0x15,addr1+0x04);break;
 case '5' : BC7281Write(0x15,addr1+0x05);break;
 case '6' : BC7281Write(0x15,addr1+0x06);break;
 case '7' : BC7281Write(0x15,addr1+0x07);break;
 case '8' : BC7281Write(0x15,addr1+0x08);break;
 case '9' : BC7281Write(0x15,addr1+0x09);break;
 default  :break;
 }



}

//The led positions of premax display v2 board are not in order,so it's address
//must be changed.
unsigned char AddressChange(unsigned char addr)
{

  switch(addr)
    {
    case 0:return(3);
    case 1:return(2);
    case 2:return(1);
    case 3:return(0);
    case 4:return(7);
    case 5:return(6);
    case 6:return(5);
    case 7:return(4);


    }

}

void LedLetterDisplay(unsigned char addr,unsigned char letter)
{
unsigned char addr1;
 addr1=AddressChange(addr);
 BC7281LetterDisplay(addr1,letter);

}

void LedStringDisplay(unsigned char* displaystring)
{
 unsigned char letter;
 int i,l,t=0;
 for(i=0;;i++)
  {letter=displaystring[i];
   if ((letter=='\000')&&((3-i+t)<0)||(letter=='\000'))
   {break;}
   if (letter=='.')
   {l=i-t-1;
    BC7281DotDisplay(3-l,0);
    t++;
	}
   else LedLetterDisplay(3-i+t,letter);
  }
 }

void ClearLedDisplay()
{
  	BC7281Write(0x14,0x0f);
	BC7281Write(0x14,0x1f);
    BC7281Write(0x14,0x2f);
	BC7281Write(0x14,0x3f);
	BC7281Write(0x14,0x4f);
	BC7281Write(0x14,0x5f);
	BC7281Write(0x14,0x6f);
	BC7281Write(0x14,0x7f);
}

void ClearDotDisplay()
{
    BC7281Write(0x18,0x87);
	BC7281Write(0x18,0x8f);
	BC7281Write(0x18,0x97);
	BC7281Write(0x18,0x9f);
	BC7281Write(0x18,0xa7);
	BC7281Write(0x18,0xaf);
	BC7281Write(0x18,0xb7);
	BC7281Write(0x18,0xbf);
}

