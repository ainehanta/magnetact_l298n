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

  pinMode(EA, LOW);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  FastGPIO::Pin<EA>::setOutputLow();

  Timer1.initialize(frequencyToInterruptUs(100));
  Timer1.attachInterrupt(timerHandler);
  Timer1.start();
}

void loop() {

}

void timerHandler() {
  FastGPIO::Pin<EA>::setOutputToggle();
}

constexpr unsigned long frequencyToInterruptUs(float frequency) {
  if (polarityCount > 2) {
    polarityCount = 0;
  }
  polarityCount++;
  return 1.0 / frequency / 2.0 * 1000000;
}
