#pragma once
#include <map>
#include "Model.h"
#include "Texture.h"
#include "Shader.h"

class ResourceManager {
private: 
	static ResourceManager* spInstance;
	ResourceManager();
public:
	char* XMLpath;
	struct ModelResource {
		static char* path;
		char* file;
	};
	struct ShaderResource {
		static char* path;
		char* vs;
		char* fs;
	};
	struct TextureResource {
		static char* path;
		int type;
		char* file;
		int min_filter;
		int mag_filter;
		int wrap_s;
		int wrap_t;
	};

	std::map<int, Model> models;
	std::map<int, Shader> shaders;
	std::map<int, Texture> textures;
	xml_node<>* resourceManagerNode;
	void Init();
	static ResourceManager* getInstance();
	
	ModelResource* loadModel(int modelId);
	TextureResource* loadTexture(int textureId);
	ShaderResource* loadShader(int shaderId);

	void parseResourceManagerXML();

	void freeResources();
	~ResourceManager();
};