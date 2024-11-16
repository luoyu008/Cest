#include "main.h"
DMA_HandleTypeDef DMA_MYDMAHandInit;
extern UART_HandleTypeDef UART_HandInit;
uint8_t arr_des[];
uint8_t arr_src[]={11,12,13,14};
void MYDMA_Init(void){
	
	//开启dma时钟
	__HAL_RCC_DMA1_CLK_ENABLE();
	
	__HAL_LINKDMA(&UART_HandInit,hdmatx,DMA_MYDMAHandInit);
	
	DMA_MYDMAHandInit.Instance=DMA1_Channel4;
	DMA_MYDMAHandInit.Init.Direction=DMA_MEMORY_TO_PERIPH;//方向为内存到外设
	DMA_MYDMAHandInit.Init.MemDataAlignment=DMA_MDATAALIGN_BYTE;//需要传输的内存的数据宽度 1字节 8bit
	DMA_MYDMAHandInit.Init.MemInc=DMA_MINC_ENABLE;//内存地址自增
	DMA_MYDMAHandInit.Init.Mode=DMA_NORMAL;//非循环模式
	DMA_MYDMAHandInit.Init.PeriphDataAlignment=DMA_PDATAALIGN_BYTE;//需要传输的外设的数据宽度 1字节 8bit
	DMA_MYDMAHandInit.Init.PeriphInc=DMA_PINC_DISABLE;//外设地址自增
	DMA_MYDMAHandInit.Init.Priority=DMA_PRIORITY_MEDIUM;//通道的软件优先级为中等
	HAL_DMA_Init(&DMA_MYDMAHandInit);
	
	HAL_NVIC_SetPriority(DMA1_Channel4_IRQn,1,2);
	HAL_NVIC_EnableIRQ(DMA1_Channel4_IRQn);
	
		/*//该功能实现数组到数组的dma传输即内存到内存的方式//开启dma时钟
	__HAL_RCC_DMA1_CLK_ENABLE();
	
	DMA_MYDMAHandInit.Instance=DMA1_Channel1;
	DMA_MYDMAHandInit.Init.Direction=DMA_MEMORY_TO_MEMORY;//方向为内存到内存
	DMA_MYDMAHandInit.Init.MemDataAlignment=DMA_MDATAALIGN_BYTE;//需要传输的内存的数据宽度 1字节 8bit
	DMA_MYDMAHandInit.Init.MemInc=DMA_PINC_ENABLE;//内存地址自增
	DMA_MYDMAHandInit.Init.Mode=DMA_NORMAL;//非循环模式
	DMA_MYDMAHandInit.Init.PeriphDataAlignment=DMA_PDATAALIGN_BYTE;//需要传输的外设的数据宽度 1字节 8bit
	DMA_MYDMAHandInit.Init.PeriphInc=DMA_PINC_ENABLE;//外设地址自增
	DMA_MYDMAHandInit.Init.Priority=DMA_PRIORITY_MEDIUM;//通道的软件优先级为中等
	HAL_DMA_Init(&DMA_MYDMAHandInit);
	
	HAL_DMA_Start(&DMA_MYDMAHandInit,(uint32_t)arr_src,(uint32_t)arr_des,0);
	*/
}

void DMA1_Channel4_IRQHandler(void){
	HAL_DMA_IRQHandler(&DMA_MYDMAHandInit);
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
	if(huart->Instance==USART1){
		__HAL_DMA_CLEAR_FLAG(&DMA_MYDMAHandInit,DMA_FLAG_TC4);
	}
}

void DMA_ENABLE(uint32_t length){
	__HAL_DMA_DISABLE(&DMA_MYDMAHandInit);
	DMA_MYDMAHandInit.Instance->CNDTR=length;
	__HAL_DMA_ENABLE(&DMA_MYDMAHandInit);
	
}
