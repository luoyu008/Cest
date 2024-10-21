#include "stm32f10x.h"                  // Device header
void ADC2_Init(void){
	//打开时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AIN;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_4|GPIO_Pin_2|GPIO_Pin_3;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	ADC_RegularChannelConfig(ADC1,ADC_Channel_4,1,ADC_SampleTime_239Cycles5);

	ADC_RegularChannelConfig(ADC1,ADC_Channel_2,2,ADC_SampleTime_239Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_3,3,ADC_SampleTime_239Cycles5);
	//外部触发adc转换使能
	ADC_ExternalTrigConvCmd(ADC1,ENABLE);///
	
	ADC_InitTypeDef ADC_InitStruct;
	ADC_InitStruct.ADC_ContinuousConvMode=DISABLE;//连续模式运行
	ADC_InitStruct.ADC_DataAlign=ADC_DataAlign_Right;//数据右对齐
	ADC_InitStruct.ADC_ExternalTrigConv=ADC_ExternalTrigConv_T2_CC2;//T2触发
										//ADC_ExternalTrigConv_None;//软件触发
	ADC_InitStruct.ADC_Mode=ADC_Mode_Independent;//独立工作模式
	ADC_InitStruct.ADC_NbrOfChannel=3;//4个通道
	ADC_InitStruct.ADC_ScanConvMode=ENABLE;//扫描模式
	ADC_Init(ADC1,&ADC_InitStruct);
	
	ADC_DMACmd(ADC1,ENABLE);
	ADC_Cmd(ADC1,ENABLE);
	
	//	启动ADC校准
	ADC_ResetCalibration(ADC1);
	while(ADC_GetResetCalibrationStatus(ADC1));
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1));
	
}

uint16_t ADC2_return(uint8_t ADC_Channel){
	ADC_RegularChannelConfig(ADC1,ADC_Channel,1,ADC_SampleTime_239Cycles5);
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
	while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));
	return ADC_GetConversionValue(ADC1);
}
