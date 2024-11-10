#include "KEY.h"
void MYKEY_Init(void){
	//打开GPIOB时钟
	__HAL_RCC_GPIOA_CLK_ENABLE();
	//设置GPIO工作模式
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Mode=GPIO_MODE_INPUT;
	GPIO_InitStruct.Pin=GPIO_PIN_1;
	GPIO_InitStruct.Pull=GPIO_PULLDOWN;
	GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);
}


uint8_t KEY_return(void){
	uint8_t temp;
	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==1){
		HAL_Delay(10);
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==1){
		while(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==1);
//		HAL_Delay(20);
		temp=1;
		}
	}
	return temp;
}
