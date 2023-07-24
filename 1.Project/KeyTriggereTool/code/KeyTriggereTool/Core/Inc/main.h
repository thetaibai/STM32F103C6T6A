/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

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
#define Led_Pin GPIO_PIN_13
#define Led_GPIO_Port GPIOC
#define Key7_Pin GPIO_PIN_5
#define Key7_GPIO_Port GPIOA
#define Key7_EXTI_IRQn EXTI9_5_IRQn
#define Key6_Pin GPIO_PIN_6
#define Key6_GPIO_Port GPIOA
#define Key6_EXTI_IRQn EXTI9_5_IRQn
#define Key5_Pin GPIO_PIN_7
#define Key5_GPIO_Port GPIOA
#define Key5_EXTI_IRQn EXTI9_5_IRQn
#define Key4_Pin GPIO_PIN_0
#define Key4_GPIO_Port GPIOB
#define Key4_EXTI_IRQn EXTI0_IRQn
#define Key3_Pin GPIO_PIN_1
#define Key3_GPIO_Port GPIOB
#define Key3_EXTI_IRQn EXTI1_IRQn
#define Key2_Pin GPIO_PIN_10
#define Key2_GPIO_Port GPIOB
#define Key2_EXTI_IRQn EXTI15_10_IRQn
#define Key1_Pin GPIO_PIN_11
#define Key1_GPIO_Port GPIOB
#define Key1_EXTI_IRQn EXTI15_10_IRQn

/* USER CODE BEGIN Private defines */
#define TRUE    1
#define FALSE   0
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
