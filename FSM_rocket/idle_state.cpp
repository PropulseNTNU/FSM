using namespace std;
#include "idle_state.h"
#include "states.h"
#include <string>
#include <iostream>

//Only the arm button b should trigger next state
int idle_state(void) {
	return_code ret_code;
	string arm;
	cout << "ARM ROCKET BY PUSHING *b*" << endl;
	cin >> arm;
	if (arm == "b") {
		cout << "ROCKET IS NOW ARMED" << endl;
		ret_code = NEXT;
	}
	else {
		ret_code = REPEAT;
	}
	return ret_code;
}