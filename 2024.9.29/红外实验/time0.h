#ifndef __TIME0_H__
#define __TIME0_H__
#include <REGX52.H>
void time0_Init();
void time0_con(unsigned char flag);//控制定时器0的启动

void time0_set(unsigned int num);//定时器0设置

unsigned int time0_return();//返回定时器走了多少数字

#endif