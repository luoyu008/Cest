#include "main.h"
#include "IICruanjianMPU6050.h"
#include "MPU6050_Reg.h"
#define MPU6050_ADDRESS 0xD0
int16_t arr_MPU6050[6];//存放六轴数据
void MPU6050ruanjianIIC_WriteByte(uint8_t ADDRESS,uint8_t Data){
	IICruanjianMPU6050_Start();
	IICruanjianMPU6050_SendByte(MPU6050_ADDRESS);
	IICruanjianMPU6050_ReadAck();
	IICruanjianMPU6050_SendByte(ADDRESS);
	IICruanjianMPU6050_ReadAck();
	IICruanjianMPU6050_SendByte(Data);
	IICruanjianMPU6050_ReadAck();
	IICruanjianMPU6050_Stop();
}

uint8_t MPU6050ruanjianIIC_ReadByte(uint8_t ADDRESS){
	uint8_t Data=0;
	IICruanjianMPU6050_Start();
	IICruanjianMPU6050_SendByte(MPU6050_ADDRESS);
	IICruanjianMPU6050_ReadAck();
	IICruanjianMPU6050_SendByte(ADDRESS);
	IICruanjianMPU6050_ReadAck();
	
	IICruanjianMPU6050_Start();
	IICruanjianMPU6050_SendByte(MPU6050_ADDRESS|0x01);
	IICruanjianMPU6050_ReadAck();
	Data=IICruanjianMPU6050_ReadByte();
	IICruanjianMPU6050_SendAck(1);
	IICruanjianMPU6050_Stop();
	return Data;
}

void MPU6050ruanjianIIC_Init(void){
	IICruanjianMPU6050_Init();
	MPU6050ruanjianIIC_WriteByte(MPU6050_PWR_MGMT_1,0x01);//解除睡眠模式
	MPU6050ruanjianIIC_WriteByte(MPU6050_PWR_MGMT_2,0x00);//选择陀螺仪时钟
	MPU6050ruanjianIIC_WriteByte(MPU6050_SMPLRT_DIV,0x09);//十分频
	MPU6050ruanjianIIC_WriteByte(MPU6050_CONFIG,0x06);//关闭外部同步 配置数字低通滤波器110
	MPU6050ruanjianIIC_WriteByte(MPU6050_GYRO_CONFIG,0x18);//陀螺仪最大量程
	MPU6050ruanjianIIC_WriteByte(MPU6050_ACCEL_CONFIG,0x18);//加速度计最大量程 关闭高通滤波 

}

void MPU6050ruanjianIIC_ReadData(int16_t* ACCX,int16_t* ACCY,int16_t* ACCZ,
						int16_t* GYROX,int16_t* GYROY,int16_t* GYROZ)
{
	uint8_t HData,LData;
	HData=MPU6050ruanjianIIC_ReadByte(MPU6050_ACCEL_XOUT_H);
	LData=MPU6050ruanjianIIC_ReadByte(MPU6050_ACCEL_XOUT_L);
	*ACCX=(HData<<8)|LData;
	
	HData=MPU6050ruanjianIIC_ReadByte(MPU6050_ACCEL_YOUT_H);
	LData=MPU6050ruanjianIIC_ReadByte(MPU6050_ACCEL_YOUT_L);
	*ACCY=(HData<<8)|LData;
	
	HData=MPU6050ruanjianIIC_ReadByte(MPU6050_ACCEL_ZOUT_H);
	LData=MPU6050ruanjianIIC_ReadByte(MPU6050_ACCEL_ZOUT_L);
	*ACCZ=(HData<<8)|LData;
	
	HData=MPU6050ruanjianIIC_ReadByte(MPU6050_GYRO_XOUT_H);
	LData=MPU6050ruanjianIIC_ReadByte(MPU6050_GYRO_XOUT_L);
	*GYROX=(HData<<8)|LData;
	
	HData=MPU6050ruanjianIIC_ReadByte(MPU6050_GYRO_YOUT_H);
	LData=MPU6050ruanjianIIC_ReadByte(MPU6050_GYRO_YOUT_L);
	*GYROY=(HData<<8)|LData;
	
	HData=MPU6050ruanjianIIC_ReadByte(MPU6050_GYRO_ZOUT_H);
	LData=MPU6050ruanjianIIC_ReadByte(MPU6050_GYRO_ZOUT_L);
	*GYROZ=(HData<<8)|LData;
}
