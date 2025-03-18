#include "main.h"
uint8_t B1_KEY;
uint8_t B2_KEY;
uint8_t B3_KEY;
uint8_t B4_KEY;
void KEY_Init(void){
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	
	GPIO_InitTypeDef GPIO_Init;
	GPIO_Init.Mode=GPIO_MODE_INPUT;
	GPIO_Init.Pin=GPIO_PIN_0;
	GPIO_Init.Pull=GPIO_PULLUP;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_Init);
	
	GPIO_Init.Mode=GPIO_MODE_IT_FALLING;
	GPIO_Init.Pin=GPIO_PIN_1;
	GPIO_Init.Pull=GPIO_PULLUP;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_Init);
	
	GPIO_Init.Mode=GPIO_MODE_IT_FALLING;
	GPIO_Init.Pin=GPIO_PIN_2;
	GPIO_Init.Pull=GPIO_PULLUP;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_Init);
	
	GPIO_Init.Mode=GPIO_MODE_IT_FALLING;
	GPIO_Init.Pin=GPIO_PIN_0;
	GPIO_Init.Pull=GPIO_PULLUP;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA,&GPIO_Init);
	
	HAL_NVIC_SetPriority(EXTI0_IRQn,1,0);
	HAL_NVIC_SetPriority(EXTI1_IRQn,1,1);
	HAL_NVIC_SetPriority(EXTI2_IRQn,1,2);
	
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
	HAL_NVIC_EnableIRQ(EXTI1_IRQn);
	HAL_NVIC_EnableIRQ(EXTI2_IRQn);
}

uint8_t KEY_return(void){
	uint8_t temp=0;
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==0){
		HAL_Delay(10);
		while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==0);
		HAL_Delay(10);
		temp=1;
	}
	return temp;
}

void EXTI0_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
}

void EXTI1_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
}

void EXTI2_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin==GPIO_PIN_0){
		for(int i=0;i<10000;i++);	//10000延时大概4ms
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)==GPIO_PIN_RESET){
			B4_KEY=1;
		}
	}else if(GPIO_Pin==GPIO_PIN_1){
		for(int i=0;i<10000;i++);	//10000延时大概4ms
		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1)==GPIO_PIN_RESET){
			B2_KEY=1;
		}
	}else if(GPIO_Pin==GPIO_PIN_2){
		for(int i=0;i<10000;i++);	//10000延时大概4ms
		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_2)==GPIO_PIN_RESET){
			B3_KEY=1;
		}
	}
}
