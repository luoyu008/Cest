#ifndef __W25Q64RUANJIAN_H__
#define __W25Q64RUANJIAN_H__
#include "stm32f10x.h"                  // Device header
#include "SPIruanjian.h"
void W25Q64ruanjian_Init(void);
void W25Q64ruanjian_ReadID(uint8_t* MID,uint16_t* ID);
void W25Q64ruanjian_SectorErase(uint32_t Address);
void W25Q64ruanjian_WritePage(uint32_t Address,uint8_t* DataArry,uint16_t count);
void W25Q64ruanjian_ReadData(uint32_t Address,uint8_t* DataArry,uint32_t count);
#endif
