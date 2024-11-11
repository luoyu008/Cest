#include "main.h"
#include "OLED.h"
TIM_HandleTypeDef TIM_SG90HandInit;
TIM_OC_InitTypeDef TIM_OC_SG90Init;
void SG90PWM_Init(void){                                                                                     
	TIM_SG90HandInit.Instance=TIM2;
	TIM_SG90HandInit.Init.Period=100-1;
	TIM_SG90HandInit.Init.Prescaler=720-1;
	TIM_SG90HandInit.Init.CounterMode=TIM_COUNTERMODE_UP;
//	TIM_SG90HandInit.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_PWM_Init(&TIM_SG90HandInit);
	
	TIM_OC_SG90Init.OCMode=TIM_OCMODE_PWM1;
	TIM_OC_SG90Init.OCPolarity=TIM_OCPOLARITY_HIGH;
	TIM_OC_SG90Init.Pulse=50;
	HAL_TIM_PWM_ConfigChannel(&TIM_SG90HandInit,&TIM_OC_SG90Init,TIM_CHANNEL_2);
	
	HAL_TIM_PWM_Start(&TIM_SG90HandInit,TIM_CHANNEL_2);
	
}

//void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim){
//	if(htim->Instance==TIM2){
//		
//		__HAL_RCC_GPIOA_CLK_DISABLE();
//		__HAL_RCC_TIM2_CLK_ENABLE();
//		
//		GPIO_InitTypeDef GPIO_Init;
//		GPIO_Init.Mode=GPIO_MODE_AF_PP;
//		GPIO_Init.Pin=GPIO_PIN_1;
//		GPIO_Init.Pull=GPIO_NOPULL;
//		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
//		HAL_GPIO_Init(GPIOA,&GPIO_Init);
//	}
//}
