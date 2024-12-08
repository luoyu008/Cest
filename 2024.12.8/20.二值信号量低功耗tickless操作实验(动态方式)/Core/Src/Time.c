#include "main.h"
#include "OLED.h"
TIM_HandleTypeDef Time2_FreeRtosInit;
TIM_HandleTypeDef Time3_FreeRtosInit;
uint32_t count2;
uint32_t count3;
uint32_t FreeRTOSRunTimeTicks;
void Time2_Init(void);
void ConfigureTimeForRunTimeStats(void){
	Time2_Init();
	FreeRTOSRunTimeTicks=0;
}


void Time2_Init(void){
	//ÅäÖÃ10us
	Time2_FreeRtosInit.Instance=TIM2;
	Time2_FreeRtosInit.Init.Prescaler=10-1;
	Time2_FreeRtosInit.Init.CounterMode=TIM_COUNTERMODE_UP;
	Time2_FreeRtosInit.Init.Period=72-1;
	Time2_FreeRtosInit.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_Base_Init(&Time2_FreeRtosInit);
	
	HAL_NVIC_SetPriority(TIM2_IRQn,6,0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
	
	
	HAL_TIM_Base_Start_IT(&Time2_FreeRtosInit);
	
}

void Time3_Init(void){
	Time3_FreeRtosInit.Instance=TIM3;
	Time3_FreeRtosInit.Init.Prescaler=10000-1;
	Time3_FreeRtosInit.Init.CounterMode=TIM_COUNTERMODE_UP;
	Time3_FreeRtosInit.Init.Period=7200-1;
	Time3_FreeRtosInit.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_Base_Init(&Time3_FreeRtosInit);
	
	HAL_NVIC_SetPriority(TIM3_IRQn,6,0);
	HAL_NVIC_EnableIRQ(TIM3_IRQn);
	
	HAL_TIM_Base_Start_IT(&Time3_FreeRtosInit);
}

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM2){
		__HAL_RCC_TIM2_CLK_ENABLE();
	}
	if(htim->Instance==TIM3){
		__HAL_RCC_TIM3_CLK_ENABLE();
	}
}

void TIM2_IRQHandler(void){
	HAL_TIM_IRQHandler(&Time2_FreeRtosInit);
}

void TIM3_IRQHandler(void){
	HAL_TIM_IRQHandler(&Time3_FreeRtosInit);
}
