# I/O Ports

## Arduino Board
The I/O ports of the Arduino Uno board can be seen in the following figure:

![Arduino Uno Board](doc/arduino_board.png)

* Analog Reference pin (orange)
* Digital Ground (light green)
* **Digital Pins 2-13** (green)
* Digital Pins 0-1/Serial In/Out - TX/RX (dark green) - These pins cannot be used for digital i/o (digitalRead and digitalWrite) if you are also using serial communication (e.g. Serial.begin).
* **Analog In Pins 0-5** (light blue)
* Power and Ground Pins (power: orange, grounds: light orange)

## Digital Ports

The digital pins on an Arduino board can be used for general purpose input and output 
via the `pinMode()`, `digitalRead()`, and `digitalWrite()` commands. 


### Digital Output
Pins configured as `OUTPUT` with `pinMode()` are said to be in a low-impedance state. 
This means that they can provide a substantial amount of current to other circuits. 
Atmega pins can source (provide positive current) or sink (provide negative current) 
up to 40 mA (milliamps) of current to other devices/circuits. 

**The maximum current per pin is 40 mA.**

This is enough current to brightly light up an LED (don't forget the series resistor), 
or run many sensors, for example, but not enough current to run most relays, solenoids, 
or motors.

Short circuits on Arduino pins, or attempting to run high current devices from them, 
can damage or destroy the output transistors in the pin, or damage the entire Atmega chip.
For this reason it is a good idea to connect OUTPUT pins to other devices with
 **470Ω or 1k resistors**, unless maximum current draw from the pins is required for 
 a particular application.


### Digital Input

Arduino (Atmega) pins **default to inputs**, so they don't need to be explicitly 
declared as inputs with `pinMode()` when you're using them as inputs. 

Pins configured this way are said to be in a **high-impedance state**. 
Input pins make extremely small demands on the circuit that they are sampling, 
equivalent to a series resistor of **100 megohm** in front of the pin.

This also means however, that pins configured as `pinMode(pin, INPUT)` with 
**nothing connected to them**, or with wires connected to them that are not 
connected to other circuits, will report seemingly **random changes** in pin state, 
picking up electrical noise from the environment, or capacitively coupling the state 
of a nearby pin.

Often it is useful to steer an input pin to a known state if no input is present. 
This can be done by adding a **pullup resistor** (to +5V), or a **pulldown resistor** 
(resistor to ground) on the input. 
A **10K resistor** is a good value for a pullup or pulldown resistor.


# Analog Ports

The analog pins can be used identically to the digital pins, using the aliases A0 
(for analog input 0), A1, etc. 

## Analog Input
The analog input pins support **10-bit analog-to-digital conversion (ADC)** using the 
`analogRead()` function. The converter is returning integers from **0 to 1023**. 
 
Most of the analog inputs can also be used as digital pins: analog input 0 as 
digital pin 14 through analog input 5 as digital pin 19. 
 
Analog inputs 6 and 7 (present on the Mini and BT) cannot be used as digital pins.
 
## Analog Output (PWM) 
**Pulse Width Modulation**, or PWM, is a technique for getting analog results with digital 
means. Digital control is used to create a square wave, a signal switched between 
on and off. This on-off pattern can simulate voltages in between the full Vcc of the board
and off (0 Volts) by changing the portion of the time the signal spends on versus the 
time that the signal spends off. 
The duration of "on time" is called the **pulse width**. 

![PWM](doc/pwm.gif)

This duration or period is the inverse of the PWM frequency. 
With Arduino's **PWM frequency at about 500Hz**, the green lines would measure 
2 milliseconds each. 

A call to `analogWrite()` is on a **scale of 0 - 255**, such that `analogWrite(255)` 
requests a 100% duty cycle (always on), and `analogWrite(127)` is a 50% duty cycle 
(on half the time) for example.


## References
* [Introduction to the Arduino Board](https://www.arduino.cc/en/reference/board)
* [Digital Pins](https://www.arduino.cc/en/Tutorial/Foundations/DigitalPins)
* [Analog Input Pins](https://www.arduino.cc/en/Tutorial/Foundations/AnalogInputPins)
* [PWM](https://www.arduino.cc/en/Tutorial/Foundations/PWM)
