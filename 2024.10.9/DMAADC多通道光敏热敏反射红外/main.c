#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "ADCMORE.h"
int main()
{	
	OLED_Init();
	ADCMORE_Init();
	while(1){
	ADCMORE_return1();
	OLED_ShowNum(1,1,des[0],4);
	OLED_ShowNum(2,1,des[1],4);
	OLED_ShowNum(3,1,des[2],4);
	OLED_ShowNum(4,1,des[3],4);
		Delay_ms(100);
	}

}

//void TIM2_IRQHandler(void){
//	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET){
//		Count=Encoderspeed_return();
//		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
//	}
//}
