#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include "DELAY.h"
extern osThreadId LEDTask1Handle;
uint8_t KEY1_Flage=0;
uint8_t KEY2_Flage=0;
uint8_t KEY3_Flage=0;
void EXIT_Init(void){
	//打开GPIO和AFIO时钟
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_AFIO_CLK_ENABLE();
	//NVIC分组在stm32f1xx_hal.c文件已进行配置
	//配置GPIO
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Mode=GPIO_MODE_IT_FALLING;//外部中断下降沿检测
	GPIO_InitStruct.Pin=GPIO_PIN_6;
	GPIO_InitStruct.Pull=GPIO_PULLUP;//上拉输入
	GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_InitStruct);//AFIO的时钟在选中中断输入模式就已经在该函数内部开启
	
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
	
//同时也会配置EXIT相关寄存器
	//设置NVIC优先级
	HAL_NVIC_SetPriority(EXTI9_5_IRQn,5,2);
	HAL_NVIC_SetPriority(EXTI0_IRQn,5,3);
	HAL_NVIC_SetPriority(EXTI1_IRQn,5,3);
	//使能外部中断三
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
	HAL_NVIC_EnableIRQ(EXTI1_IRQn);
}

void EXTI9_5_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_6);//清除挂起标志位 虽然上一个函数也会清楚该标志位但是这样更保险
}

void EXTI0_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0);
}

void EXTI1_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_1);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
//	for (volatile uint32_t i = 0; i < 1000; i++);  //实现延时事件1000us
//	DELAY_us(1);
	if(GPIO_Pin==GPIO_PIN_6){
		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6)==0){
			KEY1_Flage=1;
		}
	}
	if(GPIO_Pin==GPIO_PIN_1){
		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1)==0){
			KEY3_Flage=1;
		}
	}
	if(GPIO_Pin==GPIO_PIN_0){
		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==0){
			KEY2_Flage=1;
		}
	}
}
