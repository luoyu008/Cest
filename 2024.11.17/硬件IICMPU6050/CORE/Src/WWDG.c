#include "main.h"
WWDG_HandleTypeDef WWDG_HandInit;
uint16_t count;
void WWDG_Init(void){

	WWDG_HandInit.Init.Counter=0x40+55;
	WWDG_HandInit.Init.EWIMode=WWDG_EWI_ENABLE;
	WWDG_HandInit.Init.Prescaler=WWDG_PRESCALER_8;
	WWDG_HandInit.Init.Window=0x40+33;
	WWDG_HandInit.Instance=WWDG;
	HAL_WWDG_Init(&WWDG_HandInit);
}

void HAL_WWDG_MspInit(WWDG_HandleTypeDef *hwwdg){
	if(hwwdg->Instance==WWDG){
		__HAL_RCC_WWDG_CLK_ENABLE();
		HAL_NVIC_SetPriority(WWDG_IRQn,1,1);
		HAL_NVIC_EnableIRQ(WWDG_IRQn);
	}
}

void WWDG_IRQHandler(void){
	HAL_WWDG_IRQHandler(&WWDG_HandInit);
}

void HAL_WWDG_EarlyWakeupCallback(WWDG_HandleTypeDef *hwwdg){
	if(hwwdg->Instance==WWDG){
		HAL_WWDG_Refresh(&WWDG_HandInit);
		count++;
	}
}
