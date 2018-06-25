#if ! defined(HDR)
#define HDR

/* zawartość pliku hdr.h jest tutaj */

#endif


/* sprawdzamy jaki nagłówek wstawić do programu, pod nazwą HDR */

#if SYSTEM == SYSV
  #define HDR "sysv.h"
#elif SSYSTEM == BSD
  #define HDR "bsd.h"
#elif SYSTEM == MSDOS
  #define HDR "msdos.h"
#else
  #define HDR "default.h"
#endif
#include HDR

#ifndef HDR
#define HDR

/* zawartość pliku "hdr.h" jest tutaj */

#endif
