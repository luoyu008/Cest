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
	//��GPIO��AFIOʱ��
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_AFIO_CLK_ENABLE();
	//NVIC������stm32f1xx_hal.c�ļ��ѽ�������
	//����GPIO
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Mode=GPIO_MODE_IT_FALLING;//�ⲿ�ж��½��ؼ��
	GPIO_InitStruct.Pin=GPIO_PIN_6;
	GPIO_InitStruct.Pull=GPIO_PULLUP;//��������
	GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_InitStruct);//AFIO��ʱ����ѡ���ж�����ģʽ���Ѿ��ڸú����ڲ�����
	
	GPIO_InitStruct.Mode=GPIO_MODE_IT_FALLING;//�ⲿ�ж��½��ؼ��
	GPIO_InitStruct.Pin=GPIO_PIN_0;
	GPIO_InitStruct.Pull=GPIO_PULLUP;//��������
	GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_InitStruct);//AFIO��ʱ����ѡ���ж�����ģʽ���Ѿ��ڸú����ڲ�����
	
	GPIO_InitStruct.Mode=GPIO_MODE_IT_FALLING;//�ⲿ�ж��½��ؼ��
	GPIO_InitStruct.Pin=GPIO_PIN_1;
	GPIO_InitStruct.Pull=GPIO_PULLUP;//��������
	GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_InitStruct);//AFIO��ʱ����ѡ���ж�����ģʽ���Ѿ��ڸú����ڲ�����
	
//ͬʱҲ������EXIT��ؼĴ���
	//����NVIC���ȼ�
	HAL_NVIC_SetPriority(EXTI9_5_IRQn,5,2);
	HAL_NVIC_SetPriority(EXTI0_IRQn,5,3);
	HAL_NVIC_SetPriority(EXTI1_IRQn,5,3);
	//ʹ���ⲿ�ж���
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
	HAL_NVIC_EnableIRQ(EXTI1_IRQn);
}

void EXTI9_5_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_6);//��������־λ ��Ȼ��һ������Ҳ������ñ�־λ��������������
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
//	for (volatile uint32_t i = 0; i < 1000; i++);  //ʵ����ʱ�¼�1000us
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
