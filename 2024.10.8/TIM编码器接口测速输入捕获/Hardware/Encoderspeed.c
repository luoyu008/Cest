#include "stm32f10x.h"                  // Device header
void Encoderspeed_Init(void){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);//��tim3ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//��GPIOAʱ��
	//����a6a7��Ϊ��������ģʽ
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//ѡ��ʱ�� ��Ϊ�������ӿڻ��й�ʱ������������Բ���ѡ��ʱ��
	//����ʱ����Ԫ1khz
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;//�ò��������õ� ��Ϊ�������ӿ�Ҳ���й�	
	TIM_TimeBaseInitStructure.TIM_Period=65536-1;//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler=1-1;//PSC  //����Ƶ ��������ʱ��ֱ������������
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);
	//���ò���ͨ��
	TIM_ICInitTypeDef TIM_ICInitStructure;
	TIM_ICStructInit(&TIM_ICInitStructure);//��Ϊ�ṹ��Ĳ�����û����ȫ�õ� �����ȸ�ֵΪĬ��ֵ��ֹ������������
	TIM_ICInitStructure.TIM_Channel=TIM_Channel_1;
	TIM_ICInitStructure.TIM_ICFilter=0xf;
//	TIM_ICInitStructure.TIM_ICPolarity=TIM_ICPolarity_BothEdge; �������ӿں���������
//	TIM_ICInitStructure.TIM_ICPrescaler=TIM_ICPSC_DIV1;  �����������ò���
//	TIM_ICInitStructure.TIM_ICSelection=TIM_ICSelection_DirectTI;
	TIM_ICInit(TIM3,&TIM_ICInitStructure);
	TIM_ICInitStructure.TIM_Channel=TIM_Channel_2;
	TIM_ICInitStructure.TIM_ICFilter=0xf;
//	TIM_ICInitStructure.TIM_ICPolarity=TIM_ICPolarity_BothEdge;�������ӿں���������
//	TIM_ICInitStructure.TIM_ICPrescaler=TIM_ICPSC_DIV1;  �����������ò���
//	TIM_ICInitStructure.TIM_ICSelection=TIM_ICSelection_DirectTI;
	TIM_ICInit(TIM3,&TIM_ICInitStructure);
	//���ñ������ӿ�  ���Ĳ�������˼��ͨ���ļ��� Ҳ����ͨ���Ĳ����Ƿ��� ����ѡ�񲻷���
	TIM_EncoderInterfaceConfig(TIM3,TIM_EncoderMode_TI12,TIM_ICPolarity_Rising,TIM_ICPolarity_Rising);
	//����tim3
	TIM_Cmd(TIM3,ENABLE);
	//����tim2�ж�
	//��ʱ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
}

uint16_t Encoderspeed_return(void){
	uint16_t count;
	count=TIM_GetCounter(TIM3);
	TIM_SetCounter(TIM3,0);
	return count;
}
