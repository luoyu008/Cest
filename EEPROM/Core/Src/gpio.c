/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	
	
	GPIO_InitTypeDef GPIO_Init;
	GPIO_Init.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pin=GPIO_PIN_2;
	GPIO_Init.Pull=GPIO_NOPULL;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOD,&GPIO_Init);
	
	GPIO_Init.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pin=GPIO_PIN_8;
	GPIO_Init.Pull=GPIO_NOPULL;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC,&GPIO_Init);

	GPIO_Init.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pin=GPIO_PIN_9;
	GPIO_Init.Pull=GPIO_NOPULL;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC,&GPIO_Init);
	
	GPIO_Init.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pin=GPIO_PIN_10;
	GPIO_Init.Pull=GPIO_NOPULL;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC,&GPIO_Init);
	
	GPIO_Init.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pin=GPIO_PIN_11;
	GPIO_Init.Pull=GPIO_NOPULL;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC,&GPIO_Init);
	
	GPIO_Init.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pin=GPIO_PIN_12;
	GPIO_Init.Pull=GPIO_NOPULL;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC,&GPIO_Init);
	
	GPIO_Init.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pin=GPIO_PIN_13;
	GPIO_Init.Pull=GPIO_NOPULL;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC,&GPIO_Init);
	
	GPIO_Init.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pin=GPIO_PIN_14;
	GPIO_Init.Pull=GPIO_NOPULL;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC,&GPIO_Init);
	
	GPIO_Init.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pin=GPIO_PIN_15;
	GPIO_Init.Pull=GPIO_NOPULL;
	GPIO_Init.Speed=GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOC,&GPIO_Init);
	
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15|GPIO_PIN_8 
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOD, GPIO_PIN_2, GPIO_PIN_RESET);
}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
