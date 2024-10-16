#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "MPU6050yingjian.h"
#include "MPU6050_Reg.h"
int16_t AX, AY, AZ, GX, GY, GZ;
uint8_t Data;
int main()
{	
	OLED_Init();
	MPU6050yingjian_Init();
	Data=MPU6050yingjian_ReadReg(MPU6050_WHO_AM_I);
	while(1){
		MPU6050yingjian_ReadData(&AX, &AY, &AZ, &GX, &GY, &GZ);	
		OLED_ShowHexNum(1,1,Data,2);
		OLED_ShowSignedNum(2, 1, AX, 5);					
		OLED_ShowSignedNum(3, 1, AY, 5);
		OLED_ShowSignedNum(4, 1, AZ, 5);
		OLED_ShowSignedNum(2, 8, GX, 5);
		OLED_ShowSignedNum(3, 8, GY, 5);
		OLED_ShowSignedNum(4, 8, GZ, 5);


	}
}
