#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "DCmotors.h"
#include "Delay.h"
#include "KEY.h"
uint16_t num;
uint16_t speed;
uint8_t IN1,IN2;
int main()
{	
	DCmotors_Init();
	KEY_Init(GPIOB,1);
	OLED_Init();
	OLED_ShowString(1,1,"num:");
	OLED_ShowString(2,1,"speed:");
	OLED_ShowString(3,1,"IN1:");
	OLED_ShowString(4,1,"IN2:");
	while(1){
	
	if(KEY_GET(GPIOB,1)){
		num++;
		num%=12;
	}
	if(num<=5){
		IN1=1;IN2=0;
		Direction(IN1,IN2);
	}
	if(num>5&&num<=11){
		IN1=0;IN2=1;
		Direction(IN1,IN2);
	}
	switch(num){
		case 0:speed=0;break;
		case 1:speed=20;break;
		case 2:speed=40;break;
		case 3:speed=60;break;
		case 4:speed=80;break;
		case 5:speed=100;break;
		case 6:speed=0;break;
		case 7:speed=20;break;
		case 8:speed=40;break;
		case 9:speed=60;break;
		case 10:speed=80;break;
		case 11:speed=100;break;
	}
	OLED_ShowNum(1,5,num,5);
	OLED_ShowNum(2,7,speed,5);
	OLED_ShowNum(3,5,IN1,5);
	OLED_ShowNum(4,5,IN2,5);
	TIM_SetCompare3(TIM2,speed);
	}
}

//void TIM2_IRQHandler(void){
//	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET){
//		num++;
//		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
//	}
//}
