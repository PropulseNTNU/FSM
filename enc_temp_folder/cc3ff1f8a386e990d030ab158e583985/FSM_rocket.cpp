using namespace std;
#include <iostream>
#include <stdio.h>
#include <string>


//Declaring the possible function states
int idle_state(void);
int liftoff_state(void);
int landed_state(void);

//The pointer function values must match the state codes!
int(*state[])(void) = {idle_state, liftoff_state, landed_state};
enum state_code {IDLE, LIFTOFF, LANDED};

//The outcomes of running a specific state-function
enum return_code {OK, REPEAT};

//A simple allowed transition
struct transition {
	enum state_code source_state;
	enum return_code ret_code;
	enum state_code destination_state;
};

//All the allowed transitions
struct transition state_transitions[] = {
	{	IDLE,	OK,		LIFTOFF	},
	{	IDLE,	REPEAT,	IDLE	}
};

//Lookup if a new transition should take place, return the next state
state_code lookup_transition(state_code cur_state, return_code rc) {
	state_code next_state = cur_state;

	for (auto transition : state_transitions) {
		if ((transition.source_state == cur_state) && (transition.ret_code == rc)) {
			next_state = transition.destination_state;
			break;
		}
	}
	return next_state;
}

//Implementation of state functions
int idle_state(void) {
	int z_accel;
	return_code ret_code;
	cout << "Waiting for z-accel input: must be larger than 5" << endl;
	cin >> z_accel;
	if (z_accel >= 5) {
		ret_code = OK;
	}
	else {
		ret_code = REPEAT;
	}
	return ret_code;
}

//Code just repeats
int liftoff_state(void) {
	return_code ret_code;
	ret_code = REPEAT;
	return ret_code;
}

//Does nothing
int landed_state(void) {
	return_code ret_code;
	ret_code = REPEAT;
	return ret_code;
}
 
//Printing FSM
void print_FSM(state_code cur_state, return_code ret_code) {

	cout << "***********************" << endl;
	string state = "Current state:  ";
	if (cur_state == IDLE) {
		state += "IDLE";
	}
	else if (cur_state == LIFTOFF) {
		state += "LIFTOFF";
	}
	else if (cur_state == LANDED) {
		state += "LANDED";
	}
	cout << state << endl;

	if (ret_code == OK) {
		cout << "Transition: OK" << endl;
	}
	else {
		cout << "Transition: Repeat" << endl;
	}
	cout << "***********************" << endl;
	
}

//Should be implemented later, but pointers are necessary
void FSM_loop_once(state_code* current_state, return_code* ret_code) {
	return;
}

//Defining the start and end states
#define START_STATE IDLE
#define END_STATE LANDED

//The running code
int main(int argc, char *argv[]) {
	//Initializing state and return code
	state_code cur_state = START_STATE;
	return_code ret_code;

	//Creating pointer to state function
	int(*state_function)(void);

	//Running the FSM until LANDED state
	while (cur_state != END_STATE) {
		state_function = state[cur_state];
		ret_code = return_code(state_function());
		print_FSM(cur_state, ret_code);
		cur_state = lookup_transition(cur_state, ret_code);
	}
	system("pause");
	return 0;
}