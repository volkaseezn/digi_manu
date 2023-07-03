#include <DS1307.h>
#include <Servo.h>
#include <LiquidCrystal.h>
#include "rgb_lcd.h"
#include <string.h>
#include "Arduino.h"

const int stepPin = 10;
const int button1pin = 2;
const int button2pin = 3;
const int dirPin = A3;
const int moisSens = A4;
int moisSensVal = 0;

const int colorR = 255;
const int colorG = 255;
const int colorB = 0;

unsigned char curTime[200];
unsigned char chour;
unsigned char cmin;
unsigned char csec;

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
    clock.fillByYMD(2023, 7, 3); // Jan 19,2013
    clock.fillByHMS(06, 59, 34); // 15:28 30"
    clock.fillDayOfWeek(MON);    // Saturday
    clock.setTime();             // write time to the RTC chip

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

    int button1state = digitalRead(button1pin);
    int button2state = digitalRead(button2pin);

    if (button1state == HIGH)
    {
        clock.getTime();
        chour = clock.hour;
        cmin = clock.minute;
        csec = clock.second;

        strcat(curTime, chour);
        strcat(curTime, ":");
        strcat(curTime, cmin);
        strcat(curTime, ":");
        strcat(curTime, csec);

        lcd.setCursor(0, 0);
        lcd.print("Time: ");
        lcd.print(clock.hour);
        lcd.print(":");
        lcd.print(clock.minute);
        lcd.print(":");
        lcd.print(clock.second);

        lcd.setCursor(0, 1);
        lcd.print("Mode: Cat Mode");

        catMode();
    }
    else if (button2state = HIGH)
    {
        clock.getTime();
        chour = clock.hour;
        cmin = clock.minute;
        csec = clock.second;

        strcat(curTime, chour);
        strcat(curTime, ":");
        strcat(curTime, cmin);
        strcat(curTime, ":");
        strcat(curTime, csec);

        lcd.setCursor(0, 0);
        lcd.print("Time: ");
        lcd.print(clock.hour);
        lcd.print(":");
        lcd.print(clock.minute);
        lcd.print(":");
        lcd.print(clock.second);

        lcd.setCursor(0, 1);
        lcd.print("Mode: Dog Mode");

        dogMode();
    }
    else
    {
        clock.getTime();
        chour = clock.hour;
        cmin = clock.minute;
        csec = clock.second;

        strcat(curTime, chour);
        strcat(curTime, ":");
        strcat(curTime, cmin);
        strcat(curTime, ":");
        strcat(curTime, csec);

        lcd.setCursor(0, 0);
        lcd.print("Time: ");
        lcd.print(clock.hour);
        lcd.print(":");
        lcd.print(clock.minute);
        lcd.print(":");
        lcd.print(clock.second);
        lcd.setCursor(0, 1);

        dogMode();
    }

    checkHumid();
}

void catMode()
{

    feed1, feed2, feed3, feed4 == "07:00:00", "13:00:00", "19:00:00", "01:00:00";

    clock.getTime();
    chour = clock.hour;
    cmin = clock.minute;
    csec = clock.second;

    strcat(curTime, chour);
    strcat(curTime, ":");
    strcat(curTime, cmin);
    strcat(curTime, ":");
    strcat(curTime, csec);

    if (feed1 == curTime)
    {
        digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction

        for (int x = 0; x < feed_length; x++)
        { // Makes 200 pulses for making one full cycle rotation
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(feed_time);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(feed_time);
        }
        delay(1000);
    }
    if (feed2 == curTime)
    {
        digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction

        for (int x = 0; x < feed_length; x++)
        { // Makes 200 pulses for making one full cycle rotation
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(feed_time);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(feed_time);
        }
        delay(1000);
    }
    if (feed3 == curTime)
    {
        digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction

        for (int x = 0; x < feed_length; x++)
        { // Makes 200 pulses for making one full cycle rotation
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(feed_time);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(feed_time);
        }
        delay(1000);
    }
    if (feed4 == curTime)
    {
        digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction

        for (int x = 0; x < feed_length; x++)
        { // Makes 200 pulses for making one full cycle rotation
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(feed_time);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(feed_time);
        }
        delay(1000);
    }
}

void dogMode()
{
    feed1, feed2 = "07:00:00", "14:00:00";

    clock.getTime();
    chour = clock.hour;
    cmin = clock.minute;
    csec = clock.second;

    strcat(curTime, chour);
    strcat(curTime, ":");
    strcat(curTime, cmin);
    strcat(curTime, ":");
    strcat(curTime, csec);

    if (feed1 == curTime)
    {
        digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction

        for (int x = 0; x < feed_length; x++)
        { // Makes 200 pulses for making one full cycle rotation
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(feed_time);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(feed_time);
        }
        delay(1000);
    }

    if (feed2 == curTime)
    {
        digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction

        for (int x = 0; x < feed_length; x++)
        { // Makes 200 pulses for making one full cycle rotation
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(feed_time);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(feed_time);
        }
        delay(1000);
    }
}

void checkHumid()
{
    moisSensVal = analogRead(moisSens);

    Serial.print("Humidity (%): ");
    Serial.println(moisSensVal);

    if (moisSensVal >= 100 && moisSensVal <= 1024)
    {
        digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction

        for (int x = 0; x < (int)(feed_length / 2); x++)
        { // Makes 200 pulses for making one full cycle rotation
            digitalWrite(stepPin, HIGH);
            delayMicroseconds(feed_time);
            digitalWrite(stepPin, LOW);
            delayMicroseconds(feed_time);
        }
        delay(1000);
    }
}
