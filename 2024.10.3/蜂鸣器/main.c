#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main()
{	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure0;
	GPIO_InitStructure0.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure0.GPIO_Pin=GPIO_Pin_All;
	GPIO_InitStructure0.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure0);
	while(1){
		
		
	}
}
