using namespace std;
#include "states.h"
#include "transitions.h"
#include <iostream>
#include "print_FSM.h"

//Should be implemented later, but pointers are necessary
//void FSM_loop_once(state_code* current_state, return_code* ret_code) {
//	return;
//}

//The running code
int main(int argc, char *argv[]) {
	//Initializing state and return code
	state_code cur_state = START_STATE;
	return_code ret_code = REPEAT;

	//printing initial state and return code
	print_FSM(cur_state, ret_code);

	//Creating pointer to state function
	int(*state_function)(void);

	//The pointer function values must match the state codes!
	state_func state_funcs[NUM_STATES] =
	{ idle_state, armed_state, liftoff_state,
	burnout_state, airbrakes_state, apogee_state,
	drogue_state, chute_state, landed_state};

	//Running the FSM until LANDED state
	while (cur_state != END_STATE) {
		state_function = state_funcs[cur_state];
		ret_code = return_code(state_function());
		cur_state = lookup_transition(cur_state, ret_code);
		print_FSM(cur_state, ret_code);
	}
	system("pause");
	return 0;
}