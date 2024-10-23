#include "stm32f10x.h"                  // Device header
void SG90_Init(void){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);//打开tim2时钟信号
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	TIM_InternalClockConfig(TIM2);

	//配置时基单元
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;//不分频 这里选择的是分频系数
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;//向上计数模式
	TIM_TimeBaseInitStructure.TIM_Period=20000-1;//记数周期即ARR自动装填器的值
	TIM_TimeBaseInitStructure.TIM_Prescaler=72-1;//预分频器的值//PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;//重复记数选项 此选项只有高级定时器才会使用
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);//初始化时基单元
	
	//配置结构体
	TIM_OCInitTypeDef TIM_InitStructure;
	TIM_OCStructInit(&TIM_InitStructure);//先赋值默认值 这样不需要用到的成员就可以不用修改
	//TIM_InitStructure.TIM_OCIdleState=TIM_OCIdleState_Reset;
	TIM_InitStructure.TIM_OCMode=TIM_OCMode_PWM1;	
//	TIM_InitStructure.TIM_OCNIdleState=TIM_OCNIdleState_Reset;
//	TIM_InitStructure.TIM_OCNPolarity=0;
	TIM_InitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	//TIM_InitStructure.TIM_OutputNState=0;
	TIM_InitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_InitStructure.TIM_Pulse=0;		//CCR
	TIM_OC2Init(TIM2,&TIM_InitStructure);
	
	//开启TIM2
	TIM_Cmd(TIM2,ENABLE);
}	

//TIM_SetCompare2(TIM2,Rangle);
//中断函数2的模板
//void TIM2_IRQHandler(void){
//	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET){
//		
//		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
//	}
//}
