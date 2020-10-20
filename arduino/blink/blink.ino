/*
 * Blink
 * https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
 * This example shows the simplest thing you can do with an Arduino: it blinks the on-board LED.
 */
const int LED_PIN = 13;

void setup() 
{
  pinMode(LED_PIN, OUTPUT);         // initialize digital pin LED_BUILTIN as an output.
}

void loop() 
{
  digitalWrite(LED_PIN, HIGH);      // turn the LED on (HIGH is the voltage level)
  delay(300);                       // wait for a second
  digitalWrite(LED_PIN, LOW);       // turn the LED off by making the voltage LOW
  delay(300);                       // wait for a second
}
