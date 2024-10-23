#include "stm32f10x.h"                  // Device header
void SG90_Init(void){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);//��tim2ʱ���ź�
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	TIM_InternalClockConfig(TIM2);

	//����ʱ����Ԫ
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;//����Ƶ ����ѡ����Ƿ�Ƶϵ��
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;//���ϼ���ģʽ
	TIM_TimeBaseInitStructure.TIM_Period=20000-1;//�������ڼ�ARR�Զ�װ������ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler=72-1;//Ԥ��Ƶ����ֵ//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;//�ظ�����ѡ�� ��ѡ��ֻ�и߼���ʱ���Ż�ʹ��
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);//��ʼ��ʱ����Ԫ
	
	//���ýṹ��
	TIM_OCInitTypeDef TIM_InitStructure;
	TIM_OCStructInit(&TIM_InitStructure);//�ȸ�ֵĬ��ֵ ��������Ҫ�õ��ĳ�Ա�Ϳ��Բ����޸�
	//TIM_InitStructure.TIM_OCIdleState=TIM_OCIdleState_Reset;
	TIM_InitStructure.TIM_OCMode=TIM_OCMode_PWM1;	
//	TIM_InitStructure.TIM_OCNIdleState=TIM_OCNIdleState_Reset;
//	TIM_InitStructure.TIM_OCNPolarity=0;
	TIM_InitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	//TIM_InitStructure.TIM_OutputNState=0;
	TIM_InitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_InitStructure.TIM_Pulse=0;		//CCR
	TIM_OC2Init(TIM2,&TIM_InitStructure);
	
	//����TIM2
	TIM_Cmd(TIM2,ENABLE);
}	

//TIM_SetCompare2(TIM2,Rangle);
//�жϺ���2��ģ��
//void TIM2_IRQHandler(void){
//	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET){
//		
//		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
//	}
//}
