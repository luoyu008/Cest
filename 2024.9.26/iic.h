#ifndef __IIC_H__
#define __IIC_H__
#include <REGX52.H>
sbit SDA=P2^0;
sbit SCL=P2^1;
void iic_Start();
void iic_Stop();
void iic_Send(unsigned char date);
unsigned char iic_Receive();
void iic_Sendres(unsigned char res);
unsigned char  iic_Receiveres();
#endif