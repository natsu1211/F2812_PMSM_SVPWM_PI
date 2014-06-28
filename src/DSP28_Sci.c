

#include "DSP28_Device.h"

void InitSci(void)
{
	ScibRegs.SCICCR.all = 0x07;	
	//8位数据位，空闲线模式，禁止会送测试模式，无奇偶校验，1位结束位 
	
	ScibRegs.SCICTL1.all = 0x03; 
	//SCIA发送器和接收器使能 
	
	ScibRegs.SCICTL2.all = 0x00; //暂时不使能
	//接收器缓冲/中断使能，SCITXBUF寄存器中断使能
	
	ScibRegs.SCIHBAUD = 0x01;
	ScibRegs.SCILBAUD = 0xe7;
	//波特率为9600
	
	ScibRegs.SCICTL1.all = 0x23;
	//重启SCI

		SciaRegs.SCICCR.all = 0x07;	
	//8位数据位，空闲线模式，禁止会送测试模式，无奇偶校验，1位结束位 
	
	SciaRegs.SCICTL1.all = 0x03; 
	//SCIA发送器和接收器使能 
	
	SciaRegs.SCICTL2.all = 0x00; //暂时不使能
	//接收器缓冲/中断使能，SCITXBUF寄存器中断使能
	
	SciaRegs.SCIHBAUD = 0x01;
	SciaRegs.SCILBAUD = 0xe7;
	//波特率为9600
	
	SciaRegs.SCICTL1.all = 0x23;
//	PieCtrl.PIEIER9.bit.INTx3 = 1;
//	PieCtrl.PIEIER9.bit.INTx4 = 1;
	//SCIA的接收和发送中断分别位于GPIO第9组的第1和第2位，使能SCIA的PIE中断
 	

	// 如果需要使用SCIB，复制上面的代码，将SCIA相应的改成SCIB就可以

	

	
}

/********************************************************************************
	name:	int SciaTx_Ready(void)
	input:	none
	output:	i	1:	ready
			0:	busy
*********************************************************************************/

int ScibTx_Ready(void)
{
	unsigned int i;
	if(ScibRegs.SCICTL2.bit.TXRDY == 1)
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
	return(i);
}

/********************************************************************************
	name:	int SciaRx_Ready(void)
	input:	none
	output:	i	1:	new data
			0:	none
*********************************************************************************/

int ScibRx_Ready(void)
{
	unsigned int i;
	if(ScibRegs.SCIRXST.bit.RXRDY == 1)
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
	return(i);
}

void sci_tx(int tx_data)
{
	if(ScibTx_Ready()==1)
	{
		ScibRegs.SCITXBUF=tx_data;	
	}
}
	
//===========================================================================
// No more.
//===========================================================================
