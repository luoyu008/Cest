#ifndef __MPU6050RUANJIANIIC_H__
#define __MPU6050RUANJIANIIC_H__
extern int16_t arr_MPU6050[6];//¥Ê∑≈¡˘÷· ˝æ›
void MPU6050ruanjianIIC_WriteByte(uint8_t ADDRESS,uint8_t Data);
uint8_t MPU6050ruanjianIIC_ReadByte(uint8_t ADDRESS);
void MPU6050ruanjianIIC_Init(void);
void MPU6050ruanjianIIC_ReadData(int16_t* ACCX,int16_t* ACCY,int16_t* ACCZ,
						int16_t* GYROX,int16_t* GYROY,int16_t* GYROZ);
#endif

