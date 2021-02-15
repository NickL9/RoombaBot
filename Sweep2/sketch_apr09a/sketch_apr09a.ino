/*
 Example 3.3 – servo examination
 Created 21/04/2010 —  By John Boxall — http://tronixstuff.wordpress.com — CC by-sa v3.0
 */
#include "Servo.h"
const int buttonPin = 2;
const int LedPin = 12;
Servo myservo;  // create servo object to control a servo 

int pos = 0;    // variable to store the servo position 
int del = 100; // delay in micoseconds
volatile int buttonState = 0;
void setup() 
{ 
  pinMode(LedPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  myservo.attach(9); 
  attachInterrupt(0, pin_ISR, CHANGE);
  // attaches the servo on pin 9 to the servo object 
} 

void loop() 
{ 

  for (int loopy = 0; loopy <= 3; loopy++)
  {
    for (pos = 180; pos >= 0; pos--) // from left to right with Hextronik HXT900
    {
      myservo.write(pos);
      delay(del);
    }
    delay(1000);
  }

  for (int loopy = 0; loopy <= 3; loopy++)
  {
    myservo.write(180);
    delay (1000);
    myservo.write(90);
    delay (1000);
    myservo.write(0);
    delay (3000);
  }
}
  void pin_ISR() {
    buttonState = digitalRead(buttonPin);
    digitalWrite(LedPin, buttonState);
  }

