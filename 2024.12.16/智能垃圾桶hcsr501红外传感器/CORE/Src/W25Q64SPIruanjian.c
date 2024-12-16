#include "main.h"
#include "SPIruanjian.h"
#include "W25Q64ADDRESS.h"
#include "OLED.h"
void W25Q64SPIruanjian_Init(void){
	SPIruanjian_Init();
}

uint8_t W25Q64SPIruanjian_Swap(uint8_t Data){
	uint8_t RData;
	RData=SPIruanjian_Swap(Data);
	return RData;
}

void W25Q64SPIruanjian_WriteEnable(void){
	SPIruanjian_Start();
	W25Q64SPIruanjian_Swap(W25Q64_WRITE_ENABLE);
	SPIruanjian_Stop();
}

void W25Q64SPIruanjian_WaitBusy(void){
	uint32_t i=100000;
	SPIruanjian_Start();
	W25Q64SPIruanjian_Swap(W25Q64_READ_STATUS_REGISTER_1);
	while((W25Q64SPIruanjian_Swap(W25Q64_DUMMY_BYTE)&0x01)==1){
		i--;
		if(i==0){
			break;
		}
	}
	SPIruanjian_Stop();
}

void W25Q64SPIruanjian_EraseSector(uint32_t ADDRESS){
	W25Q64SPIruanjian_WriteEnable();
	SPIruanjian_Start();
	W25Q64SPIruanjian_Swap(W25Q64_SECTOR_ERASE_4KB);
	W25Q64SPIruanjian_Swap(ADDRESS>>16);
	W25Q64SPIruanjian_Swap(ADDRESS>>8);
	W25Q64SPIruanjian_Swap(ADDRESS);
	SPIruanjian_Stop();
	W25Q64SPIruanjian_WaitBusy();
}

void W25Q64SPIruanjian_WriteByte(uint32_t ADDRESS,uint8_t* TxData,uint8_t length){
	W25Q64SPIruanjian_EraseSector(ADDRESS);
	W25Q64SPIruanjian_WriteEnable();
	SPIruanjian_Start();
	W25Q64SPIruanjian_Swap(W25Q64_PAGE_PROGRAM);
	W25Q64SPIruanjian_Swap(ADDRESS>>16);
	W25Q64SPIruanjian_Swap(ADDRESS>>8);
	W25Q64SPIruanjian_Swap(ADDRESS);
	for(uint8_t i=0;i<length;i++){
		W25Q64SPIruanjian_Swap(TxData[i]);
	}
	SPIruanjian_Stop();
	W25Q64SPIruanjian_WaitBusy();
}

void W25Q64SPIruanjian_ReadByte(uint32_t ADDRESS,uint8_t* RxData,uint8_t length){
	SPIruanjian_Start();
	W25Q64SPIruanjian_Swap(W25Q64_READ_DATA);
	W25Q64SPIruanjian_Swap(ADDRESS>>16);
	W25Q64SPIruanjian_Swap(ADDRESS>>8);
	W25Q64SPIruanjian_Swap(ADDRESS);
	for(uint8_t i=0;i<length;i++){
		RxData[i]=W25Q64SPIruanjian_Swap(0xFF);
	}
	SPIruanjian_Stop();
}

void W25Q64SPIruanjian_ReadID(uint8_t* MID,uint16_t* ID){
	uint8_t ID1,ID2;
	SPIruanjian_Start();
	W25Q64SPIruanjian_Swap(W25Q64_JEDEC_ID);
	
	*MID=W25Q64SPIruanjian_Swap(0xFF);
	
	ID1=W25Q64SPIruanjian_Swap(0xFF);
	
	ID2=W25Q64SPIruanjian_Swap(0xFF);
//	OLED_ShowNum(0,40,rtyy,2,16);
//	OLED_UpData();
	*ID=(ID1<<8)|ID2;
	SPIruanjian_Stop();	
	W25Q64SPIruanjian_WaitBusy();
}
