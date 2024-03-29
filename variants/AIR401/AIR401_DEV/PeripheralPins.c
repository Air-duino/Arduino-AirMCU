/*
 *******************************************************************************
 * Copyright (c) 2023, AirM2M
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
/*
 */
#if !defined(CUSTOM_PERIPHERAL_PINS)
#include "Arduino.h"
#include "PeripheralPins.h"

/* =====
 * Notes:
 * - The pins mentioned Px_y_ALTz are alternative possibilities which use other
 *   HW peripheral instances. You can use them the same way as any other "normal"
 *   pin (i.e. analogWrite(PA7_ALT1, 128);).
 *
 * - Commented lines are alternative possibilities which are not used per default.
 *   If you change them, you will have to know what you do
 * =====
 */

//*** ADC ***

#ifdef HAL_ADC_MODULE_ENABLED
WEAK const PinMap PinMap_ADC[] = {
  {PB_0, ADC1, AIR_PIN_DATA_EXT(AIR_MODE_ANALOG, GPIO_NOPULL, 0, 0, 0)}, // ADC_IN0
  {PA_3, ADC1, AIR_PIN_DATA_EXT(AIR_MODE_ANALOG, GPIO_NOPULL, 0, 1, 0)}, // ADC_IN1
  {PA_4, ADC1, AIR_PIN_DATA_EXT(AIR_MODE_ANALOG, GPIO_NOPULL, 0, 2, 0)}, // ADC_IN2
  {PA_6, ADC1, AIR_PIN_DATA_EXT(AIR_MODE_ANALOG, GPIO_NOPULL, 0, 3, 0)}, // ADC_IN3
  {PA_7, ADC1, AIR_PIN_DATA_EXT(AIR_MODE_ANALOG, GPIO_NOPULL, 0, 4, 0)}, // ADC_IN4
  {PC_0, ADC1, AIR_PIN_DATA_EXT(AIR_MODE_ANALOG, GPIO_NOPULL, 0, 5, 0)}, // ADC_IN5
  {PB_6, ADC1, AIR_PIN_DATA_EXT(AIR_MODE_ANALOG, GPIO_NOPULL, 0, 6, 0)}, // ADC_IN6
  {PB_0, ADC1, AIR_PIN_DATA_EXT(AIR_MODE_ANALOG, GPIO_NOPULL, 0, 7, 0)}, // ADC_IN7
  {NC,   NP,   0}
};
#endif

//*** No DAC ***

//*** I2C ***

#ifdef HAL_I2C_MODULE_ENABLED
WEAK const PinMap PinMap_I2C_SDA[] = {
  {PB_4,  I2C, AIR_PIN_DATA(AIR_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C1)},
  {PB_6,  I2C, AIR_PIN_DATA(AIR_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C1)},
  {NC,    NP,   0}
};
#endif

#ifdef HAL_I2C_MODULE_ENABLED
WEAK const PinMap PinMap_I2C_SCL[] = {
  {PA_2,  I2C, AIR_PIN_DATA(AIR_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C1)},
  {PB_3,  I2C, AIR_PIN_DATA(AIR_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C1)},
  {NC,    NP,   0}
};
#endif

//*** TIM ***

