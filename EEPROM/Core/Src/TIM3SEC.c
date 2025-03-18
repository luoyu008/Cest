#include "main.h"
TIM_HandleTypeDef TIM4_HandInit;
uint8_t TIM4_Count;
void TIM3SEC_Init(void){
	TIM4_HandInit.Instance=TIM4;
	TIM4_HandInit.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
	TIM4_HandInit.Init.CounterMode=TIM_COUNTERMODE_UP;
	TIM4_HandInit.Init.Period=10000;					//¼ÆÂúÊÇ0.1s
	TIM4_HandInit.Init.Prescaler=800-1;
	HAL_TIM_Base_Init(&TIM4_HandInit);
	
	HAL_NVIC_SetPriority(TIM4_IRQn,0,1);
	HAL_NVIC_EnableIRQ(TIM4_IRQn);
	
	
	
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM4){
		__HAL_RCC_TIM4_CLK_ENABLE();
	}
}

void TIM4_IRQHandler(void){
	HAL_TIM_IRQHandler(&TIM4_HandInit);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM4){
		TIM4_Count++;
		if(TIM4_Count==31){
			TIM4_Count=0;
		}
	}
}
