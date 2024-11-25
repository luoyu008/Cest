#include "KEY.h"
uint8_t KEY_return(void){
	uint8_t temp=0;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3)==0){
		HAL_Delay(20);
		while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3)==0);
		HAL_Delay(20);
		temp=1;
	}
	return temp;
}
