#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "KEY.h"
#include "RTC.h"
#include <time.h>
int main()
{	
	OLED_Init();
	MYRTC_Init();
	
	OLED_ShowString(1,1,"Date:xxxx-xx-xx");
	OLED_ShowString(2,1,"Time:xx:xx:xx,x");
	while(1){
	MYRTC_ReadTime(&t);
	OLED_ShowNum(1,6,t.year,4);
	OLED_ShowNum(1,11,t.month,2);
	OLED_ShowNum(1,14,t.day,2);
	OLED_ShowNum(2,6,t.hour,2);
	OLED_ShowNum(2,9,t.min,2);
	OLED_ShowNum(2,12,t.sec,2);
	OLED_ShowNum(2,15,t.weak,1);

	}

}
