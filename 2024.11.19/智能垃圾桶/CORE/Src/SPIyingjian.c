#include "main.h"
#include "OLED.h"
SPI_HandleTypeDef SPI_yingjianHandInit;
uint8_t wer;
void SPIyingjian_Init(void){
	SPI_yingjianHandInit.Instance=SPI1;
	SPI_yingjianHandInit.Init.BaudRatePrescaler=SPI_BAUDRATEPRESCALER_4;//ʱ�ӷ�Ƶ
	SPI_yingjianHandInit.Init.CLKPhase=SPI_PHASE_1EDGE;//SPIģʽ0
	SPI_yingjianHandInit.Init.CLKPolarity=SPI_POLARITY_LOW;
	SPI_yingjianHandInit.Init.CRCCalculation=SPI_CRCCALCULATION_DISABLE;
	SPI_yingjianHandInit.Init.CRCPolynomial=7;
	SPI_yingjianHandInit.Init.DataSize=SPI_DATASIZE_8BIT;//8λ����ģʽ
	SPI_yingjianHandInit.Init.Direction=SPI_DIRECTION_2LINES;//˫˫��˫��ģʽ��ȫ˫��
	SPI_yingjianHandInit.Init.FirstBit=SPI_FIRSTBIT_MSB;//��λ����
	SPI_yingjianHandInit.Init.Mode=SPI_MODE_MASTER;//����ģʽ
	SPI_yingjianHandInit.Init.NSS=SPI_NSS_SOFT;//�������Ƭѡ����
	SPI_yingjianHandInit.Init.TIMode=SPI_TIMODE_DISABLE;//�ر�TIģʽ
	wer=HAL_SPI_Init(&SPI_yingjianHandInit);
//	OLED_ShowNum(0,0,wer,2,16);
//	OLED_UpData();
	__HAL_SPI_ENABLE(&SPI_yingjianHandInit);
	
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);//ƬѡĬ�ϸߵ�ƽ
}

void HAL_SPI_MspInit(SPI_HandleTypeDef *hspi){
	if(hspi->Instance==SPI1){
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_SPI1_CLK_ENABLE();
		GPIO_InitTypeDef GPIO_Init;
		GPIO_Init.Mode=GPIO_MODE_AF_PP;
		GPIO_Init.Pin=GPIO_PIN_5|GPIO_PIN_7;
		GPIO_Init.Pull=GPIO_NOPULL;
		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOA,&GPIO_Init);
		
		GPIO_Init.Mode=GPIO_MODE_OUTPUT_PP;
		GPIO_Init.Pin=GPIO_PIN_4;
		GPIO_Init.Pull=GPIO_NOPULL;
		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOA,&GPIO_Init);
		
		GPIO_Init.Mode=GPIO_MODE_INPUT;
		GPIO_Init.Pin=GPIO_PIN_6;
		GPIO_Init.Pull=GPIO_NOPULL;
		GPIO_Init.Speed=GPIO_SPEED_FREQ_HIGH;
		HAL_GPIO_Init(GPIOA,&GPIO_Init);
	}
}

void SPIyingjian_Start(void){
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
}

void SPIyingjian_Stop(void){
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_SET);
}
