#include "main.h"
#include "DELAY.h"
#define SCL GPIO_PIN_8
#define SDA GPIO_PIN_9
void IICruanjianMPU6050_W_SCL(uint8_t val){
	HAL_GPIO_WritePin(GPIOB,SCL,(GPIO_PinState)val);
	DELAY_us(10);
}

void IICruanjianMPU6050_W_SDA(uint8_t val){
	HAL_GPIO_WritePin(GPIOB,SDA,(GPIO_PinState)val);
	DELAY_us(10);
}

uint8_t	IICruanjianMPU6050_R_SDA(void){
	uint8_t data=HAL_GPIO_ReadPin(GPIOB,SDA);
	DELAY_us(10);
	return data;
}

void IICruanjianMPU6050_SendByte(uint8_t val){
	for(uint8_t i=0;i<8;i++){
		IICruanjianMPU6050_W_SDA(val&(0x80>>i));
		IICruanjianMPU6050_W_SCL(1);
		IICruanjianMPU6050_W_SCL(0);
	}
}

uint8_t IICruanjianMPU6050_ReadByte(void){
	uint8_t data=0x00;
	IICruanjianMPU6050_W_SDA(1);
	for(uint8_t i=0;i<8;i++){
		IICruanjianMPU6050_W_SCL(1);
		if(IICruanjianMPU6050_R_SDA()){
			data|=(0x80>>i);
		}
		IICruanjianMPU6050_W_SCL(0);
	}
	return data;
}

void IICruanjianMPU6050_SendAck(uint8_t Ack){
	IICruanjianMPU6050_W_SDA(Ack);
	IICruanjianMPU6050_W_SCL(1);
	IICruanjianMPU6050_W_SCL(0);
}

uint8_t IICruanjianMPU6050_ReadAck(void){
	uint8_t Ack=0x00;
	IICruanjianMPU6050_W_SDA(1);
	IICruanjianMPU6050_W_SCL(1);
	Ack=IICruanjianMPU6050_R_SDA();
	IICruanjianMPU6050_W_SCL(0);
	return Ack;
}

void IICruanjianMPU6050_Init(void){
	//´ò¿ªÊ±ÖÓ
	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Mode=GPIO_MODE_OUTPUT_OD;
	GPIO_InitStruct.Pin=GPIO_PIN_8;
	GPIO_InitStruct.Pull=GPIO_NOPULL;
	GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_InitStruct);
	GPIO_InitStruct.Mode=GPIO_MODE_OUTPUT_OD;
	GPIO_InitStruct.Pin=GPIO_PIN_9;
	GPIO_InitStruct.Pull=GPIO_NOPULL;
	GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOB,&GPIO_InitStruct);
	
	DELAY_Init(72);
}

void IICruanjianMPU6050_Start(void){
	IICruanjianMPU6050_W_SDA(1);
	IICruanjianMPU6050_W_SCL(1);
	IICruanjianMPU6050_W_SDA(0);
	IICruanjianMPU6050_W_SCL(0);
}

void IICruanjianMPU6050_Stop(void){
	IICruanjianMPU6050_W_SDA(0);
	IICruanjianMPU6050_W_SCL(1);
	IICruanjianMPU6050_W_SDA(1);
}
