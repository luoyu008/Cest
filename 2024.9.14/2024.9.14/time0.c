#include "time0.h"
void time0_Init(){
	TMOD|=0x01;
	TH0=0xFC;
	TL0=0X18;
	//TF0=0;
	TR0=1;
	ET0=1;
	EA=1;
	//PT0=1;
}