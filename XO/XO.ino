#define STRIP_PIN 2     // пин ленты
#include "bitmap.h"
#define M_WIDTH 16    // ширина матрицы
#define M_HEIGHT 16    // высота матрицы
#define NUM_LEDS (M_WIDTH * M_HEIGHT) // колличество диодов
#define BTN1 A2 // кнопка к пину 3
#define BTN2 A3 // кнопка к пину 4
#define BTN3 A4 // кнопка к пину 5
#define BTN4 A0 // кнопка к пину 6
#define BTN5 A1 // кнопка к пину 7
#define BTN6 8 // кнопка к пину 8
#define BTN7 9 // кнопка к пину 9
#define BTN8 10 // кнопка к пину 10
#define BTN9 11 // кнопка к пину 11
#define BTN10 A5 // для сброса игры
int value = 50;
byte myMatrix[][3] = { //нулевая матрица для проверки х  заполняется 1 0 - 2
  {0, 0, 0},
  {0, 0, 0},
  {0, 0, 0},
};
#include "GyverButton.h" // подключение библиотеки кнопок 
#define COLOR_DEBTH 2
#include <microLED.h>
microLED<NUM_LEDS, STRIP_PIN, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_HIGH> matrix(M_WIDTH, M_HEIGHT, ZIGZAG, LEFT_TOP, DIR_DOWN);
GButton butt1(BTN1); // объект кнопки и отслеживания
GButton butt2(BTN2); // объект кнопки и отслеживания
GButton butt3(BTN3); // объект кнопки и отслеживания
GButton butt4(BTN4); // объект кнопки и отслеживания
GButton butt5(BTN5); // объект кнопки и отслеживания
GButton butt6(BTN6); // объект кнопки и отслеживания
GButton butt7(BTN7); // объект кнопки и отслеживания
GButton butt8(BTN8); // объект кнопки и отслеживания
GButton butt9(BTN9); // объект кнопки и отслеживания
GButton butt10(BTN10); // для сброса


void setup() {
      butt1.setDebounce(50);        // настройка антидребезга (по умолчанию 80 мс)
      butt2.setDebounce(50);        // настройка антидребезга (по умолчанию 80 мс)
      butt3.setDebounce(50);        // настройка антидребезга (по умолчанию 80 мс)
      butt4.setDebounce(50);        // настройка антидребезга (по умолчанию 80 мс)
      butt5.setDebounce(50);        // настройка антидребезга (по умолчанию 80 мс)
      butt6.setDebounce(50);        // настройка антидребезга (по умолчанию 80 мс)
      butt7.setDebounce(50);        // настройка антидребезга (по умолчанию 80 мс)
      butt8.setDebounce(50);        // настройка антидребезга (по умолчанию 80 мс)
      butt9.setDebounce(50);        // настройка антидребезга (по умолчанию 80 мс)
      butt10.setDebounce(50);        // настройка антидребезга (по умолчанию 80 мс)
      Serial.begin(9600);
      matrix.clear();
      matrix.setBrightness(value);
      pole();// рисуем поле
}

void loop() {
    if (butt10.isSingle()){
     matrix.clear();
     pole();
     myMatrix[0][0] = 0;
     myMatrix[0][1] = 0;
     myMatrix[0][2] = 0;
     myMatrix[1][0] = 0;
     myMatrix[1][1] = 0;
     myMatrix[1][2] = 0;
     myMatrix[2][0] = 0;
     myMatrix[2][1] = 0;
     myMatrix[2][2] = 0;
  }
  butt1.tick();
  butt2.tick();
  butt3.tick();
  butt4.tick();
  butt5.tick();
  butt6.tick();
  butt7.tick();
  butt8.tick();
  butt9.tick();
  butt10.tick();
  OO();
  game();
    if (butt10.isDouble()) {                                 // если кнопка была удержана (это для инкремента)
    value=value+50;                                            // увеличивать/уменьшать переменную value с шагом и интервалом
                                // для примера выведем в порт
  }  
   matrix.setBrightness(value); 
}



