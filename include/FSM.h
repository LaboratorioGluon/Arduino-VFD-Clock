#ifndef __FSM_H__
#define __FSM_H__

#include "Input.h"

enum __FSM_STATES__ {
    STATE_CLOCK = 0,
    STATE_TEMP,
    STATE_SETTIME
};

struct FSM_State{
    FSM_State * nextState;
    void (*func)(void);
    void (*inputFunc)(void);
};

extern FSM_State * currentState;

void fsmInit(FSM_State* pCurrentState);

void fsmUpdate(float dt);

void fsmInput(Inputs::BUTTON_PRESSED btn);

#endif //__FSM_H__