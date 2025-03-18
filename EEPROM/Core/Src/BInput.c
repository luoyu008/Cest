#include "main.h"
TIM_HandleTypeDef TIM3_HandInit;
TIM_SlaveConfigTypeDef TIM3_SlaveInit;
TIM_IC_InitTypeDef TIM3_ICCHInit;
TIM_ClockConfigTypeDef sClockSourceConfig3;
TIM_MasterConfigTypeDef sMasterConfig3;
uint16_t all1=0;
uint16_t high1=0;
uint16_t empty1=0;
void BInput_Init(void){
	TIM3_HandInit.Instance=TIM3;
	TIM3_HandInit.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
	TIM3_HandInit.Init.CounterMode=TIM_COUNTERMODE_UP;
	TIM3_HandInit.Init.Period=65536-1;
	TIM3_HandInit.Init.Prescaler=80-1;
	HAL_TIM_IC_Init(&TIM3_HandInit);
	
	TIM3_SlaveInit.InputTrigger=TIM_TS_TI1FP1;
	TIM3_SlaveInit.SlaveMode=TIM_SLAVEMODE_RESET;		//Çå¿Õ¼ÆÊýÆ÷
	TIM3_SlaveInit.TriggerFilter=0xf;
	TIM3_SlaveInit.TriggerPolarity=TIM_TRIGGERPOLARITY_RISING;
	TIM3_SlaveInit.TriggerPrescaler=TIM_TRIGGERPRESCALER_DIV1;
	HAL_TIM_SlaveConfigSynchro(&TIM3_HandInit,&TIM3_SlaveInit);
	
	TIM3_ICCHInit.ICFilter=0xf;
	TIM3_ICCHInit.ICPolarity=TIM_ICPOLARITY_RISING;
	TIM3_ICCHInit.ICPrescaler=TIM_ICPSC_DIV1;
	TIM3_ICCHInit.ICSelection=TIM_ICSELECTION_DIRECTTI;
	HAL_TIM_IC_ConfigChannel(&TIM3_HandInit,&TIM3_ICCHInit,TIM_CHANNEL_1);
	
	TIM3_ICCHInit.ICFilter=0xf;
	TIM3_ICCHInit.ICPolarity=TIM_ICPOLARITY_FALLING;
	TIM3_ICCHInit.ICPrescaler=TIM_ICPSC_DIV1;
	TIM3_ICCHInit.ICSelection=TIM_ICSELECTION_INDIRECTTI;
	HAL_TIM_IC_ConfigChannel(&TIM3_HandInit,&TIM3_ICCHInit,TIM_CHANNEL_2);
	
	HAL_TIM_IC_Start_IT(&TIM3_HandInit,TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&TIM3_HandInit,TIM_CHANNEL_2);
}



void TIM3_IRQHandler(void){
	HAL_TIM_IRQHandler(&TIM3_HandInit);
}
