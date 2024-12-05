#include "main.h"
#define count 2
uint8_t arr_rx[count];
UART_HandleTypeDef UART_HandInit;
uint8_t state_rx;
void USART1_Init(void){

	UART_HandInit.Instance=USART1;
	UART_HandInit.Init.BaudRate=9600;
	UART_HandInit.Init.HwFlowCtl=UART_HWCONTROL_NONE;
	UART_HandInit.Init.Mode=UART_MODE_TX_RX;
//	UART_HandInit.Init.OverSampling=;
	UART_HandInit.Init.Parity=UART_PARITY_NONE;
	UART_HandInit.Init.StopBits=UART_STOPBITS_1;
	UART_HandInit.Init.WordLength=UART_WORDLENGTH_8B;
	
	HAL_UART_Init(&UART_HandInit);
	HAL_UART_Receive_IT(&UART_HandInit,(uint8_t *)arr_rx,count);
//	__HAL_RCC_USART1_CLK_ENABLE();
//	
//	USART_HandleTypeDef USART_HandInitStruct;
//	
//	USART_TypeDef USART_Type;
//	USART_Type.BRR=9600;
//	USART_Type.CR1=0x282C;
//	USART_Type.CR2=0x00;
//	USART_Type.CR3=0x00;
//	USART_Type.DR=0x1D4<<4;
////	USART_Type.GTPR=;
////	USART_Type.SR=;
//	UART_InitTypeDef
//	USART_InitTypeDef USART_InitStruct;
//	USART_InitStruct.BaudRate=9600;
////	USART_InitStruct.CLKLastBit=;
////	USART_InitStruct.CLKPhase=;
//	USART_InitStruct.CLKPolarity=USART_POLARITY_HIGH;
//	USART_InitStruct.Mode=USART_MODE_TX_RX;
//	USART_InitStruct.Parity=USART_PARITY_NONE;
//	USART_InitStruct.StopBits=USART_STOPBITS_1;
//	USART_InitStruct.WordLength=USART_WORDLENGTH_8B;
//	
//	
//	USART_HandInitStruct.Init=USART_InitStruct;
//	USART_HandInitStruct.Instance=&USART_Type;
//	
//	HAL_USART_Init(&USART_HandInitStruct);
}

void HAL_UART_MspInit(UART_HandleTypeDef *huart){
	if(huart->Instance==USART1){
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_USART1_CLK_ENABLE();
		
		GPIO_InitTypeDef GPIO_InitStruct;
		GPIO_InitStruct.Mode=GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pin=GPIO_PIN_9;
		GPIO_InitStruct.Pull=GPIO_NOPULL;
		GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);
		GPIO_InitStruct.Mode=GPIO_MODE_AF_INPUT;
		GPIO_InitStruct.Pin=GPIO_PIN_10;
		GPIO_InitStruct.Pull=GPIO_PULLUP;
		GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);
		
		HAL_NVIC_SetPriority(USART1_IRQn,2,0);
		HAL_NVIC_EnableIRQ(USART1_IRQn);
	}
}

void USART1_IRQHandler(){
	HAL_UART_IRQHandler(&UART_HandInit);
	//由于上一个函数会关闭接收中断 所以还需要再开启一次
	HAL_UART_Receive_IT(&UART_HandInit,(uint8_t *)arr_rx,count);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart->Instance==USART1){
	state_rx=1;
	}
}
