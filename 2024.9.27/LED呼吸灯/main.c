//#include "delay.h"
#include "blight.h"
#include <intrins.h>
#include "time0.h"
//#include "rekey.h"
void main(){
	time0_Init();
	while(1){
		blight();
	}
}
void time0() interrupt 1
{
	unsigned char count=0;
	TH0=0XFC;
	TL0=0X18;	
	count++;
	if(count>=10){
	count=0;
	blight();
	}
}