#include "DELAY.h"
uint16_t g_fac_us;
void DELAY_Init(uint16_t sysclk){
	SysTick->CTRL=0;
	HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK_DIV8);
	g_fac_us=sysclk/8;
}
			
void DELAY_us(uint32_t nus){
//	uint32_t temp;
//	SysTick->LOAD=nus*g_fac_us;
//	SysTick->VAL=0X00;
//	SysTick->CTRL|=1<<0;
//	do{
//		temp=SysTick->CTRL;
//	}while((temp&0x01)&&!(temp&(1<<16)));
//	SysTick->CTRL&=~(1<<0);
//	SysTick->VAL=0x00;
	for(int j=0;j<nus;j++){
		for(int i=0;i<27;i++);
	}
}

void DELAY_ms(uint16_t nms){
//	uint32_t repeat=nms/1000;
//	uint32_t remain=nms%1000;
//	while(repeat){
//		DELAY_us(1000*1000);
//		repeat--;
//	}
//	if(remain){
//		DELAY_us(remain*1000);
//	}
	for(int j=0;j<nms;j++){
		for(int i=0;i<2666;i++);
	}
}
