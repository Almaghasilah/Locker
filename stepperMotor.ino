//4 stepper's wires.
int pin1 = 37;
int pin2 = 43;
int pin3 = 49;
int pin4 = 53;

void setup() {
  Serial.begin(9600);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  //halfDrive(400,pin4,pin3,pin2,pin1);
  //fullDrive(400,pin4,pin3,pin2,pin1);
  halfFullDrive(400,pin4,pin3,pin2,pin1);
}


// velo is the delay, and it controls the speed between the steps
// pinName# is for the stepper direction.
// Counter-clockwise is from pin1 through pin4.
// Clockwise is from pin4 through pin1.
//half stepping (1 phase) with 4 steps in a waveform period. 
void halfDrive(int velo,char pinName1,char pinName2,char pinName3,char pinName4){
     Serial.println("Half Drive Mode");
  
     digitalWrite(pinName1, HIGH);
     delay(velo);
     digitalWrite(pinName1, LOW);
     delay(velo);
  
     digitalWrite(pinName2, HIGH);
     delay(velo);
     digitalWrite(pinName2, LOW);
     delay(velo);
  
     digitalWrite(pinName3, HIGH);
     delay(velo);
     digitalWrite(pinName3, LOW);
     delay(velo);
  
     digitalWrite(pinName4, HIGH);
     delay(velo);
     digitalWrite(pinName4, LOW);
     delay(velo);
  
  }

void fullDrive(int velo,char pinName1,char pinName2,char pinName3,char pinName4){ 
     Serial.println("Full Drive Mode");
     
     digitalWrite(pinName1, HIGH);
     digitalWrite(pinName2, HIGH);
     digitalWrite(pinName3, LOW);
     digitalWrite(pinName4, LOW);
     delay(velo);

     digitalWrite(pinName1, LOW);
     digitalWrite(pinName4, HIGH);
     digitalWrite(pinName1, HIGH);
     digitalWrite(pinName2, LOW);
     delay(velo);

     digitalWrite(pinName1, LOW);
     digitalWrite(pinName4, LOW);
     digitalWrite(pinName1, HIGH);
     digitalWrite(pinName2, HIGH);
     delay(velo);

     digitalWrite(pinName1, HIGH);
     digitalWrite(pinName4, LOW);
     digitalWrite(pinName1, LOW);
     digitalWrite(pinName2, HIGH);
     delay(velo);

     digitalWrite(pinName1, HIGH);
     digitalWrite(pinName2, HIGH);
     digitalWrite(pinName3, LOW);
     digitalWrite(pinName4, LOW);
     delay(velo);

     digitalWrite(pinName1, LOW);
     digitalWrite(pinName4, HIGH);
     digitalWrite(pinName1, HIGH);
     digitalWrite(pinName2, LOW);
     delay(velo);

     digitalWrite(pinName1, LOW);
     digitalWrite(pinName4, LOW);
     digitalWrite(pinName1, HIGH);
     digitalWrite(pinName2, HIGH);
     delay(velo);

     digitalWrite(pinName1, HIGH);
     digitalWrite(pinName4, LOW);
     digitalWrite(pinName1, LOW);
     digitalWrite(pinName2, HIGH);
     delay(velo);
  
  }

void halfFullDrive(int velo,char pinName1,char pinName2,char pinName3,char pinName4){
     Serial.println("Half-Full Drive Mode");
     
     digitalWrite(pinName1, HIGH);
     digitalWrite(pinName2, LOW);
     digitalWrite(pinName3, LOW);
     digitalWrite(pinName4, LOW);
     delay(velo);

     digitalWrite(pinName1, HIGH);
     digitalWrite(pinName2, HIGH);
     digitalWrite(pinName3, LOW);
     digitalWrite(pinName4, LOW);
     delay(velo);

     digitalWrite(pinName1, LOW);
     digitalWrite(pinName2, HIGH);
     digitalWrite(pinName3, LOW);
     digitalWrite(pinName4, LOW);
     delay(velo);

     digitalWrite(pinName1, LOW);
     digitalWrite(pinName2, HIGH);
     digitalWrite(pinName3, HIGH);
     digitalWrite(pinName4, LOW);
     delay(velo);

     digitalWrite(pinName1, LOW);
     digitalWrite(pinName2, LOW);
     digitalWrite(pinName3, HIGH);
     digitalWrite(pinName4, LOW);
     delay(velo);

     digitalWrite(pinName1, LOW);
     digitalWrite(pinName2, LOW);
     digitalWrite(pinName3, HIGH);
     digitalWrite(pinName4, HIGH);
     delay(velo);

     digitalWrite(pinName1, LOW);
     digitalWrite(pinName2, LOW);
     digitalWrite(pinName3, LOW);
     digitalWrite(pinName4, HIGH);
     delay(velo);

     digitalWrite(pinName1, HIGH);
     digitalWrite(pinName2, LOW);
     digitalWrite(pinName3, LOW);
     digitalWrite(pinName4, HIGH);
     delay(velo);

  }
 
