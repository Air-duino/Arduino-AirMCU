/* HAL raised several warnings, ignore them */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

#ifdef AIRF1xx
  #include "airf1xx_hal_gpio_ex.c"
#endif
#pragma GCC diagnostic pop
