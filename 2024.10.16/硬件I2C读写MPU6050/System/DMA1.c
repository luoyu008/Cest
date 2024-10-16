#include "stm32f10x.h"                  // Device header
uint16_t dest[4];
void DMA1_Init(void){
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	
	DMA_InitTypeDef DMA_InitStruct;
	DMA_InitStruct.DMA_BufferSize=3;//����4������
	DMA_InitStruct.DMA_DIR=DMA_DIR_PeripheralSRC;//����Ĵ���ΪԴ��ַ
	DMA_InitStruct.DMA_M2M=DMA_M2M_Disable;//�ر��ڴ浽�ڴ�ģʽ
	DMA_InitStruct.DMA_MemoryBaseAddr=(uint32_t)dest;//Ŀ�ĵص�ַ
	DMA_InitStruct.DMA_MemoryDataSize=DMA_MemoryDataSize_HalfWord;//Ŀ�ĵ����ݴ�С
	DMA_InitStruct.DMA_MemoryInc=DMA_MemoryInc_Enable;//Ŀ�ĵص�ַ����
	DMA_InitStruct.DMA_Mode=DMA_Mode_Circular;//ѭ������ģʽ
	DMA_InitStruct.DMA_PeripheralBaseAddr=(uint32_t)&ADC1->DR;//����Ĵ�����ַ
	DMA_InitStruct.DMA_PeripheralDataSize=DMA_PeripheralDataSize_HalfWord;//����Ĵ������ݴ�С��Դ���ݴ�С
	DMA_InitStruct.DMA_PeripheralInc=DMA_PeripheralInc_Disable;//�����ַ������
	DMA_InitStruct.DMA_Priority=DMA_Priority_High;//���ȼ�
	DMA_Init(DMA1_Channel1,&DMA_InitStruct);
	DMA_Cmd(DMA1_Channel1,ENABLE);
//	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
}

void DMA1_Start(void){
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
	while(DMA_GetFlagStatus(DMA1_FLAG_TC1)==RESET);
	DMA_ClearFlag(DMA1_FLAG_TC1);
}
