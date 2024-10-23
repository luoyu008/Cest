#include "stm32f10x.h"                  // Device header
void SPIruanjian_WriteCS1(uint8_t val){
	GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)val);
}

void SPIyingjian_Init(void){
	//开启时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	//配置GPIO
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//4推挽输出CS
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//5推挽复用输出CLK
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//6上拉输入DO
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//7推挽复用输出DI
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//配置SPI1
	SPI_InitTypeDef SPI_InitStruct;
	SPI_StructInit(&SPI_InitStruct);
	SPI_InitStruct.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_128;//时钟256分频
	SPI_InitStruct.SPI_CPHA=SPI_CPHA_1Edge;//从第一个边缘开始采样
	SPI_InitStruct.SPI_CPOL=SPI_CPOL_Low;//SCK默认低电平  模式0
	SPI_InitStruct.SPI_CRCPolynomial=7;
	SPI_InitStruct.SPI_DataSize=SPI_DataSize_8b;//8位数据通信
	SPI_InitStruct.SPI_Direction=SPI_Direction_2Lines_FullDuplex;
	SPI_InitStruct.SPI_FirstBit=SPI_FirstBit_MSB;//高位先行
	SPI_InitStruct.SPI_Mode=SPI_Mode_Master;//stm32的spi为主机
	SPI_InitStruct.SPI_NSS=SPI_NSS_Soft;//软件管理NSS引脚
	SPI_Init(SPI1,&SPI_InitStruct);
	//开启SPI1
	SPI_Cmd(SPI1,ENABLE);
	//CS默认高电平
	SPIruanjian_WriteCS1(1);
}

void SPIyingjian_Start(void){
	SPIruanjian_WriteCS1(0);
}

void SPIyingjian_Stop(void){
	SPIruanjian_WriteCS1(1);
}

uint8_t SPIyingjian_SwapByte(uint8_t val){
	//等待TXE
	while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_TXE)!=1);
	//写DR寄存器
	SPI_I2S_SendData(SPI1,val);
	//等待RXNE
	while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_RXNE)!=1);
	//读出数据
	return SPI_I2S_ReceiveData(SPI1);	
}
