//Draw mini numbers on 8x8 led matrix on Wemos D1 Mini
//Created for use as debug output on Decabot robots
//Daniel Almeida Chagas

#include <Adafruit_GFX.h>       // tested on 1.11.10 by Adafruit
#include <WEMOS_Matrix_GFX.h>   // tested on 1.4.0 from Thomas O Fredericks https://github.com/thomasfredericks/wemos_matrix_gfx 

static const uint8_t PROGMEM miniNumbers[10][5] = {{0x2, 0x5, 0x5, 0x5, 0x2},{0x2, 0x6, 0x2, 0x2, 0x7},{0x6, 0x1, 0x2, 0x4, 0x7},{0x6, 0x1, 0x2, 0x1, 0x6},{0x1, 0x5, 0x7, 0x1, 0x1},{0x7, 0x4, 0x6, 0x1, 0x6},{0x3, 0x4, 0x6, 0x5, 0x2},{0x7, 0x1, 0x2, 0x2, 0x2},{0x2, 0x5, 0x2, 0x5, 0x2},{0x2, 0x5, 0x3, 0x1, 0x6}};

MLED matrix(7); // intensidade 7 (máximo)

void setup() {
  matrix.setRotation(2);
}

void loop() {
  for(int i=0;i<100;i++){
    showMiniNumbers(i);
    delay(100);
  }
}

void showMiniNumbers(int value){
  int tens = value/10;
  int units = value - tens*10;
  matrix.clear();
  matrix.drawBitmap(0, 1, miniNumbers[units] , 8, 5, LED_ON);
  matrix.drawBitmap(-4, 1, miniNumbers[tens] , 8, 5, LED_ON);
  matrix.writeDisplay();
}