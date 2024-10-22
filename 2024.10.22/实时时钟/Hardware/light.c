#include "stm32f10x.h"                  // Device header
void light_Init(void){//初始化光敏传感器
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_Structure;
	GPIO_Structure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Structure.GPIO_Pin=GPIO_Pin_13;
	GPIO_Structure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Structure);
}

uint8_t light_return(void){//得到光敏传感器输出的电平
	uint8_t num;
	num=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13);
	return num;
}
