#include "time0.h"
void time0_Init(){
	TMOD|=0x01;
	TH0=0xFF;
	TL0=0XA4;
	//TF0=0;
	TR0=1;//打开定时器
	ET0=1;//打开定时器0中断允许
	EA=1;//打开总中断
	//PT0=1;
}
//void time0() interrupt 1{
//	static unsigned int count;
//	TH0=0XFC;
//	TL0=0X18;
//	count++;
//	if(count>=100){
//	count=0;
//	second++;
//		if(second==60){
//	minute++;
//			second=0;
//	
//	if(minute==60){
//	hour++;
//		minute=0;
//		second=0;
//	
//	if(hour==24){
//	hour=0;
//	}
//  }
//	}
//	}
//}
