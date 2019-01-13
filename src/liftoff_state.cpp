using namespace std;
#include "states.h"
#include <iostream>

//When allerations has "calmed down", trigger next state, Burnout
int liftoff_state(void) {
	return_code ret_code;
	int z_accel;
	cout << "Waiting for z-accel input: must be less than 5" << endl;
	cin >> z_accel;
	if (z_accel < 5) {
		ret_code = NEXT;
	}
	else {
		ret_code = REPEAT;
	}

	return ret_code;
}