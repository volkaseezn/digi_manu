#include <Servo.h>
#define second 1000
#define minute 60000
#define hour 3600000

Servo servo;
const int servoPin = 9;
const int buttonDispensePin = 7;
const int buttonMinusPin = 6;
const int buttonPlusPin = 8;
const int minMoveTime = 130;
const int minServing = 300;
const int ledPin = 13;
int servingTime = 1400; // 1000 – 9g, 2000 – 18g, 3000 – 27g, 3500 – 31g, 4000 - 36g
int servingDelta = 150;
int jerkPeriod = 700; // 1000/1000 – 9g, 1000/500 – 7g, 1400/700 – 12g
unsigned long lastFeeding=0;

void setup ()
{
    Serial.begin(57600);
    Serial.println();
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
    pinMode(buttonDispensePin, INPUT_PULLUP);
    pinMode(buttonMinusPin, INPUT_PULLUP);
    pinMode(buttonPlusPin, INPUT_PULLUP);
    buzz();
}

void loop () 
{
  int dispenseVal = digitalRead(buttonDispensePin);
  if(dispenseVal == LOW)
    dispense(servingTime);
  int plusVal = digitalRead(buttonPlusPin);
  if(plusVal == LOW){
    delay(1000);
    int plusVal = digitalRead(buttonPlusPin);
    if(plusVal == LOW){
      servingTime+=servingDelta;
      buzz();
    }    
  }
  int minusVal = digitalRead(buttonMinusPin);
  if(minusVal == LOW){
    delay(1000);
    int minusVal = digitalRead(buttonMinusPin);
    if(minusVal == LOW){
      servingTime-=servingDelta;
      servingTime = servingTime<minServing?minServing:servingTime;
      buzz();
    }    
  }
  if(millis() - lastFeeding>12*hour)//
    dispense(servingTime);
  delay(10);
}

#define countof(a) (sizeof(a) / sizeof(a[0]))

void dispense(int dispenseTime)
{
  lastFeeding = millis();
  servo.attach(servoPin);
  for(;dispenseTime>0;dispenseTime-=jerkPeriod){
    servo.write(100);
    delay(dispenseTime>=jerkPeriod ? jerkPeriod : dispenseTime%1000);
    jerk();
  }
  stop();
}

void jerk()
{
  servo.write(0);
  delay(minMoveTime);
  servo.write(180);
  delay(minMoveTime);
}

void stop()
{
  servo.write(90);
  delay(100);
  servo.detach();
}

void buzz()
{
  servo.attach(servoPin);
  servo.write(0);
  delay(50);
  jerk();
  jerk();
  stop();
}
