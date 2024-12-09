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

SemaphoreHandle_t BinSemaphore_Test;

#define Task1_STACK_SIZE 128
#define Task1_PRIO       1

#define Task2_STACK_SIZE 120
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


void* Memory_FirstAddress[10]=0;
uint8_t i=0;
uint8_t j=0;
uint8_t Count=0;
void EntryTask1(void const * argument)
{
	
	size_t Memory_Remain=0;
	char str[50]=0;
	while(1)
	{
//		Count++;
		if(KEY1_Flage==1){											/*按键一按下时申请内存*/
			Memory_FirstAddress[i] = pvPortMalloc(20);					/*申请20字节大小的内存*/
			if(Memory_FirstAddress[i]!=0){
				HAL_UART_Transmit(&UART_HandInit,"内存申请成功\r\n",16,2000);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			}
			i++;
			if(i>=10){
				i=0;
			}
			HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_4);
			KEY1_Flage=0;
		}
		if(KEY2_Flage==1){											/*按键三按下时先释放内存然后获取剩余内存大小*/	
			if(Memory_FirstAddress[j]!=0){								/*如果内存申请过则释放内存*/
				vPortFree(Memory_FirstAddress[j]);
				HAL_UART_Transmit(&UART_HandInit,"内存释放成功\r\n",16,2000);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
				Memory_FirstAddress[j]=0;
				j++;
				if(j>=10){
					j=0;
				}
			}
			HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_3);
			KEY2_Flage=0;
		}
//		if(Count>=100){
			Memory_Remain = xPortGetFreeHeapSize();					/*获取空闲内存的大小*/
			sprintf(str,"%u",Memory_Remain);
			HAL_UART_Transmit(&UART_HandInit,"剩余内存大小：",14,200);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			HAL_UART_Transmit(&UART_HandInit,str,5,200);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			HAL_UART_Transmit(&UART_HandInit,"\r\n",4,200);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			Count=0;
//		}
		osDelay(1000);
	}
  
}

//void EntryTask2(void const * argument)
//{
//	BaseType_t Semaphore_Flage=0;
//	while(1)
//	{
//		Semaphore_Flage = xSemaphoreTake(BinSemaphore_Test,portMAX_DELAY);	/*查询信号量*/
//		if(Semaphore_Flage==pdTRUE){
//			HAL_UART_Transmit(&UART_HandInit,"查询信号量成功\r\n",18,2000);
//			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
//			HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_3);
//		}
//	}
//  
//}

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
