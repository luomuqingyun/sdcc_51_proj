#include "public.h"
#include "smg.h"
#include "ired.h"


/*******************************************************************************
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
void main()
{	
	u8 ired_buf[3];

	ired_init();//红外初始化

	while(1)
	{				
		ired_buf[0]=gsmg_code[gired_data[2]/16];//将控制码高4位转换为数码管段码
		ired_buf[1]=gsmg_code[gired_data[2]%16];//将控制码低4位转换为数码管段码
		ired_buf[2]=0X76;//显示H的段码
		smg_display(ired_buf,6);	
	}		
}