#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "DMAARR.h"
#include "Delay.h"
uint8_t src[4]={0x01,0x02,0x03,0x04};
uint8_t des[4]={0,0,0,0};

int main()
{	
	OLED_Init();
	DMAARR_Init((uint32_t)src,(uint32_t)des,4);
	while(1){
	DMAARR_Start(DMA1_Channel1,4);
	OLED_ShowNum(1,1,src[0],4);
	OLED_ShowNum(1,5,src[1],4);
	OLED_ShowNum(1,9,src[2],4);
	OLED_ShowNum(1,13,src[3],4);
	OLED_ShowNum(2,1,des[0],4);
	OLED_ShowNum(2,5,des[1],4);
	OLED_ShowNum(2,9,des[2],4);
	OLED_ShowNum(2,13,des[3],4);
		src[0]++;
		src[1]++;
		src[2]++;
		src[3]++;
		Delay_ms(100);
	}

}

//void TIM2_IRQHandler(void){
//	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET){
//		Count=Encoderspeed_return();
//		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
//	}
//}
