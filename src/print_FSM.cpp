using namespace std;
#include "print_FSM.h"
#include "states.h"
#include <iostream>
#include <string>

const char states[NUM_STATES][15] = {"IDLE", "ARMED", "LIFTOFF",
								"BURNOUT", "AIRBRAKES", "APOGEE",
								"LANDED"};

void print_FSM(state cur_state, return_code ret_code) {

	printf("***********************\n");
	
	printf("Current state:  %s\n", states[cur_state]);

	if (ret_code == NEXT) {
		printf("Transition: Next\n");
	}
	else {
		printf("Transition: Repeat\n");
	}
	printf("***********************\n");

}