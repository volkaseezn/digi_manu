#include <DS1307.h>
#include <Servo.h>
#include <LiquidCrystal.h>
#include "rgb_lcd.h"

const int stepPin = 10;
const int button1pin = D2;
const int button2pin = D3;
const int dirPin = A3;
const int moisSens = A4;
int moisSensVal = 0;


DS1307 clock;

rgb_lcd lcd;

int feed_time = 2000;  // define how fast stepper motor works
int feed_length = 600; // define how much steps should your motor do (mine does 200 for full spin)

String feed1;
String feed2;
String feed3;
String feed4;

void setup()
{   
    clock.begin();
    clock.fillByYMD(2023,6,27);//Jan 19,2013
    clock.fillByHMS(15,28,30);//15:28 30"
    clock.fillDayOfWeek(TUE);//Saturday
    clock.setTime();//write time to the RTC chip

    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);

    Serial.begin(9600);

    pinMode(button1pin, INPUT);
    pinMode(button2pin, INPUT);
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(stepPin, OUTPUT);
    pinMode(dirPin, OUTPUT);
}

void loop()
{

    button1state = digitalRead(button1pin);
    button2state = digitalRead(button2pin);

    if (button1state == HIGH){
        lcd.setCursor(0, 0);
        lcd.print("Time: ");
        lcd.print(clock.getTime());

        lcd.setCursor(0, 1);
        lcd.print("Mode: Cat Mode");
        
        catMode();
    }
    else if (button2state = HIGH){
        lcd.setCursor(0, 0);
        lcd.print("Time: ");
        lcd.print(clock.getTime());

        lcd.setCursor(0, 1);
        lcd.print("Mode: Cat Mode");

        dogMode();
    }
    else{
        lcd.setCursor(0, 0);
        lcd.print("Time: ");
        lcd.print(clock.getTime());
        lcd.setCursor(0, 1);
    }

    checkHumid();
}

void catMode(){

    feed1, feed2, feed3, feed4 == "07:00:00", "13:00:00", "19:00:00", "01:00:00";

    if (feed1==clock.getTime()){  
    digitalWrite(dirPin,HIGH);        // Enables the motor to move in a particular direction
  
    for(int x = 0; x < feed_length; x++) {     // Makes 200 pulses for making one full cycle rotation
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(feed_time); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(feed_time); 
    }
    delay(1000);
    }
    if (feed2==clock.getTime()){  
    digitalWrite(dirPin,HIGH);        // Enables the motor to move in a particular direction
  
    for(int x = 0; x < feed_length; x++) {     // Makes 200 pulses for making one full cycle rotation
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(feed_time); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(feed_time); 
    }
    delay(1000);
    } 
    if (feed3==clock.getTime()){  
    digitalWrite(dirPin,HIGH);        // Enables the motor to move in a particular direction
  
    for(int x = 0; x < feed_length; x++) {     // Makes 200 pulses for making one full cycle rotation
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(feed_time); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(feed_time); 
    }
    delay(1000);
    } 
    if (feed4==clock.getTime()){  
    digitalWrite(dirPin,HIGH);        // Enables the motor to move in a particular direction
  
    for(int x = 0; x < feed_length; x++) {     // Makes 200 pulses for making one full cycle rotation
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(feed_time); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(feed_time); 
    }
    delay(1000);
    } 
}

void dogMode(){
    feed1, feed2 = "07:00:00", "14:00:00";
    
    if (feed1 == clock.getTime()){  
    digitalWrite(dirPin,HIGH);        // Enables the motor to move in a particular direction
  
    for(int x = 0; x < feed_length; x++) {     // Makes 200 pulses for making one full cycle rotation
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(feed_time); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(feed_time); 
    }
    delay(1000);
    }
    
    if (feed2 == clock.getTime()){  
    digitalWrite(dirPin,HIGH);        // Enables the motor to move in a particular direction
  
    for(int x = 0; x < feed_length; x++) {     // Makes 200 pulses for making one full cycle rotation
        digitalWrite(stepPin,HIGH); 
        delayMicroseconds(feed_time); 
        digitalWrite(stepPin,LOW); 
        delayMicroseconds(feed_time); 
    }
    delay(1000);
    } 
}

void checkHumid(){
    moisSensVal = analogRead(moisSens);

    Serial.print("Humidity (%): ");
    Serial.println(moisSensVal);

    if (moisSensVal >= 100 && moisSensVal <= 1024){
        digitalWrite(dirPin,HIGH);        // Enables the motor to move in a particular direction
  
        for(int x = 0; x < (int)(feed_length/2); x++) {     // Makes 200 pulses for making one full cycle rotation
            digitalWrite(stepPin,HIGH); 
            delayMicroseconds(feed_time); 
            digitalWrite(stepPin,LOW); 
            delayMicroseconds(feed_time); 
        }
    delay(5000);
    }
}
