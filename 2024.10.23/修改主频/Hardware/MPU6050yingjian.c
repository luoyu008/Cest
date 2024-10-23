#include "stm32f10x.h"                  // Device header
#include "MPU6050_Reg.h"
#define MPU6050_ADDRESS 0XD0
void MPU6050yingjian_WriteReg(uint8_t ADDRESS,uint8_t Date){
	//发送开始信号
	I2C_GenerateSTART(I2C2,ENABLE);
	//等待EV5事件
	while(I2C_CheckEvent(I2C2,I2C_EVENT_MASTER_MODE_SELECT)!=SUCCESS);
	//发送mpu6050地址
	I2C_Send7bitAddress(I2C2,MPU6050_ADDRESS,I2C_Direction_Transmitter);
	//等待EV6事件
	while(I2C_CheckEvent(I2C2,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)!=SUCCESS);
	//发送寄存器地址
	I2C_SendData(I2C2,ADDRESS);
	//等待EV8事件
	while(I2C_CheckEvent(I2C2,I2C_EVENT_MASTER_BYTE_TRANSMITTING)!=SUCCESS);
	//发送数据
	I2C_SendData(I2C2,Date);
	//等待EV8_2事件
	while(I2C_CheckEvent(I2C2,I2C_EVENT_MASTER_BYTE_TRANSMITTED)!=SUCCESS);
	//结束信号
	I2C_GenerateSTOP(I2C2,ENABLE);
}

uint8_t MPU6050yingjian_ReadReg(uint8_t ADDRESS){
	uint8_t Date;
	//发送开始信号
	I2C_GenerateSTART(I2C2,ENABLE);
	//等待EV5事件
	while(I2C_CheckEvent(I2C2,I2C_EVENT_MASTER_MODE_SELECT)!=SUCCESS);
	//发送mpu6050地址
	I2C_Send7bitAddress(I2C2,MPU6050_ADDRESS,I2C_Direction_Transmitter);
	//等待EV6事件
	while(I2C_CheckEvent(I2C2,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)!=SUCCESS);
	//发送寄存器地址
	I2C_SendData(I2C2,ADDRESS);
	//等待EV8事件
	while(I2C_CheckEvent(I2C2,I2C_EVENT_MASTER_BYTE_TRANSMITTED)!=SUCCESS);
	
	//发送重复开始信号
	I2C_GenerateSTART(I2C2,ENABLE);
	//等待EV5事件
	while(I2C_CheckEvent(I2C2,I2C_EVENT_MASTER_MODE_SELECT)!=SUCCESS);
	//发送mpu6050地址
	I2C_Send7bitAddress(I2C2,MPU6050_ADDRESS,I2C_Direction_Receiver);
	//等待EV6事件
	while(I2C_CheckEvent(I2C2,I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED)!=SUCCESS);
	//清除ACK并且发送停止信号
	I2C_AcknowledgeConfig(I2C2,DISABLE);
	I2C_GenerateSTOP(I2C2,ENABLE);
	//等待EV7事件
	while(I2C_CheckEvent(I2C2,I2C_EVENT_MASTER_BYTE_RECEIVED)!=SUCCESS);
	//读取数据
	Date=I2C_ReceiveData(I2C2);
	//回复ACK默认值
	I2C_AcknowledgeConfig(I2C2,ENABLE);
	return Date;
}

void MPU6050yingjian_Init(void){
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
	MPU6050yingjian_WriteReg(MPU6050_PWR_MGMT_1,0x01);//解除睡眠模式
	MPU6050yingjian_WriteReg(MPU6050_PWR_MGMT_2,0x00);//选择陀螺仪时钟
	MPU6050yingjian_WriteReg(MPU6050_SMPLRT_DIV,0x09);//十分频
	MPU6050yingjian_WriteReg(MPU6050_CONFIG,0x06);//关闭外部同步 配置数字低通滤波器110
	MPU6050yingjian_WriteReg(MPU6050_GYRO_CONFIG,0x18);//陀螺仪最大量程
	MPU6050yingjian_WriteReg(MPU6050_ACCEL_CONFIG,0x18);//加速度计最大量程 关闭高通滤波 
}

void MPU6050yingjian_ReadData(int16_t* ACCX,int16_t* ACCY,int16_t* ACCZ,
						int16_t* GYROX,int16_t* GYROY,int16_t* GYROZ)
{
	uint8_t HData,LData;
	HData=MPU6050yingjian_ReadReg(MPU6050_ACCEL_XOUT_H);
	LData=MPU6050yingjian_ReadReg(MPU6050_ACCEL_XOUT_L);
	*ACCX=(HData<<8)|LData;
	
	HData=MPU6050yingjian_ReadReg(MPU6050_ACCEL_YOUT_H);
	LData=MPU6050yingjian_ReadReg(MPU6050_ACCEL_YOUT_L);
	*ACCY=(HData<<8)|LData;
	
	HData=MPU6050yingjian_ReadReg(MPU6050_ACCEL_ZOUT_H);
	LData=MPU6050yingjian_ReadReg(MPU6050_ACCEL_ZOUT_L);
	*ACCZ=(HData<<8)|LData;
	
	HData=MPU6050yingjian_ReadReg(MPU6050_GYRO_XOUT_H);
	LData=MPU6050yingjian_ReadReg(MPU6050_GYRO_XOUT_L);
	*GYROX=(HData<<8)|LData;
	
	HData=MPU6050yingjian_ReadReg(MPU6050_GYRO_YOUT_H);
	LData=MPU6050yingjian_ReadReg(MPU6050_GYRO_YOUT_L);
	*GYROY=(HData<<8)|LData;
	
	HData=MPU6050yingjian_ReadReg(MPU6050_GYRO_ZOUT_H);
	LData=MPU6050yingjian_ReadReg(MPU6050_GYRO_ZOUT_L);
	*GYROZ=(HData<<8)|LData;
}
