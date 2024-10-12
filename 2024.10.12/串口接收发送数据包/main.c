#include "stm32f10x.h"                  // Device header
#include "OLED.h"
#include "Delay.h"
#include "Bluetooth.h"
#include "KEY.h"
#define Start '@'
#define Stop '$'
char str[100];
uint8_t Date;
uint8_t state;
uint8_t state1;
uint8_t i;
uint8_t j;
uint8_t compare;
//#define Start 0xFF
//#define Stop 0XFE
//uint8_t key;
//uint8_t Date;
//uint8_t state;
//uint8_t re[5];
//uint8_t se[5];
//uint8_t i;
int main()
{	
	OLED_Init();
	Bluetooth_Init();
	char* str1="LED#ON";
	char* str2="LED#ON#OK";
	char* str3="LED#OFF";
	char* str4="LED#OFF#OK";
	char* str5="ERROR#COMMEND";
//	KEY_Init(GPIOB,1);
	while(1){
//		if(KEY_GET(GPIOB,1)){
//			re[0]++;
//			re[1]++;
//			re[2]++;
//			re[3]++;
//			re[4]++;
//		USART_SendData(USART1,0Xff);
//		while(!USART_GetFlagStatus(USART1,USART_FLAG_TXE));
//		Serial_SendArr1(re,5);
//		USART_SendData(USART1,0xfe);
//	}
//	OLED_ShowHexNum(1,1,re[0],2);
//	OLED_ShowHexNum(1,3,re[1],2);
//	OLED_ShowHexNum(1,5,re[2],2);
//	OLED_ShowHexNum(1,7,re[3],2);
//	OLED_ShowHexNum(1,9,re[4],2);
		if(state1==1){
	while(str[j]!='\0'){
	if(str[j]==str1[j]){
	compare=2;
	j++;
	}
	else{
	compare=4;
		break;
	}
	}
	j=0;
	if(compare==4){
	while(str[j]!='\0'){
	if(str[j]==str3[j]){
	compare=3;
	j++;
	}
	else{
	compare=1;
		break;
	}
	}
}
	if(compare==1){
		Serial_SendString1(str5);
	}
	else if(compare==2){
		Serial_SendString1(str2);
		compare=0;
	}
	else if(compare==3){
		Serial_SendString1(str4);
		compare=0;
	}
	state1=0;
}
	OLED_ShowString(1,1,str);
	}
}


void USART1_IRQHandler(void){
	if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET){
		Date=USART_ReceiveData(USART1);
		if(state==0){
			if(Date==Start){
			state=1;
			return;
			}
			else{
			return;
			}
		}
		if(state==1){
			if(Date!=Stop){
				str[i]=Date;
				i++;
				return;
			}
			else{
				str[i]='\0';
				i=0;
				state=0;
				state1=1;
				return;
			}
		}
		
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
	}
}

//void USART1_IRQHandler(void){
//	if(USART_GetITStatus(USART1,USART_IT_RXNE)==SET){
//		Date=USART_ReceiveData(USART1);
//		if(state==0){
//		if(Date==Start){
//			state=1;
//			return;
//		}
//		else{
//		return;
//		}
//		}
//		if(state==1){
//			if(i<4){
//				re[i]=Date;
//				i++;
//				return ;
//			}
//			else if(i==4){
//				re[i]=Date;
//				state=2;
//				return;
//			}
//		}
//		if(state==2){
//			if(Date==Stop){
//				state=0;
//				i=0;
//				return;
//			}
//			else{
//				return;
//			}
//		}
//		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
//	}
//}
