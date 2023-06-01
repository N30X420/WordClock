#include <LiquidCrystal_I2C.h>
#include <DS3231.h>
#include <Adafruit_NeoPixel.h>

#define PIN 8
#define NUMPIXELS 114

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
DS3231 rtc(SDA, SCL);
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte buttons[] = {0, 1, 2, 3};

String now;
int menu = 0;
int Hours = 0;
int Minutes = 0;
int Seconds = 0;
int Red = 150;
int Blue = 150;
int Green = 150;

void setup() {
  rtc.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  pixels.begin();
  pixels.show();

  //rtc.setTime(01, 01, 0);
  //rtc.setDate(01, 06, 2023);

  pinMode(buttons[0], INPUT_PULLUP);
  pinMode(buttons[1], INPUT_PULLUP);
  pinMode(buttons[2], INPUT_PULLUP);
  pinMode(buttons[3], INPUT_PULLUP);
}

#include "lcd.h"
#include "menu.h"
#include "timefunc.h"

void loop() {
  String now = rtc.getTimeStr((FORMAT_LONG));
  int Hours = now.substring(0, 2).toInt();
  int Minutes = now.substring(3, 5).toInt();
  int Seconds = now.substring(6, 9).toInt();
  int Hour = 0;

  if (Hours > 11) {
    Hour = Hours - 12;
  }
  else {
    Hour = Hours;
  }

  int fiveMin = floor(Minutes / 5);
  int singleMinutes = Minutes - fiveMin * 5;

  setTimeLeds(Hour, fiveMin, singleMinutes, Red, Green, Blue);
  updateMenu(buttons, now, menu, Hours, Minutes, Seconds, Red, Green, Blue);
  LCD(now, menu, Red, Green, Blue);




}
