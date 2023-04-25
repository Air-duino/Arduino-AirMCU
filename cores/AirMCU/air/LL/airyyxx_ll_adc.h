#ifndef _AIRYYXX_LL_ADC_H_
#define _AIRYYXX_LL_ADC_H_
/* LL raised several warnings, ignore them */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#ifdef __cplusplus
  #pragma GCC diagnostic ignored "-Wregister"
#endif

#ifdef AIR001xx
  #include "air001xx_ll_adc.h"
#elif defined(AIR32F103xx)
  #include "air32f1xx_ll_adc.h"
#endif
#pragma GCC diagnostic pop
#endif /* _AIRYYXX_LL_ADC_H_ */
