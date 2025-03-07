#ifndef __OLED_H__
#define __OLED_H__
void OLED_Init(void);
void OLED_WriteData(uint8_t arr[],uint8_t count);
void OLED_WriteCommand(uint8_t command);
void OLED_SetLocation(uint8_t x,uint8_t y);
void OLED_Clear(void);
void OLED_UpData(void);
void OLED_CLearArea(uint8_t x,uint8_t y,uint8_t length,uint8_t width);
void OLED_ShowImage(uint8_t x,uint8_t y,uint8_t length,uint8_t width,const uint8_t arr[]);
void OLED_ShowChar(uint8_t x,uint8_t y,char Char,uint8_t DataSize);
void OLED_ShowString(uint8_t x,uint8_t y,char* Str,uint8_t DataSize);
void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t Num,uint8_t length,uint8_t DataSize);
void OLED_ShowSignedNum(uint8_t x,uint8_t y,int Num,uint8_t length,uint8_t DataSize);
void OLED_ShowBinNum(uint8_t x,uint8_t y,uint32_t Num,uint8_t length,uint8_t DataSize);
void OLED_ShowHexNum(uint8_t x,uint8_t y,uint32_t Num,uint8_t length,uint8_t DataSize);

#endif
