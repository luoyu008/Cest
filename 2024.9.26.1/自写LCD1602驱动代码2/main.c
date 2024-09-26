#include "delay.h"
#include "LCD1602.h"
void main(){
	LCD1602_Init();
//	LCD1602_ShowChar(1,10,'c');
//	LCD1602_ShowString(2,2,"absdf!");
//	LCD1602_ShowNum(2,10,555,3);
//	LCD1602_BinNum(1,1,28);
//	LCD1602_HexNum(1,11,96);
//	LCD1602_ShowChar(2,13,0xdf);
	LCD1602_ShowChar(2,14,'C');
	LCD1602_ShowString(1,16,"i am the fast man alive in world");
	LCD1602_ShowSignedNum(2,13,-88,2);
	while(1){
	LCD1602_Commend(0x18);
		delay(4);
	}
}