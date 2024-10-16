#ifndef __DMAARR_H__
#define __DMAARR_H__
#include "stm32f10x.h"                  // Device header
void DMAARR_Init(uint32_t src,uint32_t des,uint16_t size);
void DMAARR_Start(DMA_Channel_TypeDef* DMAy_Channelx, uint16_t DataNumber);
#endif
