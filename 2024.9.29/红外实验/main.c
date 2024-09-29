#include "LCD1602.h"
#include "delay.h"
#include "out_interrupt.h"
#include "time0.h"
#include <intrins.h>

unsigned char num;
unsigned char ADD,COM;
void main()
{
	out_Init();
	LCD_Init();
	time0_Init();
	LCD_ShowString(1,1,"add");
	LCD_ShowString(1,5,"com");
	LCD_ShowString(1,10,"num");
	LCD_ShowNum(2,1,ADD,3);
	LCD_ShowHexNum(2,5,COM,3);
	LCD_ShowNum(2,10,num,3);
	while(1){
		if(out0_getdateflage()||out0_getrepeatflage()){
				P2=0;
	ADD=out0_returnadd();
	COM=out0_returncom();
			if(COM==0x09)
			{
			num++;
			}
			if(COM==0x15){
			num--;
				}
	LCD_ShowHexNum(2,1,ADD,3);
	LCD_ShowHexNum(2,5,COM,3);
	LCD_ShowNum(2,10,num,3);
	}
}
}
