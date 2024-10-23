#ifndef __DMA1_H__
#define __DMA1_H__
#include "stm32f10x.h"// Device header
extern uint16_t dest[4];
void DMA1_Init(void);
void DMA1_Start(void);

#endif
