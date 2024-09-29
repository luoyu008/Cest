#include "time0.h"
void time1_Init(){
	TMOD|=0x01;
	TH1=0xFC;
	TL1=0X18;
	//TF0=0;
	TR1=1;
	ET1=1;
	EA=1;
	//PT0=1;
}