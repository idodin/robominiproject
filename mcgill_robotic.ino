/*
  Arduino Starter Kit example
 Project 7  - Keyboard
 
 This sketch is written to accompany Project 7 in the
 Arduino Starter Kit
 
 Parts required:
 two 10 kilohm resistors
 1 Megohm resistor 
 220 ohm resistor
 4 pushbuttons
 piezo
 
 Created 13 September 2012
 by Scott Fitzgerald
 
 http://arduino.cc/starterKit
 
 This example code is part of the public domain 
*/

void setup() {
    //start serial communication
  Serial.begin(9600);
}

void loop() {
  // create a local variable to hold the input on pin A0
  int btnSet0 = analogRead(A0);
  int btnSet1 = analogRead(A1);
  
  Serial.println(btnSet0);
  // send the value from A0 to the Serial Monitor  
  /*if(btnSet0 == 1023){
    // play the first frequency in the array on pin 8
    Serial.println(100);
  }
  else if(btnSet0 >= 990 && btnSet0 <= 1010){
    // play the second frequency in the array on pin 8
    Serial.println(1);
  }
  else if(btnSet0 >= 900 && btnSet0 <= 940){
    // play the third frequency in the array on pin 8
    Serial.println(2);
  }
  else if(btnSet0 >= 500 && btnSet0 <= 640){
    // play the fourth frequency in the array on pin 8
    Serial.println(3);
  }
  else if(btnSet0 > 4 && btnSet0 <= 20){
    // play the fourth frequency in the array on pin 8
    Serial.println(4);
  }*/
  
  
  // send the value from A1 to the Serial Monitor
  /*if(btnSet1 == 1023){
    // play the first frequency in the array on pin 8
    Serial.println(5);
  }
  else if(btnSet1 >= 990 && btnSet1 <= 1010){
    // play the second frequency in the array on pin 8
    Serial.println(6);
  }
  else if(btnSet1 >= 900 && btnSet1 <= 940){
    // play the third frequency in the array on pin 8
    Serial.println(2);
  }
  else if(btnSet1 >= 500 && btnSet1 <= 640){
    // play the fourth frequency in the array on pin 8
    Serial.println(7);
  }
  else if(btnSet1 > 4 && btnSet1 <= 20){
    // play the fourth frequency in the array on pin 8
    Serial.println(8);
  }
  else{
    // if the value is out of range, play no tone
    Serial.println(btnSet1);
  }*/
}
  

