#ifndef __ONEWIRE_H__
#define __ONEWIRE_H__
#include <REGX52.H>
#include <intrins.h>
sbit DQ=P3^7;
unsigned char onewire_Init();
void onewire_SendBit(unsigned char Bit);
unsigned char onewire_Receive();
void onewire_SendByte(unsigned char Byte);
unsigned char onewire_ReceiveByte();
#endif