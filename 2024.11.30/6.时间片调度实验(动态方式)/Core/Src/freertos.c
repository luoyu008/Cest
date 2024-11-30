#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include "USART.h"
#include "KEY.h"
#include "EXIT.h"
#include "DELAY.h"
#include "OLED.h"
#include <stdio.h>
osThreadId defaultTaskHandle;
osThreadId Task1Handle;
osThreadId Task2Handle;
osThreadId Task3Handle;

#define Task1_STACK_SIZE 128
#define Task1_PRIO       1

#define Task2_STACK_SIZE 128
#define Task2_PRIO       2

//#define Task3_STACK_SIZE 128
//#define Task3_PRIO       31

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
	uint8_t count=0;
	char str[5];
	while(1)
	{
		count++;
		taskENTER_CRITICAL();//进入临界区
		sprintf(str,"%d",count);
		HAL_UART_Transmit(&UART_HandInit,"Task1:",7,10);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		HAL_UART_Transmit(&UART_HandInit,(uint8_t *)str,3,10);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		HAL_UART_Transmit(&UART_HandInit,"\r\n",2,10);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		taskEXIT_CRITICAL();//退出临界区
		for (volatile uint32_t i = 0; i < 10000; i++);  //实现延时事件10ms
	}
  
}

void EntryTask2(void const * argument)
{
	uint8_t count=0;
	char str[5];
	while(1)
	{
		count++;
		taskENTER_CRITICAL();//进入临界区
		sprintf(str,"%d",count);
		HAL_UART_Transmit(&UART_HandInit,"Task2:",7,10);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		HAL_UART_Transmit(&UART_HandInit,(uint8_t *)str,3,10);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		HAL_UART_Transmit(&UART_HandInit,"\r\n",2,10);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		taskEXIT_CRITICAL();//退出临界区
//		for (volatile uint32_t i = 0; i < 10000; i++);  //实现延时事件10ms
//		osDelay(10);
	}
  
}

//void EntryTask3(void const * argument)
//{
//  
//  while(1)
//  {
//	HAL_UART_Transmit(&UART_HandInit,"task3 running\r\n",15,1000);
//	while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
//	if(KEY1_Flage==1){
//			HAL_UART_Transmit(&UART_HandInit,"Task1 Suspend\r\n",15,1000);
//			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
//			vTaskSuspend(LEDTask1Handle);
//			KEY1_Flage=0;
//	}
//	if(KEY3_Flage==1){
//			HAL_UART_Transmit(&UART_HandInit,"Task1 Recover\r\n",15,1000);
//			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
//			vTaskResume(LEDTask1Handle);
//			KEY3_Flage=0;
//	}
//	eTaskState TaskState = eTaskGetState(LEDTask1Handle);
//	switch(TaskState){
//		case 0: 
//		HAL_UART_Transmit(&UART_HandInit,"Task1 eRunning\r\n",16,1000);
//		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);	
//		break;
//		case 1: 
//		HAL_UART_Transmit(&UART_HandInit,"Task1 eReady\r\n",14,1000);
//		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);		
//		break;
//		case 2: 
//		HAL_UART_Transmit(&UART_HandInit,"Task1 eBlocked\r\n",16,1000);
//		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);		
//		break;
//		case 3: 
//		HAL_UART_Transmit(&UART_HandInit,"Task1 eSuspended\r\n",18,1000);
//		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);		
//		break;
//		case 4: 
//		HAL_UART_Transmit(&UART_HandInit,"Task1 eDeleted\r\n",16,1000);
//		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);		
//		break;
//		case 5: 
//		HAL_UART_Transmit(&UART_HandInit,"Task1 eInvalid\r\n",16,1000);
//		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);		
//		break;
//	}
//    osDelay(500);
//  }
//  
//}
