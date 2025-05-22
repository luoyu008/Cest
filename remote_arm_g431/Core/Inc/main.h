/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
typedef struct {
	int8_t ret;
	uint8_t i2c_error;
	uint8_t ch[25];
	uint8_t TxData[6];
}MAIN_Data;
typedef struct {
	int16_t x;
	int16_t y;
	int16_t z;
	float pitch;
	float roll;
	float yaw;
	float reset_pitch;
	float reset_roll;
	float reset_yaw;
	float pitch_all;
	float roll_all;
	float yaw_all;
	float pitch_real;
	float roll_real;
	float yaw_real;
	uint8_t count;
}MPU6050_Data;
typedef struct{
	int16_t angle_pitch;
	int16_t angle_roll;
	int16_t angle_yaw;
	int16_t pre_pitch;
	int16_t pre_roll;
	int16_t pre_yaw;
}ANGLE_Data;
typedef struct{
	FDCAN_HandleTypeDef* hfdcan;
	FDCAN_TxHeaderTypeDef hfdcantx;
	uint8_t ch[6];
}FDCAN_TX;
typedef struct{
	FDCAN_HandleTypeDef* hfdcan;
	FDCAN_RxHeaderTypeDef hfdcanrx;
	uint8_t ch[6];
}FDCAN_RX;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
