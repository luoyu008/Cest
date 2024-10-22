#ifndef __TBSENSOR_H__
#define __TBSENSOR_H__
void Tbsensor_Init(GPIO_TypeDef* GPIOx, uint16_t num);
uint16_t Tbsensor_retrrn(void);

#endif
