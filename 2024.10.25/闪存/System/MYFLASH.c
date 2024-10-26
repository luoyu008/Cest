#include "stm32f10x.h"                  // Device header
uint32_t MYFLASH_ReadWorld(uint32_t ADDRESS){
	return *(__IO uint32_t*)(ADDRESS);
}

uint16_t MYFLASH_ReadHalfWorld(uint32_t ADDRESS){
	return *(__IO uint16_t*)(ADDRESS);
}

uint8_t MYFLASH_ReadByte(uint32_t ADDRESS){
	return *(__IO uint8_t*)(ADDRESS);
}

void MYFLASH_ErasePage(uint32_t ADDRESS){
	FLASH_Unlock();
	FLASH_ErasePage(ADDRESS);
	FLASH_Lock();
}


void MYFLASH_EraseALL(void){
	FLASH_Unlock();
	FLASH_EraseAllPages();
	FLASH_Lock();
}

void MYFLASH_ProgramWorld(uint32_t ADDRESS,uint32_t Data){
	FLASH_Unlock();
	FLASH_ProgramWord(ADDRESS,Data);
	FLASH_Lock();
}

void MYFLASH_ProgramHalfWorld(uint32_t ADDRESS,uint16_t Data){
	FLASH_Unlock();
	FLASH_ProgramHalfWord(ADDRESS,Data);
	FLASH_Lock();
}
