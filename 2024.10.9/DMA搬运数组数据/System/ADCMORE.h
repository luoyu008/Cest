#ifndef __ADCMORE_H__
#define __ADCMORE_H__
#include "stm32f10x.h"                  // Device header
void ADCMORE_Init(void);
uint16_t ADCMORE_return1(uint8_t ADC_Channel, uint8_t Rank);
#endif
