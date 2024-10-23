#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "RTC.h"
uint32_t Count;
int main()
{	
	OLED_Init();
	MYRTC_Init();
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR,ENABLE);
	PWR_WakeUpPinCmd(ENABLE);
	Count=RTC_GetCounter();
	RTC_SetAlarm(Count+10);
	while(1){
	OLED_ShowNum(1,1,RTC_GetCounter(),10);
	OLED_ShowNum(2,1,Count+10,10);
	OLED_ShowNum(3,1,RTC_GetFlagStatus(RTC_FLAG_ALR),1);
	Delay_ms(1000);
	OLED_Clear();
	PWR_EnterSTANDBYMode();
	}

}
