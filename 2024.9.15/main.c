#include "delay.h"

unsigned int count;
void main(){
	uart_Init();
	while(1){
		
	}
}

void uartaccept() interrupt 4{
	unsigned char date=0;
	if(RI==1){
	RI=0;
	date=SBUF;
	uartsend(date);
	}
	}