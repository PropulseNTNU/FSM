using namespace std;
//#include "burnout_state.h"
#include "transitions.h"

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