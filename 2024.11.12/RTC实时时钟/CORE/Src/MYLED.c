#include "MYLED.h"
void MYLED_Init(void){
	//��GPIOBʱ��
	__HAL_RCC_GPIOB_CLK_ENABLE();
	//����GPIO����ģʽ
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Mode=GPIO_MODE_OUTPUT_PP;//�������
	GPIO_InitStruct.Pin=GPIO_PIN_4;
	GPIO_InitStruct.Pull=GPIO_NOPULL;//������������
	GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_InitStruct);
}
