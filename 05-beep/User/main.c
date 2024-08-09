#include "8052.h"

typedef unsigned int u16;	//对系统默认数据类型进行重定义
typedef unsigned char u8;

#define BEEP  P2_5 //将P2.5管脚定义为BEEP


/*******************************************************************************
* 函 数 名       : delay_10us
* 函数功能		 : 延时函数，ten_us=1时，大约延时10us
* 输    入       : ten_us
* 输    出    	 : 无
*******************************************************************************/
void delay_10us(u16 ten_us)
{
	while(ten_us--);	
}

/*******************************************************************************
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
void main()
{	
	u16 i=2000;

	while(1)
	{
	   	while(i--)//循环2000次
		{
			BEEP=!BEEP;//产生一定频率的脉冲信号
			delay_10us(100);
		}
		i=0;//清零
		BEEP=0;//关闭蜂鸣器
	}		
}
