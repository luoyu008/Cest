#include "UART.h"
void uart_Init(){ //11.0592mhz
		TMOD&=0x0F;
		TMOD|=0x20;
		SCON=0x50;
		PCON=0x80;
		TH1=0xFA;
		TL1=0xFA;
		TR1=1;
		ET1=1;//关闭定时器中断 若开启会与串口中断冲突
		PT1=0;
		PS=1;
		EA=1;
		ES=1;
}
void uartsend(unsigned char date){ //传送数据
	SBUF=date;
	while(TI==0);
	TI=0;
}
