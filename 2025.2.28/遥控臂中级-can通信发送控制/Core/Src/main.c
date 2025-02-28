#include "main.h"
#include "i2c.h"
#include "usart.h"
#include "gpio.h"
#include "CANLoopTest.h"
#include "stdio.h"
#include "MPU6050.h"
#include "OLED.h"
#include "DELAY.h"
#include "SG90Pitch.h"
//#include <stdio.h>
//#include <string.h>
void SystemClock_Config(void);
float pitch,yaw,roll;
float pre_pitch,pre_yaw,pre_roll;
int16_t x,y,z;
#include <stdio.h>
#include <string.h>
int fputc(int ch, FILE *f)
{
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xffff);
  return ch;
}
/**
  * 函数功能: 重定向c库函数getchar,scanf到DEBUG_USARTx
  * 输入参数: 无
  * 返 回 值: 无
  * 说    明：无
  */
int fgetc(FILE *f)
{
  uint8_t ch = 0;
  HAL_UART_Receive(&huart1, &ch, 1, 0xffff);
  return ch;
}

void Data_Send(float pitch_a,float roll_a,float yaw_a){
	int i,m;
	uint8_t tx_buf[13];  // 完整帧缓冲区：2头+功能码+长度+7数据+2校验=10字节
    uint16_t pitch = (int16_t)(pitch_a * 100);  // 转换为int16并放大100倍
    uint16_t roll = (int16_t)(roll_a * 100);
    uint16_t yaw = (int16_t)(yaw_a * 100);
    uint8_t sum_check = 0, add_check = 0;
	
	tx_buf[0] = 0xaa;
    tx_buf[1] = 0xff;
    tx_buf[2] = 0x03;
    tx_buf[3] = 7;
    tx_buf[4] = (uint8_t)(roll & 0xFF);        // Roll低字节
    tx_buf[5] = (uint8_t)(roll >> 8);          // Roll高字节
    tx_buf[6] = (uint8_t)(pitch & 0xFF);       // Pitch低字节
    tx_buf[7] = (uint8_t)(pitch >> 8);         // Pitch高字节
    tx_buf[8] = (uint8_t)(yaw & 0xFF);         // Yaw低字节
    tx_buf[9] = (uint8_t)(yaw >> 8);           // Yaw高字节
    tx_buf[10] =0x01;                // 状态标志

    // 计算校验和
    for ( i = 0; i < 11; i++) {             // 前11字节（头至数据区）
        sum_check += tx_buf[i];
        add_check += sum_check;
    }
    tx_buf[11] = sum_check;                    // 和校验
    tx_buf[12] = add_check;                    // 附加校验
	for( m=0;m<13;m++){
    printf("%c",tx_buf[m]);
	}
}

CAN_TxHeaderTypeDef CAN_TxLoopTest[]={
	{0x012,0x12345600,CAN_ID_STD,CAN_RTR_DATA,6,DISABLE},
};
CAN_RxHeaderTypeDef CAN_RxLoopTest;
uint8_t p=0;
uint8_t TxData[6]={0};
uint8_t RxData[12]={0};
uint32_t TimeOut;
uint8_t Der;
int16_t angle_Pitch;
int main(void)
{
	HAL_Init();
	SystemClock_Config();
	DELAY_Init(72);
	OLED_Init();
	OLED_Clear();
	MX_GPIO_Init();
	MX_I2C1_Init();
	MX_USART1_UART_Init();
	CANLoopTest_Init();
	SG90Pitch_Init();
	int ret=0;
	do{
	 ret=MPU6050_DMP_init();
		printf("ret=%d\n",ret);
	}while(ret);
	while (1)
	{
	/*数据部分*/
	MPU6050_DMP_Get_Date(&pitch,&roll,&yaw);
	x=(int16_t)(pitch*100);
	y=(int16_t)(roll*100);
	z=(int16_t)(yaw*100);
	TxData[0]=(uint8_t)((x>>8)&0xff);
	TxData[1]=(uint8_t)(x&0xff);
	TxData[2]=(uint8_t)((y>>8)&0xff);
	TxData[3]=(uint8_t)(y&0xff);
	TxData[4]=(uint8_t)((z>>8)&0xff);
	TxData[5]=(uint8_t)(z&0xff);
	if(pre_pitch!=pitch||pre_roll!=roll||pre_yaw!=yaw){
		uint32_t Box=CAN_TX_MAILBOX0;
	    Der=HAL_CAN_AddTxMessage(&CAN_LoopTestInit,&CAN_TxLoopTest[0],TxData,&Box);
	  	while(HAL_CAN_GetTxMailboxesFreeLevel(&CAN_LoopTestInit)!=3){
			TimeOut++;
			if(TimeOut>=100000){
				OLED_ShowHexNum(0,90,1,2,16);
			}
		}
		
		TimeOut=0;
	}
//	printf("pitch=%f yaw=%f roll=%f\n",pitch,roll,yaw);
	Data_Send(pitch,roll,yaw);
	/*控制部分*/
	angle_Pitch=150+x/100;
	if(angle_Pitch>250){
		angle_Pitch=251;
	}
	if(angle_Pitch<50){
		angle_Pitch=49;
	}
	if(pre_pitch!=x&&angle_Pitch!=49&&angle_Pitch!=251){
		__HAL_TIM_SetCompare(&SG90Pitch_HandInit,TIM_CHANNEL_2,angle_Pitch);
	}
	
	pre_pitch=x;
	pre_roll=y;
	pre_yaw=z;
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
