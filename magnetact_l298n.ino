#include <TimerOne.h>
#include <FastGPIO.h>

const char EA = 9;
const char EB = 10;
const char IN1 = 8;
const char IN2 = 11;
const char IN3 = 12;
const char IN4 = 13;

volatile char polarityCount = 0;

void setup() {
  pinMode(EA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  FastGPIO::Pin<EA>::setOutputHigh();
  FastGPIO::Pin<IN1>::setOutputLow();
  FastGPIO::Pin<IN2>::setOutputHigh();

  Timer1.initialize(frequencyToInterruptUs(50));
  Timer1.attachInterrupt(timerHandler);
  Timer1.start();
}

void loop() {

}

void timerHandler() {
  FastGPIO::Pin<IN1>::setOutputToggle();
  FastGPIO::Pin<IN2>::setOutputToggle();
}

constexpr unsigned long frequencyToInterruptUs(float frequency) {
  return 1.0 / frequency / 2.0 * 1000000;
}
