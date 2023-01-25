#pragma once
#include "Camera.h"
#include "../Utilities/utilities.h"


class Control {
	char key;
	char* action;
	void trigger();
	Control();
	~Control();
};