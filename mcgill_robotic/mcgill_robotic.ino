#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int firstOperand;
int secOperand;
int operatorIndex;
char operators[2] = {'-', '+'}; 
String intro[10] = {
  "Are you dare?",
  "More harder now!",
  //"Can you try that? I guess not!"
};

void setup() {
  //start serial communication
  //Serial.begin(9600);
  lcd.begin(16,2);
  randomCalc();
}

void loop() {
  // create a local variable to hold the input on pin A0
  int btnSet0 = analogRead(A0);
  int btnSet1 = analogRead(A1);
  int userInput;
  
  // get the value from the set of btns plugged to A0 
  if(btnSet0 == 1023){
    // play the first frequency in the array on pin 8
    userInput = 100;
  }
  else if(btnSet0 >= 990 && btnSet0 <= 1010){
    // play the second frequency in the array on pin 8
    userInput = 1;
  }
  else if(btnSet0 >= 900 && btnSet0 <= 940){
    // play the third frequency in the array on pin 8
    userInput = 2;
  }
  else if(btnSet0 >= 500 && btnSet0 <= 640){
    // play the fourth frequency in the array on pin 8
    userInput = 3;
  }
  else if(btnSet0 > 4 && btnSet0 <= 20){
    // play the fourth frequency in the array on pin 8
    userInput = 4;
  }
  
  
  // get the value from the set of btns plugged to A1
  if(btnSet1 == 1023){
    // play the first frequency in the array on pin 8
    userInput = 5;
  }
  else if(btnSet1 >= 990 && btnSet1 <= 1010){
    // play the second frequency in the array on pin 8
    userInput = 6;
  }
  else if(btnSet1 >= 900 && btnSet1 <= 940){
    // play the third frequency in the array on pin 8
    userInput = 7;
  }
  else if(btnSet1 >= 500 && btnSet1 <= 640){
    // play the fourth frequency in the array on pin 8
    userInput = 8;
  }
  else if(btnSet1 > 4 && btnSet1 <= 20){
    // play the fourth frequency in the array on pin 8
    userInput = 9;
  }
  //Serial.println(userInput);
  //Serial.println(btnSet1);
  //Serial.println(btnSet0);
}

String randomCalc() {  
  secOperand = rand() % 100;
  firstOperand = rand() % 100;
  
  lcd.print(intro[rand() % 2]);
  lcd.setCursor(0, 1);
  lcd.print(firstOperand);
  lcd.print(" ");
  lcd.print(operators[rand() % 2]);
  lcd.print(" ");
  lcd.print(secOperand);
  lcd.print(" = ");
}

