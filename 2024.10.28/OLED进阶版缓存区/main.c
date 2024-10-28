#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "MYOLEDPLUS.h"
#include "MYOLED_Data.h"
uint8_t a;

int main()
{	
	MYOLEDPLUS_Init();
	MYOLEDPLUS_ShowImage(0,0,30,30,image);
	MYOLEDPLUS_ShowHexNum(0,0,5789,8,16);
	MYOLEDPLUS_LightUpRec(0,40,15,10,1);
	MYOLEDPLUS_LightDownDot(14,46);
	MYOLEDPLUS_ShowChinese(50,30,"∞°ƒ„∫√ ¿ΩÁ∞°");
	MYOLEDPLUS_UpData();
//	MYOLEDPLUS_Clear();
	while(1){
		
	}
}
