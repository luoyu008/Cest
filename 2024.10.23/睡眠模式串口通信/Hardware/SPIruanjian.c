#include "stm32f10x.h"                  // Device header
void SPIruanjian_WriteCS(uint8_t val){
	GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)val);
}

void SPIruanjian_WriteSCK(uint8_t val){
	GPIO_WriteBit(GPIOA,GPIO_Pin_5,(BitAction)val);
}

void SPIruanjian_WriteDI(uint8_t val){
	GPIO_WriteBit(GPIOA,GPIO_Pin_7,(BitAction)val);
}

uint8_t SPIruanjian_ReadDO(void){
	return GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6);
}

void SPIruanjian_Init(void){
	//打开时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	//配置GPIO
	GPIO_InitTypeDef GPIO_InitStructure;
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//4推挽复用输出CS
//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;
//	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA,&GPIO_InitStructure);
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//5推挽复用输出CLK
//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
//	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//6上拉输入DO
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//7推挽输出DI
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7|GPIO_Pin_4|GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//CS默认高电平
	SPIruanjian_WriteCS(1);
	//SCK默认低电平
	SPIruanjian_WriteSCK(0);
}

void SPIruanjian_Start(void){
	SPIruanjian_WriteCS(0);
}

void SPIruanjian_Stop(void){
	SPIruanjian_WriteCS(1);
}
uint8_t SPIruanjian_SwapByte(uint8_t val){
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
