#ifndef __AIR401xx_HAL_CONF_H
#define __AIR401xx_HAL_CONF_H

#include "variant.h"

/* AIR401xx specific HAL configuration options. */
#if __has_include("hal_conf_custom.h")
#include "hal_conf_custom.h"
#else
#if __has_include("hal_conf_extra.h")
#include "hal_conf_extra.h"
#endif
#include "air401xx_hal_conf_default.h"
#endif

#endif /* __AIR401xx_HAL_CONF_H */
