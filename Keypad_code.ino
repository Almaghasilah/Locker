//Backspace code:
//else if(key == 'D') {
//      --k;
//      UL[k] = 0;
//      Serial.print(UL[k]);
//     
//      }
// There are also PRESS,HOLD and RELEASE functions
//===================================

#include <Keypad.h>
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(22, 23, 27, 26, 25, 24);

unsigned long t_hold;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
int k = 0;
int l = 0;
int c = 0;
int b = 0;
int a = 0;
int post;
char UL[3];
char passWord[4] ={'A','B','C'};
char chanPass[8];
char origPass[4];


char keys[ROWS][COLS] = {
  {'1','2','3','A'}
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

//Columns
//The first 4 pins from the left are columns: Col1,Col2,Col3 and Col4.
//col1 is connected to 9,col2 is 8, col3 is 7 and col4 is 6 in the Arduino.

//Rows
//The rest of the four pins are rows:row1,row2, row3 and row4.
//row1 is 5, row2 is 4, row3 is 3 and row4 is 2.

//Keypad
//   1    2    3    A
//   4    5    6    B
//   7    8    9    C
//   *    0    #    D
// Keypad         :header1  header2  header3  header4  header5  header6  header7  header8 
// confiugration  :column1  column2  column3  column4  row1     row2     row3     row4
// Ardunio        :pin 9    pin 8    pin 7    pin 6    pin 5    pin 4    pin 3    pin 2 

byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
      int s = 0;
      char key;

      // set up the LCD's number of columns and rows:
      lcd.begin(16, 2);
      Serial.begin(9600);
      Serial.println("=================================");
      Serial.println("Hold '*' to change password");
      
//      lcd.home();
//      for(post =0; post >=-19; post--){
//      lcd.setCursor(post,0);
//      lcd.print(" Hold * to change password ");
//      delay(300);
//       lcd.clear();
//      }
//      lcd.clear();
//      lcd.home();
//      for( post=1; post >=-18; post--){
//      lcd.clear();
//      lcd.setCursor(post,1);  
//      lcd.print(" Hold '#' to get original password");
//      delay(300);
//        }
     
      Serial.println("Hold '#' to get back to original password");
      Serial.println("=================================");
      //for reseting a new password
      for(l=0; l<=3; l++){
       origPass[l] = passWord[l];
      }
      keypad.addEventListener(keypadEvent); //add an event listener for this keypad
      keypad.setHoldTime(2000); //hold time the default is one second
     //setting a password
     Serial.println("Do You want to setup a password?");
     delay(1000);
     lcd.clear();
     lcd.home();
     for( post=0; post <=22; post++){
      lcd.setCursor(0,0);  
      lcd.print(" Do you want to setup a password? ");
      lcd.scrollDisplayLeft();
      delay(250);
        }
     lcd.clear();
     lcd.home();
     
     Serial.println("Press '1' for YES and '0' for NO");
      while(s<1){ 
          lcd.setCursor(0,0);
          lcd.print("YES = 1 and NO=0");
           while((key = keypad.getKey()) != NO_KEY){
                if(key != '1' && key !='0'){
                  Serial.println("Undefined key");
                  lcd.setCursor(0,1);
                  lcd.print("Undefined Key!");
                  delay(1000);
                  lcd.setCursor(0,1);
                  lcd.print("               ");
                  Serial.println("Please press '1' for YES and '0' for NO");
                  }
                  //Yes
                 else if(key == '1'){
                       Serial.println("YES");
                       lcd.setCursor(0,1);
                       lcd.print("YES");
                       delay(1000);
                       // Turn off the blinking cursor:
                        lcd.noBlink();
                        delay(200);
                        // Turn on the blinking cursor:
                        lcd.blink();
                        delay(200);
                       setPass();
                        s++;
                  }
                  //No
                 else if(key == '0'){
                  Serial.println("NO");
                  lcd.setCursor(0,1);
                  lcd.print("NO");
                  delay(1000);
                  lcd.clear(); 

                  //Scrolling text to the left
                  for(post = 0; post <= 15; post++){
                  lcd.setCursor(0,0);
                  delay(400);
                  lcd.print(" The defualt password:ABC");
                  lcd.scrollDisplayLeft();
                  }
                  
                  // Turn off the blinking cursor:
                  lcd.noBlink();
                  delay(200);
                  // Turn on the blinking cursor:
                  lcd.blink();
                  delay(200);
                  //display text on serial monitor
                  Serial.println("The defualt password: ABC");
                  s++;
                  }
            }
        
        }
       Serial.println("*********************");
      Serial.println("Please enter password: ");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Enter Password");

}


