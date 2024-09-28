#include "xpt2046.h"
//写数据
void WriteByte(unsigned char commend){
	unsigned char i=7;
//	unsigned char com;
//	com=commend;
	DCLK=0;
	for(i=0;i<8;i++){
		DIN=commend>>7;
		commend=commend<<1;
		DCLK=1;
		DCLK=0;
	}
}
//读数据
//unsigned int ReadByte(){
//	unsigned int date;
//	unsigned char i=7;
//	DCLK=0;
//	for(i=11;i>=0;i--){
//		date<<=1;
//		DCLK=1;
//		DCLK=0;
//		date|=DOUT;
////		DCLK=1;
////		DCLK=0;
////		date&(0x0001<<i)|=DOUT;
//	}
//	return date;
//}
//xpt2046读数据
unsigned int  xpt2046_ReadByte(unsigned char commend){
	unsigned int date=0;
	unsigned char i=0;
	CS=1;
	CS=0;
	DCLK=0;
	WriteByte(commend);
	for(i=0;i<12;i++){
		date<<=1;
		DCLK=1;
		DCLK=0;
		date|=DOUT;
	}
	CS=1;
	return date>>4;
}