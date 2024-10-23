#include "stm32f10x.h"                  // Device header
void ADC2_Init(void){
	//��ʱ��
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
	//�ⲿ����adcת��ʹ��
	ADC_ExternalTrigConvCmd(ADC1,ENABLE);///
	
	ADC_InitTypeDef ADC_InitStruct;
	ADC_InitStruct.ADC_ContinuousConvMode=DISABLE;//����ģʽ����
	ADC_InitStruct.ADC_DataAlign=ADC_DataAlign_Right;//�����Ҷ���
	ADC_InitStruct.ADC_ExternalTrigConv=ADC_ExternalTrigConv_T2_CC2;//T2����
										//ADC_ExternalTrigConv_None;//�������
	ADC_InitStruct.ADC_Mode=ADC_Mode_Independent;//��������ģʽ
	ADC_InitStruct.ADC_NbrOfChannel=3;//4��ͨ��
	ADC_InitStruct.ADC_ScanConvMode=ENABLE;//ɨ��ģʽ
	ADC_Init(ADC1,&ADC_InitStruct);
	
	ADC_DMACmd(ADC1,ENABLE);
	ADC_Cmd(ADC1,ENABLE);
	
	//	����ADCУ׼
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
