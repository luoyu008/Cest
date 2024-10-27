#ifndef __MYOLED_H__
#define __MYOLED_H__
#include "stm32f10x.h"                  // Device header
#include "IIC.h"
void MYOLED_WCommand(uint8_t Command);
void MYOLED_WData(uint8_t Data);
void MYOLED_Init(void);
void OLED_SetLocation(uint8_t row,uint8_t col);
void MYOLED_ShowChar(uint8_t row,uint8_t col,uint8_t Char,uint8_t DataSize);
void MYOLED_Clear(void);
void MYOLED_ShowImage(uint8_t row,uint8_t col,uint8_t length,uint8_t width,const uint8_t arr_Image[]);
void MYOLED_ShowString(uint8_t row,uint8_t col,char* Str,uint8_t DataSize);
void MYOLED_ShowNum(uint8_t row,uint8_t col,uint32_t Num,uint8_t length,uint8_t DataSize);
void MYOLED_ShowSignedNum(uint8_t row,uint8_t col,int Num,uint8_t length, uint8_t DataSize);
void MYOLED_ShowBinNum(uint8_t row,uint8_t col,uint32_t Num,uint8_t length,uint8_t DataSize);
void MYOLED_ShowHexNum(uint8_t row,uint8_t col,uint32_t Num,uint8_t length,uint8_t DataSize);


#endif
