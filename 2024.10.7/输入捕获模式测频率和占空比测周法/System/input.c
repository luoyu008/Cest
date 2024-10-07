#include "stm32f10x.h"                  // Device header
void input_Init(void){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	//配置a6为浮空输入口
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//tim3使用内部时钟
	TIM_InternalClockConfig(TIM3);
	//配置时基单元 1mhz
	TIM_TimeBaseInitTypeDef TIM_InitStructure;
	TIM_InitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_InitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_InitStructure.TIM_Period=65536-1;//ARR
	TIM_InitStructure.TIM_Prescaler=72-1;//PSC
	TIM_InitStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM3,&TIM_InitStructure);
	
	//配置输入通道
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
	//选择从模式触发源
	TIM_SelectInputTrigger(TIM3,TIM_TS_TI1FP1);
	//清零计数器
	TIM_SelectSlaveMode(TIM3,TIM_SlaveMode_Reset);
	
	//开启tim3
	TIM_Cmd(TIM3,ENABLE);
}
