#ifndef __DS18B20_H__
#define __DS18B20_H__
#include <REGX52.H>
#include "onewire.h"
#define SKIP_ROM 0xcc
#define CONVERT_T 0x44
#define READ 0xbe
void ds18b20_ConvertT();
float ds18b20_ReadT();
#endif