void pole(){
      matrix.drawBitmap16(0, 0, poleXO, 16, 16);
      matrix.show();
     myMatrix[0][0] = 0;
     myMatrix[0][1] = 0;
     myMatrix[0][2] = 0;
     myMatrix[1][0] = 0;
     myMatrix[1][1] = 0;
     myMatrix[1][2] = 0;
     myMatrix[2][0] = 0;
     myMatrix[2][1] = 0;
     myMatrix[2][2] = 0;
}

void OO(){
  
//------------обработка нажатия первой кнопки для первого квадрата-------------
  if (butt1.isSingle()) {
        matrix.drawBitmap16(1, 1, polex1, 4, 4);
        matrix.show();
        Serial.println("Button 1");
        //butt1.setTimeout(15000);
        myMatrix[2][0] = 1;
        //game();
        }
  else if (butt1.isDouble()) {
        matrix.drawBitmap16(1, 1, poleo1, 4, 4);
        matrix.show();
        Serial.println("Button 1");
        //butt1.setTimeout(15000);
        myMatrix[2][0] = 2;
        //game();
        }
//------------обработка нажатия второй кнопки для второго квадрата-------------
  else if (butt2.isSingle()) {
        matrix.drawBitmap16(6, 1, polex1, 4, 4);
        matrix.show();
        Serial.println("Button 2");
        //butt2.setTimeout(15000);
        myMatrix[2][1] = 1;
        //game();
        }
  else if (butt2.isDouble()) {
        matrix.drawBitmap16(6, 1, poleo1, 4, 4);
        matrix.show();
        Serial.println("Button 2");
        //butt2.setTimeout(15000);
        myMatrix[2][1] = 2;
        //game();
        }
//------------обработка нажатия 3-ей кнопки для 3-его квадрата-------------
  else if (butt3.isSingle()) {
        matrix.drawBitmap16(11, 1, polex1, 4, 4);
        matrix.show();
        Serial.println("Button 3");
        //butt3.setTimeout(15000);
        myMatrix[2][2] = 1;
        //game();
        }
  else if (butt3.isDouble()) {
        matrix.drawBitmap16(11, 1, poleo1, 4, 4);
        matrix.show();
        Serial.println("Button 3");
        //butt3.setTimeout(15000);
        myMatrix[2][2] = 2;
        //game();
        }
  //------------обработка нажатия 4-ой кнопки для 4-ого квадрата-------------     
  else if (butt4.isSingle()) {
        matrix.drawBitmap16(1, 6, polex1, 4, 4);
        matrix.show();
        Serial.println("Button 4");
        //butt4.setTimeout(15000);
        myMatrix[1][0] = 1;
        //game();
        }
  else if (butt4.isDouble()) {
        matrix.drawBitmap16(1, 6, poleo1, 4, 4);
        matrix.show();
        Serial.println("Button 4");
        //butt4.setTimeout(15000);
        myMatrix[1][0] = 2;
        //game();
        }
//------------обработка нажатия 5-ей кнопки для 5-ого квадрата-------------
  else if (butt5.isSingle()) {
        matrix.drawBitmap16(6, 6, polex1, 4, 4);
        matrix.show();
        Serial.println("Button 5");
        //butt5.setTimeout(15000);
        myMatrix[1][1] = 1;
       //game();
        }
  else if (butt5.isDouble()) {
        matrix.drawBitmap16(6, 6, poleo1, 4, 4);
        matrix.show();
        Serial.println("Button 5");
        //butt5.setTimeout(15000);
        myMatrix[1][1] = 2;
        //game();
        }
//------------обработка нажатия 6-ой кнопки для 6-ого квадрата-------------  
  else if (butt6.isSingle()){
        matrix.drawBitmap16(11, 6, polex1, 4, 4);
        matrix.show();
        Serial.println("Button 6");
       // butt6.setTimeout(15000);
        myMatrix[1][2] = 1;
        //game();
        }
  else if (butt6.isDouble()){
        matrix.drawBitmap16(11, 6, poleo1, 4, 4);
        matrix.show();
        Serial.println("Button 6");
        //butt6.setTimeout(15000);
        myMatrix[1][2] = 2;
        //game();
        }
//------------обработка нажатия 7-ой кнопки для 7-ого квадрата-------------  
  else if (butt7.isSingle()) {
        matrix.drawBitmap16(1, 11, polex1, 4, 4);
        matrix.show();
        Serial.println("Button 7");
        //butt7.setTimeout(15000);
        myMatrix[0][0] = 1;
        //game();
        }
  else if (butt7.isDouble()) {
        matrix.drawBitmap16(1, 11, poleo1, 4, 4);
        matrix.show();
        Serial.println("Button 7");
        //butt7.setTimeout(15000);
        myMatrix[0][0] = 2;
        //game();
        }
//------------обработка нажатия 8-ой кнопки для 8-ого квадрата------------- 
  else if (butt8.isSingle()) {
        matrix.drawBitmap16(6, 11, polex1, 4, 4);
        matrix.show();
        Serial.println("Button 8");
        //butt8.setTimeout(15000);
        myMatrix[0][1] = 1;
        //game();
        }
  else if (butt8.isDouble()) {
        matrix.drawBitmap16(6, 11, poleo1, 4, 4);
        matrix.show();
        Serial.println("Button 8");
        //butt8.setTimeout(15000);
        myMatrix[0][1] = 2;
        //game();
        }

//------------обработка нажатия 9-ой кнопки для 9-ого квадрата------------- 
  else if (butt9.isSingle()) {
        matrix.drawBitmap16(11, 11, polex1, 4, 4);
        matrix.show();
        Serial.println("Button 9");
        //butt9.setTimeout(15000);
        myMatrix[0][2] = 1;
        //game();
        }
  else if (butt9.isDouble()) {
        matrix.drawBitmap16(11, 11, poleo1, 4, 4);
        matrix.show();
        Serial.println("Button 9");
        //butt9.setTimeout(15000);
        myMatrix[0][2] = 2;
        //game();
        }
    else if (butt10.isSingle()) {
        pole();
        }
}
// игровая логика
int X = 0, O = 0; // переменные для счета игры
void game(){
  if (myMatrix[0][0] == 1 && myMatrix[0][1] == 1 && myMatrix[0][2] == 1 || myMatrix[1][0] == 1 && myMatrix[1][1] == 1 && myMatrix[1][2] == 1 || myMatrix[2][0] == 1 && myMatrix[2][1] == 1 && myMatrix[2][2] == 1 || myMatrix[0][0] == 1 && myMatrix[1][0] == 1 && myMatrix[2][0] == 1 || myMatrix[0][1] == 1 && myMatrix[1][1] == 1 && myMatrix[2][1] == 1 || myMatrix[0][2] == 1 && myMatrix[1][2] == 1 && myMatrix[2][2] == 1 || myMatrix[0][0] == 1 && myMatrix[1][1] == 1 && myMatrix[2][2] == 1 ||myMatrix[0][2] == 1 && myMatrix[1][1] == 1 && myMatrix[2][0] == 1){
     X++;
     delay (400);
     matrix.clear();
     matrix.drawBitmap16(0, 0, polex1vine, 16, 16);
     matrix.show();
     delay(1500);
     //matrix.clear();
     //balls();
     //matrix.show();
     //delay(2000);
     pole();
     }
  else if (myMatrix[0][0] == 2 && myMatrix[0][1] == 2 && myMatrix[0][2] == 2 || myMatrix[1][0] == 2 && myMatrix[1][1] == 2 && myMatrix[1][2] == 2 || myMatrix[2][0] == 2 && myMatrix[2][1] == 2 && myMatrix[2][2] == 2 || myMatrix[0][0] == 2 && myMatrix[1][0] == 2 && myMatrix[2][0] == 2 || myMatrix[0][1] == 2 && myMatrix[1][1] == 2 && myMatrix[2][1] == 2 || myMatrix[0][2] == 2 && myMatrix[1][2] == 2 && myMatrix[2][2] == 2 || myMatrix[0][0] == 2 && myMatrix[1][1] == 2 && myMatrix[2][2] == 2 ||myMatrix[0][2] == 2 && myMatrix[1][1] == 2 && myMatrix[2][0] == 2){
     O++;
     delay (400);
     matrix.clear();
     matrix.drawBitmap16(0, 0, polexovine, 16, 16);
     matrix.show();
     delay(1500);
     //matrix.clear();
     //balls();
     //matrix.show();
     //delay(2000);
     pole();
        }
   // если результат ничейный

}

// Эффект для победы
