#include "main.h"
#include "42Motor.h"
void Motoe_42Init(void){
	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	GPIO_InitTypeDef GPIO_Init;
	GPIO_Init.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pin=PUL_Signal;
	GPIO_Init.Pull=GPIO_NOPULL;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA,&GPIO_Init);
	
	GPIO_Init.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pin=ENABLE_Signal;
	GPIO_Init.Pull=GPIO_NOPULL;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA,&GPIO_Init);
	
	GPIO_Init.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pin=DIR_Signal;
	GPIO_Init.Pull=GPIO_NOPULL;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA,&GPIO_Init);
}

void Motor_42_W_ENABLE(uint8_t en){
	HAL_GPIO_WritePin(GPIOA,ENABLE_Signal,(GPIO_PinState)en);
}

void Motor_42_W_DIR(uint8_t en){
	HAL_GPIO_WritePin(GPIOA,DIR_Signal,(GPIO_PinState)en);
}

