#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "SG90.h"
#include "Delay.h"
#include "KEY.h"
uint16_t num;
uint16_t Rangle;
int main()
{	
	SG90_Init();
	KEY_Init(GPIOB,1);
	while(1){
	if(KEY_GET(GPIOB,1)){
		num++;
		num%=5;
	}
	switch(num){
		case 0:Rangle=500;break;
		case 1:Rangle=1000;break;
		case 2:Rangle=1500;break;
		case 3:Rangle=2000;break;
		case 4:Rangle=2500;break;
	}
	TIM_SetCompare2(TIM2,Rangle);
	}
}

//void TIM2_IRQHandler(void){
//	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET){
//		num++;
//		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
//	}
//}
