#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "W25Q64ruanjian.h"
uint8_t MID;
uint16_t ID;
uint8_t DataWrite[]={0xaa,0x66,0x77,0x88};
uint8_t DataRead[]={0,0,0,0};
int main()
{	
	OLED_Init();
	W25Q64yingjian_Init();
	W25Q64yingjian_ReadID(&MID,&ID);
	W25Q64yingjian_SectorErase(0x000000);
	W25Q64yingjian_WritePage(0x0000000,DataWrite,4);
	W25Q64yingjian_ReadData(0x000000,DataRead,4);
	while(1){
	OLED_ShowString(1,1,"MID:");
	OLED_ShowHexNum(1,5,MID,2);
	OLED_ShowString(1,8,"ID:");
	OLED_ShowHexNum(1,11,ID,4);
	OLED_ShowString(2,1,"W:");
	OLED_ShowHexNum(2,3,DataWrite[0],2);
	OLED_ShowHexNum(2,5,DataWrite[1],2);
	OLED_ShowHexNum(2,7,DataWrite[2],2);
	OLED_ShowHexNum(2,9,DataWrite[3],2);
	OLED_ShowString(3,1,"R:");
	OLED_ShowHexNum(3,3,DataRead[0],2);
	OLED_ShowHexNum(3,5,DataRead[1],2);
	OLED_ShowHexNum(3,7,DataRead[2],2);
	OLED_ShowHexNum(3,9,DataRead[3],2);
	}
}
