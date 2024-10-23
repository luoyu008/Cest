#ifndef __RTC_H__
#define __RTC_H__
#include "stm32f10x.h"                  // Device header
typedef struct time{
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
	int weak;
}TIME;
extern TIME t;
void TIME_Set(TIME* t,int year,int month,int day,int hour,int min,int sec,int weak);
void MYRTC_Init(void);
void MYRTC_ReadTime(TIME* t);
void MYRTC_SetTime(TIME t);
#endif
