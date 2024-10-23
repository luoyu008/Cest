#ifndef __SERIALRECEIVE_H__
#define __SERIALRECEIVE_H__
#include "stm32f10x.h"                  // Device header
extern uint8_t SerialReceive_RXFlag;
void SerialReceive_Init(void);
uint8_t SerialReceive_GetRXFlag(void);
#endif
