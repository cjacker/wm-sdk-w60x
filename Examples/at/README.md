## W600 WM_AT firmware

### Build

```
cd <SDK dir>
mv App App.bak
cp -r Examples/at App
make -C Tools/GNU
make -C Tools/GNU flash
```

### Usage
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
