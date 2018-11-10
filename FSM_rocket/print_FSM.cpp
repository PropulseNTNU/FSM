using namespace std;
#include "print_FSM.h"

void print_FSM(state_code cur_state, return_code ret_code) {

	cout << "***********************" << endl;
	string state = "Current state:  ";
	if (cur_state == IDLE) {
		state += "IDLE";
	}
	/*else if (cur_state == ARMED) {
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
	*/
	cout << state << endl;

	if (ret_code == OK) {
		cout << "Transition: OK" << endl;
	}
	else {
		cout << "Transition: Repeat" << endl;
	}
	cout << "***********************" << endl;

}