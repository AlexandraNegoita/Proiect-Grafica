#include "stdafx.h"
#include "Texture.h"
#include "stdafx.h"
#include "Resources.h"
#include <fstream>
#include "../Utilities/utilities.h"

Texture::Texture(TextureResource* tr) {
	this->tr = tr;
}

void Texture::Load() {
	Texture::loadTexture = LoadTGA(Texture::tr->file_path, &(Texture::textureWidth), &(Texture::textureHeight), &(Texture::textureBpp));	
}
void Texture::Init() {
	glGenTextures(1, &(Texture::tId));

	glBindTexture(Texture::tr->type, Texture::tId);
	glTexParameteri(Texture::tr->type, GL_TEXTURE_MIN_FILTER, Texture::tr->min_filter);
	glTexParameteri(Texture::tr->type, GL_TEXTURE_MAG_FILTER, Texture::tr->mag_filter);

	glTexParameteri(Texture::tr->type, GL_TEXTURE_WRAP_S, Texture::tr->wrap_s);
	glTexParameteri(Texture::tr->type, GL_TEXTURE_WRAP_T, Texture::tr->wrap_t);
	
	Texture::Load(); 
	
	if (Texture::textureBpp == 24) {
		glTexImage2D(Texture::tr->type, 0, GL_RGB, (GLsizei)(Texture::textureWidth), (GLsizei)(Texture::textureHeight), 0, GL_RGB, GL_UNSIGNED_BYTE, Texture::loadTexture);
	}
	else {
		glTexImage2D(Texture::tr->type, 0, GL_RGBA, (GLsizei)(Texture::textureWidth), (GLsizei)(Texture::textureHeight), 0, GL_RGBA, GL_UNSIGNED_BYTE, Texture::loadTexture);
	}

	glBindTexture(Texture::tr->type, 0);
}

void Texture::freeTexture() {
	delete(Texture::tr);
}