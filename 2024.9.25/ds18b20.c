#include "ds18b20.h"
void ds18b20_ConvertT(){
	onewire_Init();
	onewire_SendByte(SKIP_ROM);
	onewire_SendByte(CONVERT_T);
}

float ds18b20_ReadT(){
	unsigned char TLSB,TMSB;
	int temp;
	float date;
	onewire_Init();
	onewire_SendByte(SKIP_ROM);
	onewire_SendByte(READ);
	TLSB=onewire_ReceiveByte();
	TMSB=onewire_ReceiveByte();
	temp=(int)(TMSB<<8)|TLSB;
	date=(float)temp/16.0;
	return date;
}