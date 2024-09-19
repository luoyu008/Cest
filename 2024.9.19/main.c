#include <REGX52.H>
#include "time0.h"
void delay(unsigned int num){
while(num--);
}
unsigned char temp;
void main(){
	time0_Init();
 while(1){
 if(temp==1){
 P2_5=1;
	 //delay(100);
 }
 else
 {
 P2_5=0;
	 //delay(10);
 }
 }
}

void time0() interrupt 1{
	static unsigned int count;
	TH0=0xFC;
	TL0=0X18;
	count++;
	if(count==100){
	count=0;
		temp=!temp;
	}
	}