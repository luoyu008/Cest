#include "stm32f10x.h"                  // Device header
void MYIWDG_Init(void){
	//��PR��RLR��д����Ȩ��
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	//����16��Ƶ
	IWDG_SetPrescaler(IWDG_Prescaler_16);
	//����ʱ��1000ms
	IWDG_SetReload(2499);
	//�򿪶������Ź�
	IWDG_Enable();
}

void MYIWDG_FDOG(void){
	IWDG_ReloadCounter();
}
