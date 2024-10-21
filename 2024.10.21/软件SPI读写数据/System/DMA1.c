#include "stm32f10x.h"                  // Device header
uint16_t dest[4];
void DMA1_Init(void){
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	
	DMA_InitTypeDef DMA_InitStruct;
	DMA_InitStruct.DMA_BufferSize=3;//传输4个数据
	DMA_InitStruct.DMA_DIR=DMA_DIR_PeripheralSRC;//外设寄存器为源地址
	DMA_InitStruct.DMA_M2M=DMA_M2M_Disable;//关闭内存到内存模式
	DMA_InitStruct.DMA_MemoryBaseAddr=(uint32_t)dest;//目的地地址
	DMA_InitStruct.DMA_MemoryDataSize=DMA_MemoryDataSize_HalfWord;//目的地数据大小
	DMA_InitStruct.DMA_MemoryInc=DMA_MemoryInc_Enable;//目的地地址自增
	DMA_InitStruct.DMA_Mode=DMA_Mode_Circular;//循环传输模式
	DMA_InitStruct.DMA_PeripheralBaseAddr=(uint32_t)&ADC1->DR;//外设寄存器地址
	DMA_InitStruct.DMA_PeripheralDataSize=DMA_PeripheralDataSize_HalfWord;//外设寄存器数据大小即源数据大小
	DMA_InitStruct.DMA_PeripheralInc=DMA_PeripheralInc_Disable;//外设地址不自增
	DMA_InitStruct.DMA_Priority=DMA_Priority_High;//优先级
	DMA_Init(DMA1_Channel1,&DMA_InitStruct);
	DMA_Cmd(DMA1_Channel1,ENABLE);
//	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
}

void DMA1_Start(void){
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
	while(DMA_GetFlagStatus(DMA1_FLAG_TC1)==RESET);
	DMA_ClearFlag(DMA1_FLAG_TC1);
}
