#ifndef __SPIRUANJIAN_H__
#define __SPIRUANJIAN_H__
#include "stm32f10x.h"                  // Device header
void SPIruanjian_WriteCS(uint8_t val);

void SPIruanjian_WriteSCK(uint8_t val);


void SPIruanjian_WriteDI(uint8_t val);

uint8_t SPIruanjian_ReadDO(void);


void SPIruanjian_Init(void);

void SPIruanjian_Start(void);

void SPIruanjian_Stop(void);

uint8_t SPIruanjian_SwapByte(uint8_t val);

#endif
