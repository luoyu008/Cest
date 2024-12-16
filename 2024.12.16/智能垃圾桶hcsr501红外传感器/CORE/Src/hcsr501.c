#include "main.h"
void hcsr501_Init(void){
	__HAL_RCC_GPIOA_CLK_ENABLE();
	//将A0配置为下拉输入
	GPIO_InitTypeDef GPIO_Init;
	GPIO_Init.Mode=GPIO_MODE_INPUT;
	GPIO_Init.Pin=GPIO_PIN_0;
	GPIO_Init.Pull=GPIO_PULLDOWN;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA,&GPIO_Init);
	
}

uint8_t hcsr501_Get(void){
	uint8_t Data=0;
	Data = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);
	return Data;
}
