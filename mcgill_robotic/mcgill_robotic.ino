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
int previous2 = 0;

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
  int btnSet2 = analogRead(A2);

  //Serial.println(btnSet1);
  //Serial.println(btnSet0);
  
  // get the value from the set of btns plugged to A0 
  if(btnSet0 > 1015){
    if(!(previous0 > 1015)){
      saveResult(9);
    }
  }
  else if(btnSet0 >= 980 && btnSet0 <= 1010){
    if(!(previous0 >= 980 && previous0 <= 1010)){
      saveResult(8);
    }
  }
  else if(btnSet0 >= 480 && btnSet0 <= 640){
    if(!(previous0 >= 480 && previous0 <= 640)){
      saveResult(7);
    }
  }
  else if(btnSet0 > 4 && btnSet0 <= 20){
    if(!(previous0 > 4 && previous0 <= 20)){
      saveResult(6);
    }
  }
  
  
  // get the value from the set of btns plugged to A1
  if(btnSet1 > 1015){
    if(!(previous1 > 1015)){
      saveResult(5);
    }
  }
  else if(btnSet1 >= 980 && btnSet1 <= 1010){
    if(!(previous1 >= 980 && previous1 <= 1010)){
      saveResult(4);
    }
  }
  else if(btnSet1 >= 480 && btnSet1 <= 640){
    if(!(previous1 >= 500 && previous1 <= 640)){
      saveResult(3);
    }
  }
  else if(btnSet1 > 4 && btnSet1 <= 20){
    if(!(previous1 > 4 && previous1 <= 20)){
      saveResult(2);
    }
  }
  
  // get the value from the set of buttons plugged into A2
  if(btnSet2>1015){
    if(!(previous2 > 1015)){
      saveResult(1);
    }
  }
  else if(btnSet2 >= 980 && btnSet2 <= 1010){
    if(!(previous2 >= 980 && previous2 <= 1010)){
      saveResult(0);
    }
  }

  previous0 = btnSet0;
  previous1 = btnSet1;
  previous2 = btnSet2;
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
  // convert answer back into integer
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
        lcd.print("Loser!");
      }
  } else {
      if(firstOperand + secOperand == answerN) {
        lcd.print("Congrats!");
      } 
      else {
        lcd.print("Loser!");
      }
  }
  answer.remove(0);
  }
