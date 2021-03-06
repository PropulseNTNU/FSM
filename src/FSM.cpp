using namespace std;
#include "states.h"
#include "transitions.h"
#include "print_FSM.h"

//Remove library later
#include <iostream>

//Defining the start and end states
#define START_STATE IDLE
#define END_STATE LANDED

int main(int argc, char *argv[]) {

	//Initializing state and return code
	state current_state = START_STATE;
	return_code ret_code = REPEAT;

	//printing initial state and return code
	print_FSM(current_state, ret_code);

	//Creating pointer to state function
	int(*state_function)(void);

	//The pointer function values must match the state codes!
	state_func state_funcs[NUM_STATES] =
	{ idle_state, armed_state, liftoff_state,
	burnout_state, airbrakes_state, apogee_state,
	drogue_state, chute_state, landed_state};

	//Running the FSM until LANDED state
	while (current_state != END_STATE) {
		state_function = state_funcs[current_state];
		ret_code = return_code(state_function());
		current_state = lookup_transition(current_state, ret_code);
		print_FSM(current_state, ret_code);
	}
	system("pause");
	return 0;
}