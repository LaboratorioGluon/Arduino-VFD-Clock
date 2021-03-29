#include <Arduino.h>

#include "RTC.h"
#include "Extras.h"
#include "Digits.h"

#define MAIN_LOOP_MS 20

unsigned long lastMillis;

void setup() {
  
  extrasInit();
  rtcInit();
  rtcUpdate();

  Digits::Init();

  lastMillis = millis();
  Digits::setDigits(0,1,2,3);
}


void loop() {
  unsigned long millisDiff;
  
  Digits::setDigits(lastVfdTime.hd,lastVfdTime.hu,lastVfdTime.md,lastVfdTime.mu);

  Digits::updateDigits();
  updateLEDs();

  // Forzamos esperar MAIN_LOOP_MS
  millisDiff = millis() - lastMillis;
  if( millisDiff < MAIN_LOOP_MS ){
    delay(MAIN_LOOP_MS - millisDiff);
  }

  lastMillis = millis();
  

}