#include "stm32f10x.h"                  // Device header
#include "Delay.h"
int main()
{	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure0;
	GPIO_InitStructure0.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure0.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure0.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure0);
	while(1){
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);
		Delay_ms(100);
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);
		Delay_ms(100);
		GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_RESET);
		Delay_ms(100);
		GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_SET);
		Delay_ms(100);
		GPIO_WriteBit(GPIOA,GPIO_Pin_2,Bit_RESET);
		Delay_ms(100);
		GPIO_WriteBit(GPIOA,GPIO_Pin_2,Bit_SET);
		Delay_ms(100);
		GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_RESET);
		Delay_ms(100);
		GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_SET);
		Delay_ms(100);
		GPIO_WriteBit(GPIOA,GPIO_Pin_4,Bit_RESET);
		Delay_ms(100);
		GPIO_WriteBit(GPIOA,GPIO_Pin_4,Bit_SET);
		Delay_ms(100);
		GPIO_WriteBit(GPIOA,GPIO_Pin_5,Bit_RESET);
		Delay_ms(100);
		GPIO_WriteBit(GPIOA,GPIO_Pin_5,Bit_SET);
		Delay_ms(100);
		GPIO_WriteBit(GPIOA,GPIO_Pin_6,Bit_RESET);
		Delay_ms(100);
		GPIO_WriteBit(GPIOA,GPIO_Pin_6,Bit_SET);
		Delay_ms(100);
		GPIO_WriteBit(GPIOA,GPIO_Pin_7,Bit_RESET);
		Delay_ms(100);
		GPIO_WriteBit(GPIOA,GPIO_Pin_7,Bit_SET);
		Delay_ms(100);
	}
}
