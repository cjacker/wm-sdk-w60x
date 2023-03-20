# wm_sdk_w60x

Forked of latest official Winner Macro W60x SDK G3.4 (Updated at Mar 20 2020).

NOTE : Version number `G3.04` is identical to `G3.4`.

It can be downloaded from https://www.winnermicro.com/upload/1/editor/1584693446529.zip

There are various example codes merged from thingsturn.com and put at `Examples` dir. 

# Usage

Put your codes to `App/main.c`, you can also use codes from examples. build and flash it as:

```
make -C Tools/GNU
make -C Tools/GNU flash
```

When first time flashing, the `SERIAL_NAME` in `Tools/GNU/download_img.sh` need to be supplied, usually it's `ttyUSB0` or something like that. 

Set `USE_2M_FLASH = 1` in  `Tools/GNU/Makefile` for device with 2M flash.

# WM_AT firmware
WM_AT firmware for W600 is something like esp-at firmware for ESP8266/ESP32. it is close source and implemented in `./Lib/Wlan/wlan.lib`. The default build is `WM_AT` firmware indeed.

## WM_AT Usage
```
tio -e -b 115200 /dev/ttyUSB0 -m ONLCRNL
```
and Input `AT+`, it should be return 'OK'.

Note : By default, WM_AT firmware does not echo back, use `-e` to enable local echo back. you can also enable WM_AT echoback by `AT+E`.

A more complete example to connect to WiFi:

```
# test
AT+
+OK

# query hardware/software version
AT+QVER
+OK=H1.00.00.0000,G3.04.00@ 10:13:22 Mar 20 2023

# set mode to station
AT+WPRT=0
+OK

# set WiFi ESSID
AT+SSID=<essid>
+OK

# set password, <format>,<index>,<passwd>
# <format> 1 means ascii, 0 means hex.
# <index> 1-4 for WEP, 0 for others
AT+KEY=1,0,<password>
+OK

# join
AT+WJOIN
+OK=a687a96adfd4,0,1,1,"<essid>",39

# query IP
AT+NIP
+OK=0,192.168.1.1,255.255.255.0,192.168.1.1,192.168.1.1

```


# Note for latest arm-none-eabi-gcc

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


