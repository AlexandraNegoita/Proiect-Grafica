#pragma once
#include "ResourceManager.h"
#include "Vertex.h"
#include "../Utilities/utilities.h"
#include "Texture.h"


class SceneObject {
public:
	int modelId;
	int shaderId;
	char* type;
	char* name;
	bool isWired;
	int* texturesId;
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;
	Vector3 color;
	bool depthTest;

	Model* model;
	Shader* shader;
	Texture** textures;

	void Load();
	void Init();
	void Draw();

	SceneObject();
	~SceneObject();
};