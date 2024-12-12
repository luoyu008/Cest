#include "main.h"
void EXIT_Init(void){
	//打开GPIO和AFIO时钟
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_AFIO_CLK_ENABLE();
	//NVIC分组在stm32f1xx_hal.c文件已进行配置
	//配置GPIO
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Mode=GPIO_MODE_IT_FALLING;//外部中断下降沿检测
	GPIO_InitStruct.Pin=GPIO_PIN_0;
	GPIO_InitStruct.Pull=GPIO_PULLUP;//上拉输入
	GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_InitStruct);//AFIO的时钟在选中中断输入模式就已经在该函数内部开启
	
	GPIO_InitStruct.Mode=GPIO_MODE_IT_FALLING;//外部中断下降沿检测
	GPIO_InitStruct.Pin=GPIO_PIN_1;
	GPIO_InitStruct.Pull=GPIO_PULLUP;//上拉输入
	GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_InitStruct);//AFIO的时钟在选中中断输入模式就已经在该函数内部开启
	
	GPIO_InitStruct.Mode=GPIO_MODE_IT_FALLING;//外部中断下降沿检测
	GPIO_InitStruct.Pin=GPIO_PIN_3;
	GPIO_InitStruct.Pull=GPIO_PULLUP;//上拉输入
	GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_InitStruct);//AFIO的时钟在选中中断输入模式就已经在该函数内部开启
//同时也会配置EXIT相关寄存器
	//设置NVIC优先级
	HAL_NVIC_SetPriority(EXTI0_IRQn,2,2);
	HAL_NVIC_SetPriority(EXTI1_IRQn,3,2);
	HAL_NVIC_SetPriority(EXTI3_IRQn,3,3);
	//使能外部中断三
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
	HAL_NVIC_EnableIRQ(EXTI1_IRQn);
	HAL_NVIC_EnableIRQ(EXTI3_IRQn);
}

//void EXTI3_IRQHandler(void){
//	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
//	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_3);//清除挂起标志位 虽然上一个函数也会清楚该标志位但是这样更保险
//}

//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
//	HAL_Delay(10);
//	if(GPIO_Pin==GPIO_PIN_3){
//		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3)==0){
//			
//		}
//	}
//}
