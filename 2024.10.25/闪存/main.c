#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Store.h"
#include "KEY.h"
uint16_t key1,key2;
int main()
{	
	OLED_Init();
	Store_Init();
	KEY_Init(GPIOB,1);
	KEY_Init(GPIOB,11);
	while(1){
	key1+=KEY_GET(GPIOB,1);
	key2=KEY_GET(GPIOB,11);
	if(key1==1){
		arr[1]+=2;
		arr[2]+=3;
		arr[3]+=4;
	}
	if(key1==2){
		Store_Clear();
	}
	if(key2==1){
		Store_Save();
	}
	OLED_ShowHexNum(1,1,arr[0],4);
	OLED_ShowHexNum(2,1,arr[1],4);
	OLED_ShowHexNum(3,1,arr[2],4);
	OLED_ShowHexNum(4,1,arr[3],4);
	}
}
