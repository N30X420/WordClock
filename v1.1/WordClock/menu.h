
//Function for the internal workins of the menu
void updateMenu(byte buttons[],String(now), int menuI, int HoursI, int MinutesI, int SecondsI, int DaysI, int MonthsI, int YearsI) {

  //some internal values
  const byte nrButtons = 4;
  int menusize = 2;

  
  for (int n = 0; n < nrButtons; n++) {
    if (digitalRead(buttons[n]) == LOW) {
      switch (n) {
        case 0:
          menu = menu + 1;
          if (menu > menusize) {
            menu = 0;
          }

          //LCD(now, date, menu, Days, Months, Years);
          LCD(now, date, menu);
          delay (350);
          break;

        case 1: // Actions button 2
          if (menu == 0) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Button 2 ");
            delay(500);
          }

          if (menu == 1) {
            Hours = Hours + 1;
            if (Hours > 23) {
              Hours = 0;
            }
            rtc.setTime(Hours, Minutes, Seconds);
            //LCD(now, date, menu, Days, Months, Years);
            LCD(now, date, menu);
            delay(150);
          }

          if (menu == 2) {
            Days = Days + 1;
            if (Days > 31) {
              Days = 1;
            }
            //rtc.setDate(Days, Months, Years);
            //LCD(now, date, menu, Days, Months, Years);
            LCD(now, date, menu);
            delay (150);
          }
          break;

        case 2: //Actions button 3
          if (menu == 0) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Button 3 ");
            delay(500);
          }
          if (menu == 1) {
            Minutes = Minutes + 1;
            if (Minutes > 59) {
              Minutes = 0;
            }
            rtc.setTime(Hours, Minutes, Seconds);
            //LCD(now, date, menu, Days, Months, Years);
            LCD(now, date, menu);
            delay(150);
          }
          if (menu == 2) {
            Months = Months + 1;
            if (Months > 12) {
              Months = 1;
            }
            //rtc.setDate(Days, Months, Years);
            //LCD(now, date, menu, Days, Months, Years);
            LCD(now, date, menu);
            delay(150);
          }
          break;

        case 3: // Actions button 4
          if (menu == 0) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Button 4 ");
            delay(500);
          }
          if (menu == 1) {
            Seconds = Seconds + 1;
            if (Seconds > 59) {
              Seconds = 0;
            }
            rtc.setTime(Hours, Minutes, Seconds);
            //LCD(now, date, menu, Days, Months, Years);
            LCD(now, date, menu);
            delay (150);
          }
          if (menu == 2) {
            Years = Years + 1;
            if (Years > 50) {
              Years = 20;
            }
            //rtc.setDate(Days, Months, Years);
            //LCD(now, date, menu, Days, Months, Years);
            LCD(now, date, menu);
            delay(150);
          }
          break;
      }
    }
  }
}
