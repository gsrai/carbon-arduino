/* 
 * Author: Gagondeep Srai
 * E-mail: gagondeep.srai@gmail.com 
 * github: https://github.com/gsrai 
 * website: http://srai.io/
 */  
 
#include "LedControl.h"

// LED Matrix Pins
const int DIN = 12;
const int CLK = 11;
const int CS = 10;

// Bluetooth Module Pins
const int TX = 1;
const int RX = 0;

// General Globals
const int INPUT_LENGTH = 25;
char serialIn[INPUT_LENGTH];
unsigned long delayTime = 200;

LedControl lc = LedControl(DIN, CLK, CS);

// Fonts
byte font_a[8] = {0x00,0x7F,0x88,0x88,0x88,0x88,0x7F,0x00};
byte font_b[8] = {0x00,0x6E,0x91,0x91,0x91,0x91,0xFF,0x00}; // fix B!!
byte font_c[8] = {0x00,0xFF,0x81,0x81,0x81,0x81,0x81,0x00};
byte font_d[8] = {0x00,0xFF,0x81,0x81,0x81,0x42,0x3C,0x00};
byte font_e[8] = {0x00,0xFF,0x91,0x91,0x91,0x91,0x91,0x00};
byte font_f[8] = {0x00,0xFF,0x90,0x90,0x90,0x80,0x80,0x00};
byte font_g[8] = {0x00,0xFF,0x81,0x89,0x89,0x89,0x8F,0x00};
byte font_h[8] = {0x00,0xFF,0x10,0x10,0x10,0x10,0xFF,0x00};
byte font_i[8] = {0x00,0x81,0x81,0xFF,0xFF,0x81,0x81,0x00};
byte font_j[8] = {0x00,0x83,0x81,0x81,0x81,0xFF,0x80,0x00};
byte font_k[8] = {0x00,0xFF,0xFF,0x3C,0x66,0xC3,0x81,0x00};
byte font_l[8] = {0x00,0xFF,0x01,0x01,0x01,0x01,0x01,0x00};
byte font_m[8] = {0x00,0xFF,0x80,0x78,0x78,0x80,0xFF,0x00};
byte font_n[8] = {0x00,0xFF,0xC0,0x30,0x0C,0x03,0xFF,0x00};
byte font_o[8] = {0x00,0xFF,0x81,0x81,0x81,0x81,0xFF,0x00};
byte font_p[8] = {0x00,0xFF,0x90,0x90,0x90,0x90,0x60,0x00};
byte font_q[8] = {0x00,0xFE,0x82,0x8A,0x86,0xFE,0x01,0x00};
byte font_r[8] = {0x00,0xFF,0x98,0x94,0x92,0x91,0x60,0x00};
byte font_s[8] = {0x00,0xF1,0x91,0x91,0x91,0x91,0x9F,0x00};
byte font_t[8] = {0x00,0xC0,0xC0,0xFF,0xFF,0xC0,0xC0,0x00};
byte font_u[8] = {0x00,0xFF,0x01,0x01,0x01,0x01,0xFF,0x00};
byte font_v[8] = {0x00,0xE0,0x1C,0x03,0x03,0x1C,0xE0,0x00};
byte font_w[8] = {0x00,0xFF,0x01,0x1F,0x1F,0x01,0xFF,0x00};
byte font_x[8] = {0x00,0xC3,0x24,0x18,0x18,0x24,0xC3,0x00};
byte font_y[8] = {0x00,0xC1,0x22,0x14,0x18,0x30,0xE0,0x00};
byte font_z[8] = {0x00,0x81,0x83,0x8D,0x99,0xB1,0xC1,0x00};
byte font_exclaim[8] = {0x00,0x00,0x00,0xFB,0xFB,0x00,0x00,0x00};
byte font_period[8] = {0x00,0x00,0x00,0x03,0x03,0x00,0x00,0x00};
byte font_qmark[8] = {0x00,0x60,0xC0,0x8B,0x93,0xE0,0x40,0x00};
byte font_space[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

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
  byte* ret = NULL;
  switch(c) {
    case 'a': return font_a;
    case 'b': return font_b;
    case 'c': return font_c;
    case 'd': return font_d;
    case 'e': return font_e;
    case 'f': return font_f;
    case 'g': return font_g;
    case 'h': return font_h;
    case 'i': return font_i;
    case 'j': return font_j;
    case 'k': return font_k;
    case 'l': return font_l;
    case 'm': return font_m;
    case 'n': return font_n;
    case 'o': return font_o;
    case 'p': return font_p;
    case 'q': return font_q;
    case 'r': return font_r;
    case 's': return font_s;
    case 't': return font_t;
    case 'u': return font_u;
    case 'v': return font_v;
    case 'w': return font_w;
    case 'x': return font_x;
    case 'y': return font_y;
    case 'z': return font_z;
    case '!': return font_exclaim;
    case '.': return font_period;
    case '?': return font_qmark;
    case ' ': return font_space;
  }

  return ret;
}

void animate(char str[]) {
  int string_length = strlen(str);
  int fs_len = (string_length * 8); // final string length
  byte final_string[fs_len];
  int offset = 0;
  
  for (int i = 0; i < string_length; i++) {
    byte* b = getSprite(str[i]);
    memcpy(final_string + offset, b, 8 * sizeof(byte));
    offset += 8;
    b = NULL; // don't want to delete the hard coded values.
  }
  
  for (int j = 0; j < fs_len; j++) {
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

  delay(delayTime);
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
  int i = 0;

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
