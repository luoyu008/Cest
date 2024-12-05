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
char str[100]="�����ĵ�������  454 sadw";

EventGroupHandle_t EventGroup_Test;

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
	Ϊ���������ṩ�ڴ�
*/
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}

/* ��ʱ�����������ջ */
static StackType_t TimerTaskStack[configTIMER_TASK_STACK_DEPTH];
/* ��ʱ������������ƿ� */
static StaticTask_t TimerTaskTCB;
void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer,StackType_t **ppxTimerTaskStackBuffer,uint32_t *pulTimerTaskStackSize)
{
*ppxTimerTaskTCBBuffer = &TimerTaskTCB;
*ppxTimerTaskStackBuffer = TimerTaskStack;
*pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void FreeRtos_Init(void){
	taskENTER_CRITICAL();//�����ٽ���
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
	taskEXIT_CRITICAL();//�˳��ٽ���
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
	uint32_t Previous_Noti=0;
	while(1)
	{
		if(KEY1_Flage==1){												/*����1����ʱ���Ͷ�ֵ�ź�֪ͨ*/
			xTaskNotifyAndQuery(Task2Handle,0x01,eSetBits,&Previous_Noti);
			KEY1_Flage=0;
		}else	
		if(KEY2_Flage==1){												/*����2����ʱ���ͼ������ź�֪ͨ*/
			xTaskNotifyAndQuery(Task2Handle,NULL,eIncrement,&Previous_Noti);
			KEY2_Flage=0;
		}else
		osDelay(10);
	}
}

void EntryTask2(void const * argument)
{
	uint32_t PreData=0;
	char str[50];
	while(1)
	{
		xTaskNotifyWait((1<<10),(1<<10),&PreData,portMAX_DELAY);
		HAL_UART_Transmit(&UART_HandInit,"�������ź�֪ͨ��ȡ�ɹ�",22,2000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		sprintf(str,"%u",PreData);
		if(PreData>=0&&PreData<=9){
			HAL_UART_Transmit(&UART_HandInit,str,1,2000);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		}else
		if(PreData>=10&&PreData<=99){
			HAL_UART_Transmit(&UART_HandInit,str,2,2000);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		}
		if(PreData>=100&&PreData<=999){
			HAL_UART_Transmit(&UART_HandInit,str,3,2000);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		}
		HAL_UART_Transmit(&UART_HandInit,"\r\n",4,2000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
//		ulTaskNotifyTake(pdTRUE,portMAX_DELAY);
//		HAL_UART_Transmit(&UART_HandInit,"��ֵ�ź�֪ͨ��ȡ�ɹ�\r\n",24,2000);
//		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
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
