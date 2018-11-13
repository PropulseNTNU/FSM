#include "transitions.h"
#include "states.h"
#include <iostream>
#include <stdio.h>
#include <string>

//All the allowed transitions
struct transition state_transitions[] = {
	{ IDLE,			REPEAT,			IDLE		},
	{ IDLE,			NEXT,			ARMED		},
	{ ARMED,		REPEAT,			ARMED		},
	{ ARMED,		NEXT,			LIFTOFF		},
	{ LIFTOFF,		REPEAT,			LIFTOFF		},
	{ LIFTOFF,		NEXT,			BURNOUT		},
	{ BURNOUT,		REPEAT,			BURNOUT		},
	{ BURNOUT,		NEXT,			AIRBRAKES	},
	{ AIRBRAKES,	REPEAT,			AIRBRAKES	},
	{ AIRBRAKES,	NEXT,			APOGEE		}
};

//Lookup if a new transition should take place, return the next state
state_code lookup_transition(state_code cur_state, return_code rc) {
	state_code next_state = cur_state;

	//Lag matrise her, siden det er enums!
	for (auto transition : state_transitions) {
		if ((transition.source_state == cur_state) && (transition.ret_code == rc)) {
			next_state = transition.destination_state;
			break;
		}
	}
	return next_state;
}