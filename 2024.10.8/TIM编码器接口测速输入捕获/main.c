#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Encoderspeed.h"
#include "TIM2interrupt.h"
int16_t Count;
uint16_t num;
int main()
{	
	OLED_Init();
	Encoderspeed_Init();
	TIM2_interrupt();
	while(1){
	OLED_ShowSignedNum(1,1,Count,5);
	}

}

void TIM2_IRQHandler(void){
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET){
		Count=Encoderspeed_return();
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
}
