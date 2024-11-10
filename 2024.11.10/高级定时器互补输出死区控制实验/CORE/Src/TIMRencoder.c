#include "main.h"
TIM_HandleTypeDef TIM_TIMRencoder_Init;
TIM_Encoder_InitTypeDef TIM_EncoderInit;
TIM_MasterConfigTypeDef TIM_RencoderMaterInit;
void TIMRencoder_Init(void){
	TIM_TIMRencoder_Init.Instance=TIM3;
	TIM_TIMRencoder_Init.Init.ClockDivision=TIM_CLOCKDIVISION_DIV1;
	TIM_TIMRencoder_Init.Init.CounterMode=TIM_COUNTERMODE_UP;
	TIM_TIMRencoder_Init.Init.Period=65536-1;
	TIM_TIMRencoder_Init.Init.Prescaler=0;
	
	TIM_EncoderInit.EncoderMode=TIM_ENCODERMODE_TI12;
	TIM_EncoderInit.IC1Filter=0;
	TIM_EncoderInit.IC1Polarity=TIM_ENCODERINPUTPOLARITY_RISING;
	TIM_EncoderInit.IC1Prescaler=TIM_ICPSC_DIV1;
	TIM_EncoderInit.IC1Selection=TIM_ICSELECTION_DIRECTTI;
	TIM_EncoderInit.IC2Filter=0;
	TIM_EncoderInit.IC2Polarity=TIM_ENCODERINPUTPOLARITY_RISING;
	TIM_EncoderInit.IC2Prescaler=TIM_ICPSC_DIV1;
	TIM_EncoderInit.IC2Selection=TIM_ICSELECTION_INDIRECTTI;
	HAL_TIM_Encoder_Init(&TIM_TIMRencoder_Init,&TIM_EncoderInit);
	
	TIM_RencoderMaterInit.MasterOutputTrigger=TIM_TRGO_RESET;
	TIM_RencoderMaterInit.MasterSlaveMode=TIM_MASTERSLAVEMODE_DISABLE;
	HAL_TIMEx_MasterConfigSynchronization(&TIM_TIMRencoder_Init,&TIM_RencoderMaterInit);
	
	HAL_TIM_Encoder_Start(&TIM_TIMRencoder_Init,TIM_CHANNEL_ALL);
}

//void HAL_TIM_Encoder_MspInit(TIM_HandleTypeDef *htim){
//	if(htim->Instance==TIM3){
//		__HAL_RCC_TIM3_CLK_ENABLE();
//		__HAL_RCC_GPIOA_CLK_ENABLE();
//		
//		GPIO_InitTypeDef GPIO_Init;
//		GPIO_Init.Mode=GPIO_MODE_INPUT;
//		GPIO_Init.Pin=GPIO_PIN_6|GPIO_PIN_7;
//		GPIO_Init.Pull=GPIO_NOPULL;
//		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
//		HAL_GPIO_Init(GPIOA,&GPIO_Init);
//	}
//}
