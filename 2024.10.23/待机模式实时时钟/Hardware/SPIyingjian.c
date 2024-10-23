#include "stm32f10x.h"                  // Device header
void SPIruanjian_WriteCS1(uint8_t val){
	GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)val);
}

void SPIyingjian_Init(void){
	//����ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	//����GPIO
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//4�������CS
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//5���츴�����CLK
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//6��������DO
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//7���츴�����DI
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//����SPI1
	SPI_InitTypeDef SPI_InitStruct;
	SPI_StructInit(&SPI_InitStruct);
	SPI_InitStruct.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_128;//ʱ��256��Ƶ
	SPI_InitStruct.SPI_CPHA=SPI_CPHA_1Edge;//�ӵ�һ����Ե��ʼ����
	SPI_InitStruct.SPI_CPOL=SPI_CPOL_Low;//SCKĬ�ϵ͵�ƽ  ģʽ0
	SPI_InitStruct.SPI_CRCPolynomial=7;
	SPI_InitStruct.SPI_DataSize=SPI_DataSize_8b;//8λ����ͨ��
	SPI_InitStruct.SPI_Direction=SPI_Direction_2Lines_FullDuplex;
	SPI_InitStruct.SPI_FirstBit=SPI_FirstBit_MSB;//��λ����
	SPI_InitStruct.SPI_Mode=SPI_Mode_Master;//stm32��spiΪ����
	SPI_InitStruct.SPI_NSS=SPI_NSS_Soft;//�������NSS����
	SPI_Init(SPI1,&SPI_InitStruct);
	//����SPI1
	SPI_Cmd(SPI1,ENABLE);
	//CSĬ�ϸߵ�ƽ
	SPIruanjian_WriteCS1(1);
}

void SPIyingjian_Start(void){
	SPIruanjian_WriteCS1(0);
}

void SPIyingjian_Stop(void){
	SPIruanjian_WriteCS1(1);
}

uint8_t SPIyingjian_SwapByte(uint8_t val){
	//�ȴ�TXE
	while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_TXE)!=1);
	//дDR�Ĵ���
	SPI_I2S_SendData(SPI1,val);
	//�ȴ�RXNE
	while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_RXNE)!=1);
	//��������
	return SPI_I2S_ReceiveData(SPI1);	
}
