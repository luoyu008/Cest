#ifndef __USART_H__
#define __USART_H__
extern uint8_t arr_rx[1];
extern UART_HandleTypeDef UART_HandInit;
extern uint8_t state_rx;
void USART1_Init(void);
#endif
