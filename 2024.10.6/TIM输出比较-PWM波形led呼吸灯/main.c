#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Timecount.h"
#include "Delay.h"
uint16_t num;
int main()
{	
	Timecount_Init();
	while(1){
	for(num=1;num<=100;num++){
		TIM_SetCompare1(TIM2,num);
		Delay_ms(20);
	}
	for(num=100;num>0;num--){
		TIM_SetCompare1(TIM2,num);
		Delay_ms(20);
	}	
	}
}

//void TIM2_IRQHandler(void){
//	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET){
//		num++;
//		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
//	}
//}
