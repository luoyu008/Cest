#ifndef __IIC_H__
#define __IIC_H__
#include "stm32f10x.h"                  // Device header
void MyI2C_W_SCL(uint8_t val);
void MyI2C_W_SDA(uint8_t val);
uint8_t MyI2C_R_SDA(void);
void MyI2C_SendByte(uint8_t Date);
uint8_t MyI2C_ReadByte(void);
void MyI2C_SendAck(uint8_t Ack);
uint8_t MyI2C_ReadAck(void);
void IIC_Init(void);
void IIC_Start(void);
void IIC_Stop(void);



#endif
