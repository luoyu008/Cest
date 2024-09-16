#ifndef __LEDDMS_H__
#define __LEDDMS_H__
#include <REGX52.H>
sbit SER=P3^4;
sbit SRCLK=P3^6;
sbit RCLK_=P3^5;
//sbit RCLK=P3^5;
#include "delay.h"
void leddms1(unsigned char num);
#endif
