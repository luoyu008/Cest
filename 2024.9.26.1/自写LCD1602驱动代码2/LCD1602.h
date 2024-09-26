#ifndef __LCD1602_H__
#define __LCD1602_H__
#include <REGX52.H>
#include <intrins.h>
sbit RW=P2^5;
sbit RS=P2^6;
sbit EN=P2^7;
#define port P0
void LCD1602_Commend(unsigned char commend);
void LCD1602_Init();
void LCD1602_Data(unsigned char Data);
void LCD1602_ShowChar(unsigned char row,unsigned char col,char s);
void LCD1602_ShowString(unsigned char row,unsigned char col,const char* str);
void LCD1602_ShowNum(unsigned char row,unsigned char col,unsigned int num,unsigned char length);
void LCD1602_BinNum(unsigned char row,unsigned char col,unsigned char num);
void LCD1602_HexNum(unsigned char row,unsigned char col,unsigned int num);
void LCD1602_ShowSignedNum(unsigned char row,unsigned char col,int num,unsigned char length);
#endif