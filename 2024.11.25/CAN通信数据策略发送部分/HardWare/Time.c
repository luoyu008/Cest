#include "stm32f10x.h"                  // Device header
uint8_t TxFlage;
void Time_Init(void){
	//��ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	//ѡ���ڲ�ʱ��
	TIM_InternalClockConfig(TIM2);
	//����100ms
	TIM_TimeBaseInitTypeDef Time_BaseInit;
	Time_BaseInit.TIM_ClockDivision=TIM_CKD_DIV1;
	Time_BaseInit.TIM_CounterMode=TIM_CounterMode_Up;
	Time_BaseInit.TIM_Period=1000-1;
	Time_BaseInit.TIM_Prescaler=7200-1;
	Time_BaseInit.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM2,&Time_BaseInit);
	
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);//��һ��������ĩβֱ�ӿ�����һ���ж� �����Ƚ��жϱ�־λ����
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);//�����ж�
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//NVIC����
	//����NVIC
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStructure);
	//����TIM2
	TIM_Cmd(TIM2,ENABLE);

}

//�жϺ���2��ģ��
void TIM2_IRQHandler(void){
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET){
		TxFlage=1;
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
}
