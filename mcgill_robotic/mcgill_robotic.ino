#include <LiquidCrystal.h>

#include <avr/wdt.h>
#include <util/atomic.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int firstOperand;
int secOperand;
int operatorIndex;
String operators[2] = {"-", "+"};
String question; 
String answer;
int answerN;
String intro[10] = {
  "Do you dare?",
  "Harder now!",
  //"Can you try that? I guess not!"
};

int result[10];
int res_length = 0;

int previous0 = 0;
int previous1 = 0;

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

  //Serial.println(btnSet1);
  //Serial.println(btnSet0);
  
  // get the value from the set of btns plugged to A0 
  if(btnSet0 > 1020){
    if(!(previous0 > 1020)){
      saveResult(0);
    }
  }
  else if(btnSet0 >= 990 && btnSet0 <= 1010){
    if(!(previous0 >= 990 && previous0 <= 1010)){
      saveResult(1);
    }
  }
  else if(btnSet0 >= 900 && btnSet0 <= 940){
    if(!(previous0 >= 900 && previous0 <= 940)){
      saveResult(2);
    }
  }
  else if(btnSet0 >= 500 && btnSet0 <= 640){
    if(!(previous0 >= 500 && previous0 <= 640)){
      saveResult(3);
    }
  }
  else if(btnSet0 > 4 && btnSet0 <= 20){
    if(!(previous0 > 4 && previous0 <= 20)){
      saveResult(4);
    }
  }
  
  
  // get the value from the set of btns plugged to A1
  if(btnSet1 > 1020){
    if(!(previous1 > 1020)){
      saveResult(5);
    }
  }
  else if(btnSet1 >= 990 && btnSet1 <= 1010){
    if(!(previous1 >= 990 && previous1 <= 1010)){
      saveResult(6);
    }
  }
  else if(btnSet1 >= 900 && btnSet1 <= 940){
    /*if(previous1 >= 900 && previous1 <= 940){
      saveResult(7);
    }*/
    
    //Serial.println(reset);
    // code for btn reset is placed here because I don't have enough button
    if (!(previous1 >= 900 && previous1 <= 940)) {
      eraseLast();
    }
  }
  else if(btnSet1 >= 500 && btnSet1 <= 640){
    /*if(previous1 >= 500 && previous1 <= 640){
      saveResult(8);
    }*/
    
    // code for btn submit is placed here because I don't have enough button
    if (!(previous1 >= 500 && previous1 <= 640)) {
      computeResult();      
    }
  }
  else if(btnSet1 > 4 && btnSet1 <= 20){
    if(!(previous1 > 4 && previous1 <= 20)){
      saveResult(9);
    }
  }

  previous0 = btnSet0;
  previous1 = btnSet1;
}

void randomCalc() {  
  secOperand = random(100);
  firstOperand = random(100);
  
  lcd.clear();
  lcd.print(intro[random(1)]);
  lcd.setCursor(0, 1);
  operatorIndex = rand() % 2;
  question = String(firstOperand) + " " + operators[operatorIndex] + " " + String(secOperand) + " = "; 
  lcd.print(question);

  answer = "";
}

void saveResult(int num) {
  
  // we limit the length of the answer to 3 digit
  if(answer.length() < 3) {
    /*result[res_length] = num;
    //Serial.println(num);
    res_length++;*/
    
    //String numT = String(num);
  
    answer = answer + String(num);
    lcd.setCursor((question.length() + answer.length() - 1), 2);
    // print the letter:
    lcd.print(String(num));
  }
}

void eraseLast() {
  answer.remove(answer.length()-1);
  Serial.println(answer);
  lcd.setCursor(0, 2);
  lcd.print(question + answer + "  ");
  lcd.setCursor((question.length() + answer.length()), 2);
}

void computeResult() {
  if (answer.length() == 0) {
    randomCalc();
    return;
  }
  
  lcd.clear();
  answerN = atoi(answer.c_str());
  Serial.println(firstOperand - secOperand);
  Serial.println(answerN);

  Serial.println(firstOperand + secOperand);
  Serial.println(answerN);

  Serial.println(operatorIndex);
      
  if(operatorIndex == 0) {
     if(firstOperand - secOperand == answerN) {
        lcd.print("Congrats!");
      }
      else {
        lcd.print("Looser!");
      }
  } else {
      if(firstOperand + secOperand == answerN) {
        lcd.print("Congrats!");
      } 
      else {
        lcd.print("Looser!");
      }
  }
  answer.remove(0);
  }
