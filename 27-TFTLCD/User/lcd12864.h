#ifndef _lcd12864_H
#define _lcd12864_H

#include "public.h"

//管脚定义
#define LCD12864_RS  P2_6   //数据命令选择
#define LCD12864_WR  P2_5   //读写选择
#define LCD12864_E   P2_7    //使能信号

#define LCD12864_DATAPORT	P0	//LCD12864数据端口定义
#define LCD12864_PSB P3_2       //8位或4并口/串口选择

//函数声明
void lcd12864_init(void);
void lcd12864_clear(void);
void lcd12864_show_string(u8 x,u8 y,u8 *str);
#endif
