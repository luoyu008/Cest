#include "stm32f10x.h"                  // Device header
void Timecount_Init(void){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);//打开tim2时钟信号
	
	TIM_InternalClockConfig(TIM2);//选择tim2内部时钟
	//配置时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;//不分频 这里选择的是分频系数
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;//向上计数模式
	TIM_TimeBaseInitStructure.TIM_Period=10000-1;//记数周期即ARR自动装填器的值
	TIM_TimeBaseInitStructure.TIM_Prescaler=7200-1;//预分频器的值
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;//重复记数选项 此选项只有高级定时器才会使用
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);//初始化时基单元
	
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
//void TIM2_IRQHandler(void){
//	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET){
//		
//		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
//	}
//}
