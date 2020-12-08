/*
 * Analog Output
 * 
 * Pin 9 ~: ---[1K]--|>|---(GND)
 * 
 * see: https://www.arduino.cc/en/Tutorial/BuiltInExamples/Fading
 */

const int LED_PIN = 9;

void setup() 
{
}

void loop() 
{
  for(int i=0; i<255; i +=5)
  {
    analogWrite(LED_PIN, i);
    delay(30);
  }

  for(int i=255; i>0; i-=5)
  {
    analogWrite(LED_PIN, i);
    delay(30);
  }
  
}
