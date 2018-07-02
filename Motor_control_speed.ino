//void setup() {
// put your setup code here, to run once:
//}
//void loop() {
// put your main code here, to run repeatedly:
//}

// connect motor controller pins to Arduino digital pins
// motor one
int enA = 10;
int in1 = 9;
int in2 = 8;

//reading the first direction
int direcA;
int direcB;

//reading the second direction
int direcC;
int direcD;

void setup()
{
  // set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  //Serial Monitor.
  Serial.begin(9600);  
  Serial.println("--- Start Serial Monitor SEND/RCVE ---");
}

void demoOne()
{
  // this function will run the motors in both directions at a fixed speed
  
}

void loop()
{
//demoOne();
//while(1)
//{
  //run once only
//digitalWrite(in1, LOW);
//digitalWrite(in2, LOW);  
//}  

 if (Serial.available() > 0){
//read number from serial mointor
  char mov  = Serial.read();

  if (mov == '1') {
    // turn on motor A
    //turing motor into one direction by setting in1 high and in2 low.
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 255);
  delay(3000);
  //reading the direction from serial monitor
  //in1 = 9 direcB
  //in2 = 8 direcA
  direcA = digitalRead(8);
  direcB = digitalRead(9);
  //Print it out :
  Serial.println("--The first direction--");
  Serial.println(direcA);
  Serial.println(direcB);

  //Stop the motor
   if (direcB == 1 ){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    delay(2000);
    }
  
  }
 else if (mov == '2'){
  // now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);   
  delay(3000);

  //reading the direction from serial monitor
  //in1 = 9 direcD
  //in2 = 8 direcC
  direcC = digitalRead(8);
  direcD = digitalRead(9);
  
  //print out
  Serial.println("--The second direction--");
  Serial.println(direcC);
  Serial.println(direcD);

  //Stop motor
  if (direcC == 1 ){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    delay(2000);
    }
 }
 
//    else if (mov =='3'){
//    digitalWrite(in1, LOW);
//    digitalWrite(in2, LOW);
//    //print out
//    Serial.println();
//    Serial.println("STOP");
//    }
 

 }
 }
 
