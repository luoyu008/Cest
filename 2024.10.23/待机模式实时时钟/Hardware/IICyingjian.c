#include "stm32f10x.h"                  // Device header
void IICyingjian_Init(){
	//��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2,ENABLE);
	
	//����GPIO��
	GPIO_InitTypeDef GPIO_InitStature;
	GPIO_InitStature.GPIO_Mode=GPIO_Mode_AF_OD;//���ÿ�©���
	GPIO_InitStature.GPIO_Pin=GPIO_Pin_10|GPIO_Pin_11;
	GPIO_InitStature.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStature);
	//����IIC2
	I2C_InitTypeDef I2C_InitStruct;
	I2C_InitStruct.I2C_Ack=I2C_Ack_Enable;//����Ӧ��
	I2C_InitStruct.I2C_AcknowledgedAddress=I2C_AcknowledgedAddress_7bit;//IIC��Ϊ�ӻ�ʱ7λ��ַ
	I2C_InitStruct.I2C_ClockSpeed=50000;//50khz
	I2C_InitStruct.I2C_DutyCycle=I2C_DutyCycle_2;//�͵�ƽռ�ձ�2��1
	I2C_InitStruct.I2C_Mode=I2C_Mode_I2C;
	I2C_InitStruct.I2C_OwnAddress1=0x00;
	I2C_Init(I2C2,&I2C_InitStruct);
	//��IIC2
	I2C_Cmd(I2C2,ENABLE);
}
