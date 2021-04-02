
#include <Arduino.h>

#include "Input.h"

#define INPUT_BUTTONS_PIN A1

#define BUTTON_V 5.0f
#define NUM_BUTTONS 4.0f
#define ADC_MAX_VALUE 1023.0f


namespace Inputs
{

    BUTTON_PRESSED lastButton = BUTTON_PRESSED::NONE;

    void update(){
        uint16_t swAnalogValue = analogRead(INPUT_BUTTONS_PIN);

        if(swAnalogValue < 150){
            lastButton = BUTTON_PRESSED::NONE;
        }else if(swAnalogValue < 280){
            lastButton = BUTTON_PRESSED::UP; //2
        }else if(swAnalogValue < 480){
            lastButton = BUTTON_PRESSED::DOWN; //3
        }else if(swAnalogValue < 800){
            lastButton = BUTTON_PRESSED::BACK;  //4
        }else{
            lastButton = BUTTON_PRESSED::MENU; //1
        }
    }
    
} // namespace Inputs

