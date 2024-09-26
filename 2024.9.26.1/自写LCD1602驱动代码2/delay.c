#include "delay.h"
void delay(unsigned char num)	//@11.0592MHz
{
	unsigned char data i, j;

	i = 180;
	j = 73;
	while(num--){
	do
	{
		while (--j);
	} while (--i);
}
	}