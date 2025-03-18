#include "main.h"
#include "BInput.h"
TIM_HandleTypeDef TIM2_HandInit;
TIM_SlaveConfigTypeDef TIM2_SlaveInit;
TIM_IC_InitTypeDef TIM2_ICCHInit;
TIM_ClockConfigTypeDef sClockSourceConfig;
TIM_MasterConfigTypeDef sMasterConfig;
uint16_t all=0;
uint16_t high=0;
uint16_t empty=0;
void AInput_Init(void){
	TIM2_HandInit.Instance=TIM2;
	TIM2_HandInit.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
	TIM2_HandInit.Init.CounterMode=TIM_COUNTERMODE_UP;
	TIM2_HandInit.Init.Period=65536-1;
	TIM2_HandInit.Init.Prescaler=80-1;
	HAL_TIM_IC_Init(&TIM2_HandInit);
	
	TIM2_SlaveInit.InputTrigger=TIM_TS_TI1FP1;
	TIM2_SlaveInit.SlaveMode=TIM_SLAVEMODE_RESET;		//Çå¿Õ¼ÆÊýÆ÷
	TIM2_SlaveInit.TriggerFilter=0xf;
	TIM2_SlaveInit.TriggerPolarity=TIM_TRIGGERPOLARITY_RISING;
	TIM2_SlaveInit.TriggerPrescaler=TIM_TRIGGERPRESCALER_DIV1;
	HAL_TIM_SlaveConfigSynchro(&TIM2_HandInit,&TIM2_SlaveInit);
	
	TIM2_ICCHInit.ICFilter=0xf;
	TIM2_ICCHInit.ICPolarity=TIM_ICPOLARITY_RISING;
	TIM2_ICCHInit.ICPrescaler=TIM_ICPSC_DIV1;
	TIM2_ICCHInit.ICSelection=TIM_ICSELECTION_DIRECTTI;
	HAL_TIM_IC_ConfigChannel(&TIM2_HandInit,&TIM2_ICCHInit,TIM_CHANNEL_1);
	
	TIM2_ICCHInit.ICFilter=0xf;
	TIM2_ICCHInit.ICPolarity=TIM_ICPOLARITY_FALLING;
	TIM2_ICCHInit.ICPrescaler=TIM_ICPSC_DIV1;
	TIM2_ICCHInit.ICSelection=TIM_ICSELECTION_INDIRECTTI;
	HAL_TIM_IC_ConfigChannel(&TIM2_HandInit,&TIM2_ICCHInit,TIM_CHANNEL_2);
	
	HAL_TIM_IC_Start_IT(&TIM2_HandInit,TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&TIM2_HandInit,TIM_CHANNEL_2);
}

void HAL_TIM_IC_MspInit(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM2){
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_TIM2_CLK_ENABLE();
		
		GPIO_InitTypeDef GPIO_Init;
		GPIO_Init.Mode=GPIO_MODE_AF_PP;
		GPIO_Init.Pin=GPIO_PIN_15;
		GPIO_Init.Pull=GPIO_NOPULL;
		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
		GPIO_Init.Alternate = GPIO_AF1_TIM2;
		HAL_GPIO_Init(GPIOA,&GPIO_Init);
		HAL_NVIC_SetPriority(TIM2_IRQn,1,1);
		HAL_NVIC_EnableIRQ(TIM2_IRQn);
	}
	if(htim->Instance==TIM3){
		__HAL_RCC_GPIOB_CLK_ENABLE();
		__HAL_RCC_TIM3_CLK_ENABLE();
		
		GPIO_InitTypeDef GPIO_Init;
		GPIO_Init.Mode=GPIO_MODE_AF_PP;
		GPIO_Init.Pin=GPIO_PIN_4;
		GPIO_Init.Pull=GPIO_NOPULL;
		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
		GPIO_Init.Alternate = GPIO_AF2_TIM3;
		HAL_GPIO_Init(GPIOB,&GPIO_Init);
		HAL_NVIC_SetPriority(TIM3_IRQn,1,1);
		HAL_NVIC_EnableIRQ(TIM3_IRQn);
	}
}

void TIM2_IRQHandler(void){
	HAL_TIM_IRQHandler(&TIM2_HandInit);
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM2){
		if(htim->Channel==HAL_TIM_ACTIVE_CHANNEL_1){
			all=HAL_TIM_ReadCapturedValue(&TIM2_HandInit,TIM_CHANNEL_1)+1;
		}
		if(htim->Channel==HAL_TIM_ACTIVE_CHANNEL_2){
			high=HAL_TIM_ReadCapturedValue(&TIM2_HandInit,TIM_CHANNEL_2)+1;
			empty=(high+1)*100/(all+1);
		}
	}
	if(htim->Instance==TIM3){
		if(htim->Channel==HAL_TIM_ACTIVE_CHANNEL_1){
			all1=HAL_TIM_ReadCapturedValue(&TIM3_HandInit,TIM_CHANNEL_1)+1;
		}
		if(htim->Channel==HAL_TIM_ACTIVE_CHANNEL_2){
			high1=HAL_TIM_ReadCapturedValue(&TIM3_HandInit,TIM_CHANNEL_2)+1;
			empty1=(high1+1)*100/(all1+1);
		}
	}
}
