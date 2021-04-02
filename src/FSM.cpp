#include "FSM.h"

FSM_State *currentState;



void fsmInit(FSM_State* pCurrentState){
    currentState = pCurrentState;
}


void updateClock(float dt){

}


void updateTemp(float dt){

}


void updateSetTime(float dt){

}

void fsmUpdate(float dt){
    currentState->func();
}

void fsmInput(Inputs::BUTTON_PRESSED btn){
    if(currentState->inputFunc == nullptr){
        if(btn == Inputs::BUTTON_PRESSED::MENU){
            currentState = currentState->nextState;
        }
    }
}