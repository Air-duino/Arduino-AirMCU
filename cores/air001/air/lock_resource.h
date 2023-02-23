/*
 *******************************************************************************
 * Copyright (c) 2023, AirM2M
 * All rights reserved.
 *
 * This software component is licensed by AirM2M under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _LOCK_RESOURCE_H
#define _LOCK_RESOURCE_H

/* Includes ------------------------------------------------------------------*/
#include "air_def.h"
#include "airyyxx_ll_hsem.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Exported types ------------------------------------------------------------*/
typedef enum {
  LOCK_RESOURCE_STATUS_OK       = 0x00U,
  LOCK_RESOURCE_STATUS_ERROR    = 0x01U,
  LOCK_RESOURCE_STATUS_TIMEOUT  = 0x02U
} LockResource_Status_t;

/* Exported constants --------------------------------------------------------*/

/* Hardware Semaphore wait forever value */
#define HSEM_LOCK_WAIT_FOREVER                         0xFFFFFFFFU
/* Hardware Semaphore default retry value */
#ifndef HSEM_LOCK_DEFAULT_RETRY
#define HSEM_LOCK_DEFAULT_RETRY                            0xFFFFU
#endif

/*
 * @brief  hsem_lock function is used for register protection of shared Peripheral
 *         and shall be called before accessing registers of this shared Peripheral
 *         If Semaphore id is already taken, the function will busy loop waiting for it to
 *         be released, but give up after @retry downcounter have elapsed
 * @param  semID: Semaphore id used to identify which peripheral to protect
 * @param  retry: number of retry
 * @retval None
 */
static inline void hsem_lock(uint32_t semID, uint32_t retry)
{
#if 0
  if ((semID) <= HSEM_SEMID_MAX) {
    while (LL_HSEM_1StepLock(HSEM, semID)) {
      if (retry != HSEM_LOCK_WAIT_FOREVER) {
        retry--;
        if (retry == 0) {
          Error_Handler();
        }
      }
    }
  }
#else
  UNUSED(semID);
  UNUSED(retry);
#endif /* AIRMP1xx || AIRWBxx */
}

/*
 * @brief  hsem_unlock released a previously-acquired semaphore
 * @param  semID Semaphore id used to identify which peripheral to release
 * @retval None
 */
static inline void hsem_unlock(uint32_t semID)
{
#if 0
  if ((semID) <= HSEM_SEMID_MAX) {
    LL_HSEM_ReleaseLock(HSEM, semID, 0);
  }
#else
  UNUSED(semID);
#endif /* AIRMP1xx || AIRWBxx */
}

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* _LOCK_RESOURCE_H */



/************************ (C) COPYRIGHT AirM2M *****END OF FILE****/
