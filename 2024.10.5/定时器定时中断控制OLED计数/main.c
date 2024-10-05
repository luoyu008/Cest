#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Timecount.h"
uint16_t count;
int main()
{	
	Timecount_Init();
	OLED_Init();

	while(1){
	
			OLED_ShowNum(1,1,count,5);
			OLED_ShowNum(2,1,TIM_GetCounter(TIM2),5);
	}
}

void TIM2_IRQHandler(void){
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET){
		count++;
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
}
