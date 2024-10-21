#include "stm32f10x.h"                  // Device header
#include "SPIyingjian.h"
#include "W25Q64ADDRESS.h"
void W25Q64yingjian_Init(void){
	SPIyingjian_Init();
}


void W25Q64yingjian_WriteEnable(void){
	SPIyingjian_Start();
	SPIyingjian_SwapByte(W25Q64_WRITE_ENABLE);
	SPIyingjian_Stop();
}

void W25Q64yingjian_WaitBusy(void){
	uint32_t i=100000;
	SPIyingjian_Start();
	SPIyingjian_SwapByte(W25Q64_READ_STATUS_REGISTER_1);
	while((SPIyingjian_SwapByte(W25Q64_DUMMY_BYTE)&0x01)==1){
		i--;
		if(i==0){
			break;
		}
	}
	SPIyingjian_Stop();
}

void W25Q64yingjian_ReadID(uint8_t* MID,uint16_t* ID){
	SPIyingjian_Start();
	SPIyingjian_SwapByte(0x9F);
	*MID=SPIyingjian_SwapByte(0XFF);
	*ID=SPIyingjian_SwapByte(0XFF);
	*ID<<=8;
	*ID|=SPIyingjian_SwapByte(0XFF);
	SPIyingjian_Stop();
	W25Q64yingjian_WaitBusy();
}

void W25Q64yingjian_SectorErase(uint32_t Address){
	W25Q64yingjian_WriteEnable();
	SPIyingjian_Start();
	SPIyingjian_SwapByte(W25Q64_SECTOR_ERASE_4KB);
	SPIyingjian_SwapByte(Address>>16);
	SPIyingjian_SwapByte(Address>>8);
	SPIyingjian_SwapByte(Address);
	SPIyingjian_Stop();
	W25Q64yingjian_WaitBusy();
}

void W25Q64yingjian_WritePage(uint32_t Address,uint8_t* DataArry,uint16_t count){
	uint16_t i;
	W25Q64yingjian_WriteEnable();
	SPIyingjian_Start();
	SPIyingjian_SwapByte(W25Q64_PAGE_PROGRAM);
	SPIyingjian_SwapByte(Address>>16);
	SPIyingjian_SwapByte(Address>>8);
	SPIyingjian_SwapByte(Address);
	for(i=0;i<count;i++){
		SPIyingjian_SwapByte(DataArry[i]);
	}
	SPIyingjian_Stop();
	W25Q64yingjian_WaitBusy();
}

void W25Q64yingjian_ReadData(uint32_t Address,uint8_t* DataArry,uint32_t count){
	uint32_t i;
	SPIyingjian_Start();
	SPIyingjian_SwapByte(W25Q64_READ_DATA);
	SPIyingjian_SwapByte(Address>>16);
	SPIyingjian_SwapByte(Address>>8);
	SPIyingjian_SwapByte(Address);
	for(i=0;i<count;i++){
		DataArry[i]=SPIyingjian_SwapByte(W25Q64_DUMMY_BYTE);
	}
	SPIyingjian_Stop();
}
