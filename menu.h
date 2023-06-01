void updateMenu(byte buttons[],String now, int menuI, int HoursI, int MinutesI, int SecondsI, int RedI, int GreenI, int BlueI) {
  const byte nrButtons = 4;
  int menusize = 2;

  for (int n = 0; n < nrButtons; n++) {
    if (digitalRead(buttons[n]) == HIGH) {
      swith (n) {
        case 0:
          menu = menu + 1;
          if (menu > menusize) {
            menu = 0;
          }
          LCD(now, menu, Red, Green, Blue);
          delay(350);
          break;

        case 1:
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
            LCD(now, menu, Red, Green, Blue);
            delay(150);
          }
          if (menu == 2) {
            Red = Red + 10;
            if (Red > 250) {
              Red = 0;
            }
            LCD(now, menu, Red, Green, Blue);
            delay(150);
          }
          break;

        case 2:
          if (menu == 0) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Button 3 ");
            delay(500);
          }
          
      }
    }
  }
}
