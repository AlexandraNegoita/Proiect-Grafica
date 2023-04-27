#pragma once
#include <map>
struct ModelResource {
	//char* path;
	int modelId;
	char* file_path;
	bool isLoaded;
};
struct ShaderResource {
	int shaderId;
	// char* path;
	char* vs_path;
	char* fs_path;
	bool isLoaded;
};
struct TextureResource {
	int textureId;
	char* file_path;
	int type;
	//char* file;
	int min_filter;
	int mag_filter;
	int wrap_s;
	int wrap_t;
	bool isLoaded;
};



//// Lodaded materials maps
//std::map<int, Model*> loadedModels;
//std::map<int, Shader*> loadedShaders;
//std::map<int, Texture*> loadedTextures;