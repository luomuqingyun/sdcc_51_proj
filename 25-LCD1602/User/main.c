#include "public.h"
#include "lcd1602.h"


/*******************************************************************************
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
void main()
{	
	lcd1602_init();//LCD1602初始化
	lcd1602_show_string(0,0,"Hello World!");//第一行显示
	lcd1602_show_string(0,1,"0123456789");//第二行显示
	while(1)
	{
		
	}	
}