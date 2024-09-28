#ifndef __SMOTORE_H__
#define __SMOTORE_H__
#include <REGX52.H>
sbit DA=P2^1;
sbit IN2=P1^1;
sbit IN3=P1^2;
sbit IN4=P1^3;
void smotors_Start();
void smotors_Stop();
#endif