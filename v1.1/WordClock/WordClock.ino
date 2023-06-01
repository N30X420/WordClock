//v1.1

#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal_I2C.h>
#include <DS3231.h>


#define PIN 8
#define NUMPIXELS 140

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
DS3231 rtc(SDA, SCL);
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte buttons[] = { 0, 1, 2, 3 };

int y = 0;
unsigned long startTime;
unsigned long timeoutDuration = 30000;
const int buttonDonePin = 0;
const int buttonDayPin = 1;
const int buttonMonthPin = 2;
const int buttonYearPin = 3;

int day = 1;
int month = 1;
int year = 2023;

String(now);
String(date);
String(myTime);

int menu = 0;

int Days;
int Months ;
int Years ;

int Hours ;
int Minutes ;
int Seconds ;

int Red = 250;
int Blue = 250;
int Green = 250;

void setup() {

  rtc.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  pixels.begin();
  pixels.show();

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Zoey Gelissen <3");
  lcd.setCursor(6, 1);
  lcd.print("F34A");
  delay(1000);
  lcd.clear();

  //Set time to RTC module
  //rtc.setDOW(WEDNESDAY);
  //rtc.setTime(9, 20, 0);
  //rtc.setDate(1, 6, 2023);

  pinMode(buttons[0], INPUT_PULLUP);
  pinMode(buttons[1], INPUT_PULLUP);
  pinMode(buttons[2], INPUT_PULLUP);
  pinMode(buttons[3], INPUT_PULLUP);

  lcd.print("Set Date:");
  pinMode(buttonDonePin, INPUT_PULLUP);
  pinMode(buttonDayPin, INPUT_PULLUP);
  pinMode(buttonMonthPin, INPUT_PULLUP);
  pinMode(buttonYearPin, INPUT_PULLUP);

  startTime = millis();
  while (y < 1) {
    bool buttonDayState = digitalRead(buttonDayPin) == LOW;
    bool buttonMonthState = digitalRead(buttonMonthPin) == LOW;
    bool buttonYearState = digitalRead(buttonYearPin) == LOW;
    bool buttonDoneState = digitalRead(buttonDonePin) == LOW;

    if (buttonDoneState) {
      rtc.setDate(day, month, year);
      y++;
    }

    if (buttonDayState) {
      day++;
      if (day > 31) day = 1;
    }

    if (buttonMonthState) {
      month++;
      if (month > 12) month = 1;
    }

    if (buttonYearState) {
      year++;
      if (year > 2099) year = 2020;
    }

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Date: ");
    lcd.print(day);
    lcd.print("/");
    lcd.print(month);
    lcd.print("/");
    lcd.print(year);

    delay(200);

    if (millis() - startTime >= timeoutDuration) {
      y++;
    }
  }
}

#include "lcd.h"
#include "menu.h"
#include "timefunc.h"

void loop() {

  // Retrieve the date as a string from the RTC object
  String myTime = rtc.getDateStr({ FORMAT_LONG });

  // Extract day, month, and year from the 'myTime' string
  int Days = myTime.substring(0, 2).toInt();
  int Months = myTime.substring(3, 5).toInt();
  int Years = myTime.substring(8, 10).toInt();



  // Create the formatted date string
  String date = String(Days) + "/" + String(Months) + "/" + String(Years);


  //String (date) = rtc.getDateStr();

  String(now) = rtc.getTimeStr({ FORMAT_LONG });
  int Hours = now.substring(0, 2).toInt();
  int Minutes = now.substring(3, 5).toInt();
  int Seconds = now.substring(6, 9).toInt();

  //Serial.print(Minutes);
  int Hour;

  if (Hours > 11) {
    Hour = Hours - 12;
  } else {
    Hour = Hours;
  }

  int fiveMin = floor(Minutes / 5);
  int singleMinutes = Minutes - fiveMin * 5;

  setTimeLeds(Hour, fiveMin, singleMinutes, Red, Green, Blue);
  updateMenu(buttons, now, menu, Hours, Minutes, Seconds, Days, Months, Years);
  //LCD(now, date, menu, Days, Months, Years);
  LCD(now, date, menu);
}
