#pragma once
#include "../Utilities/utilities.h"
#include "Resources.h"

class Shader {
public:
	static std::map<int, Shader*> loadedShaders;
	GLuint program, vertexShader, fragmentShader;
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
	ShaderResource* sr;
	int sId;
	Shader(ShaderResource* sr);
	int Init();
	void Load();
	~Shader();
};