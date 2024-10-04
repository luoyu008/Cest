#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Tbsensor.h"

int main()
{	
	OLED_Init();
	OLED_Clear();
	Tbsensor_Init(GPIOB,14);
	while(1){
		OLED_ShowNum(1,1,Tbsensor_retrrn(),5);
	}
}
