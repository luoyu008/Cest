#ifndef __USART_H__
#define __USART_H__
#define count 2
extern uint8_t arr_rx[count];
extern UART_HandleTypeDef UART_HandInit;
extern uint8_t state_rx;
void USART1_Init(void);
#endif
