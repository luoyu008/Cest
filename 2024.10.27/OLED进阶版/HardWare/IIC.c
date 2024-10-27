                                        #include "stm32f10x.h"                  // Device header
#include "Delay.h"
void MyI2C_W_SCL(uint8_t val){
	GPIO_WriteBit(GPIOB,GPIO_Pin_10,(BitAction)val);
	Delay_us(10);
}

void MyI2C_W_SDA(uint8_t val){
	GPIO_WriteBit(GPIOB,GPIO_Pin_11,(BitAction)val);
	Delay_us(10);
}

uint8_t MyI2C_R_SDA(void){
	uint8_t date;
	date=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11);
	Delay_us(10);
	return date;
}

void MyI2C_SendByte(uint8_t Date){
	for(uint8_t i=0;i<8;i++){
		MyI2C_W_SDA(Date&(0x80>>i));
		MyI2C_W_SCL(1);
		MyI2C_W_SCL(0);
	}
}

uint8_t MyI2C_ReadByte(void){
	uint8_t date=0x00;
	MyI2C_W_SDA(1);
	for(uint8_t i=0;i<8;i++){
		MyI2C_W_SCL(1);
		if(MyI2C_R_SDA()){
			date|=(0x80>>i);
		}
		MyI2C_W_SCL(0);
	}
//	for(uint8_t i=7;i>0;i--){
//		MyI2C_W_SCL(1);
//		if(MyI2C_R_SDA()){
//			date|=0x01<<i;
//		}
//		MyI2C_W_SCL(0);
//	}
	return date;
}

void MyI2C_SendAck(uint8_t Ack){
	MyI2C_W_SDA(Ack);
	MyI2C_W_SCL(1);
	MyI2C_W_SCL(0);
}

uint8_t MyI2C_ReadAck(void){
	uint8_t Ack;
	MyI2C_W_SDA(1);
	MyI2C_W_SCL(1);
	Ack=MyI2C_R_SDA();
	MyI2C_W_SCL(0);
	return Ack;
}

void IIC_Init(void){
	//打开时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_OD;//开漏输出
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10|GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
}

void IIC_Start(void){
	MyI2C_W_SDA(1);
	MyI2C_W_SCL(1);
	MyI2C_W_SDA(0);
	MyI2C_W_SCL(0);
}

void IIC_Stop(void){
	MyI2C_W_SDA(0);
	MyI2C_W_SCL(1);
	MyI2C_W_SDA(1);
}

