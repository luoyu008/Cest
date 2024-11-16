#ifndef __MYDMA_H__
#define __MYDMA_H__
extern DMA_HandleTypeDef DMA_MYDMAHandInit;
extern uint8_t arr_des[];
extern uint8_t arr_src[];
void MYDMA_Init(void);
void DMA_ENABLE(uint32_t length);
#endif
