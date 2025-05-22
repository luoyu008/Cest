#include "main.h"
#include "gpio.h"
#include "MYLED.h"
#include "EXIT.h"
#include "OLED.h"
#include "DELAY.h"
#include "CANLoopTest.h"
#include "KEY.h"
#include "SG90.h"
#include "stdio.h"
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
	{0x078,0x0789ABFF,CAN_ID_STD,CAN_RTR_DATA,4,DISABLE},
};

CAN_RxHeaderTypeDef CAN_RxLoopTest;
uint8_t p=0;
uint8_t TxData[]={0,1,2,3};
uint8_t RxData[12]={0};
uint32_t TimeOut;
uint8_t Der;
int16_t pitch,roll,yaw;
int16_t pre_pitch,pre_roll,pre_yaw;
int16_t angle;
uint8_t ch[40];
int main(void)
{
	HAL_Init();
	SystemClock_Config();
	MYLED_Init();
	OLED_Init();
	OLED_UpData();
	EXIT_Init();
	CANLoopTest_Init();
	SG90_Init();
	while (1){
	/*接受部分*/
	if(HAL_CAN_GetRxFifoFillLevel(&CAN_LoopTestInit,CAN_RX_FIFO0)!=0){
		uint8_t tyu=HAL_CAN_GetRxMessage(&CAN_LoopTestInit,CAN_RX_FIFO0,&CAN_RxLoopTest,RxData);
		if(CAN_RxLoopTest.IDE==CAN_ID_STD){
		}
		else if(CAN_RxLoopTest.IDE==CAN_ID_EXT){
		}
		OLED_ShowHexNum(90,32,CAN_RxLoopTest.DLC,1,16);
		if(CAN_RxLoopTest.RTR==CAN_RTR_DATA){
			pitch=(int16_t)((RxData[0]<<8)|(RxData[1]));
			roll=(int16_t)((RxData[2]<<8)|(RxData[3]));
			yaw=(int16_t)((RxData[4]<<8)|(RxData[5]));
			OLED_ShowSignedNum(0,0,pitch,8,16);
			OLED_ShowSignedNum(0,20,roll,8,16);
			OLED_ShowSignedNum(0,40,yaw,8,16);
			OLED_UpData();
		}
		else if(CAN_RxLoopTest.RTR==CAN_RTR_REMOTE){
		}
	}
	
		uint32_t Num=HAL_CAN_GetTxMailboxesFreeLevel(&CAN_LoopTestInit);
		OLED_UpData();
	/*控制部分*/
	angle=150+roll/100;
	if(angle>250){
		angle=251;
	}
	if(angle<50){
		angle=49;
	}
	if(pre_roll!=roll&&angle!=49&&angle!=251){
//		HAL_TIM_PWM_Stop(&SG90_HandInit,TIM_CHANNEL_2);
		__HAL_TIM_SetCompare(&SG90_HandInit,TIM_CHANNEL_2,angle);
//		HAL_TIM_PWM_Start(&SG90_HandInit,TIM_CHANNEL_2);
	}
	
	pre_pitch=pitch;
	pre_roll=roll;
	pre_yaw=yaw;
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
