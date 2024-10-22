#ifndef __MPU6050YINGJIAN_H__
#define __MPU6050YINGJIAN_H__
#include "stm32f10x.h"                  // Device header
void MPU6050yingjian_WriteReg(uint8_t ADDRESS,uint8_t Date);
uint8_t MPU6050yingjian_ReadReg(uint8_t ADDRESS);
void MPU6050yingjian_Init(void);
void MPU6050yingjian_ReadData(int16_t* ACCX,int16_t* ACCY,int16_t* ACCZ,
						int16_t* GYROX,int16_t* GYROY,int16_t* GYROZ);
#endif
