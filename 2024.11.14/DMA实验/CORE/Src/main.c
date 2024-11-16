#include "main.h"
#include "gpio.h"
#include "KEY.h"
#include "MYLED.h"
#include "USART.h"
#include "MYDMA.h"
void SystemClock_Config(void);
uint8_t arr_tx[];
uint8_t key=0;
int main(void)
{
	HAL_Init();
	SystemClock_Config();
	MYLED_Init();
	MYKEY_Init();
	
	USART1_Init();
	
	MYDMA_Init();
//	DMA_ENABLE(4);
	  while (1)
	  {
		/*该功能实现串口dma传输 可以使用while轮询清除传输标志位也可使用中断清楚标志位
		key+=KEY_return();
		key%=2;
		if(key==1){
		  HAL_UART_Transmit_DMA(&UART_HandInit,arr_src,4);
//			while(1){
//				if(__HAL_DMA_GET_FLAG(&DMA_MYDMAHandInit,DMA_FLAG_TC4)){
//				__HAL_DMA_CLEAR_FLAG(&DMA_MYDMAHandInit,DMA_FLAG_TC4);
//					HAL_UART_DMAStop(&UART_HandInit);
//					break;
//				}
//			}
		  key=0;
		}
		 */
		  
		/*//该功能实现按键发送目的内存的数组
		key+=KEY_return();
		key%=2;
		if(key==1){
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_SET);
			HAL_UART_Transmit(&UART_HandInit,(uint8_t *)(arr_des+1),4,60);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			key=0;
		}
		if(key==0){
			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);
//			arr_des[0]++;
//			arr_des[1]++;
//			arr_des[2]++;
//			arr_des[3]++;
		}
		  */
	  }
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
