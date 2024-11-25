#ifndef __MYOLEDPLUS_H__
#define __MYOLEDPLUS_H__
#include "stm32f10x.h"                  // Device header
extern uint8_t arr_main[8][128];
void MYOLEDPLUS_WCommand(uint8_t Command);
void MYOLEDPLUS_WData(uint8_t Data[],uint8_t count);
void MYOLEDPLUS_Init(void);
void MYOLEDPLUS_SetLocation(uint8_t row,uint8_t col);
void MYOLEDPLUS_UpData(void);
void MYOLEDPLUS_Clear(void);
void MYOLEDPLUS_ClearArea(uint8_t x,uint8_t y,uint8_t length,uint8_t width);
void MYOLEDPLUS_ShowImage(uint8_t x,uint8_t y,uint8_t length,uint8_t width,uint8_t arr[]);
void MYOLEDPLUS_ShowChar(uint8_t x,uint8_t y,char Char,uint8_t DataSize);
void MYOLEDPLUS_ShowString(uint8_t x,uint8_t y,char* Str,uint8_t DataSize);
void MYOLEDPLUS_ShowNum(uint8_t x,uint8_t y,uint32_t Num,uint8_t length,uint8_t DataSize);
void MYOLEDPLUS_ShowSignedNum(uint8_t x,uint8_t y,int Num,uint8_t length,uint8_t DataSize);
void MYOLEDPLUS_ShowBinNum(uint8_t x,uint8_t y,uint32_t Num,uint8_t length,uint8_t DataSize);
void MYOLEDPLUS_ShowHexNum(uint8_t x,uint8_t y,uint32_t Num,uint8_t length,uint8_t DataSize);
void MYOLEDPLUS_LightUpDot(uint8_t x,uint8_t y);
void MYOLEDPLUS_LightDownDot(uint8_t x,uint8_t y);
void MYOLEDPLUS_LightUpRec(uint8_t x,uint8_t y,uint8_t length ,uint8_t width,uint8_t Pad);
void MYOLEDPLUS_ShowLine(uint8_t x,uint8_t y,uint8_t x1,uint8_t y1);
void MYOLEDPLUS_ShowRound(uint8_t x,uint8_t y,uint8_t radius,uint8_t Pad);
void MYOLEDPLUS_ShowChinese(uint8_t x,uint8_t y,char* Str);
#endif
