## W600 blink timer example

W600 blink led using a hardware timer.

### Build

```
cd <SDK dir>
mv App App.bak
cp -r Examples/blink_timer App
make -C Tools/GNU
make -C Tools/GNU flash
```

### Usage
```
tio -e -b 115200 /dev/ttyUSB0 -m ONLCRNL
w600 blink timer example, compile @Apr 23 2019 16:02:30
blink timer start
blink timer stop
```
You will see the 5 LEDs on TB-01 development board flashing ...
