#ifndef __EXTRAS_H__
#define __EXTRAS_H__

#include <Arduino.h>

extern int8_t lastTemperature;

void extrasInit();

void updateExtras();

void updateTemperature();

void updateLEDs();

void setLEDs(uint8_t r, uint8_t g, uint8_t b);

#endif //__EXTRAS_H__