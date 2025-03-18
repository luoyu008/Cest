#include "main.h"
uint16_t g_fac_us;
void DELAY_Init(uint16_t sysclk){
	SysTick->CTRL=0;
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
	g_fac_us=sysclk;
}

void DELAY_us(uint32_t nus){
	uint32_t temp;
	SysTick->LOAD=nus*g_fac_us;
	SysTick->VAL=0X00;
	SysTick->CTRL|=1<<0;
	do{
		temp=SysTick->CTRL;
	}while((temp&0x01)&&!(temp&(1<<16)));
	SysTick->CTRL&=~(1<<0);
	SysTick->VAL=0x00;
}
