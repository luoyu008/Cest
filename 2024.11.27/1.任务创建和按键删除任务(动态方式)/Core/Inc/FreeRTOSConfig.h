/* USER CODE BEGIN Header */
/*
 * FreeRTOS Kernel V10.0.1
 * Copyright (C) 2017 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */
/* USER CODE END Header */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * These parameters and more are described within the 'configuration' section of the
 * FreeRTOS API documentation available on the FreeRTOS.org web site.
 *
 * See http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/

/* USER CODE BEGIN Includes */
/* Section where include file can be added */
/* USER CODE END Includes */

/* Ensure definitions are only used by the compiler, and not by the assembler. */
#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
  #include <stdint.h>
  extern uint32_t SystemCoreClock;
#endif
#define configUSE_PREEMPTION                     1						/*1：抢占式调度器 0：协程式调度器 无默认需定义 */
#define configSUPPORT_STATIC_ALLOCATION          1						/*1：支持静态内存申请 0：不支持*/
#define configSUPPORT_DYNAMIC_ALLOCATION         1						/*1：支持动态内存申请 0：不支持*/
#define configUSE_IDLE_HOOK                      0						/*1：使能使用空闲任务的钩子函数(回调函数) 用户需要自定义相关钩子函数 0：不使能使用空闲任务的钩子函数*/
#define configUSE_TICK_HOOK                      0						/*1：使能使用系统时钟节拍中断钩子函数 用户需自定义相关函数 0：不使能*/
#define configCPU_CLOCK_HZ                       ( SystemCoreClock )	/*定义CPU主频 单位：HZ */
#define configTICK_RATE_HZ                       ((TickType_t)1000)		/*定义系统时钟节拍频率 单位：HZ 	无默认需定义*/
#define configMAX_PRIORITIES                     ( 32 )					/*定义最大优先级数 最大优先级=configMAX_PRIORITIES-1 无默认需定义*/
#define configMINIMAL_STACK_SIZE                 ((uint16_t)128)		/*定义空闲任务的栈空间大小 单位：Word 无默认需定义*/
#define configTOTAL_HEAP_SIZE                    ((size_t)(7*1024))		/*FREERTOS中可使用的堆的RAM总量 动态分配时*/
#define configMAX_TASK_NAME_LEN                  ( 16 )					/*定义任务名最大字符数 默认16*/
#define configUSE_16_BIT_TICKS                   0						/*1：系统节拍计数器的数据类型为16位无符号整型 0：系统节拍计数器的数据类型为32位无符号整型*/
#define configUSE_MUTEXES                        1
#define configQUEUE_REGISTRY_SIZE                8
#define configUSE_PORT_OPTIMISED_TASK_SELECTION  1						/*1：使用硬件计算下一个要运行的任务 0：使用软件算法计算下一个要运行的任务 */

/* Co-routine definitions. */
#define configUSE_CO_ROUTINES                    0
#define configMAX_CO_ROUTINE_PRIORITIES          ( 2 )

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */
#define INCLUDE_vTaskPrioritySet            1							/*1：使能设置任务优先级*/
#define INCLUDE_uxTaskPriorityGet           1							/*1：使能获取任务优先级*/
#define INCLUDE_vTaskDelete                 1							/*1：使能删除任务*/
#define INCLUDE_vTaskCleanUpResources       0							
#define INCLUDE_vTaskSuspend                1							/*1：使能挂起任务*/
#define INCLUDE_vTaskDelayUntil             0							/*1：使能任务绝对延时*/
#define INCLUDE_vTaskDelay                  1							/*1：使能任务延时*/
#define INCLUDE_xTaskGetSchedulerState      1							/*1：使能获取任务调度器状态*/

/* Cortex-M specific definitions. */
#ifdef __NVIC_PRIO_BITS
 /* __BVIC_PRIO_BITS will be specified when CMSIS is being used. */
 #define configPRIO_BITS         __NVIC_PRIO_BITS
#else
 #define configPRIO_BITS         4
#endif

/* The lowest interrupt priority that can be used in a call to a "set priority"
function. */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY   15

/* The highest interrupt priority that can be used by any interrupt service
routine that makes calls to interrupt safe FreeRTOS API functions.  DO NOT CALL
INTERRUPT SAFE FREERTOS API FUNCTIONS FROM ANY INTERRUPT THAT HAS A HIGHER
PRIORITY THAN THIS! (higher priorities are lower numeric values. */
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 5

/* Interrupt priorities used by the kernel port layer itself.  These are generic
to all Cortex-M ports, and do not rely on any particular library functions. */
#define configKERNEL_INTERRUPT_PRIORITY 		( configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )
/* !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	( configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS) )

/* Normal assert() semantics without relying on the provision of an assert.h
header file. */
/* USER CODE BEGIN 1 */
#define configASSERT( x ) if ((x) == 0) {taskDISABLE_INTERRUPTS(); for( ;; );}
/* USER CODE END 1 */

/* Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
standard names. */
#define vPortSVCHandler    SVC_Handler
#define xPortPendSVHandler PendSV_Handler

/* IMPORTANT: This define is commented when used with STM32Cube firmware, when the timebase source is SysTick,
              to prevent overwriting SysTick_Handler defined within STM32Cube HAL */

#define xPortSysTickHandler SysTick_Handler

/* USER CODE BEGIN Defines */
/* Section where parameter definitions can be added (for instance, to override default ones in FreeRTOS.h) */
/* USER CODE END Defines */

#endif /* FREERTOS_CONFIG_H */
