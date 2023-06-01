void ledSwitch(int ledNumbers[], int arraySize, int RedI, int GreenI, int BlueI) {
  for (int i = 0; i < arraySize ; i++) {
    pixels.setPixelColor(ledNumbers[i], pixels.Color(GreenI, RedI, BlueI));
  }
}

void setTimeLeds(int HourI, int fiveMinI, int singleMinutesI, int RedI, int GreenI, int BlueI) {

  int het [3] = {0, 1, 2 };
  int is [2] = {4, 5 };
  int vijf [4] = {7, 8, 9, 10  };
  int tien [4] = {21, 20, 19, 18 };
  int kwart [5] = {28, 29, 30, 31, 32 };
  int over1 [4] = {22, 23, 24, 25 };
  int over2 [4] = {36, 35, 34, 33 };
  int voor1 [4] = {14, 13, 12, 11 };
  int voor2 [4] = {44, 45, 46, 47 };
  int half [4] = {43, 42, 41, 40 };
  int uur [3] = {101, 100, 99 };

  int twaalf [6] = {109, 108, 107, 106, 105, 104 };
  int een [3] = {51, 52, 53 };
  int twee [4] = {65, 64, 63, 62 };
  int drie [4] = {58, 57, 56, 55 };
  int vier [4] = {66, 67, 68, 69 };
  int vijf2 [4] = {70, 71, 72, 73 };
  int zes [3] = {74, 75, 76 };
  int zeven [5] = {87, 86, 85, 84, 83 };
  int acht [4] = {88, 89, 90, 91};
  int negen [5] = {81, 80, 79, 78, 77 };
  int tien2 [4] = {92, 93, 94, 95 };
  int elf [3] = {96, 97, 98 };

  int minuteDots[4] = {110, 111, 112, 113};

  boolean helpword[][9] = {
    {false, false, false, false, false, false, false, false, true},
    {true, false, false, true, false, false, false, false, false},
    {false, true, false, true, false, false, false, false, false},
    {false, false, true, false, true, false, false, false, false},
    {false, true, false, false, false, true, false, true, false},
    {true, false, false, false, false, true, false, true, false},
    {false, false, false, false, false, false, false, true, false},
    {true, false, false, true, false, false, false, true, false},
    {false, true, false, true, false, false, false, true, false},
    {false, false, true, false, false, false, true, false, false},
    {false, true, false, false, false, true, false, false, false},
    {true, false, false, false, false, true, false, false, false}

  };

  int hourCutOff = 4;

  for (int i = 0; i < NUMPIXELS ; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }

  ledSwitch(minuteDots, singleMinutesI, RedI, GreenI, BlueI);
  ledSwitch(het, 3, RedI, GreenI, BlueI); //always on
  ledSwitch(is, 2, RedI, GreenI, BlueI); //always on

  if (helpword[fiveMinI][0]) {
    ledSwitch(vijf, 4, RedI, GreenI, BlueI);
  };

  if (helpword[fiveMinI][1]) {
    ledSwitch(tien, 4, RedI, GreenI, BlueI);
  };

  if (helpword[fiveMinI][2]) {
    ledSwitch(kwart, 5, RedI, GreenI, BlueI);
  };

  if (helpword[fiveMinI][3]) {
    ledSwitch(over1, 4, RedI, GreenI, BlueI);
  };

  if (helpword[fiveMinI][4]) {
    ledSwitch(over2, 4, RedI, GreenI, BlueI);
  };

  if (helpword[fiveMinI][5]) {
    ledSwitch(voor1, 4, RedI, GreenI, BlueI);
  };

  if (helpword[fiveMinI][6]) {
    ledSwitch(voor2, 4, RedI, GreenI, BlueI);
  };

  if (helpword[fiveMinI][7]) {
    ledSwitch(half, 4, RedI, GreenI, BlueI);
  };

  if (helpword[fiveMinI][8]) {
    ledSwitch(uur, 3, RedI, GreenI, BlueI);
  };

  switch (HourI) {
    case 0:
      if (fiveMinI < hourCutOff) {
        ledSwitch(twaalf, 6, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(een, 3, RedI, GreenI, BlueI);
      }
      break;


    case 1:
      if (fiveMinI < hourCutOff) {
        ledSwitch(een, 3, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(twee, 4, RedI, GreenI, BlueI);
      }
      break;


    case 2:
      if (fiveMinI < hourCutOff) {
        ledSwitch(twee, 4, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(drie, 4, RedI, GreenI, BlueI);
      }
      break;


    case 3:
      if (fiveMinI < hourCutOff) {
        ledSwitch(drie, 4, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(vier, 4, RedI, GreenI, BlueI);
      }
      break;


    case 4:
      if (fiveMinI < hourCutOff) {
        ledSwitch(vier, 4, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(vijf, 4, RedI, GreenI, BlueI);
      }
      break;


    case 5:
      if (fiveMinI < hourCutOff) {
        ledSwitch(vijf, 4, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(zes, 3, RedI, GreenI, BlueI);
      }
      break;


    case 6:
      if (fiveMinI < hourCutOff) {
        ledSwitch(zes, 3, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(zeven, 5, RedI, GreenI, BlueI);
      }
      break;


    case 7:
      if (fiveMinI < hourCutOff) {
        ledSwitch(zeven, 5, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(acht, 4, RedI, GreenI, BlueI);
      }
      break;


    case 8:
      if (fiveMinI < hourCutOff) {
        ledSwitch(acht, 4, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(negen, 5, RedI, GreenI, BlueI);
      }
      break;


    case 9:
      if (fiveMinI < hourCutOff) {
        ledSwitch(negen, 5, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(tien, 4, RedI, GreenI, BlueI);
      }
      break;


    case 10:
      if (fiveMinI < hourCutOff) {
        ledSwitch(tien, 4, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(elf, 3, RedI, GreenI, BlueI);
      }
      break;


    case 11:
      if (fiveMinI < hourCutOff) {
        ledSwitch(elf, 3, RedI, GreenI, BlueI);
      }
      else {
        ledSwitch(twaalf, 6, RedI, GreenI, BlueI);
      }
      break;
  }

  pixels.show();
}
