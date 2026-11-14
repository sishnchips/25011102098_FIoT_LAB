/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "main.h"
#include <string.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "bme280.h"
#include "ESPLib.h"
#include <stdio.h>
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
I2C_HandleTypeDef hi2c1;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
extern I2C_HandleTypeDef hi2c1; // Assumes I2C1 is configured via CubeMX
struct bme280_dev dev;
struct bme280_data comp_data;
int8_t rslt = BME280_OK;
struct bme280_settings settings;
// Variables to store final calculated values
float temperature, pressure, humidity;
/* USER CODE END PV */ 

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);
static void MX_USART2_UART_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */
/* USER CODE BEGIN 4 */
int8_t user_i2c_read(uint8_t reg_addr, uint8_t *reg_data, uint32_t len, void *intf_ptr) {
 // Dev address shifted left by 1 is handled by HAL
 uint8_t dev_addr = *(uint8_t*)intf_ptr;
 if (HAL_I2C_Mem_Read(&hi2c1, (dev_addr << 1), reg_addr, I2C_MEMADD_SIZE_8BIT, reg_data, len,
HAL_MAX_DELAY) == HAL_OK) {
 return BME280_OK;
 }
 return BME280_E_COMM_FAIL;
}
int8_t user_i2c_write(uint8_t reg_addr, const uint8_t *reg_data, uint32_t len, void *intf_ptr) {
 uint8_t dev_addr = *(uint8_t*)intf_ptr;
 if (HAL_I2C_Mem_Write(&hi2c1, (dev_addr << 1), reg_addr, I2C_MEMADD_SIZE_8BIT,
(uint8_t*)reg_data, len, HAL_MAX_DELAY) == HAL_OK) {
 return BME280_OK;
 }
 return BME280_E_COMM_FAIL;
}
void user_delay_us(uint32_t period, void *intf_ptr) {
 // HAL provides millisecond delay; convert microseconds upward
 HAL_Delay((period / 1000) + 1);
}
/* USER CODE END 4 */ 

int main(void) {
 HAL_Init();
 SystemClock_Config();
 MX_GPIO_Init();
 MX_I2C1_Init();
 /* USER CODE BEGIN 2 */
    MX_USART2_UART_Init();

 static uint8_t dev_addr = BME280_I2C_ADDR_PRIM; // 0x76 (use BME280_I2C_ADDR_SEC if SDO is high)

 // Set up the API configuration function pointers
 dev.intf_ptr = &dev_addr;
 dev.intf = BME280_I2C_INTF;
 dev.read = user_i2c_read;
 dev.write = user_i2c_write;
 dev.delay_us = user_delay_us;
 // Initialize the BME280 sensor (This automatically extracts the compensation data)
 rslt = bme280_init(&dev);
 // Configure sensor settings
settings.osr_h = BME280_OVERSAMPLING_1X;
settings.osr_p = BME280_OVERSAMPLING_1X;
settings.osr_t = BME280_OVERSAMPLING_1X;
settings.filter = BME280_FILTER_COEFF_OFF;
 rslt = bme280_set_sensor_settings(
    BME280_SEL_OSR_PRESS | BME280_SEL_OSR_TEMP |
    BME280_SEL_OSR_HUM | BME280_SEL_FILTER,
    &settings,
    &dev
);

 // Set power mode to normal to enable continuous measurement cycles
rslt = bme280_set_sensor_mode(BME280_POWERMODE_NORMAL, &dev);
 
ESP8266_Init(StationMode,huart2);
// 2. Connect to your local Wi-Fi network (Replace with your Router SSID and Password)
ESP8266_wifiConnect("SNUC", "snu12345");
// 3. Connect to your MQTT Broker (Replace with your Broker's IP Address)
// 1883 is the standard unencrypted MQTT port
ESP8266_portConnect("TCP", "broker.emqx.io", "1883");
// 4. Configure the MQTT client connection parameters
MQTT_InitTypeDef_t mqttSetting;
mqttSetting.keepAlive = 500;
mqttSetting.connectFlag = CleanSession;
mqttSetting.clientID = "25011102098_sensor";
// 5. Handshake with the MQTT broker
MQTT_connectBroker(&mqttSetting);

/* USER CODE END 2 */
 /* Infinite loop */
 /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
    /* USER CODE BEGIN 3 */
    rslt = bme280_get_sensor_data(BME280_ALL,&comp_data,&dev);
    if(rslt == BME280_OK){
        temperature = comp_data.temperature;
        pressure = comp_data.pressure / 100.0f;
        humidity = comp_data.humidity;
    }
    if(rslt == BME280_OK){
        char mqttData[160];
        snprintf(mqttData,sizeof(mqttData),"{\"status\":\"success\",\"temperature\":%.2f,\"humidity\":%.2f,\"pressure\":%.2f}",temperature,humidity,pressure);
        MQTT_publishTopic("stm32/data",mqttData,QoS0);
    }
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
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}



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
#ifdef USE_FULL_ASSERT
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
