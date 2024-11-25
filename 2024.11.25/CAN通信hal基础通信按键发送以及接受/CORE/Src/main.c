#include "main.h"
#include "gpio.h"
#include "MYLED.h"
#include "EXIT.h"
#include "OLED.h"
#include "DELAY.h"
#include "CANLoopTest.h"
void SystemClock_Config(void);
uint8_t key;
CAN_TxHeaderTypeDef CAN_TxLoopTest[]={
	{0x012,0x12345600,CAN_ID_STD,CAN_RTR_DATA,4,DISABLE},
	{0x120,0x12345601,CAN_ID_STD,CAN_RTR_REMOTE,4,DISABLE},
	{0x050,0x123456FE,CAN_ID_STD,CAN_RTR_DATA,4,DISABLE},
	{0x004,0x123456FF,CAN_ID_STD,CAN_RTR_REMOTE,4,DISABLE},
	{0x058,0x0789AB00,CAN_ID_STD,CAN_RTR_DATA,4,DISABLE},
	{0x060,0x0789AB01,CAN_ID_STD,CAN_RTR_REMOTE,4,DISABLE},
	{0x098,0x0789ABFE,CAN_ID_STD,CAN_RTR_DATA,4,DISABLE},
	{0x078,0x0789ABFF,CAN_ID_STD,CAN_RTR_REMOTE,4,DISABLE},
};

CAN_RxHeaderTypeDef CAN_RxLoopTest;
uint8_t p=0;
uint8_t TxData[]={0,1,2,3};
uint8_t RxData[]={0};
uint32_t TimeOut;
uint8_t Der;
int main(void)
{
	HAL_Init();
	SystemClock_Config();
	MYLED_Init();
	OLED_Init();
	OLED_UpData();
	EXIT_Init();
	CANLoopTest_Init();
	OLED_ShowString(0,0,"Rx:",16);
	OLED_ShowString(0,16,"ID:",16);
	OLED_ShowString(0,32,"Length:",16);
	OLED_ShowString(0,48,"Data:",16);
	while (1){
	if(key==1){
		uint32_t Box=CAN_TX_MAILBOX0;
	    Der=HAL_CAN_AddTxMessage(&CAN_LoopTestInit,&CAN_TxLoopTest[p],TxData,&Box);
		p++;
		if(p>=8){
			p=0;
		}
	  	while(HAL_CAN_GetTxMailboxesFreeLevel(&CAN_LoopTestInit)!=3){
			TimeOut++;
			if(TimeOut>=100000){
				OLED_ShowHexNum(0,90,1,2,16);
			}
		}
		
		TimeOut=0;
		key=0;
	}
	
		OLED_ShowHexNum(72,16,p,3,16);
		
		if(HAL_CAN_GetRxFifoFillLevel(&CAN_LoopTestInit,CAN_RX_FIFO0)!=0){
		uint8_t tyu=HAL_CAN_GetRxMessage(&CAN_LoopTestInit,CAN_RX_FIFO0,&CAN_RxLoopTest,RxData);
		OLED_ShowHexNum(100,16,tyu,1,16);
		if(CAN_RxLoopTest.IDE==CAN_ID_STD){
			OLED_ShowHexNum(30,16,CAN_RxLoopTest.StdId,3,16);
		}
		else if(CAN_RxLoopTest.IDE==CAN_ID_EXT){
			OLED_ShowHexNum(30,16,CAN_RxLoopTest.ExtId,8,16);
		}
		OLED_ShowHexNum(55,32,CAN_RxLoopTest.DLC,1,16);
		if(CAN_RxLoopTest.RTR==CAN_RTR_DATA){
			OLED_ShowString(25,0,"Data  ",16);
			OLED_ShowHexNum(38,48,RxData[0],2,16);
			OLED_ShowHexNum(56,48,RxData[1],2,16);
			OLED_ShowHexNum(74,48,RxData[2],2,16);
			OLED_ShowHexNum(92,48,RxData[3],2,16);

		}
		else if(CAN_RxLoopTest.RTR==CAN_RTR_REMOTE){
			OLED_ShowString(25,0,"Remote",16);
			OLED_ShowHexNum(38,48,0,2,16);
			OLED_ShowHexNum(56,48,0,2,16);
			OLED_ShowHexNum(74,48,0,2,16);
			OLED_ShowHexNum(92,48,0,2,16);
		}
	}
		uint32_t Num=HAL_CAN_GetTxMailboxesFreeLevel(&CAN_LoopTestInit);
		OLED_ShowHexNum(70,32,Num,2,16);
		OLED_ShowHexNum(90,32,Der,2,16);
		OLED_UpData();

	
  }
}

void EXTI0_IRQHandler(void){
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
//	HAL_Delay(10);
	DELAY_us(10000);
	if(GPIO_Pin==GPIO_PIN_0){
		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0)==0){
			key=1;
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
