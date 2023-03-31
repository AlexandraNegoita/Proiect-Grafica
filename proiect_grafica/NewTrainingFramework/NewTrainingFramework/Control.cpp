#include "stdafx.h"
#include "Control.h"
#include "Camera.h"
#include <fstream>
#include "../Utilities/utilities.h"


Control::Control(char* key, char* action)
{
	this->key = key;
	this->action = action;
}

void Control::trigger(Camera camera) {
	if (strcmp(action, "MOVE_CAMERA_POSITIVE_Z")) {
		camera.moveOz(1);
	}
	else if (strcmp(action, "MOVE_CAMERA_NEGATIVE_Z")) {
		camera.moveOz(-1);
	}
	else if (strcmp(action, "MOVE_CAMERA_POSITIVE_X")) {
		camera.moveOx(1);
	}
	else if (strcmp(action, "MOVE_CAMERA_NEGATIVE_X")) {
		camera.moveOx(-1);
	}
	else if (strcmp(action, "MOVE_CAMERA_POSITIVE_Y")) {
		camera.moveOy(1);
	}
	else if (strcmp(action, "MOVE_CAMERA_NEGATIVE_Y")) {
		camera.moveOy(-1);
	}
	else if (strcmp(action, "ROTATE_CAMERA_POSITIVE_Y")) {
		camera.rotateOy(1);
	}
	else if (strcmp(action, "ROTATE_CAMERA_NEGATIVE_Y")) {
		camera.rotateOy(-1);
	}
	else if (strcmp(action, "ROTATE_CAMERA_POSITIVE_X")) {
		camera.rotateOx(1);
	}
	else if (strcmp(action, "ROTATE_CAMERA_NEGATIVE_X")) {
		camera.rotateOx(-1);
	}
	else if (strcmp(action, "ROTATE_CAMERA_POSITIVE_Z")) {
		camera.rotateOz(1);
	}
	else if (strcmp(action, "ROTATE_CAMERA_NEGATIVE_Z")) {
		camera.rotateOz(-1);
	}
}

Control::~Control()
{
}
