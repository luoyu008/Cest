#include "UART.h"
void uart_Init(){ //11.0592mhz
		TMOD&=0x0F;
		TMOD|=0x20;
		SCON=0x50;
		PCON=0x80;
		TH1=0xFA;
		TL1=0xFA;
		TR1=1;
		ET1=1;
		EA=1;
		ES=1;
}
void uartsend(unsigned char date){ //´«ËÍÊý¾Ý
	SBUF=date;
	while(TI==0);
	TI=0;
}
