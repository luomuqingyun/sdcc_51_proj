#ifndef _smg_H
#define _smg_H

#include "public.h"


#define SMG_A_DP_PORT	P0	//使用宏定义数码管段码口

//定义数码管位选信号控制脚
#define LSA P2_2
#define LSB P2_3
#define LSC P2_4


void smg_display(u8 dat[],u8 pos);

#endif