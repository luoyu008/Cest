#include "stm32f10x.h"                  // Device header
void SerialReceive_Init(void){
	//打开时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	//配置引脚
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//推挽复用输出
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//上拉输入
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//初始化usart
	USART_InitTypeDef USART_InitStruct;
	USART_InitStruct.USART_BaudRate=9600;//波特率
	USART_InitStruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;//关闭硬件流控制
	USART_InitStruct.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;//打开发送和接受模式
	USART_InitStruct.USART_Parity=USART_Parity_No;//关闭奇偶检验
	USART_InitStruct.USART_StopBits=USART_StopBits_1;//一位停止位
	USART_InitStruct.USART_WordLength=USART_WordLength_8b;//传输八位数据
	USART_Init(USART1,&USART_InitStruct);
	//打开USART1中断
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	//配置NVIC
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel=USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStruct);
	//打开USART1
	USART_Cmd(USART1,ENABLE);
}


//void USART1_IRQHandler(void){
//	if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET){
//		
//		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
//	}
//}
