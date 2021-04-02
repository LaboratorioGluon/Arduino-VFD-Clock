
#include <Arduino.h>

#include "Input.h"

#define INPUT_BUTTONS_PIN A1

#define BUTTON_V 5.0f
#define NUM_BUTTONS 4.0f
#define ADC_MAX_VALUE 1023.0f

#define INPUT_TIME_BETWEEN_PRESSED 100


namespace Inputs
{

    BUTTON_PRESSED newButton = BUTTON_PRESSED::NONE;
    BUTTON_PRESSED lastButton = BUTTON_PRESSED::NONE;

    long int lastButtonPressedTime;

    void init(){
        lastButtonPressedTime = millis();
    }

    void update(){

        uint16_t swAnalogValue=0;
        int adcRead;
        for(int i = 0; i < 4; i++){
            adcRead = analogRead(INPUT_BUTTONS_PIN);
            swAnalogValue=(adcRead > swAnalogValue)?adcRead:swAnalogValue;
        }

        Serial.println(swAnalogValue);
        BUTTON_PRESSED lButton = BUTTON_PRESSED::NONE;

        if(swAnalogValue < 150){
            lButton = BUTTON_PRESSED::NONE;
        }else if(swAnalogValue < 280){
            lButton = BUTTON_PRESSED::UP; //2
        }else if(swAnalogValue < 480){
            lButton = BUTTON_PRESSED::DOWN; //3
        }else if(swAnalogValue < 800){
            lButton = BUTTON_PRESSED::BACK;  //4
        }else{
            lButton = BUTTON_PRESSED::MENU; //1
        }

        if( lButton != lastButton ){
            lastButton = lButton;
            newButton = lButton;
            Serial.print("Actualizando boton a :");Serial.println(lButton);
        }

    }
    
    void resetInput(){
        newButton = BUTTON_PRESSED::NONE;
    }

} // namespace Inputs

