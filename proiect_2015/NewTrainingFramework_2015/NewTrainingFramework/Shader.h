#pragma once
#include "ResourceManager.h"

class Shader {
	ResourceManager::ShaderResource* sr;
	int sId;
	Shader(ResourceManager::ShaderResource* sr);
	void Init();
	void Load();
	~Model();
};