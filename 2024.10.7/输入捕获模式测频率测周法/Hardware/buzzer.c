#include "stm32f10x.h"                  // Device header
void buzzer_Init(void){//初始化蜂鸣器
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_Structure;
	GPIO_Structure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_Structure.GPIO_Pin=GPIO_Pin_12;
	GPIO_Structure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Structure);
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
}

void buzzer_ON(void){//打开蜂鸣器
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
}

void buzzer_OFF(void){//关闭蜂鸣器
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
}
