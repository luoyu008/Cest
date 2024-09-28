#include "LCD1602.h"
#include "xpt2046.h"
unsigned int num1,num2,num3;
void main(){
	LCD_Init();
	LCD_ShowString(1,1,"AD1");
	LCD_ShowString(1,5,"NTC1");
	LCD_ShowString(1,10,"GR1");
	
	while(1){
	num1=xpt2046_ReadByte(0x94);
	num2=xpt2046_ReadByte(0xD4);
	num3=xpt2046_ReadByte(0xA4);
	LCD_ShowNum(2,1,num1,3);
	LCD_ShowNum(2,5,num2,3);
	LCD_ShowNum(2,10,num3,3);
	}
	
}