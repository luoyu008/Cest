#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include "USART.h"
#include "KEY.h"
#include "EXIT.h"
#include "DELAY.h"
#include "OLED.h"
#include "Time.h"
#include "semphr.h"
#include <stdio.h>
#include <stdlib.h>
osThreadId defaultTaskHandle;
osThreadId Task1Handle;
osThreadId Task2Handle;
osThreadId Task3Handle;


#define Task1_STACK_SIZE 128
#define Task1_PRIO       1

#define Task2_STACK_SIZE 128
#define Task2_PRIO       2

#define Task3_STACK_SIZE 128
#define Task3_PRIO       3

TimerHandle_t	Time_OneShot;
TimerHandle_t	Time_Cycle;
uint8_t Timer1=1;
uint8_t Timer2=2;
uint32_t Timer1_Count=0;
uint32_t Timer2_Count=0;
char str[50];

void StartDefaultTask(void const * argument);
void EntryTask1(void const * argument);
void EntryTask2(void const * argument);
void EntryTask3(void const * argument);

void FreeRtos_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];
/*
	为空闲任务提供内存
*/
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}

/* 定时器服务任务堆栈 */
static StackType_t TimerTaskStack[configTIMER_TASK_STACK_DEPTH];
/* 定时器服务任务控制块 */
static StaticTask_t TimerTaskTCB;
void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer,StackType_t **ppxTimerTaskStackBuffer,uint32_t *pulTimerTaskStackSize)
{
*ppxTimerTaskTCBBuffer = &TimerTaskTCB;
*ppxTimerTaskStackBuffer = TimerTaskStack;
*pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}

/*定时器回调函数*/
void Timer1CallbackFunction( TimerHandle_t xTimer ){
	Timer1_Count++;
	sprintf(str,"%u",Timer1_Count);
	HAL_UART_Transmit(&UART_HandInit,"单次定时器发送：",16,1000);
	while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	if(Timer1_Count>=0&&Timer1_Count<=9){
		HAL_UART_Transmit(&UART_HandInit,str,1,1000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	}else
	if(Timer1_Count>=10&&Timer1_Count<=99){
		HAL_UART_Transmit(&UART_HandInit,str,2,1000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	}else
	if(Timer1_Count>=100&&Timer1_Count<=999){
		HAL_UART_Transmit(&UART_HandInit,str,3,1000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	}
	HAL_UART_Transmit(&UART_HandInit,"\r\n",4,1000);
	while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
}

void Timer2CallbackFunction( TimerHandle_t xTimer ){
	Timer2_Count++;
	sprintf(str,"%u",Timer2_Count);
	HAL_UART_Transmit(&UART_HandInit,"周期定时器发送：",16,1000);
	while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	if(Timer2_Count>=0&&Timer2_Count<=9){
		HAL_UART_Transmit(&UART_HandInit,str,1,1000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	}else
	if(Timer2_Count>=10&&Timer2_Count<=99){
		HAL_UART_Transmit(&UART_HandInit,str,2,1000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	}else
	if(Timer2_Count>=100&&Timer2_Count<=999){
		HAL_UART_Transmit(&UART_HandInit,str,3,1000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	}
	HAL_UART_Transmit(&UART_HandInit,"\r\n",4,1000);
	while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
}

/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void FreeRtos_Init(void){
	taskENTER_CRITICAL();//进入临界区
	Time_OneShot = xTimerCreate("OneShotTime",100,pdFALSE,(void*)1,Timer1CallbackFunction);	/*10ms*/
	if(Time_OneShot!=NULL){
		HAL_UART_Transmit(&UART_HandInit,"单次定时器创建成功\r\n",22,1000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	}
	Time_Cycle = xTimerCreate("CycleTime",100,pdTRUE,(void*)2,Timer2CallbackFunction);	/*10ms*/
	if(Time_Cycle!=NULL){
		HAL_UART_Transmit(&UART_HandInit,"周期定时器创建成功\r\n",22,1000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	}
	xTaskCreate(
				(TaskFunction_t			) 	EntryTask1,
				(char *					) 	"Task1",
				(configSTACK_DEPTH_TYPE )   Task1_STACK_SIZE,
				(void *					)	NULL,
				(UBaseType_t			)   Task1_PRIO,
				(TaskHandle_t*			)   &Task1Handle
						  );
				
//	xTaskCreate(
//				(TaskFunction_t			) 	EntryTask2,
//				(char *					) 	"Task2",
//				(configSTACK_DEPTH_TYPE )   Task2_STACK_SIZE,
//				(void *					)	NULL,
//				(UBaseType_t			)   Task2_PRIO,
//				(TaskHandle_t*			)   &Task2Handle
//						  );
//	xTaskCreate(
//				(TaskFunction_t			) 	EntryTask3,
//				(char *					) 	"Task3",
//				(configSTACK_DEPTH_TYPE )   Task3_STACK_SIZE,
//				(void *					)	NULL,
//				(UBaseType_t			)   Task3_PRIO,
//				(TaskHandle_t*			)   &Task3Handle
//						  );
	taskEXIT_CRITICAL();//退出临界区
	vTaskStartScheduler();
	
}

void StartDefaultTask(void const * argument)
{
  
  for(;;)
  {
    osDelay(1);
  }
  
}


void EntryTask1(void const * argument)
{
	BaseType_t Timer_State=0;
	while(1)
	{
		if(KEY1_Flage==1){												/*按键1按下时启动单次定时器*/
			Timer_State = xTimerStart(Time_OneShot,portMAX_DELAY);
			if(Timer_State==pdPASS){
				taskENTER_CRITICAL();//进入临界区
				HAL_UART_Transmit(&UART_HandInit,"单次定时器启动成功\r\n",22,100);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
				taskEXIT_CRITICAL();//退出临界区
				Timer_State=0;
			}
			KEY1_Flage=0;
		}	
		if(KEY2_Flage==1){												/*按键2按下时启动周期定时器*/
			Timer_State = xTimerStart(Time_Cycle,portMAX_DELAY);
			if(Timer_State==pdPASS){
				taskENTER_CRITICAL();//进入临界区
				HAL_UART_Transmit(&UART_HandInit,"周期定时器启动成功\r\n",22,1000);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
				taskEXIT_CRITICAL();//退出临界区
				Timer_State=0;
			}
			KEY2_Flage=0;
		}
		if(KEY3_Flage==1){												/*按键3按下时关闭周期定时器*/
			Timer_State = xTimerStop(Time_Cycle,portMAX_DELAY);
			if(Timer_State==pdPASS){
				taskENTER_CRITICAL();//进入临界区
				HAL_UART_Transmit(&UART_HandInit,"周期定时器关闭成功\r\n",22,1000);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
				taskEXIT_CRITICAL();//退出临界区
				Timer_State=0;
			}
			KEY3_Flage=0;
		}
		osDelay(10);
	}
}

void EntryTask2(void const * argument)
{
	while(1)
	{
		
		osDelay(10);
	}
}

//void EntryTask3(void const * argument)
//{
//	
//	while(1)
//	{
//		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_3);
//		osDelay(1000);
//	}
//  
//}
