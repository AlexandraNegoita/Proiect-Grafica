#pragma once
#include "ResourceManager.h"

class Shader {
	GLuint program, vertexShader, fragmentShader;
	ResourceManager::ShaderResource* sr;
	int sId;
	Shader(ResourceManager::ShaderResource* sr);
	int Init();
	void Load();
	~Shader();
};