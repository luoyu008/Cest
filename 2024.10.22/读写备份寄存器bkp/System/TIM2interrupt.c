#include "stm32f10x.h"                  // Device header
void TIM2_interrupt(void){
	//��ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	//ѡ��ʱ��
	TIM_InternalClockConfig(TIM2);
	//����ʱ����Ԫ 10khz ��һ��Ϊ0.1ms ����10000��Ϊ1��
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period=10000-1;//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler=7200-1;//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);//��һ��������ĩβֱ�ӿ�����һ���ж� �����Ƚ��жϱ�־λ����
	//���ж�
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);
	//����NVIC
	//����
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStructure);

	//��tim2
	TIM_Cmd(TIM2,ENABLE);
}

//�жϺ���2��ģ��
//void TIM2_IRQHandler(void){
//	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET){
//		
//		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
//	}
//}
