#include "LedControl.h"

// LED Matrix Pins
const int DIN = 12;
const int CLK = 11;
const int CS = 10;

// Bluetooth Module Pins
const int TX = 1;
const int RX = 0;

const int INPUT_LENGTH = 25;
char serialIn[INPUT_LENGTH];
unsigned long delayTime = 250;
LedControl lc = LedControl(DIN, CLK, CS);

// Fonts
byte font_a[8] = {0x00,0x7F,0x88,0x88,0x88,0x88,0x7F,0x00};
byte font_b[8] = {0x00,0xFF,0x89,0x89,0x89,0x89,0x76,0x00};
byte font_c[8] = {0x00,0xFF,0x81,0x81,0x81,0x81,0x81,0x00};
byte font_d[8] = {0x00,0xFF,0x81,0x81,0x81,0x42,0x3C,0x00};
byte font_e[8] = {0x00,0xFF,0x89,0x89,0x89,0x89,0x89,0x00};
byte font_f[8] = {0x00,0xFF,0x11,0x11,0x11,0x11,0x01,0x00};
byte font_g[8] = {0x00,0xFF,0x81,0x91,0x91,0x91,0xF1,0x00};
byte font_h[8] = {0x00,0xFF,0x10,0x10,0x10,0x10,0xFF,0x00};

// Images
byte img_smile[8] = {0x3C, 0x42, 0xA5, 0x81, 0xA5, 0x99, 0x42, 0x3C};
byte img_stairs[8] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};

void setup() {
  // 0 is the device address as you can have up to 8 devices.
  lc.shutdown(0, false); // wake up the device.
  lc.setIntensity(0, 15); // set the brightness to maximum.
  lc.clearDisplay(0);

  Serial.begin(9600);
  pinMode(TX, OUTPUT);
  pinMode(RX, INPUT);
}

void draw(byte sprite[]) {
  for (int i = 0; i < 8; i++)
    lc.setColumn(0, i, sprite[i]);
}

void drawRow(byte sprite[]) {
  for (int i = 0; i < 8; i++)
    lc.setRow(0, i, sprite[i]);
}

byte* getSprite(char c) {
  byte * ret = (byte* )malloc(8 * sizeof(byte));
  Serial.println("gettting the sprite!");
  switch(c) {
    case 'a': ret = font_a;
      break;
    case 'b': ret = font_b;
      break;
    case 'c': ret = font_c;
      break;
    case 'd': ret = font_d;
      break;
    case 'e': ret = font_e;
      break;
    case 'f': ret = font_f;
      break;
    case 'g': ret = font_g;
      break;
    case 'h': ret = font_h;
      break;
  }

  return ret;
}

void animate(char str[]) {
  Serial.println("animating!");
  int string_length = strlen(str);
  //byte* final_string = (byte* )malloc(string_length * 8 * sizeof(byte));
  int fs_len = (string_length * 8); // final string length
  byte final_string[fs_len];
  int offset = 0;
  
  for (int i = 0; i < string_length; i++) {
    byte* b = getSprite(str[i]);

    if (b != 0) Serial.println("b is ok!");
    
    memcpy(final_string + offset, b, 8 * sizeof(byte));
    offset += 8;
    b = NULL; // don't want to delete the hard coded values.
    free(b);
  }
  
  for (int j = 0; j < fs_len; j++) {
    Serial.println(j);
    if (j == 0) {
      lc.setColumn(0, 7, final_string[j]);
    } else if (j == 1) {
      lc.setColumn(0, 6, final_string[j - 1]);
      lc.setColumn(0, 7, final_string[j]);
    } else if (j == 2) {
      lc.setColumn(0, 5, final_string[j - 2]);
      lc.setColumn(0, 6, final_string[j - 1]);
      lc.setColumn(0, 7, final_string[j]);
    } else if (j == 3) {
      lc.setColumn(0, 4, final_string[j - 3]);
      lc.setColumn(0, 5, final_string[j - 2]);
      lc.setColumn(0, 6, final_string[j - 1]);
      lc.setColumn(0, 7, final_string[j]);
    } else if (j == 4) {
      lc.setColumn(0, 3, final_string[j - 4]);
      lc.setColumn(0, 4, final_string[j - 3]);
      lc.setColumn(0, 5, final_string[j - 2]);
      lc.setColumn(0, 6, final_string[j - 1]);
      lc.setColumn(0, 7, final_string[j]);
    } else if (j == 5) {
      lc.setColumn(0, 2, final_string[j - 5]);
      lc.setColumn(0, 3, final_string[j - 4]);
      lc.setColumn(0, 4, final_string[j - 3]);
      lc.setColumn(0, 5, final_string[j - 2]);
      lc.setColumn(0, 6, final_string[j - 1]);
      lc.setColumn(0, 7, final_string[j]);
    } else if (j == 6) {
      lc.setColumn(0, 1, final_string[j - 6]);
      lc.setColumn(0, 2, final_string[j - 5]);
      lc.setColumn(0, 3, final_string[j - 4]);
      lc.setColumn(0, 4, final_string[j - 3]);
      lc.setColumn(0, 5, final_string[j - 2]);
      lc.setColumn(0, 6, final_string[j - 1]);
      lc.setColumn(0, 7, final_string[j]);
    } else if (j >= 7) {
      lc.setColumn(0, 0, final_string[j - 7]);
      lc.setColumn(0, 1, final_string[j - 6]);
      lc.setColumn(0, 2, final_string[j - 5]);
      lc.setColumn(0, 3, final_string[j - 4]);
      lc.setColumn(0, 4, final_string[j - 3]);
      lc.setColumn(0, 5, final_string[j - 2]);
      lc.setColumn(0, 6, final_string[j - 1]);
      lc.setColumn(0, 7, final_string[j]);
    }

    delay(delayTime);
  }

  //free(final_string);
  lc.clearDisplay(0);
  delay(delayTime);
}

void printInput(char inStr[]) {
  Serial.println(inStr);

  if(!strcmp(inStr, "smile")) {
    draw(img_smile);
    Serial.println("Smiling");
  } else if (!strcmp(inStr, "clear")) {
    lc.clearDisplay(0);
    Serial.println("Cleared Display.");
  } else if (!strcmp(inStr, "stairs")) {
    draw(img_stairs);
    Serial.println("Stairs");
  } else {
    animate(inStr);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0, m = 0;

  delay(500);

  if (Serial.available() > 0) {
    while (Serial.available() > 0) {
      serialIn[i] = Serial.read();
      i++;
    }
    serialIn[i] = '\0';
    printInput(serialIn);
  }
}
