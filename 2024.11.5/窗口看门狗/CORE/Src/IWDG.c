#include "main.h"
IWDG_HandleTypeDef IWDG_HnadInit;
void IWDG_Init(void){
	IWDG_HnadInit.Init.Prescaler=IWDG_PRESCALER_16;
	IWDG_HnadInit.Init.Reload=2500;
	IWDG_HnadInit.Instance=IWDG;
	HAL_IWDG_Init(&IWDG_HnadInit);
}
