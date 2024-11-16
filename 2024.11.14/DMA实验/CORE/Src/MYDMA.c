#include "main.h"
DMA_HandleTypeDef DMA_MYDMAHandInit;
extern UART_HandleTypeDef UART_HandInit;
uint8_t arr_des[];
uint8_t arr_src[]={11,12,13,14};
void MYDMA_Init(void){
	
	//����dmaʱ��
	__HAL_RCC_DMA1_CLK_ENABLE();
	
	__HAL_LINKDMA(&UART_HandInit,hdmatx,DMA_MYDMAHandInit);
	
	DMA_MYDMAHandInit.Instance=DMA1_Channel4;
	DMA_MYDMAHandInit.Init.Direction=DMA_MEMORY_TO_PERIPH;//����Ϊ�ڴ浽����
	DMA_MYDMAHandInit.Init.MemDataAlignment=DMA_MDATAALIGN_BYTE;//��Ҫ������ڴ�����ݿ�� 1�ֽ� 8bit
	DMA_MYDMAHandInit.Init.MemInc=DMA_MINC_ENABLE;//�ڴ��ַ����
	DMA_MYDMAHandInit.Init.Mode=DMA_NORMAL;//��ѭ��ģʽ
	DMA_MYDMAHandInit.Init.PeriphDataAlignment=DMA_PDATAALIGN_BYTE;//��Ҫ�������������ݿ�� 1�ֽ� 8bit
	DMA_MYDMAHandInit.Init.PeriphInc=DMA_PINC_DISABLE;//�����ַ����
	DMA_MYDMAHandInit.Init.Priority=DMA_PRIORITY_MEDIUM;//ͨ����������ȼ�Ϊ�е�
	HAL_DMA_Init(&DMA_MYDMAHandInit);
	
	HAL_NVIC_SetPriority(DMA1_Channel4_IRQn,1,2);
	HAL_NVIC_EnableIRQ(DMA1_Channel4_IRQn);
	
		/*//�ù���ʵ�����鵽�����dma���伴�ڴ浽�ڴ�ķ�ʽ//����dmaʱ��
	__HAL_RCC_DMA1_CLK_ENABLE();
	
	DMA_MYDMAHandInit.Instance=DMA1_Channel1;
	DMA_MYDMAHandInit.Init.Direction=DMA_MEMORY_TO_MEMORY;//����Ϊ�ڴ浽�ڴ�
	DMA_MYDMAHandInit.Init.MemDataAlignment=DMA_MDATAALIGN_BYTE;//��Ҫ������ڴ�����ݿ�� 1�ֽ� 8bit
	DMA_MYDMAHandInit.Init.MemInc=DMA_PINC_ENABLE;//�ڴ��ַ����
	DMA_MYDMAHandInit.Init.Mode=DMA_NORMAL;//��ѭ��ģʽ
	DMA_MYDMAHandInit.Init.PeriphDataAlignment=DMA_PDATAALIGN_BYTE;//��Ҫ�������������ݿ�� 1�ֽ� 8bit
	DMA_MYDMAHandInit.Init.PeriphInc=DMA_PINC_ENABLE;//�����ַ����
	DMA_MYDMAHandInit.Init.Priority=DMA_PRIORITY_MEDIUM;//ͨ����������ȼ�Ϊ�е�
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
