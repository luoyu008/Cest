#include "stm32f10x.h"                  // Device heade
#include "Delay.h"
int main()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
//	GPIO_SetBits(GPIOA,GPIO_Pin_0);
//	GPIO_ResetBits(GPIOA,GPIO_Pin_0);

	while(1){
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_0,(BitAction)1);
		Delay_ms(200);
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);
//		GPIO_WriteBit(GPIOA,GPIO_Pin_0,(BitAction)0);
		Delay_ms(200);
	}
}
