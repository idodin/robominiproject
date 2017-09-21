#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int firstOperand;
int secOperand;
int operatorIndex;
char operators[2] = {'-', '+'}; 
String intro[10] = {
  "Do you dare?",
  "More harder now!",
  //"Can you try that? I guess not!"
};

int result[10];
int res_length = 0;

int reset = 0;
int submit = 0;

void setup() {
  //start serial communication
  Serial.begin(9600);
  lcd.begin(16,2);
  randomCalc();
}

void loop() {
  // create a local variable to hold the input on pin A0 - A1
  int btnSet0 = analogRead(A0);
  int btnSet1 = analogRead(A1);
  
  // get the value from the set of btns plugged to A0 
  if(btnSet0 == 1023){
    result[res_length] = 0;
    res_length++;
  }
  else if(btnSet0 >= 990 && btnSet0 <= 1010){
    result[res_length] = 1;
    res_length++;
  }
  else if(btnSet0 >= 900 && btnSet0 <= 940){
    result[res_length] = 2;
    res_length++;
  }
  else if(btnSet0 >= 500 && btnSet0 <= 640){
    result[res_length] = 3;
    res_length++;
  }
  else if(btnSet0 > 4 && btnSet0 <= 20){
    result[res_length] = 4;
    res_length++;
  }
  
  
  // get the value from the set of btns plugged to A1
  if(btnSet1 == 1023){
    result[res_length] = 5;
    res_length++;
  }
  else if(btnSet1 >= 990 && btnSet1 <= 1010){
    result[res_length] = 6;
    res_length++;
  }
  else if(btnSet1 >= 900 && btnSet1 <= 940){
    result[res_length] = 7;
    res_length++;
    
    // code for btn reset is placed here because I don't have enough button
    if (!(reset >= 900 && reset <= 940)) {
      randomCalc();
    }
  }
  else if(btnSet1 >= 500 && btnSet1 <= 640){
    result[res_length] = 8;
    res_length++;
    
    // code for btn submit is placed here because I don't have enough button
    //if (!(submit >= 500 && submit <= 640)) {
      computeResult();      
    //}
  }
  else if(btnSet1 > 4 && btnSet1 <= 20){
    result[res_length] = 9;
    res_length++;
  }
  //Serial.println(userInput);
  //Serial.println(btnSet1);
  //Serial.println(btnSet0);
  reset = btnSet1;
  submit = btnSet1;
}

void randomCalc() {  
  secOperand = rand() % 100;
  firstOperand = rand() % 100;
  
  lcd.clear();
  lcd.print(intro[rand() % 2]);
  lcd.setCursor(0, 1);
  lcd.print(firstOperand);
  lcd.print(" ");
  lcd.print(operators[rand() % 2]);
  lcd.print(" ");
  lcd.print(secOperand);
  lcd.print(" = ");
}

void computeResult() {
  //Serial.println(result);
  for ( int i = 0; i < res_length; i++ ) {
    Serial.println(result[i]);
  }
}


