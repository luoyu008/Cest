#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"
#include "USART.h"
#include "KEY.h"
#include "EXIT.h"

osThreadId defaultTaskHandle;
osThreadId LEDTask1Handle;
osThreadId LEDTask2Handle;
osThreadId Task3Handle;

#define LEDTask1_STACK_SIZE 128
#define LEDTask1_PRIO       1

#define LEDTask2_STACK_SIZE 128
#define LEDTask2_PRIO       2

#define Task3_STACK_SIZE 128
#define Task3_PRIO       31

void StartDefaultTask(void const * argument);
void LEDEntryTask1(void const * argument);
void LEDEntryTask2(void const * argument);
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
//	taskENTER_CRITICAL();//进入临界区
	xTaskCreate(
				(TaskFunction_t			) 	LEDEntryTask1,
				(char *					) 	"LEDTask1",
				(configSTACK_DEPTH_TYPE )   LEDTask1_STACK_SIZE,
				(void *					)	NULL,
				(UBaseType_t			)   LEDTask1_PRIO,
				(TaskHandle_t*			)   &LEDTask1Handle
						  );
	xTaskCreate(
				(TaskFunction_t			) 	LEDEntryTask2,
				(char *					) 	"LEDTask2",
				(configSTACK_DEPTH_TYPE )   LEDTask2_STACK_SIZE,
				(void *					)	NULL,
				(UBaseType_t			)   LEDTask2_PRIO,
				(TaskHandle_t*			)   &LEDTask2Handle
						  );
	xTaskCreate(
				(TaskFunction_t			) 	EntryTask3,
				(char *					) 	"Task3",
				(configSTACK_DEPTH_TYPE )   Task3_STACK_SIZE,
				(void *					)	NULL,
				(UBaseType_t			)   Task3_PRIO,
				(TaskHandle_t*			)   &Task3Handle
						  );
//	taskEXIT_CRITICAL();//退出临界区
	vTaskStartScheduler();
	
}

void StartDefaultTask(void const * argument)
{
  
  for(;;)
  {
    osDelay(1);
  }
  
}


void LEDEntryTask1(void const * argument)
{
  
  while(1)
  {
	HAL_UART_Transmit(&UART_HandInit,"task1 running\r\n",15,1000);
	while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_4);
    osDelay(500);
  }
  
}

void LEDEntryTask2(void const * argument)
{
  
  while(1)
  {
	HAL_UART_Transmit(&UART_HandInit,"task2 running\r\n",15,1000);
	while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_3);
    osDelay(500);
  }
  
}

void EntryTask3(void const * argument)
{
  
  while(1)
  {
//	HAL_UART_Transmit(&UART_HandInit,(uint8_t*)LEDTask1Handle,15,1000);
//	while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	HAL_UART_Transmit(&UART_HandInit,"task3 running\r\n",15,1000);
	while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
	if(KEY_Flage==1){
		if(LEDTask1Handle!=NULL){
			HAL_UART_Transmit(&UART_HandInit,"DELETE TASK1\r\n",14,1000);
			while(__HAL_UART_GET_FLAG(&UART_HandInit,UART_FLAG_TC)!=1);
			vTaskDelete(LEDTask1Handle);
			LEDTask1Handle=NULL;
		}
		KEY_Flage=0;
	}
//	  vTaskDelete(NULL);
    osDelay(500);
  }
  
}
