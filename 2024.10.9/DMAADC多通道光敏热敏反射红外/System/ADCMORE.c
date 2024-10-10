#include "stm32f10x.h"                  // Device header
uint16_t des[8];
void ADCMORE_Init(void){
	//��ʱ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);
	//��dmaʱ��
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	//ѡ��ʱ��
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	//���ù�����ͨ��
	ADC_RegularChannelConfig(ADC1,ADC_Channel_0,1,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_1,2,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_2,3,ADC_SampleTime_55Cycles5);
	ADC_RegularChannelConfig(ADC1,ADC_Channel_3,4,ADC_SampleTime_55Cycles5);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AIN;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//��ʼ��adc
	ADC_InitTypeDef ADC_InitStructure;
	ADC_InitStructure.ADC_ContinuousConvMode=ENABLE;
											 //DISABLE;//����ģʽ
	ADC_InitStructure.ADC_DataAlign=ADC_DataAlign_Right;//�����Ҷ���
	ADC_InitStructure.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;//���ⲿ����Դ
	ADC_InitStructure.ADC_Mode=ADC_Mode_Independent;//��������ģʽ
	ADC_InitStructure.ADC_NbrOfChannel=4;//��Ҫת���Ĺ���ͨ������
	ADC_InitStructure.ADC_ScanConvMode=ENABLE;//ɨ��ģʽת��
	ADC_Init(ADC1,&ADC_InitStructure);
	//����DMAͨ��
	DMA_InitTypeDef DMA_InitStructure;
	DMA_InitStructure.DMA_BufferSize=4;//����4������
	DMA_InitStructure.DMA_DIR=DMA_DIR_PeripheralSRC;//����Ĵ���Ϊ����Դͷ
	DMA_InitStructure.DMA_M2M=DMA_M2M_Disable;//�ر��������ģʽ ��Ϊ������Ҫʹ��ADC����ΪӲ��������
	DMA_InitStructure.DMA_MemoryBaseAddr=(uint32_t)des;//Ŀ�ĵ�����
	DMA_InitStructure.DMA_MemoryDataSize=DMA_MemoryDataSize_HalfWord;//Ŀ�ĵ�һ�����ݵĴ�С 16λ
	DMA_InitStructure.DMA_MemoryInc=DMA_MemoryInc_Enable;//Ŀ�ĵص�ַ�Ĵ����Ƿ���� ��
	DMA_InitStructure.DMA_Mode=DMA_Mode_Circular;//����ת��
							 //DMA_Mode_Normal;//DMAת��ģʽ ����ת��
	DMA_InitStructure.DMA_PeripheralBaseAddr=(uint32_t)&ADC1->DR;//����Ĵ�����ַ
	DMA_InitStructure.DMA_PeripheralDataSize=DMA_PeripheralDataSize_HalfWord;//Դͷ�Ը����ݴ�С  16λ
	DMA_InitStructure.DMA_PeripheralInc=DMA_PeripheralInc_Disable;//�����ַ�Ĵ����Ƿ���� ��
	DMA_InitStructure.DMA_Priority=DMA_Priority_Medium;//���ȼ�
	DMA_Init(DMA1_Channel1,&DMA_InitStructure);

	//��dma1
	DMA_Cmd(DMA1_Channel1,ENABLE);
		//��ADC-DMAͨ��
	ADC_DMACmd(ADC1,ENABLE);
	//��ADC
	ADC_Cmd(ADC1,ENABLE);
	//	����ADCУ׼
	ADC_ResetCalibration(ADC1);
	while(ADC_GetResetCalibrationStatus(ADC1));
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1));


}

void ADCMORE_return1(){
//	DMA_Cmd(DMA1_Channel1,DISABLE);
//	//���ô��������
//	DMA_SetCurrDataCounter(DMA1_Channel1,4);
//	DMA_Cmd(DMA1_Channel1,ENABLE);
	
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);
	//�ȴ�ת�����
	while(DMA_GetFlagStatus(DMA1_FLAG_TC1)==RESET);
	DMA_ClearFlag(DMA1_FLAG_TC1);
}
