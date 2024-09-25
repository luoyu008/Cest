#include "LCD1602.h"
#include "ds18b20.h"
#include "time0.h"
#include "rekey.h"
#include "at24c02.h"
#include "delay.h"
float date;
char HT;//上限温度
char LT;//下限温度
unsigned char HT1;
unsigned char LT1;
unsigned char key;
int temp;
void main(){
	ds18b20_ConvertT();
	delay(1000);
	HT=at24c02_Readbyte(0);
	LT=at24c02_Readbyte(1);
	if(HT>125||LT<-55||HT<LT){
	HT=30;
	LT=10;
	}
	time0_Init();
	LCD_Init();
	while(1){
		//温度显示
	ds18b20_ConvertT();
	date=ds18b20_ReadT();
		if(date<0){
		LCD_ShowChar(1,1,'-');
		date=-date;
		}
		else{
		LCD_ShowChar(1,1,' ');
		}
		LCD_ShowNum(1,2,date,3);
		delay(10);
		LCD_ShowChar(1,5,'.');
		LCD_ShowNum(1,6,((unsigned long)(date*100))%100,2);
		temp=(int)date;
//		if(temp<0){
//		LCD_ShowChar(1,10,'-');
//		LCD_ShowNum(1,11,-temp,3);
//		}else
//		LCD_ShowNum(1,11,temp,3);
		//报警显示
		if(temp>HT)
		{
			LCD_ShowString(2,10,"WARNING");
			delay(5);
		}
		else if(temp<LT){
			LCD_ShowString(2,10,"WARNING");
			delay(5);
		}
		else
		{
			LCD_ShowString(2,10,"       ");
			delay(5);
		}
		//按键提取
		key=rekey_return();
		if(key){
		if(key==1)
		{
			HT++;
			if(HT>125){HT=125;}
		}
		if(key==2){
			HT--;
			if(HT<LT){HT++;}
		}
		if(key==3){
			LT++;
			if(LT>HT){LT--;}
		}
		if(key==4){
			LT--;
			if(LT<-55){LT=-55;}
		}
		at24c02_Writebyte(0,HT);
			delay(500);
			at24c02_Writebyte(1,LT);
			delay(500);
		}
		if(HT>0){
		LCD_ShowChar(2,1,' ');
		HT1=HT;
		}
		else 
		{
		LCD_ShowChar(2,1,'-');
		HT1=-HT;
		}
		if(LT>=0){
		LCD_ShowChar(2,5,' ');
			LT1=LT;
		}
		else
		{
			LCD_ShowChar(2,5,'-');
			LT1=-LT;
		}
		LCD_ShowNum(2,2,HT1,3);
		LCD_ShowNum(2,6,LT1,3);
			
	}
}

void time0() interrupt 1
{
	unsigned int count;
	TH0=0XFC;
	TL0=0X18;
	count++;
	if(count>=20){
	count=0;
	rekey_loop();
	}
}