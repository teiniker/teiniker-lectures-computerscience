/* Serial
 * https://www.arduino.cc/reference/en/language/functions/communication/serial/
 * Used for communication between the Arduino board and a computer or other devices.
 */

int counter;

void setup() 
{
  Serial.begin(9600);

  Serial.println("Initialize my Arduino!");
  counter = 0;
}

void loop() 
{
  Serial.print("Counter = ");
  Serial.println(counter++);
}
