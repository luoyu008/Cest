#include "main.h"
#include "OLED.h"
I2C_HandleTypeDef IIC_yingjianMPU6050HandInit;
uint8_t asdwd;
void IICyingjian_Init(void){
	__HAL_RCC_I2C1_CLK_ENABLE();
	IIC_yingjianMPU6050HandInit.Instance=I2C1;
	IIC_yingjianMPU6050HandInit.Init.AddressingMode=I2C_ADDRESSINGMODE_7BIT;//7位地址模式
	IIC_yingjianMPU6050HandInit.Init.ClockSpeed=50000;//50khz
	IIC_yingjianMPU6050HandInit.Init.DualAddressMode=I2C_DUALADDRESS_DISABLE;//单寻址模式
	IIC_yingjianMPU6050HandInit.Init.DutyCycle=I2C_DUTYCYCLE_2;//低电平占空比2：1
	IIC_yingjianMPU6050HandInit.Init.GeneralCallMode=I2C_GENERALCALL_DISABLE;//禁止呼叫模式
	IIC_yingjianMPU6050HandInit.Init.NoStretchMode=I2C_NOSTRETCH_DISABLE;//禁止时钟信号延展模式
	IIC_yingjianMPU6050HandInit.Init.OwnAddress1=0x00;
	IIC_yingjianMPU6050HandInit.Init.OwnAddress2=0x00;
	HAL_I2C_Init(&IIC_yingjianMPU6050HandInit);
	
}

void HAL_I2C_MspInit(I2C_HandleTypeDef *hi2c){
	if(hi2c->Instance==I2C1){
		__HAL_RCC_GPIOB_CLK_ENABLE();
		
		GPIO_InitTypeDef GPIO_Init;
		GPIO_Init.Mode=GPIO_MODE_AF_OD;
		GPIO_Init.Pin=GPIO_PIN_6|GPIO_PIN_7;
		GPIO_Init.Pull=GPIO_PULLUP;
		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOB,&GPIO_Init);
		
	}
}
