#pragma once
#include "stdafx.h"
#include "Math.h"
#include "../Utilities/utilities.h"

struct Vertex 
{
	Vector3 pos;
	//color
	Vector3 color;
	Vector3 norm;
	Vector3 binorm;
	Vector3 tgt;
	Vector2 uv;
};