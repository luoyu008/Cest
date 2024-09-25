#ifndef __AT24C02_H__
#define __AT24C02_H__
#include <REGX52.H>
#include "iic.h"
#define ataddress 0xa0
void at24c02_Writebyte(unsigned char wordaddress,date);
unsigned char at24c02_Readbyte(unsigned char wordaddress);
#endif