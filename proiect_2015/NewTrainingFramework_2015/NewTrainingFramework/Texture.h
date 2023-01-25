#pragma once
#include "ResourceManager.h"
#include "../Utilities/utilities.h"

class Texture {
	ResourceManager::TextureResource* tr;
	GLuint tId;
	int textureWidth, textureHeight, textureBpp;
	char* loadTexture;
	Texture(ResourceManager::TextureResource* tr);
	void Init();
	void Load();
	void freeTexture();
	~Texture();
};