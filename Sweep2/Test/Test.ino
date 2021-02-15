
long cm1, cm2, cm3, value1, value2, value3;
const int pingPin = 7;
const int beater = 8;
const int vaccum = 12;
const int MotorPin1 = 11;
const int MotorPin2 = 10;
#include <Servo.h>
Servo myservo;  
int pos = 0;    

void setup() {
  myservo.attach(9);  
  Serial.begin(9600);
  pinMode(MotorPin1, OUTPUT);
  pinMode(MotorPin2, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(vaccum, OUTPUT);
  pinMode(beater, OUTPUT);
}

void loop() {
  {
  digitalWrite(beater, HIGH);
  digitalWrite(vaccum, HIGH);}
  
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
  {
  digitalWrite(beater, LOW);
  digitalWrite(vaccum, LOW);}
  
  if ((cm1 > cm2) && (cm1 > cm3)) {
    digitalWrite(MotorPin1, HIGH);
    digitalWrite(MotorPin2, LOW);
    delay(500);
    digitalWrite(MotorPin1, LOW);
    digitalWrite(MotorPin2, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
  }
   else if ((cm2 > cm1) && (cm2 > cm3)) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
  }
    else if ((cm3 > cm1) && (cm3 > cm2)){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
   }
}
}

long microsecondsToCentimeters(long microseconds) {
 
  return microseconds / 29 / 2;
}

