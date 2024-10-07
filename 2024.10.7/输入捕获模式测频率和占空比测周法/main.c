#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "input.h"
#include "output.h"
uint16_t num;
uint16_t HZ;
uint16_t count1;
uint8_t duty;
int main()
{	
	OLED_Init();
	output_Init();
	input_Init();
	OLED_ShowString(1,1,"HZ:000000");
	OLED_ShowString(2,1,"DUTY:");
	SET_PSC(720-1);//1KHZ
	while(1){
		num=TIM_GetCapture1(TIM3);
		HZ=1000000/(num+1);
		OLED_ShowNum(1,4,HZ,6);
		count1=TIM_GetCapture2(TIM3);
		duty=(count1+1)*100/(num+1);
		OLED_ShowNum(2,6,duty,6);
	
	}

}

//void TIM2_IRQHandler(void){
//	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET){
//		num++;
//		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
//	}
//}
