#include "main.h"
#include "OLED.h"
TIM_HandleTypeDef TIM_AdvanceTimPwmHandInit;
TIM_OC_InitTypeDef TIM_OC_AdvanceTimPwmInit;
static uint8_t NPwm=0;
void AdvanceTimPwm_Init(void){
	//1khz
	TIM_AdvanceTimPwmHandInit.Instance=TIM1;
	TIM_AdvanceTimPwmHandInit.Init.CounterMode=TIM_COUNTERMODE_UP;
	TIM_AdvanceTimPwmHandInit.Init.Period=100-1;
	TIM_AdvanceTimPwmHandInit.Init.Prescaler=720-1;
	TIM_AdvanceTimPwmHandInit.Init.RepetitionCounter=NPwm;
	HAL_TIM_PWM_Init(&TIM_AdvanceTimPwmHandInit);
	
	TIM_OC_AdvanceTimPwmInit.OCMode=TIM_OCMODE_PWM1;
	TIM_OC_AdvanceTimPwmInit.OCPolarity=TIM_OCPOLARITY_HIGH;
	TIM_OC_AdvanceTimPwmInit.Pulse=50;
	HAL_TIM_PWM_ConfigChannel(&TIM_AdvanceTimPwmHandInit,&TIM_OC_AdvanceTimPwmInit,TIM_CHANNEL_1);
	
	HAL_NVIC_SetPriority(TIM1_UP_IRQn,1,1);
	HAL_NVIC_EnableIRQ(TIM1_UP_IRQn);
	
	__HAL_TIM_ENABLE_IT(&TIM_AdvanceTimPwmHandInit,TIM_IT_UPDATE);
	HAL_TIM_PWM_Start(&TIM_AdvanceTimPwmHandInit,TIM_CHANNEL_1);

}

void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM1){
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_TIM1_CLK_ENABLE();
		
		GPIO_InitTypeDef GPIO_Init;
		GPIO_Init.Mode=GPIO_MODE_AF_PP;
		GPIO_Init.Pin=GPIO_PIN_8;
		GPIO_Init.Pull=GPIO_PULLUP;
		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOA,&GPIO_Init);
	}
}

void AdvanceTimPwm_Set(uint8_t NPWm){
	if(NPWm==0){
	return;
	}
	else{
		NPwm=NPWm;
		HAL_TIM_GenerateEvent(&TIM_AdvanceTimPwmHandInit,TIM_EVENTSOURCE_UPDATE);
		__HAL_TIM_ENABLE(&TIM_AdvanceTimPwmHandInit);
	}
}


void TIM1_UP_IRQHandler(void){
	HAL_TIM_IRQHandler(&TIM_AdvanceTimPwmHandInit);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	OLED_ShowChar(0,0,'C',16);
	OLED_UpData();
	if(htim->Instance==TIM1){
		if(NPwm){
		TIM1->RCR=NPwm-1;
		HAL_TIM_GenerateEvent(&TIM_AdvanceTimPwmHandInit,TIM_EVENTSOURCE_UPDATE);
		__HAL_TIM_ENABLE(&TIM_AdvanceTimPwmHandInit);
		NPwm=0;
		}
		else{
		TIM1->CR1&=~(1<<0);
		}
	}
}
