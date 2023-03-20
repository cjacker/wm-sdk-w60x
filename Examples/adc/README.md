## W600 adc example

W600 does not have an external adc pin, but we can use internal adc for temperature measurement

### Build
```
cd <SDK dir>
mv App App.bak
cp -r Examples/adc App
make -C Tools/GNU
make -C Tools/GNU flash
```

### Usage

```
tio -e -b 115200 /dev/ttyUSB0 -m ONLCRNL

w600 adc example, compile @Mar 20 2023 12:30:04
task start ...
tem: 42.8
tem: 41.0
tem: 40.5
tem: 40.0
tem: 40.0
tem: 39.4
tem: 39.4
tem: 39.0
tem: 38.9
```
