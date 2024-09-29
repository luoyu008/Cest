#include "time0.h"
void time0_Init(){
	TMOD &= 0xF0;
	TMOD|=0x01;
	TH0=0;
	TL0=0;
	TF0=0;
	TR0=0;
}
void time0_con(unsigned char flag){//控制定时器0的启动
	TR0=flag;
}
void time0_set(unsigned int num){//定时器0设置
	TH0=num/256;
	TL0=num%256;
}
unsigned int time0_return()//返回定时器走了多少数字
{
	return (TH0<<8)|TL0;
}