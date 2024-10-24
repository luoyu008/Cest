#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "KEY.h"
#include "OLED.h"

int main()
{	
	OLED_Init();
	if(RCC_GetFlagStatus(RCC_FLAG_WWDGRST)){
		OLED_ShowString(2,1,"WWDGREST");
		Delay_ms(500);
		OLED_ShowString(2,1,"        ");
		RCC_ClearFlag();
	}
	else{
		OLED_ShowString(3,1,"REST");
		Delay_ms(500);
		OLED_ShowString(3,1,"        ");
	}
	//打开时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG,ENABLE);
	//设置预分频器 即WDGTB 8分频
	WWDG_SetPrescaler(WWDG_Prescaler_8);
	//	//设置窗口值 即配置寄存器CFR
	WWDG_SetWindowValue(0x40|21);//30ms
	//打开窗口看门狗
	WWDG_Enable(0x40|54);//50ms

	KEY_Init(GPIOB,1);
	while(1){
		if(KEY_GET(GPIOB,1)){
			
		}
//	
//		OLED_ShowString(1,2,"zsp is hansome");
		Delay_ms(49);
		WWDG_SetCounter(0x40|54);
	}
}
