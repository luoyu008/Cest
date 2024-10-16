#ifndef __BLUETOOTH_H__
#define __BLUETOOTH_H__
#include "stm32f10x.h"                  // Device header
void Bluetooth_Init(void);
void Serial_SendArr1(uint8_t ARR[],uint16_t length);
void Serial_SendString1(char* str);
#endif
