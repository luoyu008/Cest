/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "fdcan.h"
#include "i2c.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#include "lcd.h"
#include "MPU6050.h"
#include "DELAY.h"
#include "stdio.h"
#include "string.h"
#include "42Motor.h"
#include "math.h"
#define pi 3.1415
MAIN_Data main_data={0,0,{0},{0}};
MPU6050_Data mpu6050_data={0,0,0,0,0,0,0,0,0,0,0,0,0};
ANGLE_Data angle_data={0,0,0,0,0,0};
FDCAN_TX fdcan_tx={
	.hfdcan=&hfdcan1,
	.hfdcantx.IdType = FDCAN_STANDARD_ID,
	.hfdcantx.TxFrameType = FDCAN_DATA_FRAME,
	.hfdcantx.DataLength = 6,
	.hfdcantx.ErrorStateIndicator = FDCAN_ESI_ACTIVE,
	.hfdcantx.BitRateSwitch = FDCAN_BRS_OFF,
	.hfdcantx.FDFormat = FDCAN_CLASSIC_CAN,
	.hfdcantx.TxEventFifoControl = FDCAN_NO_TX_EVENTS,
	.hfdcantx.MessageMarker = 0,
	{0}
};
FDCAN_RX fdcan_rx;
uint8_t i2c_error;
void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c);
uint8_t caculate(float x, float y, float z, float *ptheta)
{
	float L1 = 0.14; //杆长
	float L2 = 0.11;
	float L3 = 0.04;
	float alpha, beta, lp, Bx, By;
	Bx=x-L3; //这里设置γ为-90
	By=y;
	lp=Bx*Bx+By*By;
	if (sqrt(lp)>=L1+L2 || sqrt(lp)<=fabs(L1-L2))
		return 1;
	alpha = atan2(By,Bx);
	beta = acos((L1*L1+lp-L2*L2)/(2*L1*sqrt(lp))); //这里使用弧度制
	ptheta[0] = -(pi/2.0-alpha-beta);
	ptheta[1] = acos((L1*L1+L2*L2-lp)/(2*L1*L2))-pi;
	ptheta[2] = -ptheta[0] -ptheta[1]- pi/2.0;
	return 0;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_TIM15_Init();
  MX_TIM3_Init();
  MX_FDCAN1_Init();
  /* USER CODE BEGIN 2 */
  LCD_Init();
  LCD_SetBackColor(Black);
  LCD_SetTextColor(White);
  LCD_Clear(Black);
  do{
 	 main_data.ret=MPU6050_DMP_init();
	  sprintf(main_data.ch,"%d ",main_data.ret);
	  LCD_DisplayStringLine(Line0,main_data.ch);
	}while(main_data.ret);
	HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);
	Motoe_42Init();
	Motor_42_W_ENABLE(1);
	Motor_42_W_DIR(1);
  /* USER CODE END 2 */

  /* Call init function for freertos objects (in cmsis_os2.c) */
  MX_FREERTOS_Init();

  /* Start scheduler */
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  MPU6050_DMP_Get_Date(&mpu6050_data.pitch,&mpu6050_data.roll,&mpu6050_data.yaw);
	/*数据校准*/
	  mpu6050_data.pitch=mpu6050_data.pitch-mpu6050_data.reset_pitch;
	  mpu6050_data.roll=mpu6050_data.roll-mpu6050_data.reset_roll;
	  mpu6050_data.yaw=mpu6050_data.yaw-mpu6050_data.reset_yaw;
	  sprintf(main_data.ch,"%.2f %.2f %.2f ",mpu6050_data.pitch,mpu6050_data.roll,mpu6050_data.yaw);
	  LCD_DisplayStringLine(Line1,main_data.ch);
	/*iic错误处理*/
	  if(HAL_I2C_GetError(&hi2c1)!=0){
		  i2c_error=HAL_I2C_GetError(&hi2c1);
	sprintf(main_data.ch,"%d ",i2c_error);
	LCD_DisplayStringLine(Line2,main_data.ch);
		  main_data.ret=0;
		  mpu6050_data.reset_pitch=mpu6050_data.pitch;
		  mpu6050_data.reset_roll=mpu6050_data.reset_roll;
		  mpu6050_data.reset_yaw=mpu6050_data.reset_yaw;
		do{
 	 main_data.ret=MPU6050_DMP_init();
	  sprintf(main_data.ch,"%d ",main_data.ret);
	  LCD_DisplayStringLine(Line0,main_data.ch);
	}while(main_data.ret);
	  }
	  
	  /*can发送的数据*/
	mpu6050_data.x=(int16_t)(mpu6050_data.pitch*100);
	mpu6050_data.y=(int16_t)(mpu6050_data.roll*100);
	mpu6050_data.z=(int16_t)(mpu6050_data.yaw*100);
	  
	main_data.TxData[0]=(uint8_t)((mpu6050_data.x>>8)&0xff);
	main_data.TxData[1]=(uint8_t)(mpu6050_data.x&0xff);
	main_data.TxData[2]=(uint8_t)((mpu6050_data.y>>8)&0xff);
	main_data.TxData[3]=(uint8_t)(mpu6050_data.y&0xff);
	main_data.TxData[4]=(uint8_t)((mpu6050_data.z>>8)&0xff);
	main_data.TxData[5]=(uint8_t)(mpu6050_data.z&0xff);
	
	fdcan_tx.hfdcantx.Identifier=0xaa;
	  
	HAL_FDCAN_AddMessageToTxFifoQ(fdcan_tx.hfdcan,&fdcan_tx.hfdcantx,main_data.TxData);
	  
	  angle_data.angle_pitch=150+mpu6050_data.x/100;
	  if(angle_data.angle_pitch>250){
		angle_data.angle_pitch=251;
	  }
	  if(angle_data.angle_pitch<50){
		angle_data.angle_pitch=49;
	  }
	  if(angle_data.pre_pitch!=mpu6050_data.x&&angle_data.angle_pitch!=49&&angle_data.angle_pitch!=251){
		__HAL_TIM_SetCompare(&htim3,TIM_CHANNEL_1,angle_data.angle_pitch);
	  }
	  angle_data.pre_pitch=angle_data.angle_pitch;
	if(mpu6050_data.yaw>0){
		angle_data.angle_yaw=(int16_t)(mpu6050_data.yaw/1.8);
		if(angle_data.angle_yaw!=angle_data.pre_yaw){
			if(angle_data.angle_yaw>angle_data.pre_yaw){
			Motor_42_W_DIR(0);
			for(int i=0;i<(angle_data.angle_yaw-angle_data.pre_yaw)*50;i++){
				HAL_GPIO_WritePin(GPIOA,PUL_Signal,GPIO_PIN_SET);
				DELAY_us(100);
				HAL_GPIO_WritePin(GPIOA,PUL_Signal,GPIO_PIN_RESET);
				DELAY_us(100);
			}
		}
			if(angle_data.angle_yaw<angle_data.pre_yaw){
			Motor_42_W_DIR(1);
			for(int i=0;i<(angle_data.pre_yaw-angle_data.angle_yaw)*50;i++){
				HAL_GPIO_WritePin(GPIOA,PUL_Signal,GPIO_PIN_SET);
				DELAY_us(100);
				HAL_GPIO_WritePin(GPIOA,PUL_Signal,GPIO_PIN_RESET);
				DELAY_us(100);
			}
		}
		angle_data.pre_yaw=angle_data.angle_yaw;
	}
	}
	if(mpu6050_data.yaw<0){
		angle_data.angle_yaw=-mpu6050_data.yaw;
		angle_data.angle_yaw=(int16_t)(angle_data.angle_yaw/1.8);
		if(angle_data.pre_yaw!=angle_data.angle_yaw){
			if(angle_data.angle_yaw>angle_data.pre_yaw){
			Motor_42_W_DIR(1);
			for(int i=0;i<(angle_data.angle_yaw-angle_data.pre_yaw)*50;i++){
				HAL_GPIO_WritePin(GPIOA,PUL_Signal,GPIO_PIN_SET);
				DELAY_us(100);
				HAL_GPIO_WritePin(GPIOA,PUL_Signal,GPIO_PIN_RESET);
				DELAY_us(100);
			}
		}
			if(angle_data.angle_yaw<angle_data.pre_yaw){
			Motor_42_W_DIR(0);
			for(int i=0;i<(angle_data.pre_yaw-angle_data.angle_yaw)*50;i++){
				HAL_GPIO_WritePin(GPIOA,PUL_Signal,GPIO_PIN_SET);
				DELAY_us(100);
				HAL_GPIO_WritePin(GPIOA,PUL_Signal,GPIO_PIN_RESET);
				DELAY_us(100);
			}
		}
	}
		angle_data.pre_yaw=angle_data.angle_yaw;
	}
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV3;
  RCC_OscInitStruct.PLL.PLLN = 20;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
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
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c)
{
	if(hi2c->Instance==I2C1){
		main_data.i2c_error=1;
	}
}
/* USER CODE END 4 */

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM17 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM17) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

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
