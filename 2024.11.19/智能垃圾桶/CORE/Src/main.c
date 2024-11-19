#include "main.h"
#include "gpio.h"
#include "OLED.h"
#include "DELAY.h"
#include "SG90.h"
#include "SmartRubbish.h"
#include "USART.h"
#include "ADC.h"
/*
�������ʽ��������AO���Ž�A4
������TXD��A10 RXD��A9
������źŴ������Ž�A1
OLED��SCL��B10 SDA��B11
*/
void SystemClock_Config(void);
uint32_t state;//���״̬
uint8_t B_state;//����״̬
uint8_t arr_rx1;
void B_Ctrl(void){
	
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	DELAY_Init(72);
	USART1_Init();
	SmartRubbish_Init();
	ADC_ccscmode();
	OLED_Init();
	OLED_Clear();
	HAL_UART_Transmit(&UART_HandInit,(uint8_t*)"It's ready",10,1000);
	while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	while (1){
		OLED_ShowNum(0,0,data[0],4,16);
		OLED_UpData();
		if(data[0]<=1500){//������
			arr_rx[1]=4;
		}
		if(data[0]>=2500){//û����������������뿪�ر�
			arr_rx[1]=0;
		}
		if(state_rx==1){
//		switch(arr_rx[0]){
//		case 0: 
//			HAL_UART_Transmit(&UART_HandInit,(uint8_t*)"It's closed",11,1000);
//			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
//			state_rx=0;
//			break;
//		case 1: 
//			HAL_UART_Transmit(&UART_HandInit,(uint8_t*)"Turned on plus 45 degrees",25,1000);
//			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
//			state_rx=0;
//			break;
//		case 2: 
//			HAL_UART_Transmit(&UART_HandInit,(uint8_t*)"Halfway open",12,1000);
//			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
//			state_rx=0;
//			break;
//		case 3: 
//			HAL_UART_Transmit(&UART_HandInit,(uint8_t*)"Turned on plus 135 degrees",26,1000);
//			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
//			state_rx=0;
//			break;
//		case 4: 
//			HAL_UART_Transmit(&UART_HandInit,(uint8_t*)"All opened",10,1000);
//			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
//			state_rx=0;
//			break;
//		}
	}

	switch(arr_rx[0]){
		case 0: state=500;break;
		case 1: state=1000;break;
		case 2: state=1500;break;
		case 3: state=2000;break;
		case 4: state=2500;break;
	}
	if(arr_rx[0]==0){
	switch(arr_rx[1]){
		case 0: state=500;break;
		case 4: state=2500;break;
	}
}
	if(arr_rx[0]!=0){
	__HAL_TIM_SET_COMPARE(&TIM_SG90HandInit,TIM_CHANNEL_2,state);
	}
	else if(arr_rx[1]!=0){
	__HAL_TIM_SET_COMPARE(&TIM_SG90HandInit,TIM_CHANNEL_2,state);
	}
	else{
	__HAL_TIM_SET_COMPARE(&TIM_SG90HandInit,TIM_CHANNEL_2,state);
	}
	
	}
}

//void EXTI3_IRQHandler(void){
//	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
//	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_3);
//}

//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
//	HAL_Delay(10);
//	if(GPIO_Pin==GPIO_PIN_3){
//		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3)==0){
//			key++;
//		}
//	}
//}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
