#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "KEY.h"
uint8_t key;
uint16_t num1,num2;
int main()
{	
	OLED_Init();
	KEY_Init(GPIOB,1);
	//打开PWR和BKP时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);
	//设置PWR_CR的DBP位，使能对BKP和RTC的访问
	PWR_BackupAccessCmd(ENABLE);
	

	num1=0x1245;
	num2=0x2356;
	BKP_WriteBackupRegister(BKP_DR2,num1);
	BKP_WriteBackupRegister(BKP_DR3,num2);
	while(1){
	if(KEY_GET(GPIOB,1)){
		num1++;
		num2++;
	BKP_WriteBackupRegister(BKP_DR2,num1);
	BKP_WriteBackupRegister(BKP_DR3,num2);
	}
	OLED_ShowHexNum(1,1,num1,4);
	OLED_ShowHexNum(1,8,num2,4);
	OLED_ShowHexNum(2,1,BKP_ReadBackupRegister(BKP_DR2),4);
	OLED_ShowHexNum(2,8,BKP_ReadBackupRegister(BKP_DR3),4);
	}
}