//SetPass()
//The password get setted up for the first time when the program is runned
void setPass(){
     Serial.println("Enter password");
     lcd.clear();
     lcd.home();
     lcd.setCursor(0,0);
     lcd.print(" Enter Password");
     int s =0;
     l = 0;
     char key;
     while(s < 1){
          while((key = keypad.getKey()) != NO_KEY  && key != 'D'){ 
                passWord[l] = key;
                Serial.print(key);
                lcd.setCursor(l,1);
                lcd.print(key);
                l++;
                
                
                
                if(l == 3){
                    delay(1000);
                    Serial.println(" ");
                    Serial.println("Your password:");
                   // delay(1000);
                    lcd.clear();
                    lcd.home();
                    lcd.setCursor(0,0);
                    lcd.print("Your password");
                    for(l=0; l<3; l++){
                      Serial.print(passWord[l]);
                      lcd.setCursor(l,1);
                      lcd.print(passWord[l]);
                      }
                      delay(1000);
                      s++;
                      Serial.println(" ");
                  }
            
            }

      }
  
  }


//passExist()
//Here we test if the password match the one is saved.  
void passExist(){
        
        a =0;  //needs to assign it to zero to make the '#' and '*' work
               //where the condition is if(a ==).
               
        char key = keypad.getKey();
        //the key != 'D' is included so it does not print out and save 'D' charater.
        if (key != NO_KEY && key != 'D'){
          
          // Turn off the blinking cursor:
          lcd.noBlink();
          delay(200);
          // Turn on the blinking cursor:
          lcd.blink();
          delay(200);
          
          UL[k] = key; 
          key = '*';
          Serial.print(key);
          lcd.setCursor(k,1);
          lcd.print(key); 
          k++;
          
                
               // compare the pass word and string of UL[]
               //it has to be 3 keys and the same array.
               if (k == 3 && UL[0] == passWord[0] && UL[1] == passWord[1] && UL[2] == passWord[2]){
                 delay(500);
                 k =0;
                 Serial.println(" ");
                 Serial.println("Password is correct!");
                 lcd.clear();
                 lcd.home();
                 lcd.print("Correct!");
                 delay(1000);
                 Serial.println("********************");
                 Serial.println("Please enter password: ");
                 lcd.clear();
                 lcd.home();
                 lcd.print("Enter Password");
               }
               //this is in case the pressed keys were not correct and it does not exceed the limit (3 keys)
                 if(k == 3){
                 delay(500);
                 k =0;
                 Serial.println(" ");
                 Serial.println("password is wrong!");
                 lcd.clear();
                 lcd.home();
                 lcd.print("Wrong");
                 delay(1000);
                 Serial.println("********************");
                 Serial.println("Please enter password:");
                 lcd.clear();
                 lcd.home();
                 lcd.print("Enter Password");
                 }
      
            }
         //this code for backspace.
         //so when D is pressed it will delete the last digi in the screen.
//            else if(key != NO_KEY && key == 'D'){
//                  k--;               
//                 UL[k]=' ';
//                 if(k == 0){
//                    lcd.setCursor(0,1);
//                    lcd.print(" ");
//                  }
//                  else if(k == 1){
//                     lcd.setCursor(1,1);
//                     lcd.print(" ");
//                    }
//
//                   else if (k == 2){
//                    lcd.setCursor(2,1);
//                     lcd.print(" ");
//                    }
//                } 
  
  }


//loop()
//looping for ever.
void loop(){

  passExist();
     
}


