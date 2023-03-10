/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#define LED_Pin GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#define Lora_MD0_Pin GPIO_PIN_0
#define Lora_MD0_GPIO_Port GPIOA
#define Lora_AUX_Pin GPIO_PIN_1
#define Lora_AUX_GPIO_Port GPIOA
#define Lora_TX_Pin GPIO_PIN_2
#define Lora_TX_GPIO_Port GPIOA
#define Lora_RX_Pin GPIO_PIN_3
#define Lora_RX_GPIO_Port GPIOA
#define DQ_Pin GPIO_PIN_4
#define DQ_GPIO_Port GPIOA
#define Beep_Pin GPIO_PIN_0
#define Beep_GPIO_Port GPIOB
#define Relay_Pin GPIO_PIN_1
#define Relay_GPIO_Port GPIOB
#define FS_Pin GPIO_PIN_13
#define FS_GPIO_Port GPIOB
#define SR_Pin GPIO_PIN_14
#define SR_GPIO_Port GPIOB
#define ZP_Pin GPIO_PIN_15
#define ZP_GPIO_Port GPIOB
#define Debug_TX_Pin GPIO_PIN_9
#define Debug_TX_GPIO_Port GPIOA
#define Debug_RX_Pin GPIO_PIN_10
#define Debug_RX_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */
//#define USING_DS18B20
//#define USING_FLAMESENSOR
#define USING_HCSR501
//#define USING_ZP13
//#define USING_LORA

//#define USING_RELAY
//#define USING_BEEP
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
