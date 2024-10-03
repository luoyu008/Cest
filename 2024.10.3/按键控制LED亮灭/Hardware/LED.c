#include "stm32f10x.h"                  // Device header
void LED_Init(GPIO_TypeDef* GPIOx, uint8_t num){//将A~B的numIO口配置为推挽输出50mhz
	uint32_t num1;
	uint16_t where;
	if(GPIOx==GPIOA){
		num1=RCC_APB2Periph_GPIOA;
	}
	if(GPIOx==GPIOB){
		num1=RCC_APB2Periph_GPIOB;
	}
	if(GPIOx==GPIOC){
		num1=RCC_APB2Periph_GPIOC;
	}
	if(GPIOx==GPIOD){
		num1=RCC_APB2Periph_GPIOD;
	}
	if(GPIOx==GPIOE){
		num1=RCC_APB2Periph_GPIOE;
	}
	if(GPIOx==GPIOF){
		num1=RCC_APB2Periph_GPIOF;
	}
	if(GPIOx==GPIOG){
		num1=RCC_APB2Periph_GPIOG;
	}
	switch(num){
		case 0:where=GPIO_Pin_0;break;
		case 1:where=GPIO_Pin_1;break;
		case 2:where=GPIO_Pin_2;break;
		case 3:where=GPIO_Pin_3;break;
		case 4:where=GPIO_Pin_4;break;
		case 5:where=GPIO_Pin_5;break;
		case 6:where=GPIO_Pin_6;break;
		case 7:where=GPIO_Pin_7;break;
		case 8:where=GPIO_Pin_8;break;
		case 9:where=GPIO_Pin_9;break;
		case 10:where=GPIO_Pin_10;break;
		case 11:where=GPIO_Pin_11;break;
		case 12:where=GPIO_Pin_12;break;
		case 13:where=GPIO_Pin_13;break;
		case 14:where=GPIO_Pin_14;break;
		case 15:where=GPIO_Pin_15;break;
	}
	RCC_APB2PeriphClockCmd(num1,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=(uint16_t)where;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOx,&GPIO_InitStructure);
	GPIO_SetBits(GPIOx,where);
}

void LED_ON(GPIO_TypeDef* GPIOx, uint8_t num){//将A~B的numIO口的LED灯打开
	uint16_t where;
	switch(num){
		case 0:where=GPIO_Pin_0;break;
		case 1:where=GPIO_Pin_1;break;
		case 2:where=GPIO_Pin_2;break;
		case 3:where=GPIO_Pin_3;break;
		case 4:where=GPIO_Pin_4;break;
		case 5:where=GPIO_Pin_5;break;
		case 6:where=GPIO_Pin_6;break;
		case 7:where=GPIO_Pin_7;break;
		case 8:where=GPIO_Pin_8;break;
		case 9:where=GPIO_Pin_9;break;
		case 10:where=GPIO_Pin_10;break;
		case 11:where=GPIO_Pin_11;break;
		case 12:where=GPIO_Pin_12;break;
		case 13:where=GPIO_Pin_13;break;
		case 14:where=GPIO_Pin_14;break;
		case 15:where=GPIO_Pin_15;break;
	}
	GPIO_ResetBits(GPIOx,where);
}

void LED_OFF(GPIO_TypeDef* GPIOx, uint8_t num){//将A~B的numIO口的LED灯关闭
	uint16_t where;
	switch(num){
		case 0:where=GPIO_Pin_0;break;
		case 1:where=GPIO_Pin_1;break;
		case 2:where=GPIO_Pin_2;break;
		case 3:where=GPIO_Pin_3;break;
		case 4:where=GPIO_Pin_4;break;
		case 5:where=GPIO_Pin_5;break;
		case 6:where=GPIO_Pin_6;break;
		case 7:where=GPIO_Pin_7;break;
		case 8:where=GPIO_Pin_8;break;
		case 9:where=GPIO_Pin_9;break;
		case 10:where=GPIO_Pin_10;break;
		case 11:where=GPIO_Pin_11;break;
		case 12:where=GPIO_Pin_12;break;
		case 13:where=GPIO_Pin_13;break;
		case 14:where=GPIO_Pin_14;break;
		case 15:where=GPIO_Pin_15;break;
	}
	GPIO_SetBits(GPIOx,where);
}


void LED_Rever(GPIO_TypeDef* GPIOx, uint8_t num){//反转IO口
	uint16_t where;
	switch(num){
		case 0:where=GPIO_Pin_0;break;
		case 1:where=GPIO_Pin_1;break;
		case 2:where=GPIO_Pin_2;break;
		case 3:where=GPIO_Pin_3;break;
		case 4:where=GPIO_Pin_4;break;
		case 5:where=GPIO_Pin_5;break;
		case 6:where=GPIO_Pin_6;break;
		case 7:where=GPIO_Pin_7;break;
		case 8:where=GPIO_Pin_8;break;
		case 9:where=GPIO_Pin_9;break;
		case 10:where=GPIO_Pin_10;break;
		case 11:where=GPIO_Pin_11;break;
		case 12:where=GPIO_Pin_12;break;
		case 13:where=GPIO_Pin_13;break;
		case 14:where=GPIO_Pin_14;break;
		case 15:where=GPIO_Pin_15;break;
	}
	if(GPIO_ReadOutputDataBit(GPIOx,where)==0){
		GPIO_SetBits(GPIOx,where);
	}
	else{
		GPIO_ResetBits(GPIOx,where);
	}
}
