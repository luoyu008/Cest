#include "smotore.h"
#include "xianshi.h"
#include "time0.h"
#include "xpt2046.h"
#include "LCD1602.h"
unsigned char temp;
unsigned char  num1;
void main()
{
	time0_Init();
	while(1){
	num1=xpt2046_ReadByte(0x94);
		xianshi_0(1,num1/100);
		xianshi_0(2,num1/10%10);
		xianshi_0(3,num1%10);
		if(num1>=0&&num1<50){
			temp=0;
		}
		else if(num1>=50&&num1<100){
		temp=30;
		}
		else if(num1>=100&&temp<200){
			temp=60;
		}
		else if(num1>=200&&num1<260){
			temp=100;
		}
	}
}
void time0() interrupt 1{
	static unsigned int count,count1;
	TH0=0XFC;
	TL0=0XA4;
	count++;
	count1++;
	count1%=100;
	if(count>=2){
	count=0;
		xianshi_loop();
	}
	if(count1<temp){
		smotors_Start();
	}
	else
	{
		smotors_Stop();
	}
}