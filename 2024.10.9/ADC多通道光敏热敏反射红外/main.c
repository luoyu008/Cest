#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "ADCMORE.h"
int16_t Count;
uint16_t num;
int main()
{	
	OLED_Init();
	ADCMORE_Init();
	while(1){
	OLED_ShowSignedNum(1,1,ADCMORE_return1(ADC_Channel_0,1)/1241,5);
	OLED_ShowChar(1,7,'.');
	OLED_ShowNum(1,8,ADCMORE_return1(ADC_Channel_0,1)%1241/100,1);
	OLED_ShowSignedNum(2,1,ADCMORE_return1(ADC_Channel_1,1),5);
	OLED_ShowSignedNum(3,1,ADCMORE_return1(ADC_Channel_2,1),5);
	OLED_ShowSignedNum(4,1,ADCMORE_return1(ADC_Channel_3,1),5);
	}

}

//void TIM2_IRQHandler(void){
//	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET){
//		Count=Encoderspeed_return();
//		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
//	}
//}
