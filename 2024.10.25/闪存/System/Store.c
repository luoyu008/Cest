#include "stm32f10x.h"                  // Device header
#include "MYFLASH.h"
#define count 512
uint16_t arr[count];
#define PageAddress 0x0800fc00
void Store_Init(void){
	if(MYFLASH_ReadHalfWorld(PageAddress)!=0x9889){
		MYFLASH_ErasePage(PageAddress);
		MYFLASH_ProgramHalfWorld(PageAddress,0x9889);
		for(uint16_t i=1;i<count;i++){
			MYFLASH_ProgramHalfWorld(PageAddress+i*2,0x0000);
		}
	}
	for(uint16_t i=0;i<count;i++){
		arr[i]=MYFLASH_ReadHalfWorld(PageAddress+i*2);
	}
}

void Store_Save(void){
	MYFLASH_ErasePage(PageAddress);
	for(uint16_t i=0;i<count;i++){
			MYFLASH_ProgramHalfWorld(PageAddress+i*2,arr[i]);
	}
}

void Store_Clear(void){
	for(uint16_t i=0;i<count;i++){
		arr[i]=0x0000;
	}
	MYFLASH_ErasePage(PageAddress);
	Store_Save();
}
