
#include "Extras.h"
#include "Arduino.h"

#define EXTRAS_BUZZER_PIN 6

#define LED_R 9
#define LED_G 10
#define LED_B 11

#define TEMP_PIN A7

#define ANALOG_TO_MV 4.88f
#define TEMP_MV_AT_0 500.0f
#define TEMP_MV_TO_C 1/10.0f

int8_t lastTemperature;

void extrasInit(){
    pinMode(EXTRAS_BUZZER_PIN, OUTPUT);

    analogWrite(LED_R,0);
    analogWrite(LED_G,0);
    analogWrite(LED_B,0);

    lastTemperature = 0;
    updateTemperature();
    
}

void updateTemperature(){
    float temp;
    int intTemp;
    intTemp = analogRead(TEMP_PIN);
    temp = ((float)intTemp * ANALOG_TO_MV - TEMP_MV_AT_0)*TEMP_MV_TO_C;
    lastTemperature = temp;
}

void setLEDs(uint8_t r, uint8_t g, uint8_t b){
    analogWrite(LED_R,r);
    analogWrite(LED_G,g);
    analogWrite(LED_B,b);
}

void updateLEDs(){
    static unsigned long lastMillis = millis();
    static uint16_t r = 0,g = 0,b = 0;
    static uint8_t toAdv = 0;

    unsigned long dt = millis() - lastMillis;
    lastMillis = millis();

    switch (toAdv)
    {
    case 0:
        r = (r + dt/5);
        break;
    case 1:
        g = (g + dt/5);
        break;
    case 2:
        b = (b + dt/5);
    
    default:
        break;
    }

    if(r>255){
        r = 0;
        toAdv = 1;
    }else if(g > 255){
        g = 0;
        toAdv = 2;
    }else if(b > 255){
        b = 0;
        toAdv = 0;
    }


    setLEDs(r,g,b);

}