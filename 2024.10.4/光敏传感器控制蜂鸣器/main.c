#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "BUZZER.h"
#include "LIGHT.h"
uint8_t num;
int main()
{	
	buzzer_Init();
	light_Init();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);

	while(1){
		num=light_return();
		if(num==0){
		GPIO_ResetBits(GPIOC,GPIO_Pin_13);
		buzzer_OFF();
		}
		else{
		GPIO_SetBits(GPIOC,GPIO_Pin_13);
		buzzer_ON();
		}
		
		
	}
}
