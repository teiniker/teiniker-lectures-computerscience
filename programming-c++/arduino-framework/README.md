# C++ in the Arduino Framework

## Arduino Core AVR  
The Arduino core and many sensor libraries in the Arduino Framework are written in C++.
However, not all C++ features are used. 
In particular, the Standard Template Library (STL) is not used.

The following list gives an **overview of the C++ features used** 
together with some examples:

* Namespaces
    * [cores/arduino/new](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/new)

* Function Overloading
    * [cores/arduino/Arduino.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Arduino.h)
    * [cores/arduino/IPAddress.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/IPAddress.h)

* Default Arguments
    * [cores/arduino/Arduino.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Arduino.h)
    * [cores/arduino/Print.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Print.h)

* References
    * [cores/arduino/Print.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Print.h)

* Class 
    * [cores/arduino/Print.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Print.h)
    * [cores/arduino/HardwareSerial.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/HardwareSerial.h)

* Constructor and Method Overloading
    * [cores/arduino/Print.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/Print.h)
    * [cores/arduino/IPAddress.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/IPAddress.h)

* Operator Overloading 
    * [cores/arduino/IPAddress.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/IPAddress.h)

* Inheritance 
    * [cores/arduino/HardwareSerial.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/HardwareSerial.h)
    * [cores/arduino/IPAddress.h](https://github.com/arduino/ArduinoCore-avr/blob/master/cores/arduino/IPAddress.h)	


## Arduino Libraries

Arduino libraries are, in the true sense of the word, modules that consist 
of a header file and a C++ file.

Since these files are available in source code, they are wonderful examples 
of using C++ classes in embedded programming.

* [RGBLed](https://github.com/teiniker/teiniker-lectures-arduino/tree/main/sensors-and-actuators/user-interface/rgb-led/lib/RGB-1.0.10)

* [Debounce](https://github.com/teiniker/teiniker-lectures-arduino/tree/main/sensors-and-actuators/user-interface/button-debouncing/lib/Debounce-1.2)

* [HC-SR04](https://github.com/teiniker/teiniker-lectures-arduino/tree/main/sensors-and-actuators/sensors/hc-sr04/lib/HC-SR04)

* And many more...


## References

* [GitHub: Arduino AVR Boards](https://github.com/arduino/ArduinoCore-avr)


*Egon Teiniker, 2020-2023, GPL v3.0*
