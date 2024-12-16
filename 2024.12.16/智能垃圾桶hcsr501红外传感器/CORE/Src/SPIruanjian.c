#include "main.h"
void SPIruanjian_WriteCS(uint8_t val){
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,(GPIO_PinState)val);
}

void SPIruanjian_WriteSCK(uint8_t val){
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,(GPIO_PinState)val);
}

void SPIruanjian_WriteDI(uint8_t val){
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,(GPIO_PinState)val);
}

uint8_t SPIruanjian_ReadDO(void){
	return HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6);
}

void SPIruanjian_Init(void){
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_SPI1_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_Init;
	GPIO_Init.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pin=GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_7;
	GPIO_Init.Pull=GPIO_NOPULL;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA,&GPIO_Init);
	
	GPIO_Init.Mode=GPIO_MODE_INPUT;
	GPIO_Init.Pin=GPIO_PIN_6;
	GPIO_Init.Pull=GPIO_NOPULL;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOA,&GPIO_Init);
	
	SPIruanjian_WriteCS(1);//片选默认高电平
	
	SPIruanjian_WriteSCK(0);//时钟默认低电平
}


void SPIruanjian_Start(void){
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
}

void SPIruanjian_Stop(void){
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
}

uint8_t SPIruanjian_Swap(uint8_t val){
	uint8_t i;
	for(i=0;i<8;i++){
	//发送第一位
	SPIruanjian_WriteDI(val&0x80);
	val<<=1;
	//sck升高
	SPIruanjian_WriteSCK(1);
	//读取第一位
	if(SPIruanjian_ReadDO()){
		val|=0x01;
	}
	//sck降低
	SPIruanjian_WriteSCK(0);
	}
	return val;
}
