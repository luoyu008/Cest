#include "main.h"
UART_HandleTypeDef UART_HandInit;
void UART_Init(void){
	UART_HandInit.Instance=USART1;
	UART_HandInit.Init.BaudRate=115200;
	UART_HandInit.Init.ClockPrescaler=UART_PRESCALER_DIV1;
	UART_HandInit.Init.HwFlowCtl=UART_HWCONTROL_NONE;
	UART_HandInit.Init.Mode=UART_MODE_TX_RX;
	UART_HandInit.Init.OneBitSampling=UART_ONE_BIT_SAMPLE_DISABLE;
	UART_HandInit.Init.OverSampling=UART_OVERSAMPLING_16;
	UART_HandInit.Init.Parity=UART_PARITY_NONE;
	UART_HandInit.Init.StopBits=UART_STOPBITS_1;
	UART_HandInit.Init.WordLength=UART_WORDLENGTH_8B;
	HAL_UART_Init(&UART_HandInit);
}
