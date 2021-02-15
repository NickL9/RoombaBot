
long cm1, cm2, cm3, value1, value2, value3;
const int pingPin = 7;
const int LEDpin = 12;
#include <Servo.h>
Servo myservo;  
int pos = 0;    

void setup() {
  myservo.attach(9);  
  Serial.begin(9600);
  pinMode(LEDpin, OUTPUT);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);             
    delay(15);                     
  }
{
  long duration;
  
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

 
  cm1 = duration / 29 / 2;
  //cm1 = microsecondsToCentimeters(duration);


  Serial.print(cm1);
  Serial.print("cm1");
  Serial.println();

  delay(100);
}
  
  {
    delay(1000);
    }
  for (pos = 180; pos >= 90; pos -= 1) { 
    myservo.write(pos);             
    delay(15);                      
  }
  {
    long duration;

  
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  cm2 = duration / 29 / 2;
  //cm2 = microsecondsToCentimeters(duration);


  Serial.print(cm2);
  Serial.print("cm2");
  Serial.println();

  delay(100);
  }
  {delay(1000);
  }
  for (pos = 90; pos >= 0; pos -= 1) { 
    myservo.write(pos);             
    delay(15);
  }
  {
  delay(1000);
  }
  {
  long duration;

 
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

 cm3 = duration / 29 /2;

  //cm3 = microsecondsToCentimeters(duration);


  Serial.print(cm3);
  Serial.print("cm3");
  Serial.println();
  delay(100);
  }
{

  if ((cm1 < cm2) && (cm1 < cm3)) {
    digitalWrite(LEDpin, HIGH);
    delay(100);
    digitalWrite(LEDpin, LOW);
  }
   else if ((cm2 < cm1) && (cm2 < cm3)) {
    digitalWrite(LEDpin, HIGH);
    delay(100);
    digitalWrite(LEDpin, LOW);
    delay(100);
    digitalWrite(LEDpin, HIGH);
    delay(100);
    digitalWrite(LEDpin, LOW); 
  }
    else if ((cm3 < cm1) && (cm3 < cm2)){
    digitalWrite(LEDpin, HIGH);
    delay(100);
    digitalWrite(LEDpin, LOW);
    delay(100);
    digitalWrite(LEDpin, HIGH);
    delay(100);
    digitalWrite(LEDpin, LOW);
    delay(100);
    digitalWrite(LEDpin, HIGH);
    delay(100);
    digitalWrite(LEDpin, LOW);
   }
  {delay(2000);
  }
}
}

long microsecondsToCentimeters(long microseconds) {
 
  return microseconds / 29 / 2;
}

