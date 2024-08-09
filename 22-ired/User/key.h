#ifndef _key_H
#define _key_H

#include "public.h"

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


u8 key_scan(u8 mode);

#endif