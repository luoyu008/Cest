#include "stm32f10x.h"                  // Device header
#include <stdio.h>
#include <stdarg.h>
void Serial_Init(void){
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
	USART_InitStruct.USART_Mode=USART_Mode_Tx;//打开发送模式
	USART_InitStruct.USART_Parity=USART_Parity_No;//关闭奇偶检验
	USART_InitStruct.USART_StopBits=USART_StopBits_1;//一位停止位
	USART_InitStruct.USART_WordLength=USART_WordLength_8b;//传输八位数据
	USART_Init(USART1,&USART_InitStruct);
	//打开USART1
	USART_Cmd(USART1,ENABLE);
}

void Serial_Send(uint8_t Data){
	USART_SendData(USART1,Data);
	while(!USART_GetFlagStatus(USART1,USART_FLAG_TXE));
}

void Serial_SendArr(uint8_t ARR[],uint16_t length){
	uint16_t i;
	for(i=0;i<length;i++){
	USART_SendData(USART1,ARR[i]);
	while(!USART_GetFlagStatus(USART1,USART_FLAG_TXE));
	}
}

void Serial_SendString(char* str){
	while(*str!='\0'){
	USART_SendData(USART1,*str);
	while(!USART_GetFlagStatus(USART1,USART_FLAG_TXE));
	str++;
	}
}


void Serial_Print(char * format,...){
	char str[100];
	va_list arg;
	va_start(arg,format);
	vsprintf(str,format,arg);
	va_end(arg);
	Serial_SendString(str);
}

