#ifndef __IICRUANJIAN_H__
#define __IICRUANJIAN_H__
void IICruanjian_W_SCL(uint8_t val);
void IICruanjian_W_SDA(uint8_t val);
uint8_t	IICruanjian_R_SDA(void);
void IICruanjian_SendByte(uint8_t val);
uint8_t IICruanjian_ReadByte(void);
void IICruanjian_SendAck(uint8_t Ack);
uint8_t IICruanjian_ReadAck(void);
void IICruanjian_Init(void);
void IICruanjian_Start(void);
void IICruanjian_Stop(void);
#endif
