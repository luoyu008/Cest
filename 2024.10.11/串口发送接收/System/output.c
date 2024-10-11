#include "stm32f10x.h"                  // Device header
void output_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	//ʹ���ڲ�ʱ��
	TIM_InternalClockConfig(TIM2);
	//����a0�����츴�����
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//ʱ����Ԫ 1khz 
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up ;
	TIM_TimeBaseInitStructure.TIM_Period=100-1;//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler=720-1;//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	//����tim2��ch1ͨ��
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCStructInit(&TIM_OCInitStructure);//�ȸ��ṹ�帳ֵĬ��ֵ
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse=50;//CCR //ռ�ձ�
	TIM_OC1Init(TIM2,&TIM_OCInitStructure);
	
	TIM_Cmd(TIM2,ENABLE);
}

void SET_PSC(uint16_t temp){
	TIM_PrescalerConfig(TIM2,temp,TIM_PSCReloadMode_Update);
}
