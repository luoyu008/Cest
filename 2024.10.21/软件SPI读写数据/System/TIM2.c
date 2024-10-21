#include "stm32f10x.h"                  // Device header
void TIM2_Init(){
	//��ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	//ѡ���ڲ�ʱ��
	TIM_InternalClockConfig(TIM2);
	//����TIM3 10khz   ��ʱ10ms
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period=100-1;//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler=7200-1;//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	//����OC1ͨ��
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse=100-1;//CCR
	TIM_OC2Init(TIM2,&TIM_OCInitStructure);
	//tim3����ģʽ
	TIM_SelectOutputTrigger(TIM2,TIM_TRGOSource_OC2Ref);
	//��tim3
	TIM_Cmd(TIM2,ENABLE);
}
