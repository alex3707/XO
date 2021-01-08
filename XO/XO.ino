#define STRIP_PIN 2     // пин ленты
#include "bitmap.h"

#define COLOR_DEBTH 2
#include <microLED.h>
microLED<16 * 16, STRIP_PIN, MLED_NO_CLOCK, LED_WS2812, ORDER_GRB, CLI_HIGH> matrix(16, 16, ZIGZAG, LEFT_TOP, DIR_DOWN);


void setup() {
      matrix.clear();
      matrix.setBrightness(50);
      pole();
      

}

void loop() {

  

  
  //matrix.set(0, 7, mPurple);
  //matrix.set(7, 0, mTeal);
     
      
}


void pole(){
      matrix.drawBitmap16(0, 0, poleXO, 16, 16);
      matrix.drawBitmap16(1, 1, poleo1, 4, 4);
      matrix.drawBitmap16(6, 1, polex1, 4, 4);
      //matrix.set(1, 1, mYellow);
      //matrix.set(1, 2, mYellow);
      //matrix.set(1, 3, mYellow);
      //matrix.set(1, 4, mYellow);
      matrix.show();
      delay(1000);
     // matrix.clear();
}