//keypadEvent()
//take care of some special events
void keypadEvent(KeypadEvent key){
  switch (keypad.getState()){
    case PRESSED:
      switch (key){
        case 'D': 
                //return the arrary first back
                // k is used in passExist(), where the password has been setted or exists from original defualt.
                  k--;
                // a is used in changPass(), where the user changes a password '*'.
                  a--; 
                // l is used in setPass() when the program runs for the first time. 
                  l--;
                  
                 //make the return array equals to space in other words nothing.
                 // UL[k] is used in passExist().               
                 UL[k] = ' ';
                 //chanPass[a] is used in changPass().
                 chanPass[a] = ' ';
                 //passWord[l] is used in setPass().
                 passWord[l] = ' ';
                 
                 if(k == 0 || a == 0){
                    lcd.setCursor(0,1);
                    lcd.print("");
                  }
                  else if(k == 1 || a == 1){
                     lcd.setCursor(1,1);
                     lcd.print("");
                    }

                   else if (k == 2 || a ==2){
                    lcd.setCursor(2,1);
                     lcd.print("");
                    }
                break;

//      case '*':  
      }   
        break;
    case RELEASED:
//     switch (key){
//       case '*':   if(UL[0] == '*'){
//                 changPass();
//                 }
       
       break;
//     }
    case HOLD:
      switch (key){
             case '*': if(a == 0 ){
                   //lcd.clear();
                   //lcd.print("Reset Password");
                   delay(1000);
                   changPass();
             }
             break;
             case '#':if(a == 0 ){
                    //lcd.clear();
                    //lcd.print("Defualt Password");
                    delay(1000);
                    origWord();
             }
                break;
      }
    break;
  }
}


