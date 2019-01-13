#ifndef TRANSITIONS_H
#define TRANSITIONS_H

#include "states.h"

//Transition struct
struct transition {
	enum state_code source_state;
	enum return_code ret_code;
	enum state_code destination_state;
};

state_code lookup_transition(state_code cur_state, return_code rc);

#endif