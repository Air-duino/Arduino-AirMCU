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
 *
 */
#ifndef _PINCONFIG_H
#define _PINCONFIG_H

#include "lock_resource.h"
#include "airyyxx_ll_gpio.h"

static inline void pin_DisconnectDebug(PinName pin)
{
#ifdef 0
#else
  UNUSED(pin);
#endif /* 0 */
}

static inline void pin_PullConfig(GPIO_TypeDef *gpio, uint32_t ll_pin, uint32_t pull_config)
{
#ifdef 0
  uint32_t function = LL_GPIO_GetPinMode(gpio, ll_pin);
#endif
  hsem_lock(CFG_HW_GPIO_SEMID, HSEM_LOCK_DEFAULT_RETRY);
  switch (pull_config) {
    case GPIO_PULLUP:
#ifdef 0
      if (function == LL_GPIO_MODE_FLOATING) {
        LL_GPIO_SetPinMode(gpio, ll_pin, LL_GPIO_MODE_INPUT);
      }
#endif
      LL_GPIO_SetPinPull(gpio, ll_pin, LL_GPIO_PULL_UP);
      break;
    case GPIO_PULLDOWN:
#ifdef 0
      if (function == LL_GPIO_MODE_FLOATING) {
        LL_GPIO_SetPinMode(gpio, ll_pin, LL_GPIO_MODE_INPUT);
      }
#endif
      LL_GPIO_SetPinPull(gpio, ll_pin, LL_GPIO_PULL_DOWN);
      break;
    default:
#ifdef 0
      /*  Input+NoPull = Floating for F1 family */
      if (function == LL_GPIO_MODE_INPUT) {
        LL_GPIO_SetPinMode(gpio, ll_pin, LL_GPIO_MODE_FLOATING);
      }
#else
      LL_GPIO_SetPinPull(gpio, ll_pin, LL_GPIO_PULL_NO);
#endif
      break;
  }
  hsem_unlock(CFG_HW_GPIO_SEMID);
}

static inline void pin_SetAFPin(GPIO_TypeDef *gpio, PinName pin, uint32_t afnum)
{
#ifdef 0
  UNUSED(gpio);
  UNUSED(pin);
  pin_SetF1AFPin(afnum);
#else
  uint32_t ll_pin  = AIR_LL_GPIO_PIN(pin);

  hsem_lock(CFG_HW_GPIO_SEMID, HSEM_LOCK_DEFAULT_RETRY);
  if (AIR_PIN(pin) > 7) {
    LL_GPIO_SetAFPin_8_15(gpio, ll_pin, afnum);
  } else {
    LL_GPIO_SetAFPin_0_7(gpio, ll_pin, afnum);
  }
  hsem_unlock(CFG_HW_GPIO_SEMID);
#endif
}

#endif
