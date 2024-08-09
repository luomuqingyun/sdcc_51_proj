#ifndef _ds1302_H
#define _ds1302_H

#include "public.h"

//管脚定义
#define DS1302_RST    P3_5   //复位管脚
#define DS1302_CLK    P3_6   //时钟管脚
#define DS1302_IO     P3_4   //数据管脚

//变量声明
extern u8 gDS1302_TIME[7];//存储时间

//函数声明
void ds1302_init(void);
void ds1302_read_time(void);


#endif