#include "delay.h"
#include "xianshi.h"
#include "smotore.h"
#include "time0.h"
unsigned int count;
unsigned char temp,speed;
void main(){
	uart_Init();
	time0_Init();
	while(1){
		xianshi_0(1,temp);
		if(temp==0){
			speed=0;
		}
		if(temp==1){
			speed=20;
		}
		if(temp==2){
			speed=50;
		}
		if(temp==3){
			speed=100;
		}
	}
}
void time0() interrupt 1{
	static unsigned int count,count1;
	TH0=0XFf;
	TL0=0Xa4;
	count++;
	count%=100;
	count1++;
	if(count<speed){
		smotors_Start();
	}
	else
	{
		smotors_Stop();
	}
	if(count1>=20){
		count1=0;
		xianshi_loop();
	}
}

void uartaccept() interrupt 4{
	unsigned char date=0;
	if(RI==1){
	RI=0;
	date=SBUF;
	temp=date;
	}
	}