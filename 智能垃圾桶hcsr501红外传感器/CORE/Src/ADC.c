#include "main.h"
#include "OLED.h"

//多通道	连续转换扫描模式
ADC_HandleTypeDef ADC_ccscmodeHandInit;
DMA_HandleTypeDef DMA_ccscmodeHandInit;
ADC_ChannelConfTypeDef ADC_ccscmodeChannelInit;
uint16_t data[4];
uint8_t tc_state;
void ADC_ccscmode(void){
	__HAL_RCC_DMA1_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_ADC1_CLK_ENABLE();
	DMA_ccscmodeHandInit.Instance=DMA1_Channel1;
	DMA_ccscmodeHandInit.Init.Direction=DMA_PERIPH_TO_MEMORY;//外设到内存模式
	DMA_ccscmodeHandInit.Init.MemDataAlignment=DMA_MDATAALIGN_HALFWORD;//16bit 半字
	DMA_ccscmodeHandInit.Init.MemInc=DMA_MINC_DISABLE;//内存地址不自增
	DMA_ccscmodeHandInit.Init.Mode=DMA_CIRCULAR;//不循环模式
	DMA_ccscmodeHandInit.Init.PeriphDataAlignment=DMA_PDATAALIGN_HALFWORD;//16bit 半字
	DMA_ccscmodeHandInit.Init.PeriphInc=DMA_PINC_DISABLE;//外设地址不自增
	DMA_ccscmodeHandInit.Init.Priority=DMA_PRIORITY_MEDIUM;//中等优先级
	HAL_DMA_Init(&DMA_ccscmodeHandInit);
	
	__HAL_LINKDMA(&ADC_ccscmodeHandInit,DMA_Handle,DMA_ccscmodeHandInit);
	
	ADC_ccscmodeHandInit.Instance=ADC1;
	ADC_ccscmodeHandInit.Init.ContinuousConvMode=ENABLE;//连续模式
	ADC_ccscmodeHandInit.Init.DataAlign=ADC_DATAALIGN_RIGHT;//数据右对齐
	ADC_ccscmodeHandInit.Init.DiscontinuousConvMode=DISABLE;//关闭规则组间断模式
	ADC_ccscmodeHandInit.Init.ExternalTrigConv=ADC_SOFTWARE_START;//软件触发
	ADC_ccscmodeHandInit.Init.NbrOfConversion=1;//3个通道
	ADC_ccscmodeHandInit.Init.NbrOfDiscConversion=0;//间断模式通道个数为2
	ADC_ccscmodeHandInit.Init.ScanConvMode=ADC_SCAN_ENABLE;//扫描模式
	ADC_ccscmodeHandInit.DMA_Handle=&DMA_ccscmodeHandInit;
	HAL_ADC_Init(&ADC_ccscmodeHandInit);

	
	
	
	ADC_ccscmodeChannelInit.Channel=ADC_CHANNEL_4;//采样通道
	ADC_ccscmodeChannelInit.Rank=ADC_REGULAR_RANK_1;//第一个进行
	ADC_ccscmodeChannelInit.SamplingTime=ADC_SAMPLETIME_239CYCLES_5;//采样周期
	HAL_ADC_ConfigChannel(&ADC_ccscmodeHandInit,&ADC_ccscmodeChannelInit);
	
//	ADC_ccscmodeChannelInit.Channel=ADC_CHANNEL_1;//采样通道
//	ADC_ccscmodeChannelInit.Rank=ADC_REGULAR_RANK_2;//第二个进行
//	ADC_ccscmodeChannelInit.SamplingTime=ADC_SAMPLETIME_239CYCLES_5;//采样周期
//	HAL_ADC_ConfigChannel(&ADC_ccscmodeHandInit,&ADC_ccscmodeChannelInit);
//	
//	ADC_ccscmodeChannelInit.Channel=ADC_CHANNEL_2;//采样通道
//	ADC_ccscmodeChannelInit.Rank=ADC_REGULAR_RANK_3;//第三个进行
//	ADC_ccscmodeChannelInit.SamplingTime=ADC_SAMPLETIME_239CYCLES_5;//采样周期
//	HAL_ADC_ConfigChannel(&ADC_ccscmodeHandInit,&ADC_ccscmodeChannelInit);
//	
//	ADC_ccscmodeChannelInit.Channel=ADC_CHANNEL_0;//采样通道
//	ADC_ccscmodeChannelInit.Rank=ADC_REGULAR_RANK_4;//第一个进行
//	ADC_ccscmodeChannelInit.SamplingTime=ADC_SAMPLETIME_239CYCLES_5;//采样周期
//	HAL_ADC_ConfigChannel(&ADC_ccscmodeHandInit,&ADC_ccscmodeChannelInit);
	//开启ADC校准
	HAL_ADCEx_Calibration_Start(&ADC_ccscmodeHandInit);
	HAL_ADC_Start_DMA(&ADC_ccscmodeHandInit,(uint32_t*)data,1);
}

