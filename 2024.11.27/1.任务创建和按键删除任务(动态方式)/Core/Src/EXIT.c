#include "main.h"
uint8_t KEY_Flage=0;
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
//ͬʱҲ������EXIT��ؼĴ���
	//����NVIC���ȼ�
	HAL_NVIC_SetPriority(EXTI9_5_IRQn,1,2);
	//ʹ���ⲿ�ж���
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}

void EXTI9_5_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_6);//��������־λ ��Ȼ��һ������Ҳ������ñ�־λ��������������
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin==GPIO_PIN_6){
		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6)==0){
			KEY_Flage=1;
		}
	}
}
