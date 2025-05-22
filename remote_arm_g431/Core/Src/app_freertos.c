/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : app_freertos.c
  * Description        : Code for freertos applications
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

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
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId defaultTaskHandle;
osThreadId DHT11ReadHandle;
osThreadId CANTaskHandle;
osThreadId ControlTaskHandle;
osMessageQId mpu6050QueueHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
#include "MPU6050.h"
#include "42Motor.h"
#include "DELAY.h"
#include "lcd.h"
#include "stdio.h"
extern TIM_HandleTypeDef htim3;
extern I2C_HandleTypeDef hi2c1;
extern FDCAN_TX fdcan_tx;
extern ANGLE_Data angle_data;
extern MPU6050_Data mpu6050_data;
extern MAIN_Data main_data;
extern FDCAN_RX fdcan_rx;
extern uint8_t i2c_error;
void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c);
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void DHT11ReadEntry(void const * argument);
void CANTaskEntry(void const * argument);
void ControlTaskEntry(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* definition and creation of mpu6050Queue */
  osMessageQDef(mpu6050Queue, 3, float);
  mpu6050QueueHandle = osMessageCreate(osMessageQ(mpu6050Queue), NULL);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of DHT11Read */
  osThreadDef(DHT11Read, DHT11ReadEntry, osPriorityHigh, 0, 128);
  DHT11ReadHandle = osThreadCreate(osThread(DHT11Read), NULL);

  /* definition and creation of CANTask */
  osThreadDef(CANTask, CANTaskEntry, osPriorityAboveNormal, 0, 128);
  CANTaskHandle = osThreadCreate(osThread(CANTask), NULL);

  /* definition and creation of ControlTask */
  osThreadDef(ControlTask, ControlTaskEntry, osPriorityNormal, 0, 128);
  ControlTaskHandle = osThreadCreate(osThread(ControlTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(100);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_DHT11ReadEntry */
/**
* @brief Function implementing the DHT11Read thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_DHT11ReadEntry */
void DHT11ReadEntry(void const * argument)
{
  /* USER CODE BEGIN DHT11ReadEntry */
  /* Infinite loop */
  for(;;)
  {
	  if(mpu6050_data.count<3){
	  taskENTER_CRITICAL();
	MPU6050_DMP_Get_Date(&mpu6050_data.pitch,&mpu6050_data.roll,&mpu6050_data.yaw);
	  taskEXIT_CRITICAL();
	  mpu6050_data.pitch_all+=mpu6050_data.pitch;
	  mpu6050_data.roll_all+=mpu6050_data.roll;
	  mpu6050_data.yaw_all+=mpu6050_data.yaw;
	  mpu6050_data.count++;
	  }else if(mpu6050_data.count==3){
	  mpu6050_data.pitch_real=mpu6050_data.pitch_all/3;
	  mpu6050_data.roll_real=mpu6050_data.roll_all/3;
	  mpu6050_data.yaw_real=mpu6050_data.yaw_all/3;
	/*数据校准*/
	  mpu6050_data.pitch_real=mpu6050_data.pitch_real-mpu6050_data.reset_pitch;
	  mpu6050_data.roll_real=mpu6050_data.roll_real-mpu6050_data.reset_roll;
	  mpu6050_data.yaw_real=mpu6050_data.yaw_real-mpu6050_data.reset_yaw;
	  mpu6050_data.pitch_all=0;
	  mpu6050_data.roll_all=0;
	  mpu6050_data.yaw_all=0;
	  mpu6050_data.count=0;
	  }
	  sprintf(main_data.ch,"%.2f %.2f %.2f ",mpu6050_data.pitch_real,mpu6050_data.roll_real,mpu6050_data.yaw_real);
	  taskENTER_CRITICAL();
	  LCD_DisplayStringLine(Line1,main_data.ch);
	  taskEXIT_CRITICAL();
	/*iic错误处理*/
	  if(HAL_I2C_GetError(&hi2c1)!=0){
		  i2c_error=HAL_I2C_GetError(&hi2c1);
	sprintf(main_data.ch,"%d ",i2c_error);
	LCD_DisplayStringLine(Line2,main_data.ch);
		  main_data.ret=0;
		  mpu6050_data.reset_pitch=mpu6050_data.pitch_real;
		  mpu6050_data.reset_roll=mpu6050_data.roll_real;
		  mpu6050_data.reset_yaw=mpu6050_data.yaw_real;
		do{
			taskENTER_CRITICAL();
 	 main_data.ret=MPU6050_DMP_init();
			taskEXIT_CRITICAL();
	  sprintf(main_data.ch,"%d ",main_data.ret);
			taskENTER_CRITICAL();
	  LCD_DisplayStringLine(Line0,main_data.ch);
			taskEXIT_CRITICAL();
	}while(main_data.ret);
	  }
	  
    osDelay(100);
  }
  /* USER CODE END DHT11ReadEntry */
}

/* USER CODE BEGIN Header_CANTaskEntry */
/**
* @brief Function implementing the CANTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_CANTaskEntry */
void CANTaskEntry(void const * argument)
{
  /* USER CODE BEGIN CANTaskEntry */
  /* Infinite loop */
  for(;;)
  {
	/*can发送的数据*/
	mpu6050_data.x=(int16_t)(mpu6050_data.pitch_real*100);
	mpu6050_data.y=(int16_t)(mpu6050_data.roll_real*100);
	mpu6050_data.z=(int16_t)(mpu6050_data.yaw_real*100);
	  
	main_data.TxData[0]=(uint8_t)((mpu6050_data.x>>8)&0xff);
	main_data.TxData[1]=(uint8_t)(mpu6050_data.x&0xff);
	main_data.TxData[2]=(uint8_t)((mpu6050_data.y>>8)&0xff);
	main_data.TxData[3]=(uint8_t)(mpu6050_data.y&0xff);
	main_data.TxData[4]=(uint8_t)((mpu6050_data.z>>8)&0xff);
	main_data.TxData[5]=(uint8_t)(mpu6050_data.z&0xff);
	
	fdcan_tx.hfdcantx.Identifier=0xaa;
	  taskENTER_CRITICAL();
	HAL_FDCAN_AddMessageToTxFifoQ(fdcan_tx.hfdcan,&fdcan_tx.hfdcantx,main_data.TxData);
	  taskEXIT_CRITICAL();
    osDelay(20);
  }
  /* USER CODE END CANTaskEntry */
}

/* USER CODE BEGIN Header_ControlTaskEntry */
/**
* @brief Function implementing the ControlTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_ControlTaskEntry */
void ControlTaskEntry(void const * argument)
{
  /* USER CODE BEGIN ControlTaskEntry */
  /* Infinite loop */
  for(;;)
  {
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
	if(mpu6050_data.yaw_real>0){
		angle_data.angle_yaw=(int16_t)(mpu6050_data.yaw_real/1.8);
		if(angle_data.angle_yaw!=angle_data.pre_yaw){
			if(angle_data.angle_yaw>angle_data.pre_yaw){
				taskENTER_CRITICAL();
			Motor_42_W_DIR(0);
			for(int i=0;i<(angle_data.angle_yaw-angle_data.pre_yaw)*50;i++){
				HAL_GPIO_WritePin(GPIOA,PUL_Signal,GPIO_PIN_SET);
				DELAY_us(100);
				HAL_GPIO_WritePin(GPIOA,PUL_Signal,GPIO_PIN_RESET);
				DELAY_us(100);
			}
			taskEXIT_CRITICAL();
		}
			if(angle_data.angle_yaw<angle_data.pre_yaw){
				taskENTER_CRITICAL();
			Motor_42_W_DIR(1);
			for(int i=0;i<(angle_data.pre_yaw-angle_data.angle_yaw)*50;i++){
				HAL_GPIO_WritePin(GPIOA,PUL_Signal,GPIO_PIN_SET);
				DELAY_us(100);
				HAL_GPIO_WritePin(GPIOA,PUL_Signal,GPIO_PIN_RESET);
				DELAY_us(100);
			}
			taskEXIT_CRITICAL();
		}
		angle_data.pre_yaw=angle_data.angle_yaw;
	}
	}
	if(mpu6050_data.yaw_real<0){
		angle_data.angle_yaw=-mpu6050_data.yaw_real;
		angle_data.angle_yaw=(int16_t)(angle_data.angle_yaw/1.8);
		if(angle_data.pre_yaw!=angle_data.angle_yaw){
			if(angle_data.angle_yaw>angle_data.pre_yaw){
				taskENTER_CRITICAL();
			Motor_42_W_DIR(1);
			for(int i=0;i<(angle_data.angle_yaw-angle_data.pre_yaw)*50;i++){
				HAL_GPIO_WritePin(GPIOA,PUL_Signal,GPIO_PIN_SET);
				DELAY_us(100);
				HAL_GPIO_WritePin(GPIOA,PUL_Signal,GPIO_PIN_RESET);
				DELAY_us(100);
			}
			taskEXIT_CRITICAL();
		}
			if(angle_data.angle_yaw<angle_data.pre_yaw){
				taskENTER_CRITICAL();
			Motor_42_W_DIR(0);
			for(int i=0;i<(angle_data.pre_yaw-angle_data.angle_yaw)*50;i++){
				HAL_GPIO_WritePin(GPIOA,PUL_Signal,GPIO_PIN_SET);
				DELAY_us(100);
				HAL_GPIO_WritePin(GPIOA,PUL_Signal,GPIO_PIN_RESET);
				DELAY_us(100);
			}
			taskEXIT_CRITICAL();
		}
	}
		angle_data.pre_yaw=angle_data.angle_yaw;
	}
    osDelay(50);
  }
  /* USER CODE END ControlTaskEntry */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

