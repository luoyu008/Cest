#include "time0.h"
#include "smotore.h"
void delay(unsigned char num){
	unsigned char i=2,j=199;
	while(num--){
	do{
		while(--j);
	}while(--i);
	}
}
unsigned char count,i,temp;
void main(){
	time0_Init();
	while(1){
		for(i=0;i<100;i++){
			temp=i;
			delay(1);
		}
		for(i=99;i>=0;i--){
			temp=i;
			delay(1);
		}
	}
}
void time0() interrupt 1{
	TH0=0XFf;
	TL0=0Xa4;
	count++;
	count%=100;
	if(count<=temp){
	smotors_Start();
	}
	else
	{
	smotors_Stop();
	}
}