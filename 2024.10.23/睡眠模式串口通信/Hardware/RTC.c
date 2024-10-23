#include "stm32f10x.h"                  // Device header
#include <time.h>
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
	RTC_SetCounter(cnt);
	RTC_WaitForLastTask();
}

void MYRTC_Init(void){
	//打开PWR和BKP时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_BKP,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);
	//设置PWR_CR的DBP位，使能对BKP和RTC的访问
	PWR_BackupAccessCmd(ENABLE);
	if(BKP_ReadBackupRegister(BKP_DR1)!=0xA5A5){
	//选择时钟
	RCC_LSEConfig(RCC_LSE_ON);
	//等待LSE准备好
	while(RCC_GetFlagStatus(RCC_FLAG_LSERDY)!=1);
	
	//RTC时钟选择
	RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);
	//使能时钟
	RCC_RTCCLKCmd(ENABLE);
	
	//等待同步
	RTC_WaitForSynchro();
	//等待上次写操作完成
	RTC_WaitForLastTask();
	
	
	//设置预分频器PRL的值 内置进入配置模式和退出配置模式的函数不需额外添加 1hz
	RTC_SetPrescaler(32678-1);
	//等待上次写操作完成
	RTC_WaitForLastTask();
	//设置时间
	RTC_SetCounter(1729597300);
	//等待上次写操作完成
	RTC_WaitForLastTask();
	TIME_Set(&t,2024,10,22,21,33,00,2);
	MYRTC_SetTime(t);
	BKP_WriteBackupRegister(BKP_DR1,0xA5A5);
	}
	else{
	//等待同步
	RTC_WaitForSynchro();
	//等待上次写操作完成
	RTC_WaitForLastTask();
	}
}
	

void MYRTC_ReadTime(TIME* t){
	time_t cnt;
	struct tm time;
	cnt=RTC_GetCounter()+8*60*60;
	time=*localtime(&cnt);
	(*t).year=time.tm_year+1900;
	(*t).month=time.tm_mon+1;
	(*t).hour=time.tm_hour;
	(*t).day=time.tm_mday;
	(*t).min=time.tm_min;
	(*t).sec=time.tm_sec;
	(*t).weak=time.tm_wday;
}
