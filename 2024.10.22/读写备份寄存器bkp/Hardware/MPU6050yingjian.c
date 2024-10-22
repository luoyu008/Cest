#include "stm32f10x.h"                  // Device header
#include "MPU6050_Reg.h"
#define MPU6050_ADDRESS 0XD0
void MPU6050yingjian_WriteReg(uint8_t ADDRESS,uint8_t Date){
	//���Ϳ�ʼ�ź�
	I2C_GenerateSTART(I2C2,ENABLE);
	//�ȴ�EV5�¼�
	while(I2C_CheckEvent(I2C2,I2C_EVENT_MASTER_MODE_SELECT)!=SUCCESS);
	//����mpu6050��ַ
	I2C_Send7bitAddress(I2C2,MPU6050_ADDRESS,I2C_Direction_Transmitter);
	//�ȴ�EV6�¼�
	while(I2C_CheckEvent(I2C2,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)!=SUCCESS);
	//���ͼĴ�����ַ
	I2C_SendData(I2C2,ADDRESS);
	//�ȴ�EV8�¼�
	while(I2C_CheckEvent(I2C2,I2C_EVENT_MASTER_BYTE_TRANSMITTING)!=SUCCESS);
	//��������
	I2C_SendData(I2C2,Date);
	//�ȴ�EV8_2�¼�
	while(I2C_CheckEvent(I2C2,I2C_EVENT_MASTER_BYTE_TRANSMITTED)!=SUCCESS);
	//�����ź�
	I2C_GenerateSTOP(I2C2,ENABLE);
}

uint8_t MPU6050yingjian_ReadReg(uint8_t ADDRESS){
	uint8_t Date;
	//���Ϳ�ʼ�ź�
	I2C_GenerateSTART(I2C2,ENABLE);
	//�ȴ�EV5�¼�
	while(I2C_CheckEvent(I2C2,I2C_EVENT_MASTER_MODE_SELECT)!=SUCCESS);
	//����mpu6050��ַ
	I2C_Send7bitAddress(I2C2,MPU6050_ADDRESS,I2C_Direction_Transmitter);
	//�ȴ�EV6�¼�
	while(I2C_CheckEvent(I2C2,I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED)!=SUCCESS);
	//���ͼĴ�����ַ
	I2C_SendData(I2C2,ADDRESS);
	//�ȴ�EV8�¼�
	while(I2C_CheckEvent(I2C2,I2C_EVENT_MASTER_BYTE_TRANSMITTED)!=SUCCESS);
	
	//�����ظ���ʼ�ź�
	I2C_GenerateSTART(I2C2,ENABLE);
	//�ȴ�EV5�¼�
	while(I2C_CheckEvent(I2C2,I2C_EVENT_MASTER_MODE_SELECT)!=SUCCESS);
	//����mpu6050��ַ
	I2C_Send7bitAddress(I2C2,MPU6050_ADDRESS,I2C_Direction_Receiver);
	//�ȴ�EV6�¼�
	while(I2C_CheckEvent(I2C2,I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED)!=SUCCESS);
	//���ACK���ҷ���ֹͣ�ź�
	I2C_AcknowledgeConfig(I2C2,DISABLE);
	I2C_GenerateSTOP(I2C2,ENABLE);
	//�ȴ�EV7�¼�
	while(I2C_CheckEvent(I2C2,I2C_EVENT_MASTER_BYTE_RECEIVED)!=SUCCESS);
	//��ȡ����
	Date=I2C_ReceiveData(I2C2);
	//�ظ�ACKĬ��ֵ
	I2C_AcknowledgeConfig(I2C2,ENABLE);
	return Date;
}

void MPU6050yingjian_Init(void){
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
	MPU6050yingjian_WriteReg(MPU6050_PWR_MGMT_1,0x01);//���˯��ģʽ
	MPU6050yingjian_WriteReg(MPU6050_PWR_MGMT_2,0x00);//ѡ��������ʱ��
	MPU6050yingjian_WriteReg(MPU6050_SMPLRT_DIV,0x09);//ʮ��Ƶ
	MPU6050yingjian_WriteReg(MPU6050_CONFIG,0x06);//�ر��ⲿͬ�� �������ֵ�ͨ�˲���110
	MPU6050yingjian_WriteReg(MPU6050_GYRO_CONFIG,0x18);//�������������
	MPU6050yingjian_WriteReg(MPU6050_ACCEL_CONFIG,0x18);//���ٶȼ�������� �رո�ͨ�˲� 
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
