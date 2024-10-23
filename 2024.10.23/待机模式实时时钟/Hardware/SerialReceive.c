#include "stm32f10x.h"                  // Device header
void SerialReceive_Init(void){
	//��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	//��������
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//���츴�����
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//��������
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//��ʼ��usart
	USART_InitTypeDef USART_InitStruct;
	USART_InitStruct.USART_BaudRate=9600;//������
	USART_InitStruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;//�ر�Ӳ��������
	USART_InitStruct.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;//�򿪷��ͺͽ���ģʽ
	USART_InitStruct.USART_Parity=USART_Parity_No;//�ر���ż����
	USART_InitStruct.USART_StopBits=USART_StopBits_1;//һλֹͣλ
	USART_InitStruct.USART_WordLength=USART_WordLength_8b;//�����λ����
	USART_Init(USART1,&USART_InitStruct);
	//��USART1�ж�
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	//����NVIC
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel=USART1_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVIC_InitStruct);
	//��USART1
	USART_Cmd(USART1,ENABLE);
}


//void USART1_IRQHandler(void){
//	if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET){
//		
//		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
//	}
//}
