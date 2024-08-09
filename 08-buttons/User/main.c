#include "8052.h"

typedef unsigned int u16;	//对系统默认数据类型进行重定义
typedef unsigned char u8;

#define LED1 P2_0 //将P2.0管脚定义为LED1

//定义独立按键控制脚
#define KEY1 P3_1
#define KEY2 P3_0
#define KEY3 P3_2
#define KEY4 P3_3


//使用宏定义独立按键按下的键值
#define KEY1_PRESS	1
#define KEY2_PRESS	2
#define KEY3_PRESS	3
#define KEY4_PRESS	4
#define KEY_UNPRESS	0	

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
* 函 数 名       : key_scan
* 函数功能		 : 检测独立按键是否按下，按下则返回对应键值
* 输    入       : mode=0：单次扫描按键
				   mode=1：连续扫描按键
* 输    出    	 : KEY1_PRESS：K1按下
				   KEY2_PRESS：K2按下
				   KEY3_PRESS：K3按下
				   KEY4_PRESS：K4按下
				   KEY_UNPRESS：未有按键按下
*******************************************************************************/
u8 key_scan(u8 mode)
{
	static u8 key=1;

	if(mode)key=1;//连续扫描按键
	if(key==1&&(KEY1==0||KEY2==0||KEY3==0||KEY4==0))//任意按键按下
	{
		delay_10us(1000);//消抖
		key=0;
		if(KEY1==0)
			return KEY1_PRESS;
		else if(KEY2==0)
			return KEY2_PRESS;
		else if(KEY3==0)
			return KEY3_PRESS;
		else if(KEY4==0)
			return KEY4_PRESS;	
	}
	else if(KEY1==1&&KEY2==1&&KEY3==1&&KEY4==1)	//无按键按下
	{
		key=1;			
	}
	return KEY_UNPRESS;		
}
/*******************************************************************************
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
void main()
{	
	u8 key=0;

	while(1)
	{
	   	key=key_scan(0);
		if(key==KEY1_PRESS)//检测按键K1是否按下
			LED1=!LED1;//LED1状态翻转	
	}		
}
