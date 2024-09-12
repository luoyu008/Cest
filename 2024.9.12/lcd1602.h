#ifndef __LCD1602_H__
#define __LCD1602_H__
#include <REGX52.H>
void delay(unsigned int count);
void LCDCMD(unsigned char num);
void LCD_Init();
void LCD_SHOWSTRING(unsigned char line,unsigned char column,char* strinng);
void LCD_SHOWNUM(unsigned char line,unsigned char column,unsigned int num);
void LCD_SHOWSIGNEDNNUM(unsigned char line,unsigned char column,int num);
#endif