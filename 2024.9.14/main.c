
#include "time0.h"
#include "LCD1602.h"
#include "juzhen.h"
void main(){
	
	unsigned int pass=9527;
	unsigned char location=4;
	unsigned int my_pass=0;
	unsigned char key=0;
	LCD_Init();
	LCD_ShowString(1,1,"PassWord:");
	LCD_ShowString(2,1,"0000");
	time0_Init();
	while(1){
		key=retkey();
		delay(8);
		if(key){
			if(key<=10){
				if(location>0){
			my_pass=(my_pass)*10+key%10;
			LCD_ShowNum(2,location,my_pass,numlen(my_pass));
			(location)--;
				}
			}
			if(key==11){
			location=4;
			LCD_WriteCommand(0x01);
			LCD_ShowString(1,1,"PassWord:");
			LCD_ShowString(2,1,"0000");
			my_pass=0;
			}
			delay(5);
			if(my_pass==pass&&location==0){
			LCD_ShowString(1,11,"ok");
			}
			if(my_pass!=pass&&location==0){
			LCD_ShowString(1,11,"error");
			}
		}
	}
}

void time0() interrupt 1{
	static unsigned int count;
	TH0=0XFC;
		TL0=0X18;
	count++;
	if(count==1000){
		count=0;
		P2_0=~P2_0;
	}
}