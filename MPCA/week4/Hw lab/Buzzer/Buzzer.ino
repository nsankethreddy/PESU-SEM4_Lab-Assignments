  
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(8, OUTPUT);
}
  int a = 0;
  int b = 1;
  int c = 0;
// the loop function runs over and over again forever
void loop() {
  
  // c = a + b;
  digitalWrite(8, LOW); // turn the LED on (HIGH is the voltage level)
  delay(c);              // wait for a second
  digitalWrite(8, HIGH);    // turn the LED off by making the voltage LOW
  delay(c);              // wait for a second
  Serial.println(analogRead(c));
  //a = b;
  //b = c;
   c++;
}
