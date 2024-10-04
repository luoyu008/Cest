#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "R_encoder.h"

int main()
{	
	OLED_Init();
	R_encoder_Init();                       
	while(1){
		OLED_ShowNum(1,1,R_encoder_return(),5);
	}
}
