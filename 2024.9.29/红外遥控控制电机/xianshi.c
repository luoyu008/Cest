#include "xianshi.h"
unsigned char str[]={0,10,10,10,10,10,10,10,10};
unsigned char ARR1[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x00,0x80
										 //0x6f,0x7f,0x07,0x7d,0x6d,0x66,0x4f,0x5b,0x06,0x3f,0x00
	};
void xianshi_0(unsigned char location,unsigned char num){
	str[location]=num;
	//xianshi(location,str1[location]);
}
void xianshi(unsigned char location,number){
	P0=0x00;
	switch(location){
		case 8:P2_2=0;
		P2_3=0;
	P2_4=0;
		break;
		case 7:P2_2=1;
	P2_3=0;
	P2_4=0;
		break;
		case 6:P2_2=0;
	P2_3=1;
	P2_4=0;
		break;
		case 5:P2_2=1;
	P2_3=1;
	P2_4=0;
		break;
		case 4:P2_2=0;
	P2_3=0;
	P2_4=1;
		break;
		case 3:P2_2=1;
	P2_3=0;
	P2_4=1;
		break;
		case 2:P2_2=0;
	P2_3=1;
	P2_4=1;
		break;
		case 1:P2_2=1;
	P2_3=1;
	P2_4=1;
		break;
		default:
			break;
	}
	P0=ARR1[number];
}
void xianshi_loop(){
	static unsigned char i=1;
	xianshi(i,str[i]);
	i++;
	if(i>=9){
	i=1;
	}
}
//void delay(unsigned int num){
//		unsigned char i,j;
//	i=2;
//	j=199;
//	while(num--){
//	do{
//		while(--j);
//	}while(--i);
//}
//	}