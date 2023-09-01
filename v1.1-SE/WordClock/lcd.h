//void LCD(String(now), String(date), int menu, int Days, int Months, int Years) {
void LCD(String(now), String(date), int menu) {
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  lcd.print(now);

  lcd.setCursor(0, 1);
  lcd.print("Date: ");
  lcd.print(date);

  if (menu == 1) {
    lcd.setCursor(15, 0);
    lcd.print("S");
  } else {
    lcd.setCursor(15, 0);
    lcd.print(" ");
    
    if (menu == 2) {
      lcd.setCursor(15, 1);
      lcd.print("S");
    } else {
      lcd.setCursor(15, 1);
      lcd.print(" ");
    }
  }
}
