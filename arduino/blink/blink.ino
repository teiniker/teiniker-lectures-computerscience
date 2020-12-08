/*
 * Blink
 * 
 * Pin 13: (on-board LED)
 * 
 * see: https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
 */

const int LED_PIN = 13;

void setup() 
{
  pinMode(LED_PIN, OUTPUT);        
}

void loop() 
{
  digitalWrite(LED_PIN, HIGH);      
  delay(500);                       
  
  digitalWrite(LED_PIN, LOW);       
  delay(500);                       
}
