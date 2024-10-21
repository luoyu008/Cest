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
	//��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	//����GPIO
	GPIO_InitTypeDef GPIO_InitStructure;
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//4���츴�����CS
//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;
//	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA,&GPIO_InitStructure);
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//5���츴�����CLK
//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
//	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//6��������DO
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//7�������DI
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7|GPIO_Pin_4|GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//CSĬ�ϸߵ�ƽ
	SPIruanjian_WriteCS(1);
	//SCKĬ�ϵ͵�ƽ
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
	//���͵�һλ
	SPIruanjian_WriteDI(val&0x80);
	val<<=1;
	//sck����
	SPIruanjian_WriteSCK(1);
	//��ȡ��һλ
	if(SPIruanjian_ReadDO()){
		val|=0x01;
	}
	//sck����
	SPIruanjian_WriteSCK(0);
	}
	return val;
}
