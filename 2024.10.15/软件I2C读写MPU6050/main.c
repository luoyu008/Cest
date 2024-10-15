#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "MPU6050ruanjian.h"
#include "MPU6050_Reg.h"
int16_t ACCX,ACCY,ACCZ,GYROX,GYROY,GYROZ;
int16_t arr1[6];
int main()
{	
	OLED_Init();
	MPU6050_Init();

	while(1){
//	MPU6050_ReadData(&ACCX,&ACCY,&ACCZ,&GYROX,&GYROY,&GYROZ);
	MPU6050_ReadData1(arr1,MPU6050_ACCEL_XOUT_H);
	OLED_ShowSignedNum(2,1,arr1[0],4);
	OLED_ShowSignedNum(3,1,arr1[1],4);
	OLED_ShowSignedNum(4,1,arr1[2],4);
	OLED_ShowSignedNum(2,8,arr1[3],4);
	OLED_ShowSignedNum(3,8,arr1[4],4);
	OLED_ShowSignedNum(4,8,arr1[5],4);
	Delay_ms(10);
	}
}
