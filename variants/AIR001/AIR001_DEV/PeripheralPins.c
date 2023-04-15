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
  {PA_0, ADC1, AIR_PIN_DATA_EXT(AIR_MODE_ANALOG, GPIO_NOPULL, 0, 0, 0)}, // ADC_IN0
  {PA_1, ADC1, AIR_PIN_DATA_EXT(AIR_MODE_ANALOG, GPIO_NOPULL, 0, 1, 0)}, // ADC_IN1
  {PA_2, ADC1, AIR_PIN_DATA_EXT(AIR_MODE_ANALOG, GPIO_NOPULL, 0, 2, 0)}, // ADC_IN2
  {PA_3, ADC1, AIR_PIN_DATA_EXT(AIR_MODE_ANALOG, GPIO_NOPULL, 0, 3, 0)}, // ADC_IN3
  {PA_4, ADC1, AIR_PIN_DATA_EXT(AIR_MODE_ANALOG, GPIO_NOPULL, 0, 4, 0)}, // ADC_IN4
  {PA_5, ADC1, AIR_PIN_DATA_EXT(AIR_MODE_ANALOG, GPIO_NOPULL, 0, 5, 0)}, // ADC_IN5
  {PA_6, ADC1, AIR_PIN_DATA_EXT(AIR_MODE_ANALOG, GPIO_NOPULL, 0, 6, 0)}, // ADC_IN6
  {PA_7, ADC1, AIR_PIN_DATA_EXT(AIR_MODE_ANALOG, GPIO_NOPULL, 0, 7, 0)}, // ADC_IN7
  {PB_0, ADC1, AIR_PIN_DATA_EXT(AIR_MODE_ANALOG, GPIO_NOPULL, 0, 8, 0)}, // ADC_IN8
  {PB_1, ADC1, AIR_PIN_DATA_EXT(AIR_MODE_ANALOG, GPIO_NOPULL, 0, 9, 0)}, // ADC_IN9
  {NC,   NP,   0}
};
#endif

//*** No DAC ***

//*** I2C ***

#ifdef HAL_I2C_MODULE_ENABLED
WEAK const PinMap PinMap_I2C_SDA[] = {
  {PA_2,  I2C, AIR_PIN_DATA(AIR_MODE_AF_OD, GPIO_NOPULL, GPIO_AF12_I2C)},
  {PA_7,  I2C, AIR_PIN_DATA(AIR_MODE_AF_OD, GPIO_NOPULL, GPIO_AF12_I2C)},
  {PA_9,  I2C, AIR_PIN_DATA(AIR_MODE_AF_OD, GPIO_NOPULL, GPIO_AF12_I2C)},
  {PA_10, I2C, AIR_PIN_DATA(AIR_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C)},
  {PA_12, I2C, AIR_PIN_DATA(AIR_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C)},
  {PB_7, I2C, AIR_PIN_DATA(AIR_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C)},
  {PB_8, I2C, AIR_PIN_DATA(AIR_MODE_AF_OD, GPIO_NOPULL, GPIO_AF12_I2C)},
  {PF_0, I2C, AIR_PIN_DATA(AIR_MODE_AF_OD, GPIO_NOPULL, GPIO_AF12_I2C)},
  {NC,    NP,   0}
};
#endif

#ifdef HAL_I2C_MODULE_ENABLED
WEAK const PinMap PinMap_I2C_SCL[] = {
  {PA_3,  I2C, AIR_PIN_DATA(AIR_MODE_AF_OD, GPIO_NOPULL, GPIO_AF12_I2C)},
  {PA_8,  I2C, AIR_PIN_DATA(AIR_MODE_AF_OD, GPIO_NOPULL, GPIO_AF12_I2C)},
  {PA_9, I2C, AIR_PIN_DATA(AIR_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C)},
  {PA_10, I2C, AIR_PIN_DATA(AIR_MODE_AF_OD, GPIO_NOPULL, GPIO_AF12_I2C)},
  {PA_11, I2C, AIR_PIN_DATA(AIR_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C)},
  {PB_6, I2C, AIR_PIN_DATA(AIR_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C)},
  {PB_8, I2C, AIR_PIN_DATA(AIR_MODE_AF_OD, GPIO_NOPULL, GPIO_AF6_I2C)},
  {PF_1, I2C, AIR_PIN_DATA(AIR_MODE_AF_OD, GPIO_NOPULL, GPIO_AF12_I2C)},
  {NC,    NP,   0}
};
#endif

//*** TIM ***

#ifdef HAL_TIM_MODULE_ENABLED
WEAK const PinMap PinMap_TIM[] = {
  //TODO
  {NC,         NP,    0}
};
#endif

//*** UART ***

#ifdef HAL_UART_MODULE_ENABLED
WEAK const PinMap PinMap_UART_TX[] = {
  {PA_2,  USART1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_USART1)},
  {NC,    NP,     0}
};
#endif

#ifdef HAL_UART_MODULE_ENABLED
WEAK const PinMap PinMap_UART_RX[] = {
  {PA_3,  USART1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF1_USART1)},
  {NC,    NP,     0}
};
#endif

#ifdef HAL_UART_MODULE_ENABLED
WEAK const PinMap PinMap_UART_RTS[] = {
  {NC,    NP,     0}
};
#endif

#ifdef HAL_UART_MODULE_ENABLED
WEAK const PinMap PinMap_UART_CTS[] = {
  {NC,    NP,     0}
};
#endif

//*** SPI ***

#ifdef HAL_SPI_MODULE_ENABLED
WEAK const PinMap PinMap_SPI_MOSI[] = {
  //{PB_5,  SPI1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF0_SPI1)}, TODO
  {NC,    NP,   0}
};
#endif

#ifdef HAL_SPI_MODULE_ENABLED
WEAK const PinMap PinMap_SPI_MISO[] = {
  //{PA_6,  SPI1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF0_SPI1)},
  {NC,    NP,   0}
};
#endif

#ifdef HAL_SPI_MODULE_ENABLED
WEAK const PinMap PinMap_SPI_SCLK[] = {
  //{PA_5,  SPI1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF0_SPI1)},
  {NC,    NP,   0}
};
#endif

#ifdef HAL_SPI_MODULE_ENABLED
WEAK const PinMap PinMap_SPI_SSEL[] = {
  //{PA_4,  SPI1, AIR_PIN_DATA(AIR_MODE_AF_PP, GPIO_PULLUP, GPIO_AF0_SPI1)},
  {NC,    NP,   0}
};
#endif

//*** No CAN ***

//*** No ETHERNET ***

//*** No QUADSPI ***

//*** No USB ***

//*** No SD ***

#endif /* !CUSTOM_PERIPHERAL_PINS */
