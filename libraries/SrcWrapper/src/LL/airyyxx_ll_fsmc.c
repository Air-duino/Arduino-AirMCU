/* LL raised several warnings, ignore them */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

#ifdef AIRF1xx
  #include "airf1xx_ll_fsmc.c"
#elif AIRF2xx
  #include "airf2xx_ll_fsmc.c"
#elif AIRF4xx
  #include "airf4xx_ll_fsmc.c"
#elif AIRL1xx
  #include "airl1xx_ll_fsmc.c"
#endif
#pragma GCC diagnostic pop
