#ifndef __AIR32F103xx_HAL_CONF_H
#define __AIR32F103xx_HAL_CONF_H

#include "variant.h"

/* AIR32F103xx specific HAL configuration options. */
#if __has_include("hal_conf_custom.h")
#include "hal_conf_custom.h"
#else
#if __has_include("hal_conf_extra.h")
#include "hal_conf_extra.h"
#endif
#include "air32f1xx_hal_conf_default.h"
#endif

#endif /* __AIR32F103xx_HAL_CONF_H */
