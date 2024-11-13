#include "main.h"
uint8_t num;
void WEAKUPEXTI_Init(void){
	//��GPIO��AFIOʱ��
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_AFIO_CLK_ENABLE();
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Mode=GPIO_MODE_IT_RISING;//�ⲿ�ж��½��ؼ��
	GPIO_InitStruct.Pin=GPIO_PIN_0;
	GPIO_InitStruct.Pull=GPIO_PULLDOWN;//��������
	GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);//AFIO��ʱ����ѡ���ж�����ģʽ���Ѿ��ڸú����ڲ�����
//ͬʱҲ������EXIT��ؼĴ���
	//����NVIC���ȼ�
	HAL_NVIC_SetPriority(EXTI0_IRQn,1,2);
	//ʹ���ⲿ�ж���
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

void EXTI0_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0);//��������־λ ��Ȼ��һ������Ҳ������ñ�־λ��������������
}

//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
//	HAL_Delay(10);
//	if(GPIO_Pin==GPIO_PIN_0){
//		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)==1){
//			num++;
//		}
//	}
//}
