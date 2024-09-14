#include <REGX52.H>

void delay(unsigned int num){
// while(num--);
	unsigned char i, j;

	i = 12;
	j = 169;
	while(num--){
	do
	{
		while (--j);
	} while (--i);
	}
	}
void exter0_Init(){
	IT0=1;
	EX0=1;
	EA=1;
}
void main(){
	exter0_Init();
	while(1){
	
	}
}

void exter() interrupt 0{
	delay(5);
	if(P3_2==0){
	P2_0=!P2_0;
	}
}