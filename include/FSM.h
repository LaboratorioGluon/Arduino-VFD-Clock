#ifndef __FSM_H__
#define __FSM_H__

enum __FSM_STATES__ {
    STATE_CLOCK = 0,
    STATE_TEMP,
    STATE_SETTIME
};


void fsmInit();

void fsmUpdate(float dt);

#endif //__FSM_H__