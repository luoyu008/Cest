#include "stm32f10x.h"                  // Device header
uint16_t count1;
void R_encoder_Init(void){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	//EXTI≈‰÷√
//	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource0);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource1);
	EXTI_InitTypeDef EXTI_InitStructure;
	EXTI_InitStructure.EXTI_Line=EXTI_Line1;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;
	EXTI_Init(&EXTI_InitStructure);
	//NVIC≈‰÷√
	//≈‰÷√NVIC
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitTypeDef NVID_InitStructure;
	NVID_InitStructure.NVIC_IRQChannel=EXTI1_IRQn;
	NVID_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVID_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
	NVID_InitStructure.NVIC_IRQChannelSubPriority=1;
	NVIC_Init(&NVID_InitStructure);
//	NVID_InitStructure.NVIC_IRQChannel=EXTI0_IRQn;
//	NVID_InitStructure.NVIC_IRQChannelCmd=ENABLE;
//	NVID_InitStructure.NVIC_IRQChannelPreemptionPriority=1;
//	NVID_InitStructure.NVIC_IRQChannelSubPriority=2;
//	NVIC_Init(&NVID_InitStructure);
}

uint16_t R_encoder_return(void){
	return count1;
}

void EXTI1_IRQHandler(void){
	if(EXTI_GetITStatus(EXTI_Line1)==SET){
			if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)==0){
				count1--;
			}
			else{
				count1++;
			}
		EXTI_ClearITPendingBit(EXTI_Line1);
	}
}

//void EXTI0_IRQHandler(void){
//	if(EXTI_GetITStatus(EXTI_Line0)==SET){
//		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)==0){
//			if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0){
//				count1--;
//			}
//		}
//		EXTI_ClearITPendingBit(EXTI_Line0);
//	}
//}
//void EXTI1_IRQHandler(void){
//	if(EXTI_GetITStatus(EXTI_Line1)==SET){
//		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0){
//			if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)==0){
//				count1++;
//			}
//		}
//		EXTI_ClearITPendingBit(EXTI_Line1);
//	}
//}
