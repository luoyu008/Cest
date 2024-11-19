#include "main.h"
#include "IICyingjian.h"
#include "MPU6050_Reg.h"
#include "OLED.h"
uint8_t asdwe;
#define MPU6050_ADDRESS 0xD0
uint8_t arr_Spackge[2];
uint8_t arr_Rpackge[2];
void MPU6050IICyingjian_WriteByte(uint8_t ADDRESS,uint8_t Data){
	HAL_I2C_GetState(&IIC_yingjianMPU6050HandInit);
	asdwe=HAL_I2C_Mem_Write(&IIC_yingjianMPU6050HandInit,MPU6050_ADDRESS,ADDRESS,I2C_MEMADD_SIZE_8BIT,&Data,1,100);
//	OLED_ShowHexNum(0,20,asdwe,2,16);
//	OLED_UpData();
}

uint8_t MPU6050IICyingjian_ReadByte(uint8_t ADDRESS){
	uint8_t DATA;
	HAL_I2C_Mem_Read(&IIC_yingjianMPU6050HandInit,MPU6050_ADDRESS,ADDRESS,I2C_MEMADD_SIZE_8BIT,&DATA,1,100);
	return DATA;
}


void MPU6050IICyingjian_Init(void){
	IICyingjian_Init();
	MPU6050IICyingjian_WriteByte(MPU6050_PWR_MGMT_1,0x01);//解除睡眠模式
	MPU6050IICyingjian_WriteByte(MPU6050_PWR_MGMT_2,0x00);//选择陀螺仪时钟
	MPU6050IICyingjian_WriteByte(MPU6050_SMPLRT_DIV,0x09);//十分频
	MPU6050IICyingjian_WriteByte(MPU6050_CONFIG,0x06);//关闭外部同步 配置数字低通滤波器110
	MPU6050IICyingjian_WriteByte(MPU6050_GYRO_CONFIG,0x18);//陀螺仪最大量程
	MPU6050IICyingjian_WriteByte(MPU6050_ACCEL_CONFIG,0x18);//加速度计最大量程 关闭高通滤波 

}

void MPU6050IICyingjian_ReadData(int16_t* ACCX,int16_t* ACCY,int16_t* ACCZ,
						int16_t* GYROX,int16_t* GYROY,int16_t* GYROZ)
{
		uint8_t HData,LData;
	HData=MPU6050IICyingjian_ReadByte(MPU6050_ACCEL_XOUT_H);
	LData=MPU6050IICyingjian_ReadByte(MPU6050_ACCEL_XOUT_L);
	*ACCX=(HData<<8)|LData;
	
	HData=MPU6050IICyingjian_ReadByte(MPU6050_ACCEL_YOUT_H);
	LData=MPU6050IICyingjian_ReadByte(MPU6050_ACCEL_YOUT_L);
	*ACCY=(HData<<8)|LData;
	
	HData=MPU6050IICyingjian_ReadByte(MPU6050_ACCEL_ZOUT_H);
	LData=MPU6050IICyingjian_ReadByte(MPU6050_ACCEL_ZOUT_L);
	*ACCZ=(HData<<8)|LData;
	
	HData=MPU6050IICyingjian_ReadByte(MPU6050_GYRO_XOUT_H);
	LData=MPU6050IICyingjian_ReadByte(MPU6050_GYRO_XOUT_L);
	*GYROX=(HData<<8)|LData;
	
	HData=MPU6050IICyingjian_ReadByte(MPU6050_GYRO_YOUT_H);
	LData=MPU6050IICyingjian_ReadByte(MPU6050_GYRO_YOUT_L);
	*GYROY=(HData<<8)|LData;
	
	HData=MPU6050IICyingjian_ReadByte(MPU6050_GYRO_ZOUT_H);
	LData=MPU6050IICyingjian_ReadByte(MPU6050_GYRO_ZOUT_L);
	*GYROZ=(HData<<8)|LData;
	
}
