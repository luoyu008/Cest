#include "main.h"
TIM_HandleTypeDef	SG90Pitch_HandInit;
TIM_OC_InitTypeDef	SG90Pitch_OCHandInit;
void SG90Pitch_Init(void){
	SG90Pitch_HandInit.Instance=TIM2;
	SG90Pitch_HandInit.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
	SG90Pitch_HandInit.Init.CounterMode=TIM_COUNTERMODE_UP;
	SG90Pitch_HandInit.Init.Period=2000-1;
	SG90Pitch_HandInit.Init.Prescaler=720-1;
	HAL_TIM_PWM_Init(&SG90Pitch_HandInit);
	
	SG90Pitch_OCHandInit.OCMode=TIM_OCMODE_PWM1;
	SG90Pitch_OCHandInit.OCPolarity=TIM_OCPOLARITY_HIGH;
	SG90Pitch_OCHandInit.Pulse=150;
	HAL_TIM_PWM_ConfigChannel(&SG90Pitch_HandInit,&SG90Pitch_OCHandInit,TIM_CHANNEL_2);
	
	HAL_TIM_PWM_Start(&SG90Pitch_HandInit,TIM_CHANNEL_2);
}

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM2){
		__HAL_RCC_TIM2_CLK_ENABLE();
		__HAL_RCC_GPIOA_CLK_ENABLE();
		
		GPIO_InitTypeDef GPIO_Init;
		GPIO_Init.Mode=GPIO_MODE_AF_PP;
		GPIO_Init.Pin=GPIO_PIN_1;
		GPIO_Init.Pull=GPIO_NOPULL;
		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOA,&GPIO_Init);
	}
}
