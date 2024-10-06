#include "delay.h"
void delay(unsigned int num){
	unsigned char  i, j;

	while(num--){
	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}
}