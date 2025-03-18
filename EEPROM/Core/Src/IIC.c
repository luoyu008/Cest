#include "main.h"
GPIO_InitTypeDef	GPIO_Init;
#define SCL GPIO_PIN_6
#define SDA GPIO_PIN_7
void IIIC_Init(void){
	__HAL_RCC_GPIOB_CLK_ENABLE();
	
	GPIO_Init.Mode=GPIO_MODE_OUTPUT_OD;
	GPIO_Init.Pin=SCL;
	GPIO_Init.Pull=GPIO_NOPULL;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_Init);
	
	GPIO_Init.Mode=GPIO_MODE_OUTPUT_OD;
	GPIO_Init.Pin=SDA;
	GPIO_Init.Pull=GPIO_NOPULL;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_Init);
}

void IIC_SCL_Write(uint8_t date){
	HAL_GPIO_WritePin(GPIOB,SCL,(GPIO_PinState)date);
	for(int i=0;i<800;i++);//ÑÓÊ±10us
}

void IIC_SDA_Write(uint8_t date){
	HAL_GPIO_WritePin(GPIOB,SDA,(GPIO_PinState)date);
	for(int i=0;i<800;i++);
}

uint8_t IIC_SDA_Read(void){
	uint8_t date=HAL_GPIO_ReadPin(GPIOB,SDA);
	for(int i=0;i<800;i++);
	return date;
}

void IIC_Start(void){
	IIC_SDA_Write(1);
	IIC_SCL_Write(1);
	IIC_SDA_Write(0);
	IIC_SCL_Write(0);
}

void IIC_Stop(void){
	IIC_SDA_Write(0);
	IIC_SCL_Write(1);
	IIC_SDA_Write(1);
}

void IIC_WriteByte(uint8_t val){
	for(int i=0;i<8;i++){
		IIC_SDA_Write(val&(0x80>>i));
		IIC_SCL_Write(1);
		IIC_SCL_Write(0);
	}
}

uint8_t IIC_ReadByte(void){
	uint8_t Data=0;
	IIC_SDA_Write(1);
	for(uint8_t i=0;i<8;i++){
		IIC_SCL_Write(1);
		if(IIC_SDA_Read()){
			Data|=(0x80>>i);
		}
		IIC_SCL_Write(0);
	}
	return Data;
}

uint8_t IIC_ReadAck(void){
	uint8_t Ack=0;
	IIC_SDA_Write(1);
	IIC_SCL_Write(1);
	Ack=IIC_SDA_Read();
	IIC_SCL_Write(0);
	return Ack;
}

void IIC_SendAck(uint8_t Ack){
	IIC_SDA_Write(Ack);
	IIC_SCL_Write(1);
	IIC_SCL_Write(0);
}

void M24c02_Init(void){
	IIIC_Init();
}

void M24c02_Write(uint8_t Address,uint8_t Data){
	IIC_Start();
	IIC_WriteByte(0XA0);
	IIC_ReadAck();
	IIC_WriteByte(Address);
	IIC_ReadAck();
	IIC_WriteByte(Data);
	IIC_ReadAck();
	IIC_Stop();
}

uint8_t M24c02_Read(uint8_t Address){
	uint8_t Data=0;
	IIC_Start();
	IIC_WriteByte(0xa0);
	IIC_ReadAck();
	IIC_WriteByte(Address);
	IIC_ReadAck();
	
	IIC_Start();
	IIC_WriteByte(0xa1);
	IIC_ReadAck();
	Data=IIC_ReadByte();
	IIC_ReadAck();
	IIC_Stop();
	return Data;
}
