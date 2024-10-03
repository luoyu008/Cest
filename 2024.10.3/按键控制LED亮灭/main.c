#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "KEY.h"
uint8_t key1;
uint8_t key2;
int main()
{	
	LED_Init(GPIOA,0);
	LED_Init(GPIOA,1);
	KEY_Init(GPIOB,11);
	KEY_Init(GPIOB,1);
	while(1){
		key1=KEY_GET(GPIOB,11);
		if(key1){
			LED_Rever(GPIOA,1);
		}
		key2=KEY_GET(GPIOB,1);
		if(key2){
			LED_Rever(GPIOA,0);
		}
	}
}
