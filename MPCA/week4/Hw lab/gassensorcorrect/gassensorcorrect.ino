#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

const int gasPin = A0;

int pos  = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int servo_pin=7;
  myservo.attach(servo_pin);  // attaches the servo on pin 10 to the servo object
}

void servoRotate() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15ms for the servo to reach the position
  }
}

void loop() {
 
  Serial.println(analogRead(gasPin));
  if(analogRead(gasPin) > 500) {
    servoRotate();
  }
  
  delay(1000);//print value every 1 sec
  // put your main code here, to run repeatedly:

} 
