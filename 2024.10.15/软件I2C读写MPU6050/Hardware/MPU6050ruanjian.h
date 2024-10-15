#ifndef __MPU6050RUANJIAN_H__
#define __MPU6050RUANJIAN_H__
#include "stm32f10x.h"                  // Device header
#include "IIC.h"
extern int16_t arr[6];
void MPU6050_WriteByte(uint8_t ADDRESS,uint8_t Data);
uint8_t MPU6050_ReadByte(uint8_t ADDRESS);
void MPU6050_Init(void);
void MPU6050_ReadData(int16_t* ACCX,int16_t* ACCY,int16_t* ACCZ,int16_t* GYROX,int16_t* GYROY,int16_t* GYROZ);
void MPU6050_ReadData1(int16_t arr[6],uint8_t ADDRESS);
#endif
