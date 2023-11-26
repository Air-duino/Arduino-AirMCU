/* LL raised several warnings, ignore them */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

#ifdef AIRC0xx
  #include "airc0xx_ll_usart.c"
#elif AIR001xx
  #include "air001xx_ll_usart.c"
#elif AIR401xx 
  #include "air401xx_ll_usart.c"
#elif AIR32F1xx
  #include "AIR32F1xx_ll_usart.c"
#elif AIRF2xx
  #include "airf2xx_ll_usart.c"
#elif AIRF3xx
  #include "airf3xx_ll_usart.c"
#elif AIRF4xx
  #include "airf4xx_ll_usart.c"
#elif AIRF7xx
  #include "airf7xx_ll_usart.c"
#elif AIRG0xx
  #include "airg0xx_ll_usart.c"
#elif AIRG4xx
  #include "airg4xx_ll_usart.c"
#elif AIRH7xx
  #include "airh7xx_ll_usart.c"
#elif AIRL0xx
  #include "airl0xx_ll_usart.c"
#elif AIRL1xx
  #include "airl1xx_ll_usart.c"
#elif AIRL4xx
  #include "airl4xx_ll_usart.c"
#elif AIRL5xx
  #include "airl5xx_ll_usart.c"
#elif AIRMP1xx
  #include "airmp1xx_ll_usart.c"
#elif AIRU5xx
  #include "airu5xx_ll_usart.c"
#elif AIRWBxx
  #include "airwbxx_ll_usart.c"
#elif AIRWLxx
  #include "airwlxx_ll_usart.c"
#endif
#pragma GCC diagnostic pop
