# Raspberry Pi OS

Raspberry Pi OS is a free operating system based on **Debian**, optimised for the Raspberry Pi hardware, and is the recommended operating system for normal use on a Raspberry Pi.

## Connecting via SSH

The **Secure Shell Protocol (SSH)** provides a secure encrypted connection between two 
hosts over an insecure network. 

This connection can also be used for terminal access, file transfers, and for tunneling other applications. 

_Example_: Connect to a remote Rasperry Pi 
```
$ ssh pi@192.168.0.213
```

_Example_: Copy a file to a remote Rasperry Pi 
```
$ scp led.py pi@192.168.0.213:/home/pi/sandbox
```

## GPIO
A powerful feature of the Raspberry Pi is the row of GPIO **General-Purpose Input/Output (GPIO)**) pins along the top edge of the board. 

![GPIO Pinout](GPIO-Pinout-Diagram.png)

A **40-pin GPIO header** is found on all current Raspberry Pi boards (unpopulated on Raspberry Pi Zero, Raspberry Pi Zero W and Raspberry Pi Zero 2 W). 

Prior to the Raspberry Pi 1 Model B+ (2014), boards comprised a shorter **26-pin header**.

Two 5V pins and two 3.3V pins are present on the board, as well as a number of ground pins (0V), which are unconfigurable. The remaining pins are all general purpose 3.3V pins, meaning outputs are set to 3.3V and inputs are 3.3V-tolerant.

A **GPIO pin designated as an output pin** can be set to high (3.3V) or low (0V).

A **GPIO pin designated as an input pin** can be read as high (3.3V) or low (0V). This is made easier with the use of internal pull-up or pull-down resistors. Pins GPIO2 and GPIO3 have fixed pull-up resistors, but for other pins this can be configured in software.

A handy reference can be accessed on the Raspberry Pi by opening a terminal window and running the command `pinout`.
```
$ pinout 
    3V3     (1)  (2)  5V    
    GPIO2   (3)  (4)  5V    
    GPIO3   (5)  (6)  GND   
    GPIO4   (7)  (8)  GPIO14
    GND     (9)  (10) GPIO15
    GPIO17  (11) (12) GPIO18
    GPIO27  (13) (14) GND   
    GPIO22  (15) (16) GPIO23
    3V3     (17) (18) GPIO24
    GPIO10  (19) (20) GND   
    GPIO9   (21) (22) GPIO25
    GPIO11  (23) (24) GPIO8 
    GND     (25) (26) GPIO7 
    GPIO0   (27) (28) GPIO1 
    GPIO5   (29) (30) GND   
    GPIO6   (31) (32) GPIO12
    GPIO13  (33) (34) GND   
    GPIO19  (35) (36) GPIO16
    GPIO26  (37) (38) GPIO20
    GND     (39) (40) GPIO21
```

## Permissions

In order to use the GPIO ports your user must be a member of the **gpio group**. 
The pi user is a member by default, other users need to be added manually.

```
$ sudo usermod -a -G gpio <username>
```


## GPIO via Files

Because of the OS abstractions, we can access the GPIO pins via the file system.

_Example_: LED on GPIO17 (including resistor)
```
$ echo 17 > /sys/class/gpio/export 

$ ll /sys/class/gpio/
-rwxrwx--- 1 root gpio 4096 Mär 29 19:40 export
lrwxrwxrwx 1 root gpio    0 Mär 29 19:40 gpio17 -> ../../devices/platform/soc/3f200000.gpio/gpiochip0/gpio/gpio17
lrwxrwxrwx 1 root gpio    0 Mär 29 11:11 gpiochip0 -> ../../devices/platform/soc/3f200000.gpio/gpio/gpiochip0
lrwxrwxrwx 1 root gpio    0 Mär 29 11:11 gpiochip504 -> ../../devices/platform/soc/soc:firmware/soc:firmware:expgpio/gpio/gpiochip504
-rwxrwx--- 1 root gpio 4096 Mär 29 11:11 unexport

$ ll /sys/class/gpio/gpio17/
-rwxrwx--- 1 root gpio 4096 Mär 29 19:40 active_low
lrwxrwxrwx 1 root gpio    0 Mär 29 19:40 device -> ../../../gpiochip0
-rwxrwx--- 1 root gpio 4096 Mär 29 19:40 direction
-rwxrwx--- 1 root gpio 4096 Mär 29 19:40 edge
drwxrwx--- 2 root gpio    0 Mär 29 19:40 power
lrwxrwxrwx 1 root gpio    0 Mär 29 19:40 subsystem -> ../../../../../../../class/gpio
-rwxrwx--- 1 root gpio 4096 Mär 29 19:40 uevent
-rwxrwx--- 1 root gpio 4096 Mär 29 19:40 value

$ echo out > /sys/class/gpio/gpio17/direction 

$ echo 1 > /sys/class/gpio/gpio17/value 
$ echo 0 > /sys/class/gpio/gpio17/value 
```

## GPIO in Python

Using the **GPIO Zero library** [gpiozero](https://gpiozero.readthedocs.io/en/stable/)
makes it easy to get started with controlling GPIO devices with Python.

_Example_: LED on GPIO17 (including resistor)
```Python
from gpiozero import LED
from time import sleep

led = LED(17)

while True:
	led.on()
	sleep(1)
	led.off()
	sleep(1)
```

## References

* [Raspberry Pi: Software Download](https://www.raspberrypi.com/software/)  
* [Raspberry Pi: Documentation](https://www.raspberrypi.com/documentation/computers)  

* [Python Library: gpiozero](https://gpiozero.readthedocs.io/en/stable/)

* [SSH (Secure Shell) Home Page](https://www.ssh.com/academy/ssh)
			

*Egon Teiniker, 2020-2022, GPL v3.0*    