RCC_PeriphCLKInitTypeDef RCC_ccscmodeInit;
void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc){
	if(hadc->Instance==ADC1){
		
		GPIO_InitTypeDef GPIO_Init;
		GPIO_Init.Mode=GPIO_MODE_ANALOG;//模拟输入
		GPIO_Init.Pin=GPIO_PIN_4;
//		|GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2;
		GPIO_Init.Pull=GPIO_NOPULL;
		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOA,&GPIO_Init);
		
		RCC_ccscmodeInit.PeriphClockSelection=RCC_PERIPHCLK_ADC;
		RCC_ccscmodeInit.AdcClockSelection=RCC_ADCPCLK2_DIV6;
		HAL_RCCEx_PeriphCLKConfig(&RCC_ccscmodeInit);
	}
}

/*
//单通道连续转换非扫描模式实验
ADC_HandleTypeDef ADC_onetimenoscmodeHandInit;
DMA_HandleTypeDef DMA_onetimescmodeHandInit;
ADC_ChannelConfTypeDef ADC_onetimenoscmodeChannelInit;
uint32_t Data;
uint8_t tc_state;
void ADC_onetime_noscmode(void){
	__HAL_RCC_DMA1_CLK_ENABLE();
	
	DMA_onetimescmodeHandInit.Instance=DMA1_Channel1;
	DMA_onetimescmodeHandInit.Init.Direction=DMA_PERIPH_TO_MEMORY;//ADC外设到内存模式
	DMA_onetimescmodeHandInit.Init.MemDataAlignment=DMA_MDATAALIGN_HALFWORD;//16bit 半字模式
	DMA_onetimescmodeHandInit.Init.MemInc=DMA_MINC_DISABLE;//内存地址不自增
	DMA_onetimescmodeHandInit.Init.Mode=DMA_NORMAL;//不循环模式
	DMA_onetimescmodeHandInit.Init.PeriphDataAlignment=DMA_PDATAALIGN_HALFWORD;//16bit 半字模式
	DMA_onetimescmodeHandInit.Init.PeriphInc=DMA_PINC_DISABLE;//外设地址不自增
	DMA_onetimescmodeHandInit.Init.Priority=DMA_PRIORITY_MEDIUM;//中等优先级
	HAL_DMA_Init(&DMA_onetimescmodeHandInit);
	
	__HAL_LINKDMA(&ADC_onetimenoscmodeHandInit,DMA_Handle,DMA_onetimescmodeHandInit);
	
	ADC_onetimenoscmodeHandInit.Instance=ADC1;
	ADC_onetimenoscmodeHandInit.Init.ContinuousConvMode=ENABLE;//连续转换模式
	ADC_onetimenoscmodeHandInit.Init.DataAlign=ADC_DATAALIGN_RIGHT;//右对齐模式
	ADC_onetimenoscmodeHandInit.Init.DiscontinuousConvMode=DISABLE;//不使用规则组的间断模式
	ADC_onetimenoscmodeHandInit.Init.ExternalTrigConv=ADC_SOFTWARE_START;//软件触发
	ADC_onetimenoscmodeHandInit.Init.NbrOfConversion=1;//转换通道个数为1
	ADC_onetimenoscmodeHandInit.Init.NbrOfDiscConversion=0;//间断模式通道为0
	ADC_onetimenoscmodeHandInit.Init.ScanConvMode=ADC_SCAN_DISABLE;//非扫描模式
	ADC_onetimenoscmodeHandInit.DMA_Handle=&DMA_onetimescmodeHandInit;
	HAL_ADC_Init(&ADC_onetimenoscmodeHandInit);
	
	//开启ADC校准
	HAL_ADCEx_Calibration_Start(&ADC_onetimenoscmodeHandInit);
	
	ADC_onetimenoscmodeChannelInit.Channel=ADC_CHANNEL_0;//采样通道
	ADC_onetimenoscmodeChannelInit.Rank=ADC_REGULAR_RANK_1;//第一个进行
	ADC_onetimenoscmodeChannelInit.SamplingTime=ADC_SAMPLETIME_239CYCLES_5;//采样周期
	HAL_ADC_ConfigChannel(&ADC_onetimenoscmodeHandInit,&ADC_onetimenoscmodeChannelInit);
//	HAL_ADC_Start_DMA(&ADC_onetimenoscmodeHandInit,&Data,1);
//	HAL_ADC_Start(&ADC_onetimenoscmodeHandInit);
	
	HAL_NVIC_SetPriority(DMA1_Channel1_IRQn,1,1);
	HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);
	
	HAL_DMA_Start_IT(&DMA_onetimescmodeHandInit,(uint32_t)&ADC1->DR,(uint32_t)&Data,0);
	HAL_ADC_Start_DMA(&ADC_onetimenoscmodeHandInit,&Data,0);
	
}

void ADC_ENABLEDMA(void){
	__HAL_ADC_DISABLE(&ADC_onetimenoscmodeHandInit);
	
	__HAL_DMA_DISABLE(&DMA_onetimescmodeHandInit);
	DMA1_Channel1->CNDTR=1;
	__HAL_DMA_ENABLE(&DMA_onetimescmodeHandInit);
	
	__HAL_ADC_ENABLE(&ADC_onetimenoscmodeHandInit);
	HAL_ADC_Start(&ADC_onetimenoscmodeHandInit);
//	ADC1->CR2 &= ~(1<<0);
//	
//	DMA1_Channel1->CCR &= ~(1<<0);
//	while(DMA1_Channel1->CCR &(1<<0));
//	DMA1_Channel1->CNDTR=1;
//	DMA1_Channel1->CCR |=(1<<0);
//	
//	ADC1->CR2 |=(1<<0);
//	ADC1->CR2 |=(1<<22);
}

void DMA1_Channel1_IRQHandler(void){
	if(__HAL_DMA_GET_FLAG(&DMA_onetimescmodeHandInit,DMA_FLAG_TC1)){
		tc_state=1;
		__HAL_DMA_CLEAR_FLAG(&DMA_onetimescmodeHandInit,DMA_FLAG_TC1);
	}
//	if(DMA1->ISR&(1<<1)){
//		tc_state=1;
//		DMA1->IFCR |=1<<1;
//	}
}

RCC_PeriphCLKInitTypeDef RCC_onetimenoscmodeInit;
void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc){
	if(hadc->Instance==ADC1){
		__HAL_RCC_ADC1_CLK_ENABLE();
		
		__HAL_RCC_GPIOA_CLK_ENABLE();

		GPIO_InitTypeDef GPIO_Init;
		GPIO_Init.Mode=GPIO_MODE_ANALOG;//模拟输入
		GPIO_Init.Pin=GPIO_PIN_0;
		GPIO_Init.Pull=GPIO_NOPULL;
		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOA,&GPIO_Init);
		
		RCC_onetimenoscmodeInit.PeriphClockSelection=RCC_PERIPHCLK_ADC;
		RCC_onetimenoscmodeInit.AdcClockSelection=RCC_ADCPCLK2_DIV6;
		HAL_RCCEx_PeriphCLKConfig(&RCC_onetimenoscmodeInit);
	}
}
*/
