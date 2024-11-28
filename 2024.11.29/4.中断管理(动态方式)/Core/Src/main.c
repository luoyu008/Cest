#include "main.h"
#include "cmsis_os.h"
#include "gpio.h"
#include "DELAY.h"
#include "USART.h"
#include "OLED.h"
#include "KEY.h"
#include "EXIT.h"
#include "Time.h"
void SystemClock_Config(void);
void FreeRtos_Init(void);

uint8_t key;

int main(void)
{

	HAL_Init();
	SystemClock_Config();
	DELAY_Init(72);
	MX_GPIO_Init();
	OLED_Init();
	OLED_Clear();
	EXIT_Init();
	USART1_Init();
	Time2_Init();
	Time3_Init();
	OLED_ShowNum(0,0,7414,8,16);
	OLED_UpData();
    FreeRtos_Init();
	
//	while (1)
//	{
//    
////	HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_4);
////	HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_3);
////	if(KEY1_Flage==1){
////		HAL_UART_Transmit(&UART_HandInit,"ad",2,1000);
////		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
////		KEY1_Flage=0;
////	}
////	if(KEY2_Flage==1){
////		HAL_UART_Transmit(&UART_HandInit,"as",2,1000);
////		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
////		KEY2_Flage=0;
////	}
////	if(KEY3_Flage==1){
////		HAL_UART_Transmit(&UART_HandInit,"rf",2,1000);
////		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
////		KEY3_Flage=0;
////	}
//	OLED_ShowNum(0,0,count2,8,16);
//	OLED_ShowNum(0,20,count3,8,16);
//	OLED_UpData();
//	}

}

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
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM4 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM4) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */
	if(htim->Instance==TIM2){
		HAL_UART_Transmit(&UART_HandInit,"time2\r\n",7,1000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	}
	if(htim->Instance==TIM3){
		HAL_UART_Transmit(&UART_HandInit,"time3\r\n",7,1000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	}
  /* USER CODE END Callback 1 */
}

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
