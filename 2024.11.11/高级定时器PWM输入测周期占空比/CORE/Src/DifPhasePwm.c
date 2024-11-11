#include "main.h"
TIM_HandleTypeDef TIM_DifPhasePwmInit;
TIM_OC_InitTypeDef TIM_OC_DifPhasePwmInit;
void DifPhasePwm_Init(void){
	//1khz����Ƶ�ʼ�500hzPWMƵ��
	TIM_DifPhasePwmInit.Instance=TIM1;
	TIM_DifPhasePwmInit.Init.CounterMode=TIM_COUNTERMODE_UP;
	TIM_DifPhasePwmInit.Init.Period=100-1;
	TIM_DifPhasePwmInit.Init.Prescaler=720-1;
	HAL_TIM_OC_Init(&TIM_DifPhasePwmInit);
	
	TIM_OC_DifPhasePwmInit.OCMode=TIM_OCMODE_TOGGLE;//��תģʽ
	TIM_OC_DifPhasePwmInit.OCPolarity=TIM_OCPOLARITY_HIGH;//������β�����
	TIM_OC_DifPhasePwmInit.Pulse=0;//��ʼ��λֵ
	HAL_TIM_OC_ConfigChannel(&TIM_DifPhasePwmInit,&TIM_OC_DifPhasePwmInit,TIM_CHANNEL_1);
	HAL_TIM_OC_ConfigChannel(&TIM_DifPhasePwmInit,&TIM_OC_DifPhasePwmInit,TIM_CHANNEL_2);
	HAL_TIM_OC_ConfigChannel(&TIM_DifPhasePwmInit,&TIM_OC_DifPhasePwmInit,TIM_CHANNEL_3);
	HAL_TIM_OC_ConfigChannel(&TIM_DifPhasePwmInit,&TIM_OC_DifPhasePwmInit,TIM_CHANNEL_4);
	//ʹ��ͨ��Ԥװ�ؼ�����Ӱ�ӼĴ�����������
	__HAL_TIM_ENABLE_OCxPRELOAD(&TIM_DifPhasePwmInit,TIM_CHANNEL_1);
	__HAL_TIM_ENABLE_OCxPRELOAD(&TIM_DifPhasePwmInit,TIM_CHANNEL_2);
	__HAL_TIM_ENABLE_OCxPRELOAD(&TIM_DifPhasePwmInit,TIM_CHANNEL_3);
	__HAL_TIM_ENABLE_OCxPRELOAD(&TIM_DifPhasePwmInit,TIM_CHANNEL_4);
	//�������ģʽ
	HAL_TIM_OC_Start(&TIM_DifPhasePwmInit,TIM_CHANNEL_1);
	HAL_TIM_OC_Start(&TIM_DifPhasePwmInit,TIM_CHANNEL_2);
	HAL_TIM_OC_Start(&TIM_DifPhasePwmInit,TIM_CHANNEL_3);
	HAL_TIM_OC_Start(&TIM_DifPhasePwmInit,TIM_CHANNEL_4);
}

//void HAL_TIM_OC_MspInit(TIM_HandleTypeDef *htim){
//	if(htim->Instance==TIM1){
//		//������Ӧ��ʱ��
//		__HAL_RCC_GPIOA_CLK_ENABLE();
//		__HAL_RCC_TIM1_CLK_ENABLE();
//		//��������ģʽ
//		GPIO_InitTypeDef GPIO_Init;
//		GPIO_Init.Mode=GPIO_MODE_AF_PP;
//		GPIO_Init.Pin=GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11;
//		GPIO_Init.Pull=GPIO_NOPULL;
//		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
//		HAL_GPIO_Init(GPIOA,&GPIO_Init);
//	}
//}

//void DifPhasePwm_SetPhase(uint16_t Phase,uint32_t Channel){
//	__HAL_TIM_SET_COMPARE(&TIM_DifPhasePwmInit,Channel,Phase);
//	HAL_TIM_GenerateEvent(&TIM_DifPhasePwmInit,TIM_EVENTSOURCE_UPDATE);
//	__HAL_TIM_ENABLE(&TIM_DifPhasePwmInit);
//}
