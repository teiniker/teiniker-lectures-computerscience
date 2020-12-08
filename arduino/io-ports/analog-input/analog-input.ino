/* Analog Input (Poti)
 *  
 * see: https://www.arduino.cc/en/Tutorial/BuiltInExamples/ReadAnalogVoltage
 */


void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int value = analogRead(A0);

  float voltage = value * 5.0/1023.0;
  Serial.print(voltage);
  Serial.println("[V]");
}
