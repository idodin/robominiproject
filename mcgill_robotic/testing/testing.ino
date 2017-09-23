void setup() {
  Serial.begin(9600);

}

void loop() {
  int btnSet0 = analogRead(A0);
  int btnSet1 = analogRead(A1);
  int btnSet2 = analogRead(A2);
  Serial.println("Button Set 0 is reading..." + String(btnSet0));
  Serial.println("Button Set 1 is reading..." + String(btnSet1));
  Serial.println("Button Set 2 is reading..." + String(btnSet2));
}
