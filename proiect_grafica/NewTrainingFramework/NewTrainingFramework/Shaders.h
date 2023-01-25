#pragma once
#include "../Utilities/utilities.h"

class Shaders 
{
public:
	GLuint program, vertexShader, fragmentShader;
	char fileVS[260];
	char fileFS[260];
	GLint positionAttribute;
	GLint normAttribute;
	GLint binormAttribute;
	GLint tgtAttribute;
	GLint uvAttribute;
	GLint viewUniform;
	GLint textureUniform;
	GLint perspectiveUniform;
	GLint colorAttribute;
	GLint matrixUniform;

	int Init();
	~Shaders();
};