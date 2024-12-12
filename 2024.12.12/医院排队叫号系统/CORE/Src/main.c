#include "main.h"
#include "gpio.h"
#include "MYLED.h"
#include "EXIT.h"
#include "OLED.h"
#include "DELAY.h"
#include "Hospital_Number.h"
#include "USART.h"
#include <stdlib.h>
void SystemClock_Config(void);
HL* List=NULL;
uint8_t KEY0_Flage=0;
uint8_t KEY1_Flage=0;
uint8_t KEY2_Flage=0;
uint16_t patient_num=0;
uint16_t doctor1_num=0;
uint16_t doctor2_num=0;
char str[50];
int main(void)
{
	HAL_Init();
	SystemClock_Config();
	MYLED_Init();
	OLED_Init();
	EXIT_Init();
	USART1_Init();
	List = Hospital_List_Init();
	HAL_UART_Transmit(&UART_HandInit,"结构体创建成功\r\n",18,1000);
	while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	while (1){
	if(KEY0_Flage==1){												/*按键0按下患者取号*/
		patient_num = Hospital_patient_Take(&List);
		HAL_UART_Transmit(&UART_HandInit,"患者取到的号码是：",18,1000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		sprintf(str,"%u",patient_num);
		if(patient_num>=0&&patient_num<10){
				HAL_UART_Transmit(&UART_HandInit,str,1,10);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			}else
			if(patient_num>=10&&patient_num<100){
				HAL_UART_Transmit(&UART_HandInit,str,2,10);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			}else
			if(patient_num>=100&&patient_num<1000){
				HAL_UART_Transmit(&UART_HandInit,str,3,10);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			}
		HAL_UART_Transmit(&UART_HandInit,"\r\n",4,10);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		KEY0_Flage=0;
	}
	
	if(KEY1_Flage==1){												/*按键1按下1号医生取号*/
		doctor1_num = Hospital_doctor_Take(&List);
		if(doctor1_num==0){
			HAL_UART_Transmit(&UART_HandInit,"当前无患者取号",14,1000);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		}else{
		HAL_UART_Transmit(&UART_HandInit,"1号医生取到的号码是：",21,1000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		sprintf(str,"%u",doctor1_num);
		if(doctor1_num>=0&&doctor1_num<10){
				HAL_UART_Transmit(&UART_HandInit,str,1,10);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			}else
			if(doctor1_num>=10&&doctor1_num<100){
				HAL_UART_Transmit(&UART_HandInit,str,2,10);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			}else
			if(doctor1_num>=100&&doctor1_num<1000){
				HAL_UART_Transmit(&UART_HandInit,str,3,10);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			}
		}
		HAL_UART_Transmit(&UART_HandInit,"\r\n",4,10);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		KEY1_Flage=0;
	}
	
	if(KEY2_Flage==1){												/*按键2按下2号医生取号*/
		doctor2_num = Hospital_doctor_Take(&List);
		if(doctor2_num==0){
			HAL_UART_Transmit(&UART_HandInit,"当前无患者取号",14,1000);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		}else{
		HAL_UART_Transmit(&UART_HandInit,"2号医生取到的号码是：",21,1000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		sprintf(str,"%u",doctor2_num);
		if(doctor2_num>=0&&doctor2_num<10){
				HAL_UART_Transmit(&UART_HandInit,str,1,10);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			}else
			if(doctor2_num>=10&&doctor2_num<100){
				HAL_UART_Transmit(&UART_HandInit,str,2,10);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			}else
			if(doctor2_num>=100&&doctor2_num<1000){
				HAL_UART_Transmit(&UART_HandInit,str,3,10);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			}
		}
		HAL_UART_Transmit(&UART_HandInit,"\r\n",4,10);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		KEY2_Flage=0;
	}
  }
}

void EXTI0_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0);
}

void EXTI1_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_1);
}

void EXTI3_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_3);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
//	HAL_Delay(10);
	DELAY_us(1000);
	if(GPIO_Pin==GPIO_PIN_0){
		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==0){
			KEY0_Flage=1;
		}
	}
	if(GPIO_Pin==GPIO_PIN_1){
		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1)==0){
			KEY1_Flage=1;
		}
	}
	if(GPIO_Pin==GPIO_PIN_3){
		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3)==0){
			KEY2_Flage=1;
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
