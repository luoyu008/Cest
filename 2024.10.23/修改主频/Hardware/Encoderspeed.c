#include "stm32f10x.h"                  // Device header
void Encoderspeed_Init(void){
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);//打开tim3时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//打开GPIOA时钟
	//配置a6a7口为浮空输入模式
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//选择时钟 因为编码器接口会托管时钟所以这里可以不用选择时钟
	//配置时基单元1khz
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;//该参数是无用的 因为编码器接口也会托管	
	TIM_TimeBaseInitStructure.TIM_Period=65536-1;//ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler=1-1;//PSC  //不分频 编码器的时钟直接驱动计数器
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);
	//配置捕获通道
	TIM_ICInitTypeDef TIM_ICInitStructure;
	TIM_ICStructInit(&TIM_ICInitStructure);//因为结构体的参数并没有完全用到 所以先赋值为默认值防止出现其他干扰
	TIM_ICInitStructure.TIM_Channel=TIM_Channel_1;
	TIM_ICInitStructure.TIM_ICFilter=0xf;
//	TIM_ICInitStructure.TIM_ICPolarity=TIM_ICPolarity_BothEdge; 编码器接口函数会配置
//	TIM_ICInitStructure.TIM_ICPrescaler=TIM_ICPSC_DIV1;  这两个参数用不到
//	TIM_ICInitStructure.TIM_ICSelection=TIM_ICSelection_DirectTI;
	TIM_ICInit(TIM3,&TIM_ICInitStructure);
	TIM_ICInitStructure.TIM_Channel=TIM_Channel_2;
	TIM_ICInitStructure.TIM_ICFilter=0xf;
//	TIM_ICInitStructure.TIM_ICPolarity=TIM_ICPolarity_BothEdge;编码器接口函数会配置
//	TIM_ICInitStructure.TIM_ICPrescaler=TIM_ICPSC_DIV1;  这两个参数用不到
//	TIM_ICInitStructure.TIM_ICSelection=TIM_ICSelection_DirectTI;
	TIM_ICInit(TIM3,&TIM_ICInitStructure);
	//配置编码器接口  三四参数的意思是通道的极性 也就是通过的波形是否反向 这里选择不反相
	TIM_EncoderInterfaceConfig(TIM3,TIM_EncoderMode_TI12,TIM_ICPolarity_Rising,TIM_ICPolarity_Rising);
	//开启tim3
	TIM_Cmd(TIM3,ENABLE);
	//配置tim2中断
	//打开时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
}

uint16_t Encoderspeed_return(void){
	uint16_t count;
	count=TIM_GetCounter(TIM3);
	TIM_SetCounter(TIM3,0);
	return count;
}
