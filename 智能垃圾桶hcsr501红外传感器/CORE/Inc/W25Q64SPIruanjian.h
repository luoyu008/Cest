#ifndef __W25Q64SPIRUANJIAN_H__
#define __W25Q64SPIRUANJIAN_H__
void W25Q64SPIruanjian_Init(void);
uint8_t W25Q64SPIruanjian_Swap(uint8_t Data);
void W25Q64SPIruanjian_WriteEnable(void);
void W25Q64SPIruanjian_WaitBusy(void);
void W25Q64SPIruanjian_EraseSector(uint32_t ADDRESS);
void W25Q64SPIruanjian_WriteByte(uint32_t ADDRESS,uint8_t* TxData,uint8_t length);
void W25Q64SPIruanjian_ReadByte(uint32_t ADDRESS,uint8_t* RxData,uint8_t length);
void W25Q64SPIruanjian_ReadID(uint8_t* MID,uint16_t* ID);
#endif
