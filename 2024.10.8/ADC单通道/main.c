#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "ADCONE.h"
int16_t Count;
uint16_t num;
int main()
{	
	OLED_Init();
	ADCONE_Init();
	while(1){
	OLED_ShowSignedNum(1,1,ADCONE_return()/1241,5);
	OLED_ShowChar(1,7,'.');
	OLED_ShowNum(1,8,ADCONE_return()%1241/100,1);
	}

}

//void TIM2_IRQHandler(void){
//	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET){
//		Count=Encoderspeed_return();
//		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
//	}
//}
