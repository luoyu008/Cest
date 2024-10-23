#include "stm32f10x.h"                  // Device header
#include "MPU6050ruanjian.h"
#include "MPU6050_Reg.h"
#define MPU6050_ADDRESS 0XD0
int16_t arr[6];
void MPU6050_WriteByte(uint8_t ADDRESS,uint8_t Data){
	IIC_Start();
	MyI2C_SendByte(MPU6050_ADDRESS);
	MyI2C_ReadAck();
	MyI2C_SendByte(ADDRESS);
	MyI2C_ReadAck();
	MyI2C_SendByte(Data);
	MyI2C_ReadAck();
	IIC_Stop();
}

uint8_t MPU6050_ReadByte(uint8_t ADDRESS){
	uint8_t Data;
	IIC_Start();
	MyI2C_SendByte(MPU6050_ADDRESS);
	MyI2C_ReadAck();
	MyI2C_SendByte(ADDRESS);
	MyI2C_ReadAck();
	
	IIC_Start();
	MyI2C_SendByte(MPU6050_ADDRESS|0x01);
	MyI2C_ReadAck();
	Data=MyI2C_ReadByte();
	MyI2C_SendAck(1);
	IIC_Stop();
	return Data;
}

void MPU6050_Init(void){
	IIC_Init();
	MPU6050_WriteByte(MPU6050_PWR_MGMT_1,0x01);//解除睡眠模式
	MPU6050_WriteByte(MPU6050_PWR_MGMT_2,0x00);//选择陀螺仪时钟
	MPU6050_WriteByte(MPU6050_SMPLRT_DIV,0x09);//十分频
	MPU6050_WriteByte(MPU6050_CONFIG,0x06);//关闭外部同步 配置数字低通滤波器110
	MPU6050_WriteByte(MPU6050_GYRO_CONFIG,0x18);//陀螺仪最大量程
	MPU6050_WriteByte(MPU6050_ACCEL_CONFIG,0x18);//加速度计最大量程 关闭高通滤波 
}

void MPU6050_ReadData1(int16_t arr[6],uint8_t ADDRESS){
	uint8_t HData,LData,j=0;
	IIC_Start();
	MyI2C_SendByte(MPU6050_ADDRESS);
	MyI2C_ReadAck();
	MyI2C_SendByte(ADDRESS);
	MyI2C_ReadAck();
	
	IIC_Start();
	MyI2C_SendByte(MPU6050_ADDRESS|0x01);
	MyI2C_ReadAck();
	HData=MyI2C_ReadByte();
	MyI2C_SendAck(0);
	for(uint8_t i=0;i<11;i++){
		if(i%2==0&&i!=10){
			LData=MyI2C_ReadByte();
			MyI2C_SendAck(0);
		}
		else if(i%2==0&&i==10){
			LData=MyI2C_ReadByte();
			MyI2C_SendAck(1);
		}
		else{
			HData=MyI2C_ReadByte();
			MyI2C_SendAck(0);
		}
		if(i%2==0){
			arr[j++]=(HData<<8)|LData;
		}
	}
	j=0;
	IIC_Stop();
}

void MPU6050_ReadData(int16_t* ACCX,int16_t* ACCY,int16_t* ACCZ,
						int16_t* GYROX,int16_t* GYROY,int16_t* GYROZ)
{
	uint8_t HData,LData;
	HData=MPU6050_ReadByte(MPU6050_ACCEL_XOUT_H);
	LData=MPU6050_ReadByte(MPU6050_ACCEL_XOUT_L);
	*ACCX=(HData<<8)|LData;
	
	HData=MPU6050_ReadByte(MPU6050_ACCEL_YOUT_H);
	LData=MPU6050_ReadByte(MPU6050_ACCEL_YOUT_L);
	*ACCY=(HData<<8)|LData;
	
	HData=MPU6050_ReadByte(MPU6050_ACCEL_ZOUT_H);
	LData=MPU6050_ReadByte(MPU6050_ACCEL_ZOUT_L);
	*ACCZ=(HData<<8)|LData;
	
	HData=MPU6050_ReadByte(MPU6050_GYRO_XOUT_H);
	LData=MPU6050_ReadByte(MPU6050_GYRO_XOUT_L);
	*GYROX=(HData<<8)|LData;
	
	HData=MPU6050_ReadByte(MPU6050_GYRO_YOUT_H);
	LData=MPU6050_ReadByte(MPU6050_GYRO_YOUT_L);
	*GYROY=(HData<<8)|LData;
	
	HData=MPU6050_ReadByte(MPU6050_GYRO_ZOUT_H);
	LData=MPU6050_ReadByte(MPU6050_GYRO_ZOUT_L);
	*GYROZ=(HData<<8)|LData;
}
