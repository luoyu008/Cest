#ifndef __W25Q64SPIYINGJIAN_H__
#define __W25Q64SPIYINGJIAN_H__
void W25Q64SPIyingjian_Init(void);
uint8_t W25Q64SPIyingjian_Swap(uint8_t Data);
void W25Q64SPIyingjian_WriteEnable(void);
void W25Q64yingjian_WaitBusy(void);
void W25Q64SPIyingjian_ReadID(uint8_t* MID,uint16_t* ID);
void W25Q64SPIyingjian_EraseSector(uint32_t ADDRESS);
void W25Q64SPIyingjian_WriteByte(uint32_t ADDRESS,uint8_t* TxData,uint8_t length);
void W25Q64SPIyingjian_ReadByte(uint32_t ADDRESS,uint8_t* RxData,uint8_t length);
#endif

