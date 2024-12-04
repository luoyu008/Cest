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

QueueSetHandle_t	SetQueue_Test;
QueueHandle_t	Queue_Test;
QueueHandle_t	BinSemaphore_Test;
QueueHandle_t	CountSemaphore_Test;
QueueHandle_t MutexSemaphore_Test;

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
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void FreeRtos_Init(void){
	taskENTER_CRITICAL();//�����ٽ���
	BaseType_t SetState=0;
	SetQueue_Test = xQueueCreateSet(4);							/*�������м�*/
	if(SetQueue_Test!=NULL){
		HAL_UART_Transmit(&UART_HandInit,"���м������ɹ�\r\n",18,2000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	}
	Queue_Test = xQueueCreate(3,sizeof(uint8_t));				/*��������*/
	if(Queue_Test!=NULL){
		HAL_UART_Transmit(&UART_HandInit,"���д����ɹ�\r\n",16,2000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	}
	BinSemaphore_Test = xSemaphoreCreateBinary();					/*������ֵ�ź���*/
	if(BinSemaphore_Test!=NULL){
		HAL_UART_Transmit(&UART_HandInit,"��ֵ�ź��������ɹ�\r\n",22,2000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	}
	CountSemaphore_Test = xSemaphoreCreateCounting(100,0);		/*�����������ź���*/
	if(CountSemaphore_Test!=NULL){
		HAL_UART_Transmit(&UART_HandInit,"�������ź��������ɹ�\r\n",24,2000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	}
	MutexSemaphore_Test = xSemaphoreCreateMutex();				/*���������ź���*/
	if(MutexSemaphore_Test!=NULL){
		HAL_UART_Transmit(&UART_HandInit,"�����ź��������ɹ�\r\n",24,2000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		xSemaphoreTake(MutexSemaphore_Test,portMAX_DELAY);	/*��ѯ�ź��� ���ڴ���ʱ���Զ��ͷ�һ���ź���������Ҫ�Ȳ�ѯ�����*/
	}
	SetState = xQueueAddToSet(Queue_Test,SetQueue_Test);		/*��Ӷ��е����м�*/
	if(SetState==pdPASS){
		HAL_UART_Transmit(&UART_HandInit,"�������������м�\r\n",22,2000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	}
	SetState = xQueueAddToSet(BinSemaphore_Test,SetQueue_Test);	/*��Ӷ�ֵ�ź��������м�*/
	if(SetState==pdPASS){
		HAL_UART_Transmit(&UART_HandInit,"��ֵ�ź������������м�\r\n",28,2000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	}
	SetState = xQueueAddToSet(CountSemaphore_Test,SetQueue_Test);/*��Ӽ������ź��������м�*/
	if(SetState==pdPASS){
		HAL_UART_Transmit(&UART_HandInit,"�������ź������������м�\r\n",30,2000);
		while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	}
	SetState = xQueueAddToSet(MutexSemaphore_Test,SetQueue_Test);/*��ӻ����ź��������м�*/
	if(SetState==pdPASS){
		HAL_UART_Transmit(&UART_HandInit,"�����ź������������м�\r\n",28,2000);
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
	BaseType_t Send_State=0;
	while(1)
	{
		if(KEY1_Flage==1){					/*�ͷż������ź���*/
			Send_State=xSemaphoreGive(CountSemaphore_Test);
			if(Send_State==pdTRUE){
			HAL_UART_Transmit(&UART_HandInit,"�������ź����ͷųɹ�\r\n",24,2000);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			KEY1_Flage=0;
			}
		}
		if(KEY2_Flage==1){				/*�������������*/
			arr++;
			Send_State=xQueueSend(Queue_Test,&arr,portMAX_DELAY);
			if(Send_State==pdTRUE){
			HAL_UART_Transmit(&UART_HandInit,"������ӳɹ�\r\n",16,2000);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			KEY2_Flage=0;
			}
		}
		if(KEY3_Flage==1){					/*�ͷŶ�ֵ�ź���*/
			Send_State=xSemaphoreGive(BinSemaphore_Test);
			if(Send_State==pdTRUE){
			HAL_UART_Transmit(&UART_HandInit,"��ֵ�ź����ͷųɹ�\r\n",22,2000);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			KEY3_Flage=0;
			}
		}
		osDelay(10);
	}
}

void EntryTask2(void const * argument)
{
	QueueSetMemberHandle_t Receive_Set;
	UBaseType_t	Count=0;
	char str[50];
	uint8_t Receive_Data=0;
	BaseType_t Queue_Flage=0;
	BaseType_t Bin_Flage=0;
	while(1)
	{
		Receive_Set = xQueueSelectFromSet(SetQueue_Test,portMAX_DELAY);		/*��ѯ���м�����Ϣ*/
		if(Receive_Set==CountSemaphore_Test){
			HAL_UART_Transmit(&UART_HandInit,"�������ź�����ѯ�ɹ�",20,2000);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			Count = uxSemaphoreGetCount(CountSemaphore_Test);
			sprintf(str,"%lu",Count);
			if(Count>=0&&Count<=9){
				HAL_UART_Transmit(&UART_HandInit,str,1,2000);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			}
			if(Count>=10&&Count<=99){
				HAL_UART_Transmit(&UART_HandInit,str,2,2000);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			}
			HAL_UART_Transmit(&UART_HandInit,"\r\n",4,2000);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
		}
		if(Receive_Set==Queue_Test){										/*���ն�������*/
			Queue_Flage = xQueueReceive(Queue_Test,&Receive_Data,portMAX_DELAY);
			if(Queue_Flage==pdTRUE){
			sprintf(str,"%u",Receive_Data);
			HAL_UART_Transmit(&UART_HandInit,"�������ݽ��ճɹ�",16,2000);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			if(arr>=0&&arr<=9){
				HAL_UART_Transmit(&UART_HandInit,str,1,2000);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			}
			if(arr>=10&&arr<=99){
				HAL_UART_Transmit(&UART_HandInit,str,2,2000);
				while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			}
			HAL_UART_Transmit(&UART_HandInit,"\r\n",4,2000);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			}
		}
		if(Receive_Set==BinSemaphore_Test){									/*��ѯ��ֵ�ź���*/
			Bin_Flage = xSemaphoreTake(BinSemaphore_Test,portMAX_DELAY);
			if(Bin_Flage==pdTRUE){
			HAL_UART_Transmit(&UART_HandInit,"��ֵ�ź�����ѯ�ɹ�\r\n",22,2000);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			}
		}
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
