#ifndef STATES_H
#define STATES_H

//Include states here
#include "idle_state.h"
#include "armed_state.h"
#include "liftoff_state.h"
#include "burnout_state.h"
#include "airbrakes_state.h"
#include "apogee_state.h"
#include "landed_state.h"

//Defining the start and end states
#define START_STATE IDLE
#define END_STATE LANDED

//All posible states, NUM_STATES is not a state
enum state_code {
	IDLE, ARMED, LIFTOFF, BURNOUT, AIRBRAKES,
	APOGEE, LANDED, NUM_STATES
};

//The outcomes of running a state-function
enum return_code { NEXT, REPEAT };

typedef int(*state_func)(void);

//se p� denne, funker ikke c, namespace funker ikke i c
//namespace state_code {
//	enum type {
//		IDLE/* , ARMED, LIFTOFF, BURNOUT,
//		AIRBRAKES, APOGEE, LANDED*/
//	};
//}

#endif