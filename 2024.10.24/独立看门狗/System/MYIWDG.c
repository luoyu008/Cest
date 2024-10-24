#include "stm32f10x.h"                  // Device header
void MYIWDG_Init(void){
	//打开PR和RLR的写访问权限
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	//设置16分频
	IWDG_SetPrescaler(IWDG_Prescaler_16);
	//设置时长1000ms
	IWDG_SetReload(2499);
	//打开独立看门狗
	IWDG_Enable();
}

void MYIWDG_FDOG(void){
	IWDG_ReloadCounter();
}
