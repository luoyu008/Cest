#include "main.h"
#include "gpio.h"
#include "OLED.h"
#include "DELAY.h"
#include "TIMRencoder.h"
#include "USART.h"
#include "SG90.h"
#include <stdio.h>
/*
	旋转编码器的A端接A6 B端接A7
	蓝牙模块Rx接A9 Tx接A10
	舵机的棕色接地 红色接5v 黄色接A1
	OLEDSCL接B10 SDA接B11
*/
void SystemClock_Config(void);
int16_t state;
int16_t prestate;
char str[50];
uint16_t compare=1500;
int main(void)
{
	HAL_Init();
	SystemClock_Config();
	DELAY_Init(72);
//	OLED_Init();
//	OLED_Clear();
	SG90PWM_Init();
	USART1_Init();
	TIMRencoder_Init();
	while (1){
	state=__HAL_TIM_GET_COUNTER(&TIM_TIMRencoder_Init);
	state/=4;
	OLED_ShowSignedNum(0,0,state,10,16);
	OLED_UpData();
	if(prestate!=state){
		sprintf(str,"%d",state);
		if(state>=0&&state<=9){
			HAL_UART_Transmit(&UART_HandInit,str,1,1000);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		}else
		if((state>=10&&state<=99)||(state<0&&state>-10)){
			HAL_UART_Transmit(&UART_HandInit,str,2,1000);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		}else 
		if((state>=100&&state<=999)||(state<=-10&&state>-100)){
			HAL_UART_Transmit(&UART_HandInit,str,3,1000);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		}
		compare+=((state-prestate)*100);
		prestate=state;
	}
	__HAL_TIM_SET_COMPARE(&TIM_SG90HandInit,TIM_CHANNEL_2,compare);
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
