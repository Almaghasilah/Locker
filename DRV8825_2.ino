//IR Sensor & LED
#define LEDPIN 13  //LED pin
#define SENSORPIN 12  //Receiver (omitter)

//Direction pin
#define Head1_DIR     6 
#define Head2_DIR     7
#define Solder_DIR    8
#define Shaft1_DIR    9
#define Shaft2_DIR    10

//Step pin
#define Head1_STP     1
#define Head2_STP     2 
#define Solder_STP    3
#define Shaft1_STP    4
#define Shaft2_STP    5 

//Mircrostep Resolution (pin number)
//Mircrostep Resolution 
// Full step: MODE_0 = Low, MODE_1 = low and MODE_2 = low.
// Half step: MODE_0 = High, MODE_1 = low and MODE_2 = low.
// 1/4 step: MODE_0 = Low, MODE_1 = High and MODE_2 = low.
// 1/16 step: MODE_0 = Low, MODE_1 = low and MODE_2 = High.
// 1/32 step: MODE_0 = High, MODE_1 = low and MODE_2 = High.

//DRV8825
// Full Step: 200 steps per a resolution.(800us good start)
// Half Step: 400 steps per a resolution.
// 1/4 step : 800 steps per a resolution.
// 1/8 step : 1600 steps per a resolution.
// 1/16 step: 3200 steps per a resolution.
// 1/32 step: 6400 steps per a resolution.

int delayTime=600; //Delay between each pause (uS)
                   //Control how fast the rotation.
int stps_Head1=2200;// Steps to move.  200 steps per revolution. 
               //1.8 angle per step => 1.8*200 = 360 angle
int stps_Head2=2200;

int stps_Solder=2200;

int stps_Shaft1=2200;

int stps_Shaft2=2200;

void step(boolean dir, byte dirPin, byte stepperPin, int steps)

{

  digitalWrite(dirPin, dir);

  delay(10);

  for (int i = 0; i < steps; i++) {

    digitalWrite(stepperPin, HIGH);

    delayMicroseconds(delayTime); 

    digitalWrite(stepperPin, LOW);

    delayMicroseconds(delayTime); 

  }

}

void setup(){
//Steps and directions set up
  pinMode(Head1_DIR, OUTPUT); pinMode(Head1_STP, OUTPUT);

  pinMode(Head2_DIR, OUTPUT); pinMode(Head2_STP, OUTPUT);

  pinMode(Solder_DIR, OUTPUT); pinMode(Solder_STP, OUTPUT);

  pinMode(Shaft1_DIR, OUTPUT); pinMode(Shaft1_STP, OUTPUT);

  pinMode(Shaft2_DIR, OUTPUT); pinMode(Shaft2_STP, OUTPUT);

// initialize the LED pin as an output:
  pinMode(LEDPIN, OUTPUT);      
// initialize the sensor pin as an input:
  pinMode(SENSORPIN, INPUT);     
  digitalWrite(SENSORPIN, HIGH); // turn on the pullup
}

void loop(){
  step(false, Head1_DIR, Head1_STP, stps_Head1); //Head1,Clockwise
  step(false, Head2_DIR, Head2_STP, stps_Head2); //Head2,Clockwise
  step(false, Solder_DIR, Solder_STP, stps_Solder); //Solder,Clockwise
  step(false, Shaft1_DIR, Shaft1_STP, Shaft1_Solder);//Shaft1,Clockwise
  step(false, Shaft2_DIR, Shaft2_STP, Shaft2_Solder);//Shaft2,Clockwise
  delay(500);

  //step(true, Head1_DIR, Head1_STP, stps_Head1); //Head1, Counterclockwise
  //step(true, Head2_DIR, Head2_STP, stps_Head2); //Head2, Counterclockwise
  //step(true, Solder_DIR, Solder_STP, stps_Solder); //Solder, Counterclockwise
  //step(true, Shaft1_DIR, Shaft1_STP, Shaft1_Solder);//Shaft1,Counterlockwise
  //step(true, Shaft2_DIR, Shaft2_STP, Shaft2_Solder);//Shaft2,counterclockwise
  //delay(10);
}


