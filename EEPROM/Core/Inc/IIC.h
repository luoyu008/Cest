#ifndef __IIC_H__
#define __IIC_H__
void M24c02_Init(void);
void M24c02_Write(uint8_t Address,uint8_t Data);
uint8_t M24c02_Read(uint8_t Address);
#endif 
