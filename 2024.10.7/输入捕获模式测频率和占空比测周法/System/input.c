#include "stm32f10x.h"                  // Device header
void input_Init(void){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	//����a6Ϊ���������
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//tim3ʹ���ڲ�ʱ��
	TIM_InternalClockConfig(TIM3);
	//����ʱ����Ԫ 1mhz
	TIM_TimeBaseInitTypeDef TIM_InitStructure;
	TIM_InitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_InitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_InitStructure.TIM_Period=65536-1;//ARR
	TIM_InitStructure.TIM_Prescaler=72-1;//PSC
	TIM_InitStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM3,&TIM_InitStructure);
	
	//��������ͨ��
	TIM_ICInitTypeDef TIM_ICInitStructure;
	TIM_ICInitStructure.TIM_Channel=TIM_Channel_1;
	TIM_ICInitStructure.TIM_ICFilter=0xf;
	TIM_ICInitStructure.TIM_ICPolarity=TIM_ICPolarity_Rising;
	TIM_ICInitStructure.TIM_ICPrescaler=TIM_ICPSC_DIV1;
	TIM_ICInitStructure.TIM_ICSelection=TIM_ICSelection_DirectTI;
//	TIM_ICInitStructure.TIM_Channel=TIM_Channel_2;
//	TIM_ICInitStructure.TIM_ICFilter=0xf;
//	TIM_ICInitStructure.TIM_ICPolarity=TIM_ICPolarity_BothEdge;
//	TIM_ICInitStructure.TIM_ICPrescaler=TIM_ICPSC_DIV1;
//	TIM_ICInitStructure.TIM_ICSelection=TIM_ICSelection_IndirectTI;
	//TIM_ICInit(TIM3,&TIM_ICInitStructure);
	TIM_PWMIConfig(TIM3,&TIM_ICInitStructure);
	//ѡ���ģʽ����Դ
	TIM_SelectInputTrigger(TIM3,TIM_TS_TI1FP1);
	//���������
	TIM_SelectSlaveMode(TIM3,TIM_SlaveMode_Reset);
	
	//����tim3
	TIM_Cmd(TIM3,ENABLE);
}
