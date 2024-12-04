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

QueueHandle_t KEY_Queue;
QueueHandle_t Big_Data_Queue;
uint8_t arr=0;
char str[100]="哇塞的低洼撒旦  454 sadw";

QueueHandle_t CountSemaphore_Test;

#define Task1_STACK_SIZE 128
#define Task1_PRIO       1

#define Task2_STACK_SIZE 128
#define Task2_PRIO       2

#define Task3_STACK_SIZE 128
#define Task3_PRIO       3

List_t		Test_List;
ListItem_t	Test_ListItem1;
ListItem_t	Test_ListItem2;
ListItem_t	Test_ListItem3;

uint8_t add;

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
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void FreeRtos_Init(void){
	taskENTER_CRITICAL();//进入临界区
	CountSemaphore_Test = xSemaphoreCreateCounting(100,100);				/*创建二值信号量*/
	if(CountSemaphore_Test!=NULL){
		HAL_UART_Transmit(&UART_HandInit,"计数型信号量创建成功\r\n",24,2000);
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
				
	xTaskCreate(
				(TaskFunction_t			) 	EntryTask2,
				(char *					) 	"Task2",
				(configSTACK_DEPTH_TYPE )   Task2_STACK_SIZE,
				(void *					)	NULL,
				(UBaseType_t			)   Task2_PRIO,
				(TaskHandle_t*			)   &Task2Handle
						  );
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
	BaseType_t Semaphore_Flage=0;
	while(1)
	{
		if(KEY3_Flage==1){
			Semaphore_Flage = xSemaphoreGive(CountSemaphore_Test);			/*释放信号量*/
			if(Semaphore_Flage==pdPASS){
				HAL_UART_Transmit(&UART_HandInit,"释放信号量成功\r\n",18,2000);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			}
			HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_4);
			KEY3_Flage=0;
		}
		osDelay(10);
	}
  
}

void EntryTask2(void const * argument)
{
	BaseType_t Semaphore_Flage=0;
	UBaseType_t Count=0;
	char str[50];
	while(1)
	{
		Semaphore_Flage = xSemaphoreTake(CountSemaphore_Test,portMAX_DELAY);	/*查询信号量*/
		if(Semaphore_Flage==pdTRUE){
			HAL_UART_Transmit(&UART_HandInit,"查询信号量成功:",15,2000);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			Count = uxSemaphoreGetCount(CountSemaphore_Test);
			sprintf(str,"%lu",Count);
			if(Count<=99&&Count>=10){
				HAL_UART_Transmit(&UART_HandInit,str,2,2000);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			}
			if(Count>=0&&Count<=9){
				HAL_UART_Transmit(&UART_HandInit,str,1,2000);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			}
			HAL_UART_Transmit(&UART_HandInit,"\r\n",4,2000);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_3);
		}
		osDelay(1000);
	}
}

//void EntryTask3(void const * argument)
//{
//	char* buf;
//	BaseType_t Receive_State=0;
//	while(1)
//	{
//		Receive_State=xQueueReceive(Big_Data_Queue,&buf,portMAX_DELAY);
//		if(Receive_State==pdTRUE){
//			HAL_UART_Transmit(&UART_HandInit,(uint8_t *)buf,100,2000);
//			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
//		}
////		osDelay(500);
//	}
//  
//}
