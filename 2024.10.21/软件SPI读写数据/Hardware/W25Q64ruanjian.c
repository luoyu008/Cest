#include "stm32f10x.h"                  // Device header
#include "SPIruanjian.h"
#include "W25Q64ADDRESS.h"
void W25Q64ruanjian_Init(void){
	SPIruanjian_Init();
}


void W25Q64ruanjian_WriteEnable(void){
	SPIruanjian_Start();
	SPIruanjian_SwapByte(W25Q64_WRITE_ENABLE);
	SPIruanjian_Stop();
}

void W25Q64ruanjian_WaitBusy(void){
	uint32_t i=100000;
	SPIruanjian_Start();
	SPIruanjian_SwapByte(W25Q64_READ_STATUS_REGISTER_1);
	while((SPIruanjian_SwapByte(W25Q64_DUMMY_BYTE)&0x01)==1){
		i--;
		if(i==0){
			i=100000;
			break;
		}
	}
	SPIruanjian_Stop();
}

void W25Q64ruanjian_ReadID(uint8_t* MID,uint16_t* ID){
	SPIruanjian_Start();
	SPIruanjian_SwapByte(0x9F);
	*MID=SPIruanjian_SwapByte(0XFF);
	*ID=SPIruanjian_SwapByte(0XFF);
	*ID<<=8;
	*ID|=SPIruanjian_SwapByte(0XFF);
	SPIruanjian_Stop();
	W25Q64ruanjian_WaitBusy();
}

void W25Q64ruanjian_SectorErase(uint32_t Address){
	W25Q64ruanjian_WriteEnable();
	SPIruanjian_Start();
	SPIruanjian_SwapByte(W25Q64_SECTOR_ERASE_4KB);
	SPIruanjian_SwapByte(Address>>16);
	SPIruanjian_SwapByte(Address>>8);
	SPIruanjian_SwapByte(Address);
	SPIruanjian_Stop();
	W25Q64ruanjian_WaitBusy();
}

void W25Q64ruanjian_WritePage(uint32_t Address,uint8_t* DataArry,uint16_t count){
	uint16_t i;
	W25Q64ruanjian_WriteEnable();
	SPIruanjian_Start();
	SPIruanjian_SwapByte(W25Q64_PAGE_PROGRAM);
	SPIruanjian_SwapByte(Address>>16);
	SPIruanjian_SwapByte(Address>>8);
	SPIruanjian_SwapByte(Address);
	for(i=0;i<count;i++){
		SPIruanjian_SwapByte(DataArry[i]);
	}
	SPIruanjian_Stop();
	W25Q64ruanjian_WaitBusy();
}

void W25Q64ruanjian_ReadData(uint32_t Address,uint8_t* DataArry,uint32_t count){
	uint32_t i;
	SPIruanjian_Start();
	SPIruanjian_SwapByte(W25Q64_READ_DATA);
	SPIruanjian_SwapByte(Address>>16);
	SPIruanjian_SwapByte(Address>>8);
	SPIruanjian_SwapByte(Address);
	for(i=0;i<count;i++){
		DataArry[i]=SPIruanjian_SwapByte(W25Q64_DUMMY_BYTE);
	}
	SPIruanjian_Stop();
}
