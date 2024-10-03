#ifndef __LED_H__
#define __LED_H__
void LED_Init(GPIO_TypeDef* GPIOx, uint8_t num);

void LED_ON(GPIO_TypeDef* GPIOx, uint8_t num);

void LED_OFF(GPIO_TypeDef* GPIOx, uint8_t num);

void LED_Rever(GPIO_TypeDef* GPIOx, uint8_t num);
#endif
