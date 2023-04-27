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
	this->loadTexture = LoadTGA(this->tr->file_path, &(this->textureWidth), &(this->textureHeight), &(this->textureBpp));
}
void Texture::Init() {
	glGenTextures(1, &(this->tId));

	glBindTexture(this->tr->type, this->tId);
	glTexParameteri(this->tr->type, GL_TEXTURE_MIN_FILTER, this->tr->min_filter);
	glTexParameteri(this->tr->type, GL_TEXTURE_MAG_FILTER, this->tr->mag_filter);

	glTexParameteri(this->tr->type, GL_TEXTURE_WRAP_S, this->tr->wrap_s);
	glTexParameteri(this->tr->type, GL_TEXTURE_WRAP_T, this->tr->wrap_t);
	
	// Texture::Load(); 
	
	if (this->textureBpp == 24) {
		glTexImage2D(this->tr->type, 0, GL_RGB, (GLsizei)(this->textureWidth), (GLsizei)(this->textureHeight), 0, GL_RGB, GL_UNSIGNED_BYTE, this->loadTexture);
	}
	else {
		glTexImage2D(this->tr->type, 0, GL_RGBA, (GLsizei)(this->textureWidth), (GLsizei)(this->textureHeight), 0, GL_RGBA, GL_UNSIGNED_BYTE, this->loadTexture);
	}

	glBindTexture(this->tr->type, 0);
}

void Texture::freeTexture() {
	delete(this->tr);
}