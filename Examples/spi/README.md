## W600 spi example

compile the w600 spi firmware.

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

w600 spi0 firmware, compile@Mar 30 2020 19:14:48
ready
```
