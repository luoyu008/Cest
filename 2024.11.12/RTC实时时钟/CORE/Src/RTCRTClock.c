#include "main.h"
#include <time.h>
#include "OLED.h"
RTC_HandleTypeDef RTC_RTClockHandInit;
RCC_OscInitTypeDef RCC_RTCOscInit;
RCC_PeriphCLKInitTypeDef RCC_RTClockPerInit;
uint8_t wasd;
typedef struct time{
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
	int weak;
}TIME;
TIME t;
void TIME_Set(TIME* t,int year,int month,int day,int hour,int min,int sec,int weak){
	(*t).year=year;
	(*t).month=month;
	(*t).day=day;
	(*t).hour=hour;
	(*t).min=min;
	(*t).sec=sec;
	(*t).weak=weak;
}

void MYRTC_SetTime(TIME t){
	time_t cnt;
	struct tm time;
	time.tm_year=t.year-1900;
	time.tm_mon=t.month-1;
	time.tm_mday=t.day;
	time.tm_hour=t.hour;
	time.tm_min=t.min;
	time.tm_sec=t.sec;
	time.tm_wday=t.weak;
	cnt=mktime(&time)-8*60*60;

	RTC_WriteTimeCounter(&RTC_RTClockHandInit,cnt);
}

void MYRTC_ReadTime(TIME* t){
	time_t cnt;
	struct tm time;
	cnt=RTC_ReadTimeCounter(&RTC_RTClockHandInit)+8*60*60;
	time=*localtime(&cnt);
	(*t).year=time.tm_year+1900;
	(*t).month=time.tm_mon+1;
	(*t).hour=time.tm_hour;
	(*t).day=time.tm_mday;
	(*t).min=time.tm_min;
	(*t).sec=time.tm_sec;
	(*t).weak=time.tm_wday;
}

void RTCRTClock_Init(void){
	RTC_RTClockHandInit.Instance=RTC;
	RTC_RTClockHandInit.Init.AsynchPrediv=RTC_AUTO_1_SECOND;//分频器的值
	RTC_RTClockHandInit.Init.OutPut=RTC_OUTPUTSOURCE_NONE;
//	RTC_RTClockHandInit.State=
	wasd=HAL_RTC_Init(&RTC_RTClockHandInit);
	OLED_ShowNum(0,40,wasd,3,16);
	OLED_UpData();
	RCC_RTCOscInit.LSEState=RCC_LSE_ON;
	RCC_RTCOscInit.OscillatorType=RCC_OSCILLATORTYPE_LSE;
//	RCC_RTCOscInit.PLL=RCC_PLL_NONE;
	HAL_RCC_OscConfig(&RCC_RTCOscInit);
	
	RCC_RTClockPerInit.RTCClockSelection=RCC_RTCCLKSOURCE_LSE;
	RCC_RTClockPerInit.PeriphClockSelection=RCC_PERIPHCLK_RTC;
	HAL_RCCEx_PeriphCLKConfig(&RCC_RTClockPerInit);
	
	if(HAL_RTCEx_BKUPRead(&RTC_RTClockHandInit,RTC_BKP_DR1)!=0X5050){
		TIME_Set(&t,2024,11,12,20,20,20,2);
		MYRTC_SetTime(t);
		HAL_RTCEx_BKUPWrite(&RTC_RTClockHandInit,RTC_BKP_DR1,0X5050);
	}
}

void HAL_RTC_MspInit(RTC_HandleTypeDef *hrtc){
	if(hrtc->Instance==RTC){
//		//使能RTC备份域访问权
		HAL_PWR_EnableBkUpAccess();
		
//		__HAL_RCC_PWR_CLK_ENABLE();
		__HAL_RCC_BKP_CLK_ENABLE();
		
		__HAL_RCC_RTC_ENABLE();
	}
}

void HAL_RTC_MspDeInit(RTC_HandleTypeDef* rtcHandle)
{

  if(rtcHandle->Instance==RTC)
  {
  /* USER CODE BEGIN RTC_MspDeInit 0 */

  /* USER CODE END RTC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_RTC_DISABLE();
  /* USER CODE BEGIN RTC_MspDeInit 1 */

  /* USER CODE END RTC_MspDeInit 1 */
  }
}
