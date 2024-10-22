#ifndef __Serial_H__
#define __Serial_H__
#include "stm32f10x.h"                  // Device header
void Serial_Init(void);
void Serial_Send(uint8_t Data);
void Serial_SendArr(uint8_t ARR[],uint16_t length);
void Serial_SendString(char* str);
void Serial_Print(char * format,...);
#endif
