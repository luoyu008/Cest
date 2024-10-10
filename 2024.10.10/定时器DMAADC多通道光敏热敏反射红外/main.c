#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "ADC2.h"
#include "DMA1.h"
#include "TIM2.h"
uint32_t count3;
int main()
{	
	OLED_Init();
	TIM2_Init();
	ADC2_Init();
	DMA1_Init();

	while(1){
//		DMA1_Start();
	OLED_ShowNum(1,1,dest[0],4);
	OLED_ShowNum(2,1,dest[1],4);
	OLED_ShowNum(3,1,dest[2],4);
	OLED_ShowNum(4,1,dest[3],4);
		Delay_ms(100);
	}

}

//void TIM2_IRQHandler(void){
//	if(TIM_GetITStatus(TIM2,TIM_IT_CC2)==SET){
//		count3++;
//		TIM_ClearITPendingBit(TIM2,TIM_IT_CC2);
//	}
//}
