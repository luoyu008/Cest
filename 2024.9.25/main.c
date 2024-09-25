#include <REGX52.H>
#include "LCD1602.h"
#include "ds18b20.h"
float date;
void main(){
	LCD_Init();
	LCD_ShowString(1,1,"Temperature:");
	while(1){
	ds18b20_ConvertT();
		date=ds18b20_ReadT();
		if(date<0){
		LCD_ShowChar(2,1,'-');
		date=-date;
		}
		else{
		LCD_ShowChar(2,1,' ');
		}
		LCD_ShowNum(2,2,date,3);
		LCD_ShowChar(2,5,'.');
		LCD_ShowNum(2,6,((unsigned long)(date*10000))%10000,4);
	}
}