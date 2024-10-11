#ifndef __ADC2_H__
#define __ADC2_H__
#include "stm32f10x.h"                  // Device header
void ADC2_Init(void);
uint16_t ADC2_return(uint8_t ADC_Channel);
#endif
