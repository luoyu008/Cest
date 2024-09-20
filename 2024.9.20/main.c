#include <REGX52.H>
#include "buzzer.h"
#include "delay.h"
#include "time0.h"
#define  num   500
unsigned char fre[]={0,
	63638,63731,63835,63928,64021,64103,64185,64260,64311,64400,64463,64528,
	64580,64633,64684,64732,64777,64820,64860,64898,64934,64968,65000,65030,
	65058,65085,65110,65134,65157,65178,65198,65127,65235,65252,65268,65283};
unsigned char selct[]={
	12,4,
	12,4,
	19,4,
	19,4,
	21,4,
	21,4,
	19,4+4,
	17,4,
	17,4,
	16,4,
	16,4,
	14,4,
	14,4,
	12,4+4
};
unsigned char temp,musicselct;
void main(){
	time0_Init();
	while(1){
		musicselct=selct[temp];
	temp++;
	delay(num/4*selct[temp]);	
	temp++;
		TR0=0;
		delay(5);
		TR0=1;
	temp=temp%14;

	}
}
void time0() interrupt 1{
	if(fre[musicselct]!=0){
	TH0=fre[musicselct]/256;
	TL0=fre[musicselct]%256;
	buz=!buz;
	}
	
}