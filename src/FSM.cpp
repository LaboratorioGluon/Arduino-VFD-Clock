#include "FSM.h"

__FSM_STATES__ currentState;

void fsmInit(){
    currentState = STATE_CLOCK;
}



void updateClock(float dt){

}


void updateTemp(float dt){

}


void updateSetTime(float dt){

}

void fsmUpdate(float dt){
    switch(currentState){
        case STATE_CLOCK:   updateClock(dt);   break;
        case STATE_TEMP:    updateTemp(dt);    break;
        case STATE_SETTIME: updateSetTime(dt); break;
        default: updateClock(dt);
    }
}
