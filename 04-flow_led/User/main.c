#include "8052.h"

typedef unsigned int u16;	//对系统默认数据类型进行重定义
typedef unsigned char u8;


#define LED_PORT	P2	//使用宏定义P2端口


u8 rotate_right(u8 value, u8 shift) {
    return (value >> shift) | (value << (8 - shift));
}

u8 rotate_left(u8 value, u8 shift) {
    return (value << shift) | (value >> (8 - shift));
}

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
   	u8 i=0;

	LED_PORT=~0x01;
	delay_10us(50000);
	while(1)
	{
		//方法1：使用移位+循环实现流水灯
//		for(i=0;i<8;i++)
//		{
//			LED_PORT=~(0x01<<i);	//将1右移i位，然后取反将结果赋值到LED_PORT
//			delay_10us(50000);
//		}
		
		//方法2：使用循环+_crol_或_cror_函数实现流水灯
		for(i=0;i<7;i++)	 //将led左移一位
		{									  
			LED_PORT=rotate_left(LED_PORT,1);
			delay_10us(50000); 	
		}
		for(i=0;i<7;i++)	//将led右移一位
		{
			LED_PORT=rotate_right(LED_PORT,1);
			delay_10us(50000);	
		}	
	}		
}