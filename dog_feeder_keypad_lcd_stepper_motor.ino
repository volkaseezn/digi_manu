#include <DS3231.h>
#include <Servo.h>
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <dht11.h>


#define DHT11PIN 4

dht11 DHT11;

const byte ROWS = 4;
const byte COLS = 4;
const int stepPin = 10;
const int dirPin = A3;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = { 2, 3, 4, 5 };
byte colPins[COLS] = { 6, 7, 8, 9 };

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
DS3231 rtc(A4, A5);

LiquidCrystal lcd(A0, A1, A2, 11, 12, 13); // (rs, enable, d4, d5, d6, d7)

int feed_time = 2000;       //define how fast stepper motor works
int feed_length = 600;             //define how much steps should your motor do (mine does 200 for full spin)

String feed1;
String feed2;
char key[8];
int j = 0;
char button;


 void setup() {
  
  rtc.begin();
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}
 
 void loop() {

 lcd.setCursor(0,0);
 lcd.print("Time: ");
 lcd.print(rtc.getTimeStr());
 lcd.setCursor(0,1);
      //lcd.print("Date: ");               //Date to display
      //lcd.print(rtc.getDateStr());
 lcd.print("1)");
 lcd.print(feed1);
 lcd.setCursor(7,1);
 lcd.print(" 2)");
 lcd.print(feed2);
 lcd.setCursor(15,1);
 lcd.print(" ");
  
 button = keypad.getKey();
 
 if(button == 'A'){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("HH:MM:SS 1st");
  delay(500);
  j = 0;
  lcd.setCursor(j,1);
  key[0] = keypad.waitForKey();
  lcd.print(key[0]);j++;
  lcd.setCursor(j,1);
  key[1] = keypad.waitForKey();
  lcd.print(key[1]);j++;
  lcd.setCursor(j,1);
  key[2] = ':';
  lcd.print(key[2]);j++;
  lcd.setCursor(j,1);
  key[3] = keypad.waitForKey();
  lcd.print(key[3]);j++;
  lcd.setCursor(j,1);
  key[4] = keypad.waitForKey();
  lcd.print(key[4]);j++;
  lcd.setCursor(j,1);
  key[5] = ':';
  lcd.print(key[5]);j++;
  lcd.setCursor(j,1);
  key[6] = keypad.waitForKey();
  lcd.print(key[6]);j++;
  lcd.setCursor(j,1);
  key[7] = keypad.waitForKey();
  lcd.print(key[7]);
  key[8] = '\0';
  feed1 = String(key);
  delay(1000);
  lcd.clear(); 
 }

 if(button == 'B'){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("HH:MM:SS 2nd");
  delay(500);
  j = 0;
  lcd.setCursor(j,1);
  key[0] = keypad.waitForKey();
  lcd.print(key[0]);j++;
  lcd.setCursor(j,1);
  key[1] = keypad.waitForKey();
  lcd.print(key[1]);j++;
  lcd.setCursor(j,1);
  key[2] = ':';
  lcd.print(key[2]);j++;
  lcd.setCursor(j,1);
  key[3] = keypad.waitForKey();
  lcd.print(key[3]);j++;
  lcd.setCursor(j,1);
  key[4] = keypad.waitForKey();
  lcd.print(key[4]);j++;
  lcd.setCursor(j,1);
  key[5] = ':';
  lcd.print(key[5]);j++;
  lcd.setCursor(j,1);
  key[6] = keypad.waitForKey();
  lcd.print(key[6]);j++;
  lcd.setCursor(j,1);
  key[7] = keypad.waitForKey();
  lcd.print(key[7]);
  key[8] = '\0';
  feed2 = String(key);
  delay(1000);
  lcd.clear(); 
 }
 if(button == 'D'){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Time: ");
  lcd.print(rtc.getTimeStr());
  lcd.setCursor(0,1);
  lcd.print("Date: ");               //Date to display
  lcd.print(rtc.getDateStr());
  delay(5000);
  lcd.clear();
 }
 if(button == 'C'){
 digitalWrite(dirPin,HIGH);        // Enables the motor to move in a particular direction
  
  for(int x = 0; x < feed_length; x++) {     // Makes 200 pulses for making one full cycle rotation
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(feed_time); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(feed_time); 
  }
  delay(1000);
 } 
 if (feed1==rtc.getTimeStr()){
  digitalWrite(dirPin, HIGH); // Enables the motor to move in a particular direction

  for(int x = 0; x < feed_length; x++) {     // Makes 200 pulses for making one full cycle rotation
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(feed_time); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(feed_time);
  }
  delay(1000);
  } 
 if (feed2==rtc.getTimeStr())
 { 
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
