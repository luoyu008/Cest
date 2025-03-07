#include "main.h"
#include "42Motor.h"
TIM_HandleTypeDef	TIM2_HandInit;
TIM_OC_InitTypeDef	TIM2_OCHandInit;
uint8_t count1;
void Motoe_42Init(void){
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_TIM2_CLK_ENABLE();
	
	
//	TIM2_HandInit.Instance=TIM2;
//	TIM2_HandInit.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
//	TIM2_HandInit.Init.CounterMode=TIM_COUNTERMODE_UP;
//	TIM2_HandInit.Init.Period=100-1;
//	TIM2_HandInit.Init.Prescaler=360-1;
//	HAL_TIM_PWM_Init(&TIM2_HandInit);
//	
//	HAL_NVIC_SetPriority(TIM2_IRQn,0,0);
//	HAL_NVIC_EnableIRQ(TIM2_IRQn);
//	
//	TIM2_OCHandInit.OCMode=TIM_OCMODE_PWM1;
//	TIM2_OCHandInit.OCPolarity=TIM_OCPOLARITY_HIGH;
//	TIM2_OCHandInit.Pulse=50;
//	HAL_TIM_PWM_ConfigChannel(&TIM2_HandInit,&TIM2_OCHandInit,TIM_CHANNEL_2);
	
//	GPIO_InitTypeDef GPIO_Init;
//	GPIO_Init.Mode=GPIO_MODE_AF_PP;
//	GPIO_Init.Pin=PUL_Signal;
//	GPIO_Init.Pull=GPIO_NOPULL;
//	GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
//	HAL_GPIO_Init(GPIOA,&GPIO_Init);
	
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

void TIM2_IRQHandler(void){
	HAL_TIM_IRQHandler(&TIM2_HandInit);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM2){
		count1++;
	}
}
