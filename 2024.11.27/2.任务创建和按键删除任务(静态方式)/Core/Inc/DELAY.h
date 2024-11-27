#ifndef __DELAY_H__
#define __DELAY_H__
#include "main.h"
extern uint16_t g_fac_us;
void DELAY_Init(uint16_t sysclk);
void DELAY_us(uint32_t nus);
void DELAY_ms(uint16_t nms);

#endif 
