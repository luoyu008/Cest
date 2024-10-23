#ifndef __SPIYINGJIAN_H__
#define __SPIYINGJIAN_H__
#include "stm32f10x.h"                  // Device header

void SPIyingjian_Init(void);

void SPIyingjian_Start(void);

void SPIyingjian_Stop(void);

uint8_t SPIyingjian_SwapByte(uint8_t val);
#endif
