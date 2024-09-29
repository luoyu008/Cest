#include "delay.h"
void delay560us(void)	//@11.0592MHz
{
	unsigned char data i, j;

	i = 1;
	j = 254;
	do
	{
		while (--j);
	} while (--i);
}
void Delay1680us(void)	//@11.0592MHz
{
	unsigned char data i, j;

	i = 3;
	j = 0;
	do
	{
		while (--j);
	} while (--i);
}
void Delay9ms(void)	//@11.0592MHz
{
	unsigned char data i, j;

	i = 17;
	j = 31;
	do
	{
		while (--j);
	} while (--i);
}
void Delay4ms(void)	//@11.0592MHz
{
	unsigned char data i, j;

	i = 8;
	j = 40;
	do
	{
		while (--j);
	} while (--i);
}
void Delay2ms(void)	//@11.0592MHz
{
	unsigned char data i, j;

	_nop_();
	i = 4;
	j = 146;
	do
	{
		while (--j);
	} while (--i);
}
void Delay98ms(void)	//@11.0592MHz
{
	unsigned char data i, j;

	i = 176;
	j = 179;
	do
	{
		while (--j);
	} while (--i);
}