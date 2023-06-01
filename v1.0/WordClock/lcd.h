void LCD(String now, int menu, int Red, int Green, int Blue) {
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  lcd.print(now);

  if (menu == 1) {
    lcd.setCursor(15, 0);
    lcd.print("S");
  }
  else {
    lcd.setCursor(15, 0);
    lcd.print(" ");
    {
      lcd.setCursor(0, 1);
      lcd.print("R");
      if (Red < 10) {
        lcd.print("  ");
      }
      else if (Red < 100) {
        lcd.print(" ");
      }

      lcd.print(Red);
      lcd.setCursor(5, 1);
      lcd.print("G");
      if (Green < 10) {
        lcd.print("  ");
      }
      else if (Green < 100) {
        lcd.print(" ");
      }
      lcd.print(Green);
      lcd.setCursor(10, 1);
      lcd.print("B");
      if (Blue < 10) {
        lcd.print("  ");
      }
      else if (Blue < 100) {
        lcd.print(" ");
      }
      lcd.print(Blue);

      if (menu == 2) {
        lcd.setCursor(15, 1);
        lcd.print("S");
      }
      else {
        lcd.setCursor(15, 1);
        lcd.print(" ");
      }
    }
  }
}
