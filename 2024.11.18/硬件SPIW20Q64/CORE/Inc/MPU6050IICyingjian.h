#ifndef __MPU6050IICYINGJIAN_H__
#define __MPU6050IICYINGJIAN_H__
extern uint8_t arr_Spackge[2];
extern uint8_t arr_Rpackge[2];
void MPU6050IICyingjian_WriteByte(uint8_t ADDRESS,uint8_t Data);
uint8_t MPU6050IICyingjian_ReadByte(uint8_t ADDRESS);
void MPU6050IICyingjian_Init(void);
void MPU6050IICyingjian_ReadData(int16_t* ACCX,int16_t* ACCY,int16_t* ACCZ,
						int16_t* GYROX,int16_t* GYROY,int16_t* GYROZ);
#endif
