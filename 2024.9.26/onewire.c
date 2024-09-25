#include "onewire.h"
unsigned char onewire_Init(){
	unsigned char i;
	unsigned char res=0;
	EA=0;
	DQ=1;
	DQ=0;
	i = 227;while (--i);		//延时500us
	DQ=1;
	i = 29;while (--i);			//延时70us
	res=DQ;
	i = 227;while (--i);		//延时500us
	EA=1;
	return res;
}
void onewire_SendBit(unsigned char Bit){
	

	unsigned char i;
	EA=0;
	if(Bit){
	DQ=0;
	_nop_();i = 3;while (--i);			//延时10us
	DQ=1;
	i=24;while(--i);				//延时50us

	}
	else{
	DQ=0;
	i = 25;while (--i);			//延时60us
	DQ=1;
	}
	EA=1;
	/*
	DQ=0;
	i=4;while(--i);  				//延时10us
	DQ=Bit;
	i=24;while(--i);				//延时50us
	DQ=1;
	*/
}

unsigned char onewire_ReceiveBit(){
	
	unsigned char i,date;
	EA=0;
	DQ=0;
	_nop_();i = 1;while (--i);//延时5us
	DQ=1;
	_nop_();i = 1;while (--i);//延时5us
	date=DQ;
	i=24;while(--i);				//延时50us	
	EA=1;
	return date;
}

void onewire_SendByte(unsigned char Byte){
	
	unsigned char i=0;
	EA=0;
	for(i=0;i<8;i++){
	onewire_SendBit(Byte&(0x01<<i));
	}
	EA=1;
}

unsigned char onewire_ReceiveByte(){
	
	unsigned char i=0,date=0;
	EA=0;
	for(i=0;i<8;i++){
	if(onewire_ReceiveBit()){
	date|=(0x01<<i);
	}
		//date|=((0x01<<i)&onewire_ReceiveBit());
	}
	EA=1;
	return date;
}