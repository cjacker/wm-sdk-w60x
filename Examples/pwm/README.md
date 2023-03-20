## W600 pwm example

W600 breathing led using hardware pwm.

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

w600 pwm example, compile @Apr 23 2019 16:44:22
pwm task start ...
```
You will see the 5 LEDs on the development board breathing ...
