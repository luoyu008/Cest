#include "main.h"
#include "gpio.h"
#include "OLED.h"
#include "DELAY.h"
#include "SPIyingjian.h"
#include "W25Q64SPIyingjian.h"
void SystemClock_Config(void);
uint8_t MID;
uint16_t ID;
uint8_t TxData[]={0,5,2,249};
uint8_t RxData[]={0,0,0,0};
int main(void)
{
	HAL_Init();
	SystemClock_Config();
	DELAY_Init(72);
	OLED_Init();
	OLED_Clear();
	W25Q64SPIyingjian_Init();
	W25Q64SPIyingjian_ReadID(&MID,&ID);
	OLED_ShowHexNum(0,0,MID,2,16);
	OLED_ShowHexNum(50,0,ID,4,16);
	OLED_UpData();
	W25Q64SPIyingjian_WriteByte(0x000000,TxData,4);
	W25Q64SPIyingjian_ReadByte(0X000000,RxData,4);
	while (1){
		OLED_ShowNum(0,20,TxData[0],3,6);
		OLED_ShowNum(0,30,TxData[1],3,6);
		OLED_ShowNum(0,40,TxData[2],3,6);
		OLED_ShowNum(0,50,TxData[3],3,6);
		OLED_UpData();
		OLED_ShowNum(30,20,RxData[0],3,6);
		OLED_ShowNum(30,30,RxData[1],3,6);
		OLED_ShowNum(30,40,RxData[2],3,6);
		OLED_ShowNum(30,50,RxData[3],3,6);
		OLED_UpData();
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
