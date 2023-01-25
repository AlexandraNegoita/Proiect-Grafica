#pragma once
#include "ResourceManager.h"
#include "Vertex.h"
#include "../Utilities/utilities.h"


class Model {
	ResourceManager::ModelResource* mr;
	GLuint iboId, wiredIboId, vboId;
	GLuint nrIndices, nrVertices, nrIndicesWired;
	Vertex* verticesData;
	unsigned short* indices;
	Model(ResourceManager::ModelResource* mr);
	void Init();
	void Load();
	void freeModel();
	~Model();
};