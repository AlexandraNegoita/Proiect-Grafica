#pragma once
#include <map>
#include "Shader.h"
#include "Model.h"
#include "Texture.h"

#include "../Utilities/rapidxml-1.13/rapidxml.hpp"
using namespace rapidxml;

class ResourceManager {
private: 
	static ResourceManager* spInstance;
	ResourceManager();
	
public:
	char* XMLpath;
	
	void Init();
	static ResourceManager* getInstance();
	
	Model* loadModel(int modelId);
	Texture* loadTexture(int textureId);
	Shader* loadShader(int shaderId);

	// Resources maps
	std::map<int, ModelResource*> models;
	std::map<int, ShaderResource*> shaders;
	std::map<int, TextureResource*> textures;

	void parseResourceManagerXML();

	void freeResources();
	~ResourceManager();
};