#ifndef __STORE_H__
#define __STORE_H__
#include "stm32f10x.h"                  // Device header
extern uint16_t arr[];
void Store_Init(void);
void Store_Save(void);
void Store_Clear(void);
#endif
