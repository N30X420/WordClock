void ledSwitch(int ledNumbers[], int arraySize, int RedI, int GreenI, int BlueI) {
  for(int i = 0; i < arraySize ; i++) {
    pixels.setPixelColor(ledNumbers[i], pixels.Color(GreenI, RedI, BlueI));
  }
}

void setTimeLeds(int HourI, int fiveMinI, int singleMinutesI, int RedI, int GreenI, int BlueI) {
  int it[2] = { 134, 135 };
  int is[2] = { 137, 138 };
  int half[4] = { 129, 130, 131, 132 };  // Corrected array size
  int ten[3] = { 124, 125, 126 };
  int quarter[7] = { 115, 116, 117, 118, 119, 120, 121 };
  int twenty[6] = { 107, 108, 109, 110, 111, 112 };
  int five[4] = { 101, 102, 103, 104 };
  int minutes[7] = { 88, 89, 90, 91, 92, 93, 94 };
  int to[2] = { 98, 99 };
  int past[4] = { 83, 84, 85, 86 };
  int oclock[6] = { 0, 2, 3, 4, 5, 6 };

  int one[3] = { 76, 77, 78 };
  int two[3] = { 66, 67, 68 };
  int three[5] = { 70, 71, 72, 73, 74 };
  int four[4] = { 61, 62, 63, 64 };
  int five2[4] = { 53, 54, 55, 56 };
  int six[3] = { 40, 41, 42 };
  int seven[5] = { 47, 48, 49, 50, 51 };
  int eight[5] = { 35, 36, 37, 38, 39 };
  int nine[4] = { 27, 28, 29, 30 };
  int ten2[3] = { 16, 17, 18 };
  int eleven[6] = { 20, 21, 22, 23, 24, 25 };
  int twelve[6] = { 8, 9, 10, 11, 12, 13 };

  int minuteDots[4] = { 81, 80, 58, 59 };

  boolean helpWord[][11] = {
    { true, true, false, false, false, false, false, false, false, false, true },
    { true, true, false, false, false, false, true, true, false, true, false },
    { true, true, false, true, false, false, false, true, false, true, false },
    { true, true, false, false, true, false, false, false, false, true, false },
    { true, true, false, false, false, true, false, true, false, true, false },
    { true, true, false, false, false, true, true, true, false, true, false },
    { true, true, true, false, false, false, false, false, false, true, false },
    { true, true, false, false, false, true, true, true, true, false, false },
    { true, true, false, false, true, false, false, false, true, false, false },
    { true, true, false, true, false, false, false, true, true, false, false },
    { true, true, false, false, false, false, true, true, true, false, false },
  };
  int hourCutOff = 4;

  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }

  ledSwitch(minuteDots, singleMinutesI, RedI, GreenI, BlueI);  // Corrected array size and removed 'int' before RedI, GreenI, BlueI

  ledSwitch(it, 2, RedI, GreenI, BlueI);
  ledSwitch(is, 2, RedI, GreenI, BlueI);

  if (helpWord[fiveMinI][0]) {
    ledSwitch(half, 4, RedI, GreenI, BlueI);
  }

  if (helpWord[fiveMinI][1]) {
    ledSwitch(ten, 3, RedI, GreenI, BlueI);
  }

  if (helpWord[fiveMinI][2]) {
    ledSwitch(quarter, 7, RedI, GreenI, BlueI);
  }

  if (helpWord[fiveMinI][3]) {
    ledSwitch(twenty, 6, RedI, GreenI, BlueI);
  }

  if (helpWord[fiveMinI][4]) {
    ledSwitch(five, 4, RedI, GreenI, BlueI);
  }

  if (helpWord[fiveMinI][5]) {
    ledSwitch(minutes, 7, RedI, GreenI, BlueI);
  }

  if (helpWord[fiveMinI][6]) {
    ledSwitch(to, 2, RedI, GreenI, BlueI);
  }

  if (helpWord[fiveMinI][7]) {
    ledSwitch(past, 4, RedI, GreenI, BlueI);
  }

  if (helpWord[fiveMinI][8]) {
    ledSwitch(oclock, 4, RedI, GreenI, BlueI);
  }

  switch (HourI) {
    case 0:  // Corrected lowercase 'case'
      if (fiveMinI < hourCutOff) {
        ledSwitch(twelve, 6, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(one, 3, RedI, GreenI, BlueI);
      }
      break;

    case 1:
      if (fiveMinI < hourCutOff) {
        ledSwitch(one, 3, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(two, 3, RedI, GreenI, BlueI);
      }
      break;

    case 2:
      if (fiveMinI < hourCutOff) {
        ledSwitch(two, 3, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(three, 5, RedI, GreenI, BlueI);
      }
      break;

    case 3:
      if (fiveMinI < hourCutOff) {
        ledSwitch(three, 5, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(four, 4, RedI, GreenI, BlueI);
      }
      break;

    case 4:
      if (fiveMinI < hourCutOff) {
        ledSwitch(four, 4, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(five2, 4, RedI, GreenI, BlueI);  // Corrected array name from 'five' to 'five2'
      }
      break;

    case 5:
      if (fiveMinI < hourCutOff) {
        ledSwitch(five2, 4, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(six, 3, RedI, GreenI, BlueI);
      }
      break;

    case 6:
      if (fiveMinI < hourCutOff) {
        ledSwitch(six, 3, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(seven, 5, RedI, GreenI, BlueI);
      }
      break;

    case 7:
      if (fiveMinI < hourCutOff) {
        ledSwitch(seven, 5, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(eight, 5, RedI, GreenI, BlueI);
      }
      break;

    case 8:
      if (fiveMinI < hourCutOff) {
        ledSwitch(eight, 5, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(nine, 4, RedI, GreenI, BlueI);
      }
      break;

    case 9:
      if (fiveMinI < hourCutOff) {
        ledSwitch(nine, 4, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(ten2, 3, RedI, GreenI, BlueI);
      }
      break;

    case 10:
      if (fiveMinI < hourCutOff) {
        ledSwitch(ten2, 3, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(eleven, 6, RedI, GreenI, BlueI);
      }
      break;

    case 11:
      if (fiveMinI < hourCutOff) {
        ledSwitch(eleven, 6, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(twelve, 6, RedI, GreenI, BlueI);
      }
      break;
  }
  pixels.show();
}

