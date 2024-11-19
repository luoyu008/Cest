#include "main.h"
#include "OLED.h"
TIM_HandleTypeDef TIM_AdvancedICPWM;
TIM_IC_InitTypeDef TIM_IC_AdvancedPWM;
TIM_SlaveConfigTypeDef TIM_SlaveAdvancedICPWMInit;
uint8_t state9;
uint16_t high=0;
uint16_t all=0;
uint16_t count4;
void ADVANCEDTIMICPWM_Init(void){
	
	TIM_AdvancedICPWM.Instance=TIM1;	
	TIM_AdvancedICPWM.Init.CounterMode=TIM_COUNTERMODE_UP;
	TIM_AdvancedICPWM.Init.Period=65536-1;
	TIM_AdvancedICPWM.Init.Prescaler=72-1;
	TIM_AdvancedICPWM.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
	HAL_TIM_IC_Init(&TIM_AdvancedICPWM);
	//改为下面这些便可使用通用定时器测pwm
//	TIM_AdvancedICPWM.Instance=TIM3;	
//	TIM_AdvancedICPWM.Init.CounterMode=TIM_COUNTERMODE_UP;
//	TIM_AdvancedICPWM.Init.Period=65536-1;
//	TIM_AdvancedICPWM.Init.Prescaler=72-1;
//	TIM_AdvancedICPWM.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
//	HAL_TIM_IC_Init(&TIM_AdvancedICPWM);
	
	TIM_SlaveAdvancedICPWMInit.InputTrigger=TIM_TS_TI1FP1;
	TIM_SlaveAdvancedICPWMInit.SlaveMode=TIM_SLAVEMODE_RESET;//复位模式即清空计数器
	TIM_SlaveAdvancedICPWMInit.TriggerPolarity=TIM_TRIGGERPOLARITY_RISING;//上升沿触发
//	TIM_SlaveAdvancedICPWMInit.TriggerPrescaler=TIM_TRIGGERPRESCALER_DIV1;//不分频
	HAL_TIM_SlaveConfigSynchro(&TIM_AdvancedICPWM,&TIM_SlaveAdvancedICPWMInit);
	
	TIM_IC_AdvancedPWM.ICPolarity=TIM_INPUTCHANNELPOLARITY_RISING;//上升沿检测
	TIM_IC_AdvancedPWM.ICPrescaler=TIM_ICPSC_DIV1;//不分频
	TIM_IC_AdvancedPWM.ICSelection=TIM_ICSELECTION_DIRECTTI;//IC1输入映射到T1
	TIM_IC_AdvancedPWM.ICFilter=0xF;
	HAL_TIM_IC_ConfigChannel(&TIM_AdvancedICPWM,&TIM_IC_AdvancedPWM,TIM_CHANNEL_1);
	
	TIM_IC_AdvancedPWM.ICPolarity=TIM_INPUTCHANNELPOLARITY_FALLING;//下降沿检测
	TIM_IC_AdvancedPWM.ICPrescaler=TIM_ICPSC_DIV1;//不分频
	TIM_IC_AdvancedPWM.ICSelection=TIM_ICSELECTION_INDIRECTTI;//IC2输入映射到T1
	TIM_IC_AdvancedPWM.ICFilter=0xF;
	HAL_TIM_IC_ConfigChannel(&TIM_AdvancedICPWM,&TIM_IC_AdvancedPWM,TIM_CHANNEL_2);
	
	HAL_TIM_IC_Start_IT(&TIM_AdvancedICPWM,TIM_CHANNEL_1);
	HAL_TIM_IC_Start_IT(&TIM_AdvancedICPWM,TIM_CHANNEL_2);
	
	
}

void HAL_TIM_IC_MspInit(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM1){
	__HAL_RCC_TIM1_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
		
	GPIO_InitTypeDef GPIO_Init;
	GPIO_Init.Mode=GPIO_MODE_INPUT;
	GPIO_Init.Pin=GPIO_PIN_8;
	GPIO_Init.Pull=GPIO_NOPULL;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA,&GPIO_Init);
	
	HAL_NVIC_SetPriority(TIM1_CC_IRQn,1,1);
	HAL_NVIC_EnableIRQ(TIM1_CC_IRQn);
	}
}

void TIM1_CC_IRQHandler(void){
	HAL_TIM_IRQHandler(&TIM_AdvancedICPWM);
	
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM1){
		if(htim->Channel==HAL_TIM_ACTIVE_CHANNEL_1){ 
			all=HAL_TIM_ReadCapturedValue(&TIM_AdvancedICPWM,TIM_CHANNEL_1)+1;
			}
		else if(htim->Channel==HAL_TIM_ACTIVE_CHANNEL_2){
			high=HAL_TIM_ReadCapturedValue(&TIM_AdvancedICPWM,TIM_CHANNEL_2)+1;
			count4=(high+1)*100/(all+1);
		}
		}
}
