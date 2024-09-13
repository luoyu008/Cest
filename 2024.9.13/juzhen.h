#ifndef __JUZHEN_H__
#define __JUZHEN_H__
#include "LCD1602.h"
#include "delay.h"
void LCD_WriteCommand(unsigned char Command);
int numlen(unsigned int num);
unsigned char retkey();
void xianshi(unsigned char rekey,unsigned int* pass,unsigned char* locationn,unsigned int* my_pass);
void judge(unsigned int pass,unsigned int my_pass,unsigned location);
#endif