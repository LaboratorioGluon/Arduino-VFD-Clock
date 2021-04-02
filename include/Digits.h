#ifndef __DIGITS_H__
#define __DIGITS_H__

#include <stdint.h>

#define DIGITS_DOUT 8
#define DIGITS_CLK 7

#define DIGITS_REFRESH_PERIOD_MS 100
#define DIGITS_TIME_BETWEEN_DIGIT_MS 10

// Pins of the GRIDs
#define GRID_1 2
#define GRID_2 3
#define GRID_3 4
#define GRID_4 5

#define SYMBOL_BLANK ' '
#define SYMBOL_DEGREE '.'
#define SYMBOL_MINUS '-'

namespace Digits{

    enum SYMBOLS{
        EMPTY = 22,
        DEGREE,
        MINUS
    };

    extern uint8_t charToDigitTable[];
    extern uint8_t digitsValues[4];

    void Init();

    void setDigits(uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4);
    void updateDigits();
}

#endif //__DIGITS_H__
