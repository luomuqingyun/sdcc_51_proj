#ifndef _public_H
#define _public_H

#include "8052.h"

typedef unsigned int u16;	//对系统默认数据类型进行重定义
typedef unsigned char u8;
typedef unsigned long u32;


typedef enum 
{
	DISABLE = 0, ENABLE = !DISABLE
}FunctionalState;


#define _nop_() __asm__("nop")

void delay_10us(u16 ten_us);
void delay_ms(u16 ms);
// void _nop_();

#endif
