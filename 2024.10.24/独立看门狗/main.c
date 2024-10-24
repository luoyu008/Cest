#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "KEY.h"
#include "OLED.h"
#include "MYIWDG.h"
int main()
{	
	OLED_Init();
	KEY_Init(GPIOB,1);
	if(RCC_GetFlagStatus(RCC_FLAG_IWDGRST)){
		OLED_ShowString(2,1,"IWDGREST");
		Delay_ms(500);
		OLED_ShowString(2,1,"        ");
		RCC_ClearFlag();
	}
	else{
		OLED_ShowString(3,1,"REST");
		Delay_ms(500);
		OLED_ShowString(3,1,"        ");
	}
	
	//��PR��RLR��д����Ȩ��
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	//����16��Ƶ
	IWDG_SetPrescaler(IWDG_Prescaler_16);
	//����ʱ��1000ms
	IWDG_SetReload(2499);
	//�򿪶������Ź�
	IWDG_Enable();
	IWDG_ReloadCounter();
	while(1){
		if(KEY_GET(GPIOB,1)){
			
		}
		
		OLED_ShowString(1,2,"zsp is hansome");
		Delay_ms(500);
		IWDG_ReloadCounter();
	}
}
