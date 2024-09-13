#ifndef __JUZHEN_H__
#define __JUZHEN_H__
#include "LCD1602.h"
#include "delay.h"
void LCD_WriteCommand(unsigned char Command);
int numlen(unsigned int num);
#endif

int numlen(unsigned int num){
	unsigned char count=0;
	while(num>0){
	num=num/10;
		count++;
	}
	return count;
}
unsigned char retkey(){
	unsigned char key=0;
	P1=0xFF;
	P1_3=0;
	if(P1_7==0){delay(8);while(P1_7==0);delay(8);key=1;}
	if(P1_6==0){delay(8);while(P1_6==0);delay(8);key=5;}
	if(P1_5==0){delay(8);while(P1_5==0);delay(8);key=9;}
	if(P1_4==0){delay(8);while(P1_4==0);delay(8);key=13;}
	P1_2=0;
	if(P1_7==0){delay(8);while(P1_7==0);delay(8);key=2;}
	if(P1_6==0){delay(8);while(P1_6==0);delay(8);key=6;}
	if(P1_5==0){delay(8);while(P1_5==0);delay(8);key=10;}
	if(P1_4==0){delay(8);while(P1_4==0);delay(8);key=14;}
	P1_1=0;
	if(P1_7==0){delay(8);while(P1_7==0);delay(8);key=3;}
	if(P1_6==0){delay(8);while(P1_6==0);delay(8);key=7;}
	if(P1_5==0){delay(8);while(P1_5==0);delay(8);key=11;}
	if(P1_4==0){delay(8);while(P1_4==0);delay(8);key=15;}
	P1_0=0;
	if(P1_7==0){delay(8);while(P1_7==0);delay(8);key=4;}
	if(P1_6==0){delay(8);while(P1_6==0);delay(8);key=8;}
	if(P1_5==0){delay(8);while(P1_5==0);delay(8);key=12;}
	if(P1_4==0){delay(8);while(P1_4==0);delay(8);key=16;}
	return key;
}

//void xianshi(unsigned char rekey,unsigned int* pass,unsigned char* location,unsigned int* my_pass){
//	
//	if(rekey==11){
//	*location=4;
//			LCD_WriteCommand(0x01);
//			LCD_ShowString(1,1,"PassWord:");
//			LCD_ShowString(2,1,"0000");
//			*my_pass=0;
//	}
//	*my_pass=(*my_pass)*10+rekey;
//			LCD_ShowNum(2,*location,*my_pass,numlen(*my_pass));
//			(*location)--;
//	delay(10);
//	}

//void judge(unsigned int pass,unsigned int my_pass,unsigned location){
//	if(my_pass==pass&&location==0){
//			LCD_ShowString(1,11,"ok");
//			}
//			if(my_pass!=pass&&location==0){
//			LCD_ShowString(1,11,"error");
//			}
//			delay(10);
//}