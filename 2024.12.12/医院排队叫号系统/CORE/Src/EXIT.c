#include "main.h"
void EXIT_Init(void){
	//��GPIO��AFIOʱ��
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_AFIO_CLK_ENABLE();
	//NVIC������stm32f1xx_hal.c�ļ��ѽ�������
	//����GPIO
	GPIO_InitTypeDef GPIO_InitStruct;
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
	
	GPIO_InitStruct.Mode=GPIO_MODE_IT_FALLING;//�ⲿ�ж��½��ؼ��
	GPIO_InitStruct.Pin=GPIO_PIN_3;
	GPIO_InitStruct.Pull=GPIO_PULLUP;//��������
	GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_InitStruct);//AFIO��ʱ����ѡ���ж�����ģʽ���Ѿ��ڸú����ڲ�����
//ͬʱҲ������EXIT��ؼĴ���
	//����NVIC���ȼ�
	HAL_NVIC_SetPriority(EXTI0_IRQn,2,2);
	HAL_NVIC_SetPriority(EXTI1_IRQn,3,2);
	HAL_NVIC_SetPriority(EXTI3_IRQn,3,3);
	//ʹ���ⲿ�ж���
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
	HAL_NVIC_EnableIRQ(EXTI1_IRQn);
	HAL_NVIC_EnableIRQ(EXTI3_IRQn);
}

//void EXTI3_IRQHandler(void){
//	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
//	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_3);//��������־λ ��Ȼ��һ������Ҳ������ñ�־λ��������������
//}

//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
//	HAL_Delay(10);
//	if(GPIO_Pin==GPIO_PIN_3){
//		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3)==0){
//			
//		}
//	}
//}
