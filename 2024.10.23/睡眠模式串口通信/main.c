#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "Serial.h"
#include "SerialReceive.h"
uint8_t Date;
int main()
{	
	OLED_Init();
	Serial_Init();
	SerialReceive_Init();
	while(1){
		if(SerialReceive_GetRXFlag()){
			OLED_ShowHexNum(1,1,Date,2);
		}
	OLED_ShowString(2,1,"Running");
	Delay_ms(500);
	OLED_ShowString(2,1,"       ");
	Delay_ms(500);
	
	__WFI();
	}

}

void USART1_IRQHandler(void){
	if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET){
		Date=USART_ReceiveData(USART1);
		SerialReceive_RXFlag=1;
		Serial_Send(Date+1);
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
	}
}
