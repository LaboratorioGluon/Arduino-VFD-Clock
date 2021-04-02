#include <Arduino.h>

#include "RTC.h"
#include "Extras.h"
#include "Digits.h"
#include "Input.h"
#include "FSM.h"

#define MAIN_LOOP_MS 20

unsigned long lastMillis;


void fsmClockFunc(void){
  Digits::setDigits(lastVfdTime.hd,lastVfdTime.hu,lastVfdTime.md,lastVfdTime.mu);
}

void fsmClockInput(void){

}

void fsmTempFunc(void){
  Digits::setDigits(lastTemperature/10,lastTemperature%10,SYMBOL_DEGREE,'C');
}

void fsmTempInput(void){

}

extern FSM_State fsmTemp;
FSM_State fsmClock = { &fsmTemp, fsmClockFunc , nullptr };
FSM_State fsmTemp = { &fsmClock, fsmTempFunc, nullptr };


void setup() {
  
  extrasInit();
  rtcInit();
  rtcUpdate();
  fsmInit(&fsmClock);

  Digits::Init();

  lastMillis = millis();
  Digits::setDigits(0,1,2,3);

  Serial.begin(9600);
}

uint32_t cycle;

void loop() {
  unsigned long millisDiff;

  if(cycle%1000 == 0){
    rtcUpdate();
  }

  
  Inputs::update();
  

  fsmUpdate(MAIN_LOOP_MS);

  Digits::updateDigits();

  fsmInput(Inputs::newButton);
  

  // Forzamos esperar MAIN_LOOP_MS
  millisDiff = millis() - lastMillis;
  if( millisDiff < MAIN_LOOP_MS ){
    delay(MAIN_LOOP_MS - millisDiff);
  }

  //Inputs::update();
  Inputs::resetInput();
  lastMillis = millis();
  cycle++;  

}