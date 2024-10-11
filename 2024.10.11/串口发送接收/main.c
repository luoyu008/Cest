#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "Serial.h"
#include "SerialReceive.h"
uint8_t Date;
int main()
{	
//	uint8_t ARR[]={0x69,0x87,0x68,0x66};
//	char* str="scdef";
	SerialReceive_Init();
//	Serial_Send(0x41);
//	Serial_SendArr(ARR,4);
//	Serial_SendString(str);
//	Serial_Print("ÖìÊÀÅôÊÇÂÞµ¤µÄµù");
	while(1){

	}

}

void USART1_IRQHandler(void){
	if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET){
		Date=USART_ReceiveData(USART1);
		Serial_Send(Date);
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
	}
}
