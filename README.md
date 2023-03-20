# wm_sdk_w60x

Forked of latest official Winner Macro W60x SDK v3.04 (Updated at Mar 20 2020).

It can be downloaded from https://www.winnermicro.com/upload/1/editor/1584693446529.zip

# usage

Put your codes to `App/main.c`, build and flash it as:

```
cd Tools/GNU/
make
make flash
```

# note for latest arm-none-eabi-gcc

If you encounter `timeval` or `fd_set` redefined error, it due to below codes in `arm-none-eabi/include/sys/types.h` of arm-none-eabi-gcc toolchain. There is no way to undefined this macro and have to define it to 0 when include headers (too many errors need to fix). The simplest way is to comment below lines out.

```
#if __BSD_VISIBLE
#include <machine/endian.h>
#include <sys/select.h>
#  define   physadr     physadr_t
#  define   quad        quad_t

#ifndef _IN_ADDR_T_DECLARED
typedef __uint32_t  in_addr_t;  /* base type for internet address */
#define _IN_ADDR_T_DECLARED
#endif

#ifndef _IN_PORT_T_DECLARED
typedef __uint16_t  in_port_t;
#define _IN_PORT_T_DECLARED
#endif

typedef __uintptr_t u_register_t;
#endif /* __BSD_VISIBLE */
```


