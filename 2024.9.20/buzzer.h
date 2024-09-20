#ifndef __BUZZER_H__
#define __BUZZER_H__
#include <REGX52.H>
#include "delay.h"
sbit buz=P2^5;
void Buzzer(unsigned int ms);
#endif