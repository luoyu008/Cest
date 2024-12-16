#include "main.h"
TIM_HandleTypeDef TIM6_HnadInit;
uint16_t count1;
void TIM6_Init(void){
	TIM6_HnadInit.Instance=TIM2;
//	TIM6_HnadInit.Init.AutoReloadPreload=TIM_AUTORELOAD_PRELOAD_ENABLE;
//	TIM6_HnadInit.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
//	TIM6_HnadInit.Init.CounterMode=TIM_COUNTERMODE_UP;
	TIM6_HnadInit.Init.Period=10000-1;
	TIM6_HnadInit.Init.Prescaler=7200-1;
//	TIM6_HnadInit.Init.RepetitionCounter=;
	HAL_TIM_Base_Init(&TIM6_HnadInit);
	HAL_TIM_Base_Start_IT(&TIM6_HnadInit);
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM2){
		__HAL_RCC_TIM2_CLK_ENABLE();
		
		HAL_NVIC_SetPriority(TIM2_IRQn,1,1);
		HAL_NVIC_EnableIRQ(TIM2_IRQn);
	}
}

//void TIM2_IRQHandler(void){
//	HAL_TIM_IRQHandler(&TIM6_HnadInit);
//}

//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
//	if(htim->Instance==TIM2){
//		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_4);
//		count1++;
//	}
//}
