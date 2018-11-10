#ifndef STATES_H
#define STATES_H

//Including states, new states should also be included here
#include "idle_state.h"
#include "armed_state.h"

//se på denne, funker ikke c, namespace funker ikke i c
//namespace state_code {
//	enum type {
//		IDLE/* , ARMED, LIFTOFF, BURNOUT,
//		AIRBRAKES, APOGEE, LANDED*/
//	};
//}

//All posible states, NUM_STATES is not a state
enum state_code{
	IDLE, ARMED, NUM_STATES
};

//Transition struct
struct transition {
	enum state_code source_state;
	enum return_code ret_code;
	enum state_code destination_state;
};

//The outcomes of running a specific state-function
enum return_code { NEXT, REPEAT };

typedef int(*state_func)(void);

state_code lookup_transition(state_code cur_state, return_code rc);

#endif