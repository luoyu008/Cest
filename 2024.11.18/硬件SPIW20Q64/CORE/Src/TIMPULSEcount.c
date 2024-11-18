#include "main.h"
TIM_HandleTypeDef TIM_PULSEHandInit;
TIM_SlaveConfigTypeDef TIM_PULSESlaveInit;
uint8_t temp5;
void TIMPULSEcount_Init(void){
	TIM_PULSEHandInit.Instance=TIM2;
//	TIM_PULSEHandInit.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
	TIM_PULSEHandInit.Init.CounterMode=TIM_COUNTERMODE_UP;
	TIM_PULSEHandInit.Init.Period=10-1;
	TIM_PULSEHandInit.Init.Prescaler=0;
	HAL_TIM_IC_Init(&TIM_PULSEHandInit);
	
	TIM_PULSESlaveInit.InputTrigger=TIM_TS_TI1FP1;
	TIM_PULSESlaveInit.SlaveMode=TIM_SLAVEMODE_EXTERNAL1;
	TIM_PULSESlaveInit.TriggerFilter=0;
	TIM_PULSESlaveInit.TriggerPolarity=TIM_TRIGGERPOLARITY_RISING;
//	TIM_PULSESlaveInit.TriggerPrescaler=TIM_TRIGGERPRESCALER_DIV1;
	HAL_TIM_SlaveConfigSynchro(&TIM_PULSEHandInit,&TIM_PULSESlaveInit);
	
	HAL_TIM_Base_Start_IT(&TIM_PULSEHandInit);//开启定时器更新中断后会置定时器更新标志位为1需要进行清除
	__HAL_TIM_CLEAR_FLAG(&TIM_PULSEHandInit,TIM_FLAG_UPDATE);

	HAL_NVIC_SetPriority(TIM2_IRQn,1,2);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);

	HAL_TIM_IC_Start(&TIM_PULSEHandInit,TIM_CHANNEL_1);
}

//void HAL_TIM_IC_MspInit(TIM_HandleTypeDef *htim){
//	if(htim->Instance==TIM2){
//		__HAL_RCC_GPIOA_CLK_ENABLE();
//		__HAL_RCC_TIM2_CLK_ENABLE();
//		
//		GPIO_InitTypeDef GPIO_Init;
//		GPIO_Init.Mode=GPIO_MODE_AF_PP;
//		GPIO_Init.Pin=GPIO_PIN_0;
//		GPIO_Init.Pull=GPIO_PULLDOWN;
//		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
//		HAL_GPIO_Init(GPIOA,&GPIO_Init);
//	}
//}

//void TIM2_IRQHandler(void){
//	HAL_TIM_IRQHandler(&TIM_PULSEHandInit);
//	
//}

//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
//	if(htim->Instance==TIM2){
//		temp5++;
//	}
//}
