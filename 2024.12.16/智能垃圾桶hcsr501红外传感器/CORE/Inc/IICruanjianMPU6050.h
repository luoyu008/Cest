#ifndef __IICRUANJIANMPU6050_H__
#define __IICRUANJIANMPU6050_H__
void IICruanjianMPU6050_W_SCL(uint8_t val);
void IICruanjianMPU6050_W_SDA(uint8_t val);
uint8_t	IICruanjianMPU6050_R_SDA(void);
void IICruanjianMPU6050_SendByte(uint8_t val);
uint8_t IICruanjianMPU6050_ReadByte(void);
void IICruanjianMPU6050_SendAck(uint8_t Ack);
uint8_t IICruanjianMPU6050_ReadAck(void);
void IICruanjianMPU6050_Init(void);
void IICruanjianMPU6050_Start(void);
void IICruanjianMPU6050_Stop(void);

#endif
