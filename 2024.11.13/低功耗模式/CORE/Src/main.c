#include "main.h"
#include "gpio.h"
#include "EXIT.h"
#include "MYLED.h"
#include "USART.h"
#include "WEAKUPEXTI.h"
#include "OLED.h"
void SystemClock_Config(void);
uint8_t key;
uint8_t arr_re[]={0x95,0x75};
int main(void)
{
	HAL_Init();
	SystemClock_Config();
	MYLED_Init();
	EXIT_Init();
	USART1_Init();
	HAL_PWR_EnableWakeUpPin(PWR_WAKEUP_PIN1);
	__HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);//设置唤醒引脚后会自动置标志位 需要手动清除
  while (1)
  {
		/*//待机模式 唤醒后程序会从头开始执行	
		HAL_UART_Transmit(&UART_HandInit,"out of standby mood\r\n",21,60);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	  
		HAL_UART_Transmit(&UART_HandInit,"enter standby mood\r\n",20,60);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		__HAL_RCC_PWR_CLK_ENABLE();
		HAL_PWR_EnterSTANDBYMode();//下面的程序执行不到
		*/
	  
	  /*停止模式
		HAL_UART_Transmit(&UART_HandInit,"enter stop mood\r\n",17,50);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	  
		HAL_PWR_EnterSTOPMode(PWR_MAINREGULATOR_ON,PWR_SLEEPENTRY_WFI);
		SystemClock_Config();//停止模式会关闭HSE 所以退出之后需要手动调用函数开启
		/在此处添加程序
		arr_re[0]=key;
		HAL_UART_Transmit(&UART_HandInit,"ok\r\n",4,50);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		/
		HAL_UART_Transmit(&UART_HandInit,"out of stop mood\r\n",18,50);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	  */
	  
	  /*睡眠模式
		HAL_UART_Transmit(&UART_HandInit,"enter sleep mood\r\n",18,50);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		
		HAL_SuspendTick();//关闭滴答定时器增量 因为该睡眠模式为中断唤醒 滴答定时器会周期性的产生中断
		HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON,PWR_SLEEPENTRY_WFI);
		HAL_ResumeTick();//开启滴答定时器增量
		/在此处添加程序
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_4);
		/
		HAL_UART_Transmit(&UART_HandInit,"out of sleep mood\r\n",19,50);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	  */
  }
}

void EXTI3_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_3);//清除挂起标志位 虽然上一个函数也会清楚该标志位但是这样更保险
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	HAL_Delay(10);
	if(GPIO_Pin==GPIO_PIN_3){
		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3)==0){
			key++;
		}
	}
	if(GPIO_Pin==GPIO_PIN_0){
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)==1){
		}
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
