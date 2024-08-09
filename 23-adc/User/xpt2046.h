#ifndef _xpt2046_H
#define _xpt2046_H

#include "public.h"

//管脚定义
#define DOUT  P3_7	  //输出
#define CLK   P3_6	  //时钟
#define DIN   P3_4	  //输入
#define CS    P3_5	  //片选


//函数声明
u16 xpt2046_read_adc_value(u8 cmd);

#endif