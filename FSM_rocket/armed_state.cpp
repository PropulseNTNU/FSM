using namespace std;
#include "states.h"
#include <iostream>

int armed_state(void) {
	int z_accel;
	return_code ret_code;
	cout << "Waiting for z-accel input: must be larger than 7" << endl;
	cin >> z_accel;
	if (z_accel > 7) {
		ret_code = NEXT;
	}
	else {
		ret_code = REPEAT;
	}
	return ret_code;
}