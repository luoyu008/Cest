#include "stm32f10x.h"                  // Device header
void Timecount_Init(void){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);//��tim2ʱ���ź�
	
	TIM_InternalClockConfig(TIM2);//ѡ��tim2�ڲ�ʱ��
	//����ʱ����Ԫ
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;//����Ƶ ����ѡ����Ƿ�Ƶϵ��
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ
	TIM_TimeBaseInitStructure.TIM_Period=10000-1;//�������ڼ�ARR�Զ�װ������ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler=7200-1;//Ԥ��Ƶ����ֵ
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;//�ظ�����ѡ�� ��ѡ��ֻ�и߼���ʱ���Ż�ʹ��
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);//��ʼ��ʱ����Ԫ
	
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
//void TIM2_IRQHandler(void){
//	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET){
//		
//		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
//	}
//}
