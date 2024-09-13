#include "delay.h"
void delay(unsigned int num){
unsigned char data i, j;

	_nop_();
	while(num--){
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}
}