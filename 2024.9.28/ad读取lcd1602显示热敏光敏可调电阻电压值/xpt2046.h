#ifndef __XPT2046_H__
#define __XPT2046_H__
#include <REGX52.H>
sbit DIN=P3^4;
sbit CS=P3^5;
sbit DCLK=P3^6;
sbit DOUT=P3^7;
void WriteByte(unsigned char commend);
//unsigned int ReadByte();
unsigned int  xpt2046_ReadByte(unsigned char commend);
#endif