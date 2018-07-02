 
#define STEP_PIN 2
#define DIR_PIN 5
 
bool dirHigh;
 
void setup()
{
  dirHigh = true;
  digitalWrite(DIR_PIN, HIGH);
  digitalWrite(STEP_PIN, LOW);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(STEP_PIN, OUTPUT);
}
 
void loop()
{
  // Toggle the DIR pin to change direction.
  if(dirHigh)
  {
    dirHigh = false;
    digitalWrite(DIR_PIN, LOW);
  }
  else
  {
    dirHigh = true;
    digitalWrite(DIR_PIN, HIGH);
  }
 
  // Step the motor 50 times before changing direction again.
  for(int i = 0; i < 1000; i++)
  {
    // Trigger the motor to take one step.
    digitalWrite(STEP_PIN, HIGH);
    delay(500);
    digitalWrite(STEP_PIN, LOW);
    delay(500);
  }
}