//changPass()
//After user pressed '*', will promote to this function
void changPass(){
   c = 0;  //an option if the user want to keep the new password or not. 
   a = 0;  //for typing new password.
   b = 0;  //to break out from the first loop of changPass in case the desired work is done.
   k = 0;  //this is to make sure the k counting start from zero whenever enters in changPass().
  char key = keypad.getKey();
  
  Serial.println(" ");
  delay(500);
  Serial.println("Changing password?");
  lcd.clear();
  lcd.print(" Reset Password?");
  delay(1000);
  Serial.println("Please type '1' for Yes or '0' for No to continue");
  lcd.setCursor(0,1);
  lcd.print("YES or NO");
  delay(1000);
  while (b != 1){
       lcd.clear();
       lcd.print("Yes=1 / No=0");
       delay(100);
       while((key = keypad.getKey()) != NO_KEY){
              c = 0;
              //Serial.println(key);
              
              if (key != '0' && key != '1'){
                  Serial.println("Undefined key");
                  delay(500);
                  lcd.setCursor(0,1);
                  lcd.print("Undefined Key");
                  delay(1000);
                  lcd.setCursor(0,1);
                  lcd.print("             ");
                  Serial.println("Please press '1' for yes or '0' for no");
                
              }
              
              else if (key == '0'){
                 Serial.println("NO");
                 lcd.setCursor(0,1);
                 lcd.print("NO");
                 delay(1000);
                 lcd.print("   ");
                 Serial.println("Don't worry! you will get back to password mode in a bit");
                 lcd.setCursor(0,1);
                 lcd.print("Password Mode");
                 delay(1000);
                 lcd.setCursor(13,1);
                 lcd.print(".");
                 Serial.print(".");
                 delay(1000);
                 lcd.setCursor(14,1);
                 lcd.print(".");
                 Serial.print(".");
                 delay(1000);
                 lcd.setCursor(15,1);
                 lcd.print(".");
                 Serial.print(".");
                 delay(1000);
                 Serial.println(".");
                 b++;
                 lcd.clear();
                 lcd.print("Enter Password");
                 Serial.println("********************");
                 Serial.println("Please enter password: ");
                 
                  
               }
              else if (key == '1'){
                    Serial.println("YES");
                    lcd.setCursor(0,1);
                    lcd.print("YES");
                    delay(1000);
                    Serial.println("Tyep your new password (three characters):");
                    lcd.clear();
                    lcd.print("Type Password");
                    while(a !=3 ){
                          while((key = keypad.getKey()) != NO_KEY && key != 'D') {
                          chanPass[a] = key;
                          Serial.print(key);
                          lcd.setCursor(a,1);
                          lcd.print(key);
                          a++;
                          }
                    }
              }
                     if ( a >= 3 && c ==0){
                        Serial.println(" ");
                        Serial.println("You just changed your password!");
                        delay(1000);
                        Serial.println("Are you stasified with the new password");
                        lcd.clear();
                        lcd.print("Are U Stasified?");
                        lcd.setCursor(0,1);
                        delay(1000);
                        Serial.println("'1' for yes and '0'for no?");
                        
                        while(c < 1){
                                lcd.clear();
                                lcd.home();
                                lcd.print("YES=1 / NO=0");
                                delay(100);
                               while((key = keypad.getKey()) != NO_KEY){
                                      if (key == '0'){
                                         Serial.println("NO");
                                         lcd.setCursor(0,1);
                                         lcd.print("NO");
                                         delay(1000);
                                         lcd.print("   ");
                                         //delay(500);
                                         Serial.println("ok! lets' start over!");
                                         lcd.setCursor(0,1);
                                         lcd.print("Ok! Start Ovar");
                                         delay(1000);
                                         c++;
                                         a = 0;
                                         Serial.println(" ");
                                         delay(500);
                                         Serial.println("Changing password?");
                                         lcd.clear();
                                         lcd.home();
                                         lcd.print("Reset Password?");
                                         delay(1000);
                                         Serial.println("Please type '1' for Yes or '0' for No to continue");
                                         lcd.setCursor(0,1);
                                         lcd.print("Yes=1 / No=0");
                                         
                                       }
                                       else if (key == '1'){
                                              Serial.println("YES");
                                              lcd.setCursor(0,1);
                                              lcd.print("YES");
                                              delay(1000);
                                              lcd.print("    ");
                                              Serial.println("Give me a minute to save the new password");
                                              lcd.clear();
                                              lcd.print("Saving Password");
                                              delay(1000);
                                              Serial.print(".");
                                              lcd.setCursor(3,1);
                                              lcd.print(".");
                                              delay(1000);
                                              Serial.print(".");
                                              lcd.setCursor(4,1);
                                              lcd.print(".");
                                              delay(1000);
                                              Serial.print(".");
                                              lcd.setCursor(5,1);
                                              lcd.print(".");
                                              delay(1000);
                                              Serial.print(".");
                                              lcd.setCursor(6,1);
                                              lcd.print(".");
                                              for(a=0; a<= 3; a++){
                                                passWord[a] = chanPass[a];
                                              }
                                              //turn off the display
                                              lcd.noDisplay();
                                              delay(500);
                                              //turn on the display
                                              lcd.display();
                                              delay(500);
                                              
                                              Serial.println(" ");
                                              Serial.println("Done! Your new password is:");
                                              lcd.clear();
                                              lcd.print("Your password:");
                                              Serial.print( passWord[0] );
                                              lcd.setCursor(0,1);
                                              lcd.print(passWord[0]);
                                              Serial.print( passWord[1] );
                                              lcd.setCursor(2,1);
                                              lcd.print(passWord[1]);
                                              Serial.println( passWord[2] );
                                              lcd.setCursor(3,1);
                                              lcd.print(passWord[3]);
                                              b++;
                                              Serial.println("********************");
                                              Serial.println("Please enter password: ");
                                              lcd.clear();
                                              lcd.print("Enter Password");
                                              a =0;
                                        }
                                      
                                       c++;
                                     
                                }
                                
                         }
                     } 
                        
            }
  
       }
  } 

  
//origWord()
//after user presses '#', it will excute this funtion which makes password ABC,  
void origWord(){
     Serial.println(" ");
     Serial.println("Going back to the original password");
     lcd.clear();

     //scrolling the text (lcd.print(back....))
     for(post =0;post <= 15; post++){
     lcd.setCursor(0,0);
     lcd.print(" Back to defulat password:ABC");
     lcd.scrollDisplayLeft();
     delay(500); 
     }

     //Saving the oringinal password from above
     for(l=0; l<=3; l++){
       passWord[l] = origPass[l] ;
      }
      //setting k which is indext of password array to zero
     k =0;
     Serial.println("********************");
     Serial.println("Please enter password: ");
     lcd.clear();
     lcd.print("Enter Password");
     delay(1000);
  }
  
