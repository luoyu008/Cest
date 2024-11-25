#include "stm32f10x.h"                  // Device header
uint8_t TxFlage;
void Time_Init(void){
	//打开时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	//选择内部时钟
	TIM_InternalClockConfig(TIM2);
	//配置100ms
	TIM_TimeBaseInitTypeDef Time_BaseInit;
	Time_BaseInit.TIM_ClockDivision=TIM_CKD_DIV1;
	Time_BaseInit.TIM_CounterMode=TIM_CounterMode_Up;
	Time_BaseInit.TIM_Period=1000-1;
	Time_BaseInit.TIM_Prescaler=7200-1;
	Time_BaseInit.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM2,&Time_BaseInit);
	
	TIM_ClearFlag(TIM2,TIM_FLAG_Update);//上一个函数的末尾直接开启了一次中断 所以先将中断标志位清零
	TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);//开启中断
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//NVIC分组
	//配置NVIC
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel=TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStructure);
	//开启TIM2
	TIM_Cmd(TIM2,ENABLE);

}

//中断函数2的模板
void TIM2_IRQHandler(void){
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET){
		TxFlage=1;
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
}
