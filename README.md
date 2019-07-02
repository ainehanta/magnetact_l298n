# magnetact_l298n

Arduino project for vibrating a magnet with an electromagnet.

## Parts List

- Seedstudio Motor Shield V1
- Arduino Uno
- Electromagnet
- Magnet
- DC 9-12V Power Supply

## How to run it

In first, please stack the motor shield to your aruduino board and
connect the power supply to motor shield. The electromagnet should be
connected to `M1+` and `M1-` terminal.

This sketch requires [`TimerOne`](https://github.com/PaulStoffregen/TimerOne) and [`FastGPIO`](https://github.com/pololu/fastgpio-arduino) libraries.
Please install these libraries from Library Manager in Arduino IDE.

Then upload the sketch to your arduino board.

## To change the frequency

Please change `100` to any frequency.

```C++
// L24
Timer1.initialize(frequencyToInterruptUs(100));
```