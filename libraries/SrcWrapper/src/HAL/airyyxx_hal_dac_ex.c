/* HAL raised several warnings, ignore them */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

#ifdef AIR001xx
  #include "air001xx_hal_dac_ex.c"
#elif AIRF1xx
  #include "airf1xx_hal_dac_ex.c"
#elif AIRF2xx
  #include "airf2xx_hal_dac_ex.c"
#elif AIRF3xx
  #include "airf3xx_hal_dac_ex.c"
#elif AIRF4xx
  #include "airf4xx_hal_dac_ex.c"
#elif AIRF7xx
  #include "airf7xx_hal_dac_ex.c"
#elif AIRG0xx
  #include "airg0xx_hal_dac_ex.c"
#elif AIRG4xx
  #include "airg4xx_hal_dac_ex.c"
#elif AIRH7xx
  #include "airh7xx_hal_dac_ex.c"
#elif AIRL0xx
  #include "airl0xx_hal_dac_ex.c"
#elif AIRL1xx
  #include "airl1xx_hal_dac_ex.c"
#elif AIRL4xx
  #include "airl4xx_hal_dac_ex.c"
#elif AIRL5xx
  #include "airl5xx_hal_dac_ex.c"
#elif AIRMP1xx
  #include "airmp1xx_hal_dac_ex.c"
#elif AIRU5xx
  #include "airu5xx_hal_dac_ex.c"
#elif AIRWLxx
  #include "airwlxx_hal_dac_ex.c"
#endif
#pragma GCC diagnostic pop
