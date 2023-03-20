## W600 hello world example

W600 printf hello world using a task.

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
w600 hello world example, compile @Apr 23 2019 16:02:30
hello world!
hello world!
hello world!
```
