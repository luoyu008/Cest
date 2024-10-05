#include "stm32f10x.h"                  // Device header
void Timecount_Init(void){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);//��tim2ʱ���ź�
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	TIM_ETRClockMode1Config(TIM2,TIM_ExtTRGPSC_OFF,TIM_ExtTRGPolarity_Inverted,0x0f);//���ĸ�������С��ѡֵΪ0x03���Ϊ0x0f
	//����ʱ����Ԫ
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;//����Ƶ ����ѡ����Ƿ�Ƶϵ��
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ
	TIM_TimeBaseInitStructure.TIM_Period=100-1;//�������ڼ�ARR�Զ�װ������ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler=1-1;//Ԥ��Ƶ����ֵ
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
