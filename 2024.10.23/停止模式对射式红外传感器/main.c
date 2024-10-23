#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "Tbsensor.h"
uint8_t Date;
int main()
{	
	OLED_Init();
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);
	Tbsensor_Init(GPIOB,14);
	while(1){
	OLED_ShowNum(1,1,Tbsensor_retrrn(),5);
	OLED_ShowString(2,1,"Running");
	Delay_ms(500);
	OLED_ShowString(2,1,"       ");
	Delay_ms(500);
	PWR_EnterSTOPMode(PWR_Regulator_ON,PWR_STOPEntry_WFI);
	SystemInit();
	}

}

