#include "time0.h"
void time0_Init(){
	TMOD &= 0xF0;
	TMOD|=0x01;
	TH0=0;
	TL0=0;
	TF0=0;
	TR0=0;
}
void time0_con(unsigned char flag){//���ƶ�ʱ��0������
	TR0=flag;
}
void time0_set(unsigned int num){//��ʱ��0����
	TH0=num/256;
	TL0=num%256;
}
unsigned int time0_return()//���ض�ʱ�����˶�������
{
	return (TH0<<8)|TL0;
}