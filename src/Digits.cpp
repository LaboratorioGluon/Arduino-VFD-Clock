#include <Arduino.h>

#include "Digits.h"

#define INTERDIGIT_MS 3


namespace Digits
{

    /*
        Orden: DP, 10, 6, 5, 4, 3, 2, 1
        Orden: 1,2,3,4,5,6,10,DP
            ---2---
           /      /
          4      1 
         /      /
        ---3---
       /      /
      5     10
     /      /
     ---6---  DP

    */
    uint8_t charToDigitTable[] = {
        0b11011110, //0
        0b10000010,
        0b11101100,
        0b11100110,
        0b10110010,
        0b01110110,
        0b01111110,
        0b11000010,
        0b11111110,
        0b11110110, //9
        0b11111010, //A
        0b11111110, //B
        0b01011100, //C
        0b10101110, //d
        0b01111100, //E
        0b01111000, //F
        0b00000001, //G
        0b10111010, //H
        0b10000010, //I
        0b10000110, //J
        0b00000001, //K
        0b00011100, //L

    };

    uint8_t digitsValues[4] = {0};



    void Init(){
        pinMode(DIGITS_DOUT, OUTPUT);
        pinMode(DIGITS_CLK, OUTPUT);

        pinMode(GRID_1, OUTPUT);
        digitalWrite(GRID_1, LOW);
        pinMode(GRID_2, OUTPUT);
        digitalWrite(GRID_2, LOW);
        pinMode(GRID_3, OUTPUT);
        digitalWrite(GRID_3, LOW);
        pinMode(GRID_4, OUTPUT);
        digitalWrite(GRID_4, LOW);

        
    }

    uint8_t charToDigit(uint8_t digit){
        if(digit < 10){
            return digit;
        }else if(digit <= 'L' && digit >= 'A'){
            return digit-'A';
        }else{
            return 0;
        }
    }

    void setTime(uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4){
        digitsValues[0] = (d1<10)?d1:0;
        digitsValues[1] = (d2<10)?d2:0;
        digitsValues[2] = (d3<10)?d3:0;
        digitsValues[3] = (d4<10)?d4:0;
    }

    void setDigits(uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4){
        digitsValues[0] = charToDigit(d1);
        digitsValues[1] = charToDigit(d2);
        digitsValues[2] = charToDigit(d3);
        digitsValues[3] = charToDigit(d4);
    }

    void updateDigits(){

        digitalWrite(GRID_1, HIGH);
        shiftOut(DIGITS_DOUT, DIGITS_CLK, LSBFIRST, charToDigitTable[digitsValues[0]]);
        delay(INTERDIGIT_MS);
        digitalWrite(GRID_1, LOW);
        digitalWrite(GRID_2, HIGH);
        shiftOut(DIGITS_DOUT, DIGITS_CLK, LSBFIRST, charToDigitTable[digitsValues[1]]);
        delay(INTERDIGIT_MS);
        digitalWrite(GRID_2, LOW);
        digitalWrite(GRID_3, HIGH);
        shiftOut(DIGITS_DOUT, DIGITS_CLK, LSBFIRST, charToDigitTable[digitsValues[2]]);
        delay(INTERDIGIT_MS);
        digitalWrite(GRID_3, LOW);
        digitalWrite(GRID_4, HIGH);
        shiftOut(DIGITS_DOUT, DIGITS_CLK, LSBFIRST, charToDigitTable[digitsValues[3]]);
        delay(INTERDIGIT_MS);
        digitalWrite(GRID_4, LOW);
    }

} // namespace
