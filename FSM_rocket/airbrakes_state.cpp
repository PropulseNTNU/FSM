using namespace std;
#include "transitions.h"
//#include "airbrakes_state.h"

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