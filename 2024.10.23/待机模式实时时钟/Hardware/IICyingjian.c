#include "stm32f10x.h"                  // Device header
void IICyingjian_Init(){
	//打开时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2,ENABLE);
	
	//配置GPIO口
	GPIO_InitTypeDef GPIO_InitStature;
	GPIO_InitStature.GPIO_Mode=GPIO_Mode_AF_OD;//复用开漏输出
	GPIO_InitStature.GPIO_Pin=GPIO_Pin_10|GPIO_Pin_11;
	GPIO_InitStature.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStature);
	//配置IIC2
	I2C_InitTypeDef I2C_InitStruct;
	I2C_InitStruct.I2C_Ack=I2C_Ack_Enable;//启动应答
	I2C_InitStruct.I2C_AcknowledgedAddress=I2C_AcknowledgedAddress_7bit;//IIC作为从机时7位地址
	I2C_InitStruct.I2C_ClockSpeed=50000;//50khz
	I2C_InitStruct.I2C_DutyCycle=I2C_DutyCycle_2;//低电平占空比2：1
	I2C_InitStruct.I2C_Mode=I2C_Mode_I2C;
	I2C_InitStruct.I2C_OwnAddress1=0x00;
	I2C_Init(I2C2,&I2C_InitStruct);
	//打开IIC2
	I2C_Cmd(I2C2,ENABLE);
}
