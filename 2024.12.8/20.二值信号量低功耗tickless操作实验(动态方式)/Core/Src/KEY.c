#include "KEY.h"
void MYKEY_Init(void){
	//打开GPIOB时钟
	__HAL_RCC_GPIOB_CLK_ENABLE();
	//设置GPIO工作模式
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Mode=GPIO_MODE_INPUT;
	GPIO_InitStruct.Pin=GPIO_PIN_6;
	GPIO_InitStruct.Pull=GPIO_PULLUP;
	GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_InitStruct);
}


uint8_t KEY_return(void){
	uint8_t temp=0;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6)==0){
		HAL_Delay(10);
		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6)==0){
		while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6)==0);
//		HAL_Delay(20);
		temp=1;
		}
	}
	return temp;
}
