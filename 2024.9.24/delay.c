#include "delay.h"
void delay(unsigned int num){
	unsigned char i,j;
	i=2;
	j=199;
	while(num--){
	do{
		while(--j);
	}while(--i);
}
}