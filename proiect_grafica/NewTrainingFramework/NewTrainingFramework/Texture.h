#pragma once
#include "../Utilities/utilities.h"
#include "Resources.h"

class Texture {
public:
	static std::map<int, Texture*> loadedTextures;
	TextureResource* tr;
	GLuint tId;
	int textureWidth, textureHeight, textureBpp;
	char* loadTexture;
	Texture(TextureResource *tr);
	void Init();
	void Load();
	void freeTexture();
	~Texture();
};