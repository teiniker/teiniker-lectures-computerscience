/*
 * Digital Output PWD
 * 
 * Pin 13: (on-board LED)
 * 
 */

const int LED_PIN = 13;


void period(int T, int power_on)
{
    digitalWrite(LED_PIN, HIGH);      
    delay(power_on);                       
  
    digitalWrite(LED_PIN, LOW);       
    delay(T-power_on);                         
}

void setup() 
{
  pinMode(LED_PIN, OUTPUT);        
}

void loop() 
{
  int T = 20; // [ms]

  // t=0..19[ms]
  for(int t=0; t<T; t++)
  {
    period(T, t);
  }

  // t=20..1 [ms]
  for(int t=T; t>0; t--)
  {
    period(T, t);
  }  
}
