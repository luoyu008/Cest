#include "time1.h"
#include "time1.h"
#include "out_interrupt.h"
#include "xianshi.h"
#include "smotore.h"
unsigned char ADD,COM;
unsigned char temp,speed;
void main()
{
	time1_Init();
	out_Init();
	while(1){
	if(out0_getdateflage())
	{
		ADD=out0_returnadd();
		COM=out0_returncom();
		if(COM==0X16){
			speed=0;temp=0;
			xianshi_0(1,0);
		}
		if(COM==0x0c){
		speed=1;temp=20;
			xianshi_0(1,1);
		}
		if(COM==0x18){
		speed=2;temp=60;
			xianshi_0(1,2);
		}
		if(COM==0x5e){
		speed=3;temp=100;
			xianshi_0(1,3);
		}
	}
			
	}
}
void time1() interrupt 3
{
	unsigned char count,count1;
	TH1=0xFf;
	TL1=0Xa4;
	count++;
	count%=100;
	count1++;
	if(count<temp){
		smotors_Start();
	}
	else{
		smotors_Stop();
	}
	if(count1>=20){
		count1=0;
		xianshi_loop();
	}
}
