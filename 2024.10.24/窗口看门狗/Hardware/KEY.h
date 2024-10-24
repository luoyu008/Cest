#ifndef __KEY_H__
#define __KEY_H__
uint8_t KEY_GET(GPIO_TypeDef* GPIOx, uint8_t num);
void KEY_Init(GPIO_TypeDef* GPIOx, uint8_t num);
#endif
