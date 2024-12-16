#ifndef __RTCRTCLOCK_H__
#define __RTCRTCLOCK_H__
extern RTC_HandleTypeDef RTC_RTClockHandInit;
extern RCC_OscInitTypeDef RCC_RTCOscInit;
extern RCC_PeriphCLKInitTypeDef RCC_RTClockPerInit;
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
void MYRTC_SetTime(TIME t);
void RTCRTClock_Init(void);

void MYRTC_ReadTime(TIME* t);
void MYRTC_SetTime(TIME t);
void TIME_Set(TIME* t,int year,int month,int day,int hour,int min,int sec,int weak);
#endif
