#include "time0.h"
void time0_Init(){
	TMOD|=0x01;
	TH0=0xFF;
	TL0=0XA4;
	//TF0=0;
	TR0=1;//�򿪶�ʱ��
	ET0=1;//�򿪶�ʱ��0�ж�����
	EA=1;//�����ж�
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
