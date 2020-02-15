int redPin = 11;
int greenPin = 10;
int bluePin = 9;
 
//uncomment this line if using a Common Anode LED
#define COMMON_ANODE
 
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}
 
void loop()
{
  setColor(255, 0, 0);  // red
  delay(80);
  Serial.println("22");
  setColor(0, 255, 0);  // green
  delay(80);
  setColor(0, 0, 255);  // blue
  delay(80);
  setColor(255, 255, 0);  // yellow
  delay(80);  
  setColor(100, 0, 80);  // purple
  delay(80);
  setColor(0, 255, 255);  // aqua
  delay(80);
}
 
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
