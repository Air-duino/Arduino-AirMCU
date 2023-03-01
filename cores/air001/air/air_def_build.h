#ifndef _AIR_DEF_BUILD_
#define _AIR_DEF_BUILD_

#if !defined(CMSIS_STARTUP_FILE) && !defined(CUSTOM_STARTUP_FILE)
  #if defined(ARDUINO_AIR001_DEV)
    #define CMSIS_STARTUP_FILE "startup_air001xx.s"
  #else
    #error UNKNOWN CHIP
  #endif
#else
  #warning "No CMSIS startup file defined, custom one should be used"
#endif /* !CMSIS_STARTUP_FILE && !CUSTOM_STARTUP_FILE */
#endif /* _AIR_DEF_BUILD_ */
