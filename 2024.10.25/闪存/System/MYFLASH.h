#ifndef __MYFLASH_H__
#define __MYFLASH_H__
#include "stm32f10x.h"                  // Device header
uint32_t MYFLASH_ReadWorld(uint32_t ADDRESS);
uint16_t MYFLASH_ReadHalfWorld(uint32_t ADDRESS);
uint8_t MYFLASH_ReadByte(uint32_t ADDRESS);
void MYFLASH_ErasePage(uint32_t ADDRESS);
void MYFLASH_EraseALL(void);
void MYFLASH_ProgramWorld(uint32_t ADDRESS,uint32_t Data);
void MYFLASH_ProgramHalfWorld(uint32_t ADDRESS,uint16_t Data);
#endif
