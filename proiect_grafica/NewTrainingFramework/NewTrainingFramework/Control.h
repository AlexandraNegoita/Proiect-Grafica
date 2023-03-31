#pragma once
#include "Camera.h"
#include "../Utilities/utilities.h"


class Control {
public:
	char* key;
	char* action;
	Control(char* key, char* action);
	void trigger(Camera camera);
	~Control();
};