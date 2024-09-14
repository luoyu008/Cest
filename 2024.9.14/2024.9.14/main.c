#include "LCD1602.h"
#include <REGX52.H>
#include "time0.h"
#include <intrins.h>
#include "rekey.h"
//实现时钟
unsigned char second;
unsigned char minute;
unsigned char hour;
void main(){
	LCD_Init();
	LCD_ShowString(1,1,"Clock:");
	LCD_ShowString(2,1,"00:00:00");
	time0_Init();
	while(1){
	LCD_ShowNum(2,1,hour,2);
	LCD_ShowChar(2,3,':');
	LCD_ShowNum(2,4,minute,2);
	LCD_ShowChar(2,6,':');
	LCD_ShowNum(2,7,second,2);
	}
}

void time0() interrupt 1{
	static unsigned int count;
	TH0=0XFC;
	TL0=0X18;
	count++;
	if(count>=100){
	count=0;
	second++;
		if(second==60){
	minute++;
			second=0;
	
	if(minute==60){
	hour++;
		minute=0;
		second=0;
	
	if(hour==24){
	hour=0;
	}
  }
	}
	}
}
////按键实现流水灯
//	unsigned char key,keynum;
//void main(){
//	P2=0xFE;
//	time0_Init();
//	while(1){
//		key=rekey();
//	if(key){
//	  keynum++;
//		if(keynum>=2){
//		keynum=0;
//		}
//	}
//	}
//}
//void time0() interrupt 1{
//	static unsigned int count;
//	TH0=0XFC;
//	TL0=0X18;
//	count++;
//	if(count>=500){
//	count=0;
//	if(keynum==0){
//	P2=_crol_(P2,1);
//	}
//	if(keynum==1){
//	P2=_cror_(P2,1);
//	}
//	}
//}