#ifdef HAL_TIM_MODULE_ENABLED
WEAK const PinMap PinMap_TIM[] = {
  {PA_0,       TIM1,  AIR_PIN_DATA_EXT(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM1, 1, 0)}, // TIM1_CH1
  {PA_1,       TIM1,  AIR_PIN_DATA_EXT(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM1, 2, 0)}, // TIM1_CH2
  {PA_2,       TIM1,  AIR_PIN_DATA_EXT(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM1, 4, 0)}, // TIM1_CH4
  {PA_3,       TIM1,  AIR_PIN_DATA_EXT(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM1, 2, 0)}, // TIM1_CH2
  {PA_4,  TIM1, AIR_PIN_DATA_EXT(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM1, 3, 0)}, // TIM1_CH3
  {PA_5,  TIM1, AIR_PIN_DATA_EXT(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM1, 1, 0)}, // TIM1_CH1
  {PA_7,  TIM1, AIR_PIN_DATA_EXT(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM1, 4, 0)}, // TIM1_CH4
  {PB_0,  TIM1, AIR_PIN_DATA_EXT(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM1, 2, 0)}, // TIM1_CH2
  {PB_1,  TIM1, AIR_PIN_DATA_EXT(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM1, 2, 1)}, // TIM1_CH2N
  {PB_2,  TIM1, AIR_PIN_DATA_EXT(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM1, 1, 1)}, // TIM1_CH1N
  {PB_5,  TIM1, AIR_PIN_DATA_EXT(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM1, 3, 0)}, // TIM1_CH3
  {PC_0,  TIM1, AIR_PIN_DATA_EXT(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF2_TIM1, 1, 1)}, // TIM1_CH1N

  {PA_4,       TIM14,  AIR_PIN_DATA_EXT(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_TIM14, 1, 0)}, // TIM14_CH1
  {PA_5,       TIM14,  AIR_PIN_DATA_EXT(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_TIM14, 1, 0)}, // TIM14_CH1
  {PB_5,       TIM14,  AIR_PIN_DATA_EXT(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_TIM14, 1, 0)}, // TIM14_CH1
  {PB_7,       TIM14,  AIR_PIN_DATA_EXT(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF5_TIM14, 1, 0)}, // TIM14_CH1

  {NC,         NP,    0}
};
#endif

//*** UART ***

#ifdef HAL_UART_MODULE_ENABLED
WEAK const PinMap PinMap_UART_TX[] = {
  {PA_3,  USART1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_USART1)},
  {PA_6,  USART1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_USART1)},
  {PA_7,  USART1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_USART1)},
  {PB_4,  USART1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_USART1)},
  {PB_6,  USART1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_USART1)},

  {NC,    NP,     0}
};
#endif

#ifdef HAL_UART_MODULE_ENABLED
WEAK const PinMap PinMap_UART_RX[] = {
  {PA_2,  USART1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_USART1)},
  {PA_4,  USART1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_USART1)},
  {PB_5,  USART1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_USART1)},
  
  {NC,    NP,     0}
};
#endif

#ifdef HAL_UART_MODULE_ENABLED
WEAK const PinMap PinMap_UART_RTS[] = {
  {PB_1,       USART1,  AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_USART1)},
  {NC,    NP,     0}
};
#endif

#ifdef HAL_UART_MODULE_ENABLED
WEAK const PinMap PinMap_UART_CTS[] = {
  {PB_2,       USART1,  AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_USART1)},
  {NC,    NP,     0}
};
#endif

//*** SPI ***

#ifdef HAL_SPI_MODULE_ENABLED
WEAK const PinMap PinMap_SPI_MOSI[] = {
  {PA_0,  SPI1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF0_SPI1)},
  {PA_7,  SPI1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF0_SPI1)},
  {PB_7,  SPI1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF0_SPI1)},
  

  {NC,    NP,   0}
};
#endif

#ifdef HAL_SPI_MODULE_ENABLED
WEAK const PinMap PinMap_SPI_MISO[] = {
  {PA_1,  SPI1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF0_SPI1)},
  {PB_6,  SPI1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF0_SPI1)},
  {NC,    NP,   0}
};
#endif

#ifdef HAL_SPI_MODULE_ENABLED
WEAK const PinMap PinMap_SPI_SCLK[] = {
  {PB_0,  SPI1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF0_SPI1)},
  {PB_2,  SPI1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF0_SPI1)},
  {NC,    NP,   0}
};
#endif

#ifdef HAL_SPI_MODULE_ENABLED
WEAK const PinMap PinMap_SPI_SSEL[] = {
  {PA_6,  SPI1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF0_SPI1)},
  {PB_5,  SPI1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF0_SPI1)},
  {NC,    NP,   0}
};
#endif

//*** No CAN ***

//*** No ETHERNET ***

//*** No QUADSPI ***

//*** No USB ***

//*** No SD ***

#endif /* !CUSTOM_PERIPHERAL_PINS */
