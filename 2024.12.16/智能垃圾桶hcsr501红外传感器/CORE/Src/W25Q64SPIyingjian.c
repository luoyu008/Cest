#include "main.h"
#include "SPIyingjian.h"
#include "W25Q64ADDRESS.h"
#include "OLED.h"
uint8_t rtyy;
extern SPI_HandleTypeDef SPI_yingjianHandInit;
void W25Q64SPIyingjian_Init(void){
	SPIyingjian_Init();
}

uint8_t W25Q64SPIyingjian_Swap(uint8_t Data){
	uint8_t RData;
	HAL_SPI_TransmitReceive(&SPI_yingjianHandInit,&Data,&RData,1,10);
	return RData;
}

void W25Q64SPIyingjian_WriteEnable(void){
	SPIyingjian_Start();
	W25Q64SPIyingjian_Swap(W25Q64_WRITE_ENABLE);
	SPIyingjian_Stop();
}

void W25Q64yingjian_WaitBusy(void){
	uint32_t i=100000;
	SPIyingjian_Start();
	W25Q64SPIyingjian_Swap(W25Q64_READ_STATUS_REGISTER_1);
	while((W25Q64SPIyingjian_Swap(W25Q64_DUMMY_BYTE)&0x01)==1){
		i--;
		if(i==0){
			break;
		}
	}
	SPIyingjian_Stop();
}

void W25Q64SPIyingjian_EraseSector(uint32_t ADDRESS){
	W25Q64SPIyingjian_WriteEnable();
	SPIyingjian_Start();
	W25Q64SPIyingjian_Swap(W25Q64_SECTOR_ERASE_4KB);
	W25Q64SPIyingjian_Swap(ADDRESS>>16);
	W25Q64SPIyingjian_Swap(ADDRESS>>8);
	W25Q64SPIyingjian_Swap(ADDRESS);
	SPIyingjian_Stop();
	W25Q64yingjian_WaitBusy();
}

void W25Q64SPIyingjian_WriteByte(uint32_t ADDRESS,uint8_t* TxData,uint8_t length){
	W25Q64SPIyingjian_EraseSector(ADDRESS);
	W25Q64SPIyingjian_WriteEnable();
	SPIyingjian_Start();
	W25Q64SPIyingjian_Swap(W25Q64_PAGE_PROGRAM);
	W25Q64SPIyingjian_Swap(ADDRESS>>16);
	W25Q64SPIyingjian_Swap(ADDRESS>>8);
	W25Q64SPIyingjian_Swap(ADDRESS);
	for(uint8_t i=0;i<length;i++){
		W25Q64SPIyingjian_Swap(TxData[i]);
	}
	SPIyingjian_Stop();
	W25Q64yingjian_WaitBusy();
}

void W25Q64SPIyingjian_ReadByte(uint32_t ADDRESS,uint8_t* RxData,uint8_t length){
	SPIyingjian_Start();
	W25Q64SPIyingjian_Swap(W25Q64_READ_DATA);
	W25Q64SPIyingjian_Swap(ADDRESS>>16);
	W25Q64SPIyingjian_Swap(ADDRESS>>8);
	W25Q64SPIyingjian_Swap(ADDRESS);
	for(uint8_t i=0;i<length;i++){
		RxData[i]=W25Q64SPIyingjian_Swap(0xFF);
	}
	SPIyingjian_Stop();
}

void W25Q64SPIyingjian_ReadID(uint8_t* MID,uint16_t* ID){
	uint8_t ID1,ID2;
	SPIyingjian_Start();
	W25Q64SPIyingjian_Swap(W25Q64_JEDEC_ID);
	
	*MID=W25Q64SPIyingjian_Swap(0xFF);
	
	ID1=W25Q64SPIyingjian_Swap(0xFF);
	
	ID2=W25Q64SPIyingjian_Swap(0xFF);
//	OLED_ShowNum(0,40,rtyy,2,16);
//	OLED_UpData();
	*ID=(ID1<<8)|ID2;
	SPIyingjian_Stop();	
	W25Q64yingjian_WaitBusy();
}
