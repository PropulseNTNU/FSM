#pragma once
#include "transitions.h"
#include <iostream>

//Airbrakes can deploy, when velocity less than 1, change state
//to apogee
int airbrakes_state(void);