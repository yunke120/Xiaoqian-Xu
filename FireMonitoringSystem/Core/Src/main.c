/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "bsp_ds18b20.h"
#include "bsp_flamesensor.h"
#include "bsp_hcsr501.h"
#include "bsp_zp13.h"
#include "bsp_lora.h"
#include "bsp_relay.h"
#include "bsp_beep.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/*
   8 7 6 5 4 3 2 1 0
  TmpH TmpL 14 01 00

*/

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	uint32_t cnt = 0;
	uint8_t people;
	uint8_t smoke = 0;
	int ret = 1;
	uint16_t temp = 0;
	uint8_t tmpH,tmpL;;
	uint8_t LORA_SENDBUF[LORA_SENDBUF_LEN];
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  //MX_ADC1_Init();
  /* USER CODE BEGIN 2 */
#ifdef USING_DS18B20
		ret = 1;
	  while(ret)
	  {
		  ret = DS18B20_Init();
		  HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
		  HAL_Delay(200);
	  }
	  printf("DS18B20 Init Success!\r\n");
#endif
	  
#ifdef USING_LORA
	  ret = 1;
	  while(ret)
	  {
		  ret = lora_init();
		  HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
		  HAL_Delay(200);
	  }
	  printf("Lora Init Success!\r\n");
#endif
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
#ifdef USING_DS18B20
	temp = DS18B20_Get_Temp(); /* 获取温度值 */
	tmpH = (temp >> 8) & 0x00FF;
	tmpL = (temp >> 0) & 0x00FF;
	printf("temp = %d\r\n", temp);
#endif
#ifdef USING_HCSR501

	people = exist_people();
	  if(people == 1)
	  {
		  printf("exist people %d\r\n", cnt);
	  }
	  else
	  {
		  printf("not exist people %d\r\n", cnt);
	  }


//	HAL_ADC_Start(&hadc1);         /* 开启ADC转换 */
//	if(HAL_OK == HAL_ADC_PollForConversion(&hadc1, 50)) /* 等待转换完成 */
//	{
//		val = HAL_ADC_GetValue(&hadc1); /* 获取ADC值 */
//	}
//	HAL_ADC_Stop(&hadc1); /* 关闭ADC转换 */
//	  printf("adc = %f\r\n", val/4096.0*3.3);
#endif

#ifdef USING_ZP13
	 
	smoke = exist_smoke();
	if(smoke)
	{
		printf("exist smoke %d\r\n", cnt);
	}
	else
	{
		printf("not exist smoke %d\r\n", cnt);
	}
	  
#endif
	  
#ifdef USING_LORA
	LORA_SENDBUF[0] = 0x00;
	LORA_SENDBUF[1] = MASTER_ADDR;
	LORA_SENDBUF[2] = MASTER_CHANNEL;
	LORA_SENDBUF[3] = tmpH;
	LORA_SENDBUF[4] = tmpL;
	
	lora_send(LORA_SENDBUF, LORA_SENDBUF_LEN);
	
	
#endif
	  
#ifdef USING_RELAY
	open_relay();
	HAL_Delay(1000);
	close_relay();
#endif

#ifdef USING_BEEP
	open_beep();
	HAL_Delay(1000);
	close_beep();
#endif
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	cnt ++;
	  HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
	  HAL_Delay(1000);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
