using namespace std;
#include <iostream>
#include <stdio.h>
#include <string>

//Declaring the possible function states
int idle_state(void);
int armed_state(void);
int liftoff_state(void);
int burnout_state(void);
int airbrakes_state(void);
int apogee_state(void);
int landed_state(void);

//The pointer function values must match the state codes!
int(*state[])(void) = {idle_state, armed_state,
					liftoff_state, burnout_state, 
					airbrakes_state,apogee_state,
					landed_state};
enum state_code {IDLE, ARMED, LIFTOFF, BURNOUT, AIRBRAKES, APOGEE,
				LANDED};

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
	{	IDLE,		REPEAT,		IDLE		},
	{	IDLE,		OK,			ARMED		},
	{	ARMED,		REPEAT,		ARMED		},
	{	ARMED,		OK,			LIFTOFF		},
	{	LIFTOFF,	REPEAT,		LIFTOFF		},
	{	LIFTOFF,	OK,			BURNOUT		},
	{	BURNOUT,	REPEAT,		BURNOUT		},
	{	BURNOUT,	OK,			AIRBRAKES	},
	{	AIRBRAKES,	REPEAT,		AIRBRAKES	},
	{	AIRBRAKES,	OK,			APOGEE		}
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

//Only an arm button B should trigger next state
int idle_state(void) {
	return_code ret_code;
	string arm;
	cout << "ARM ROCKET BY PUSHING *b*" << endl;
	cin >> arm;
	if (arm == "b") {
		cout << "ROCKET IS NOW ARMED" << endl;
		ret_code = OK;
	}
	else {
		ret_code = REPEAT;
	}
	return ret_code;
}

//Only a large acceleration should trigger next lift-off state
int armed_state(void) {
	int z_accel;
	return_code ret_code;
	cout << "Waiting for z-accel input: must be larger than 7" << endl;
	cin >> z_accel;
	if (z_accel > 7) {
		ret_code = OK;
	}
	else {
		ret_code = REPEAT;
	}
	return ret_code;
}

//When allerations has "calmed down", trigger next state, Burnout
int liftoff_state(void) {
	return_code ret_code;
	int z_accel;
	cout << "Waiting for z-accel input: must be less than 5" << endl;
	cin >> z_accel;
	if (z_accel < 5) {
		ret_code = OK;
	}
	else {
		ret_code = REPEAT;
	}

	return ret_code;
}

//Next state Aibrakes should be triggered once a_z = 0.
int burnout_state(void) {
	return_code ret_code;
	int z_accel;
	cout << "Waiting for z-accel input: must be less or equal to 0" << endl;
	cin >> z_accel;
	if (z_accel <= 0) {
		ret_code = OK;
	}
	else {
		ret_code = REPEAT;
	}

	return ret_code;
}

//Airbrakes can deploy, when velocity less than 1, change state
//to apogee
int airbrakes_state(void) {
	return_code ret_code;

	int z_vel;
	cout << "Waiting for velocity input: must be less or equal to 1" << endl;
	cin >> z_vel;
	if (z_vel <= 1) {
		ret_code = OK;
	}
	else {
		ret_code = REPEAT;
	}

	return ret_code;
}

int apogee_state(void) {
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
	else if (cur_state == ARMED) {
		state += "ARMED";
	}
	else if (cur_state == LIFTOFF) {
		state += "LIFTOFF";
	}
	else if (cur_state == BURNOUT) {
		state += "BURNOUT";
	}
	else if (cur_state == AIRBRAKES) {
		state += "AIRBRAKES";
	}
	else if (cur_state == APOGEE) {
		state += "APOGEE";
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
	return_code ret_code = REPEAT;

	//Creating pointer to state function
	int(*state_function)(void);

	print_FSM(cur_state, ret_code);

	//Running the FSM until LANDED state
	while (cur_state != END_STATE) {
		state_function = state[cur_state];
		ret_code = return_code(state_function());
		cur_state = lookup_transition(cur_state, ret_code);
		print_FSM(cur_state, ret_code);

	}
	system("pause");
	return 0;
}