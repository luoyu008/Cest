#include "stm32f10x.h"                  // Device header
uint16_t count;
void Tbsensor_Init(GPIO_TypeDef* GPIOx, uint16_t num){//初始化传感器为上拉输入50mhz模式,并配置外部中断
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
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);//打开AFIO时钟
	GPIO_InitTypeDef GPIO_Structure;
	GPIO_Structure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Structure.GPIO_Pin=where;
	GPIO_Structure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOx,&GPIO_Structure);
	//配置EXTI
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line=EXTI_Line14;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStructure);

	//配置NVIC
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVID_InitStructure;
	NVID_InitStructure.NVIC_IRQChannel=EXTI15_10_IRQn;
	NVID_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVID_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVID_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVID_InitStructure);
	
}

void EXTI15_10_IRQHandler(void){
	if(EXTI_GetITStatus(EXTI_Line14)==SET){
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)==0){
		count++;
		}
		EXTI_ClearITPendingBit(EXTI_Line14);
	}
}

uint16_t Tbsensor_retrrn(void){//读取传感器do口输出电平
	return count;
}
