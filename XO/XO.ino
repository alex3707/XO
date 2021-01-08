#define STRIP_PIN 2     // пин ленты
#include "bitmap.h"
#define BTN1 3 // кнопка к пину 3
#define BTN2 4 // кнопка к пину 4
#define BTN3 5 // кнопка к пину 5
#define BTN4 A0 // кнопка к пину 6
#define BTN5 A1 // кнопка к пину 7
#define BTN6 8 // кнопка к пину 8
#define BTN7 9 // кнопка к пину 9
#define BTN8 10 // кнопка к пину 10
#define BTN9 11 // кнопка к пину 11
#include "GyverButton.h" // подключение библиотеки кнопок 
#define COLOR_DEBTH 2
#include <microLED.h>
microLED<16 * 16, STRIP_PIN, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_HIGH> matrix(16, 16, ZIGZAG, LEFT_TOP, DIR_DOWN);
GButton butt1(BTN1); // объект кнопки и отслеживания
GButton butt2(BTN2); // объект кнопки и отслеживания
GButton butt3(BTN3); // объект кнопки и отслеживания
GButton butt4(BTN4); // объект кнопки и отслеживания
GButton butt5(BTN5); // объект кнопки и отслеживания
GButton butt6(BTN6); // объект кнопки и отслеживания
GButton butt7(BTN7); // объект кнопки и отслеживания
GButton butt8(BTN8); // объект кнопки и отслеживания
GButton butt9(BTN9); // объект кнопки и отслеживания

void setup() {
      Serial.begin(9600);
      matrix.clear();
      matrix.setBrightness(50);
      pole();// рисуем поле
}

void loop() {
  butt1.tick();
  butt2.tick();
  butt3.tick();
  butt4.tick();
  butt5.tick();
  butt6.tick();
  butt7.tick();
  butt8.tick();
  butt9.tick();
  OO();
  //matrix.set(0, 7, mPurple);
  //matrix.set(7, 0, mTeal);
     
      
}


void pole(){
      matrix.drawBitmap16(0, 0, poleXO, 16, 16);
      
      
      //
      //
     // matrix.drawBitmap16(6, 6, poleo1, 4, 4);
     // matrix.drawBitmap16(6, 11, poleo1, 4, 4);
     // matrix.drawBitmap16(11, 6, poleo1, 4, 4);
     // matrix.drawBitmap16(11, 11, poleo1, 4, 4);
      
      //matrix.drawBitmap16(6, 1, polex1, 4, 4);
      //matrix.set(1, 1, mYellow);
      //matrix.set(1, 2, mYellow);
      //matrix.set(1, 3, mYellow);
      //matrix.set(1, 4, mYellow);
      matrix.show();
     // delay(1000);
     // matrix.clear();
}

void OO(){
//------------обработка нажатия первой кнопки для первого квадрата-------------
  if (butt1.isSingle()) {
        matrix.drawBitmap16(1, 1, polex1, 4, 4);
        matrix.show();
        Serial.println("Button 1");
        }
  else if (butt1.isDouble()) {
        matrix.drawBitmap16(1, 1, poleo1, 4, 4);
        matrix.show();
        Serial.println("Button 1");
        }
//------------обработка нажатия второй кнопки для второго квадрата-------------
  else if (butt2.isSingle()) {
        matrix.drawBitmap16(6, 1, polex1, 4, 4);
        matrix.show();
        Serial.println("Button 2");
        }
  else if (butt2.isDouble()) {
        matrix.drawBitmap16(6, 1, poleo1, 4, 4);
        matrix.show();
        Serial.println("Button 2");
        }

  else if (butt3.isSingle()) {
        matrix.drawBitmap16(11, 1, polex1, 4, 4);
        matrix.show();
        Serial.println("Button 3");
        }
  else if (butt3.isDouble()) {
        matrix.drawBitmap16(11, 1, poleo1, 4, 4);
        matrix.show();
        Serial.println("Button 3");
        }
        
  else if (butt4.isSingle()) {
        matrix.drawBitmap16(1, 6, polex1, 4, 4);
        matrix.show();
        Serial.println("Button 4");
        }
  else if (butt4.isDouble()) {
        matrix.drawBitmap16(1, 6, polex1, 4, 4);
        matrix.show();
        Serial.println("Button 4");
        }




  
  else if (butt6.isSingle()){
        matrix.drawBitmap16(11, 6, polex1, 4, 4);
        matrix.show();
        Serial.println("Button 6");
        }
  else if (butt6.isDouble()){
        matrix.drawBitmap16(11, 6, poleo1, 4, 4);
        matrix.show();
        Serial.println("Button 6");
        }
  
  }
//}
