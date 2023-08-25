/*
 *******************************************************************************
 * Copyright (c) 2023-2023, AirM2M, HalfSweet
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#if defined(ARDUINO_AIR32F103CB)
#include "pins_arduino.h"

#include <stdint.h>

enum class ClockSource : uint8_t
{
  HSI = 0,
  HSE = 1,
};

namespace CuluateClock
{
  constexpr uint8_t GetPLLMultiplier(ClockSource soure, uint32_t sourceFreq, uint32_t sysFrequency)
  {
    if (soure == ClockSource::HSI)
    {
      sourceFreq /= 2;
    }
    if (sysFrequency % sourceFreq != 0)
    {
      return (sysFrequency / sourceFreq) - 1;
    }
    else
    {
      return sysFrequency / sourceFreq;
    }
  }

  constexpr uint32_t Get_RCC_CFGR_PLLMULL(uint8_t multiplier)
  {
    uint32_t mulTable[] = {
        RCC_PLL_MUL2, RCC_PLL_MUL3, RCC_PLL_MUL4, RCC_PLL_MUL5, RCC_PLL_MUL6, RCC_PLL_MUL7, RCC_PLL_MUL8, RCC_PLL_MUL9,
        RCC_PLL_MUL10, RCC_PLL_MUL11, RCC_PLL_MUL12, RCC_PLL_MUL13, RCC_PLL_MUL14, RCC_PLL_MUL15, RCC_PLL_MUL16, RCC_PLL_MUL17,
        RCC_PLL_MUL18, RCC_PLL_MUL19, RCC_PLL_MUL20, RCC_PLL_MUL21, RCC_PLL_MUL22, RCC_PLL_MUL23, RCC_PLL_MUL24, RCC_PLL_MUL25,
        RCC_PLL_MUL26, RCC_PLL_MUL27, RCC_PLL_MUL28, RCC_PLL_MUL29, RCC_PLL_MUL30, RCC_PLL_MUL31, RCC_PLL_MUL32};
    if (multiplier > 32 || multiplier < 2)
    {
      return 0xFFFFFFFF;
    }
    else
    {
      return mulTable[multiplier - 2];
    }
  }
}

/**
 * @brief  System Clock Configuration
 * @param  None
 * @retval None
 */
WEAK void SystemClock_Config(void)
#if defined(USBCON)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {};

  /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL12;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
  PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}
#else
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {};

  /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
#if defined(USE_HSI)
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  constexpr uint32_t sourceFreq = CLOCK_SOURCE;
  constexpr auto clockSource = ClockSource::HSI;
  constexpr auto sysClkSource = RCC_SYSCLKSOURCE_HSI;
#elif defined(USE_HSE)
#undef HSE_VALUE
#define HSE_VALUE CLOCK_SOURCE
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  constexpr uint32_t sourceFreq = CLOCK_SOURCE;
  constexpr auto clockSource = ClockSource::HSE;
  constexpr auto sysClkSource = RCC_SYSCLKSOURCE_HSE;
#else
#error "No clock source defined"
#endif

  constexpr uint32_t sysFrequency = F_CPU;
  constexpr uint8_t multiplier = CuluateClock::GetPLLMultiplier(clockSource, sourceFreq, sysFrequency);
  if (multiplier < 2)
  {
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_OFF;
    RCC_ClkInitStruct.SYSCLKSource = sysClkSource;
  }
  else
  {
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLMUL = CuluateClock::Get_RCC_CFGR_PLLMULL(multiplier);
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  }

  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}
#endif /* USBCON */

#endif /* ARDUINO_GENERIC_* */
