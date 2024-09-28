#include "rekey.h"
#include "time0.h"
#include "smotore.h"
#include "xianshi.h"
unsigned char key;
unsigned char count,count1,count2,temp;
unsigned char speed;
void main(){
	time0_Init();
	while(1){
		key=rekey_return();
		if(key==1){
		speed++;
			speed%=4;
			switch(speed)
			{
				case 0:temp=0;break;
				case 1:temp=30;break;
				case 2:temp=60;break;
				case 3:temp=100;break;
			}
		}
			xianshi_0(1,speed);
	}
}
void time0() interrupt 1{
	TH0=0XFf;
	TL0=0Xa4;
	count++;
	count%=100;
	count1++;
	count2++;
	if(count<=temp){
	smotors_Start();
	}
	else
	{
	smotors_Stop();
	}
	if(count2>=10){
	count2=0;
	rekey_loop();
	}
	if(count1>=20){
	count1=0;
	xianshi_loop();
	}
}