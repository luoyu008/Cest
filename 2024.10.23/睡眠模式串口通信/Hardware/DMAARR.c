#include "stm32f10x.h"                  // Device header
void DMAARR_Init(uint32_t src,uint32_t des,uint16_t size){
	//打开dma时钟
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	//配置DMA通道
	DMA_InitTypeDef DMA_InitStructure;
	DMA_InitStructure.DMA_BufferSize=size;
	DMA_InitStructure.DMA_DIR=DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_M2M=DMA_M2M_Enable;
	DMA_InitStructure.DMA_MemoryBaseAddr=des;
	DMA_InitStructure.DMA_MemoryDataSize=DMA_MemoryDataSize_Byte;
	DMA_InitStructure.DMA_MemoryInc=DMA_MemoryInc_Enable;
	DMA_InitStructure.DMA_Mode=DMA_Mode_Normal;
	DMA_InitStructure.DMA_PeripheralBaseAddr=src;
	DMA_InitStructure.DMA_PeripheralDataSize=DMA_PeripheralDataSize_Byte;
	DMA_InitStructure.DMA_PeripheralInc=DMA_PeripheralInc_Enable;
	DMA_InitStructure.DMA_Priority=DMA_Priority_VeryHigh;
	DMA_Init(DMA1_Channel1,&DMA_InitStructure);
	//打开dma1
//	DMA_Cmd(DMA1_Channel1,ENABLE);
}

void DMAARR_Start(DMA_Channel_TypeDef* DMAy_Channelx, uint16_t DataNumber){
	DMA_Cmd(DMAy_Channelx,DISABLE);
	DMA_SetCurrDataCounter(DMAy_Channelx,DataNumber);
	DMA_Cmd(DMAy_Channelx,ENABLE);
	while(DMA_GetFlagStatus(DMA1_FLAG_TC1)==RESET);
	DMA_ClearFlag(DMA1_FLAG_TC1);
}
