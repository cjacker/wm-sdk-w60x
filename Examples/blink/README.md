## W600 blink example

W600 blink led using a task.

### Build

```
cd <SDK dir>
mv App App.bak
cp -r Examples/blink App
make -C Tools/GNU
make -C Tools/GNU flash
```

### Usage
```
tio -e -b 115200 /dev/ttyUSB0 -m ONLCRNL

w600 blink example, compile @Apr 23 2019 16:02:30
blink task start ...
```
You will see the five LEDs on the TB-01 development board flashing ...
