#ifndef __OUT_INTERRUPT_H__
#define __OUT_INTERRUPT_H__
#include <REGX52.H>
#include "time0.h"
void out_Init();
unsigned char out0_returnadd();//·µ»ØµØÖ·Âë
unsigned char out0_returncom();//·µ»ØÃüÁîÂë
unsigned char out0_getdateflage();
unsigned char out0_getrepeatflage();
#endif