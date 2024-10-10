#include "stm32f10x.h"                  // Device header
uint16_t des[8];
void ADCMORE_Init(void){
	//打开时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
	//打开dma时钟
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	//选择时钟
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	//配置规则组通道
	ADC_RegularChannelConfig(ADC1,ADC_Channel_0,1,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_1,2,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_2,3,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_3,4,ADC_SampleTime_55Cycles5);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AIN;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//初始化adc
	ADC_InitTypeDef ADC_InitStructure;
	ADC_InitStructure.ADC_ContinuousConvMode=ENABLE;
											 //DISABLE;//单次模式
	ADC_InitStructure.ADC_DataAlign=ADC_DataAlign_Right;//数据右对齐
	ADC_InitStructure.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;//无外部触发源
	ADC_InitStructure.ADC_Mode=ADC_Mode_Independent;//独立工作模式
	ADC_InitStructure.ADC_NbrOfChannel=4;//需要转换的规则通道个数
	ADC_InitStructure.ADC_ScanConvMode=ENABLE;//扫描模式转换
	ADC_Init(ADC1,&ADC_InitStructure);
	//配置DMA通道
	DMA_InitTypeDef DMA_InitStructure;
	DMA_InitStructure.DMA_BufferSize=4;//传输4个数据
	DMA_InitStructure.DMA_DIR=DMA_DIR_PeripheralSRC;//外设寄存器为传输源头
	DMA_InitStructure.DMA_M2M=DMA_M2M_Disable;//关闭软件触发模式 因为这里需要使用ADC触发为硬件出触发
	DMA_InitStructure.DMA_MemoryBaseAddr=(uint32_t)des;//目的地数组
	DMA_InitStructure.DMA_MemoryDataSize=DMA_MemoryDataSize_HalfWord;//目的地一个数据的大小 16位
	DMA_InitStructure.DMA_MemoryInc=DMA_MemoryInc_Enable;//目的地地址寄存器是否递增 是
	DMA_InitStructure.DMA_Mode=DMA_Mode_Circular;//连续转换
							 //DMA_Mode_Normal;//DMA转换模式 单次转换
	DMA_InitStructure.DMA_PeripheralBaseAddr=(uint32_t)&ADC1->DR;//外设寄存器地址
	DMA_InitStructure.DMA_PeripheralDataSize=DMA_PeripheralDataSize_HalfWord;//源头以个数据大小  16位
	DMA_InitStructure.DMA_PeripheralInc=DMA_PeripheralInc_Disable;//外设地址寄存器是否递增 否
	DMA_InitStructure.DMA_Priority=DMA_Priority_Medium;//优先级
	DMA_Init(DMA1_Channel1,&DMA_InitStructure);

	//打开dma1
	DMA_Cmd(DMA1_Channel1,ENABLE);
		//打开ADC-DMA通道
	ADC_DMACmd(ADC1,ENABLE);
	//打开ADC
	ADC_Cmd(ADC1,ENABLE);
	//	启动ADC校准
	ADC_ResetCalibration(ADC1);
	while(ADC_GetResetCalibrationStatus(ADC1));
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1));


}

void ADCMORE_return1(){
//	DMA_Cmd(DMA1_Channel1,DISABLE);
//	//设置传输计数器
//	DMA_SetCurrDataCounter(DMA1_Channel1,4);
//	DMA_Cmd(DMA1_Channel1,ENABLE);
	
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
	//等待转换完成
	while(DMA_GetFlagStatus(DMA1_FLAG_TC1)==RESET);
	DMA_ClearFlag(DMA1_FLAG_TC1);
}
