#include "main.h"
#include "OLED.h"
#include "DELAY.h"
GPIO_InitTypeDef GPIO_RencoderInit;
uint16_t Rcount;
void Rencoder_Init(void){
	//´ò¿ªÊ±ÖÓ
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_AFIO_CLK_ENABLE();
	
	GPIO_RencoderInit.Mode=GPIO_MODE_IT_FALLING;
	GPIO_RencoderInit.Pin=GPIO_PIN_1;
	GPIO_RencoderInit.Pull=GPIO_PULLUP;
	GPIO_RencoderInit.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA,&GPIO_RencoderInit);
	GPIO_RencoderInit.Mode=GPIO_MODE_INPUT;
	GPIO_RencoderInit.Pin=GPIO_PIN_2;
	GPIO_RencoderInit.Pull=GPIO_PULLUP;
	GPIO_RencoderInit.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA,&GPIO_RencoderInit);
	HAL_NVIC_SetPriority(EXTI1_IRQn,0,0);
	HAL_NVIC_EnableIRQ(EXTI1_IRQn);
//	HAL_NVIC_SetPriority(EXTI2_IRQn,0,1);
//	HAL_NVIC_EnableIRQ(EXTI2_IRQn);
}

void EXTI1_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_1);
}

//void EXTI2_IRQHandler(void){
//	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
//	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_2);
//	OLED_ShowChar(0,17,'C',16);
//	OLED_UpData();
//}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	DELAY_us(5);
	
	if(GPIO_Pin==GPIO_PIN_1){
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_2)==1){
			Rcount++;
		}
		else{
			Rcount--;
		}
	}
//	if(GPIO_Pin==GPIO_PIN_2){
//		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1)==0){
//			Rcount--;
//		}
//	}
}
