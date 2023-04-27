#pragma once
#include "ResourceManager.h"
#include "Vertex.h"
#include "../Utilities/utilities.h"
#include "Texture.h"
#include "Camera.h"


class SceneObject {
public:
	int modelId;
	int shaderId;
	char* type;
	char* name;
	bool isWired;
	int* texturesId;
	int texturesIdLength;
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;
	Vector3 color;
	bool depthTest;

	Model* model;
	Shader* shader;
	static std::map<int, Texture*> textures;
	//Texture** textures = new Texture[sizeof(texturesId)];

	void Load();
	void Init();
	void Update();
	void Draw();

	SceneObject();
	~SceneObject();
};