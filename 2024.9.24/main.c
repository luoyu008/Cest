#include <REGX52.H>
#include "delay.h"
#include "LCD1602.h"
#include "rekey.h"
#include "at24c02.h"
#include "iic.h"
#include "xianshi.h"
unsigned int date;
unsigned char num1,num2;
unsigned char key;
void main(){
	LCD_Init();
	LCD_ShowNum(1,1,date,5);
	while(1){
		key=rekey();
		if(key==1){
		date++;
			delay(1);
		LCD_ShowNum(1,1,date,5);
		}
		if(key==2){
		date--;
			delay(1);
			LCD_ShowNum(1,1,date,5);
		}
		if(key==3){
		at24c02_Writebyte(0,date/256);
			delay(5);
			at24c02_Writebyte(1,date%256);
			delay(5);
			LCD_ShowString(2,1,"write ok");
			delay(30);
			LCD_ShowString(2,1,"        ");
		}
		if(key==4){
		num1=at24c02_Readbyte(0);
		num2=at24c02_Readbyte(1);
		date=num1*256+num2;
		LCD_ShowNum(1,1,date,5);
		LCD_ShowString(2,1,"read ok");
		delay(30);
		LCD_ShowString(2,1,"       ");
		}
	}
}