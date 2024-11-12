#include "MYLED.h"
void MYLED_Init(void){
	//打开GPIOB时钟
	__HAL_RCC_GPIOB_CLK_ENABLE();
	//设置GPIO工作模式
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Mode=GPIO_MODE_OUTPUT_PP;//推挽输出
	GPIO_InitStruct.Pin=GPIO_PIN_4;
	GPIO_InitStruct.Pull=GPIO_NOPULL;//不上拉或下拉
	GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_InitStruct);
}
