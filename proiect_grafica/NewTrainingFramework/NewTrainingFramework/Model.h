#pragma once
#include "stdafx.h"
#include "Resources.h"
#include "Vertex.h"
#include "../Utilities/utilities.h"



class Model {
public:
	static std::map<int, Model*> loadedModels;
	ModelResource* mr;
	GLuint iboId, wiredIboId, vboId;
	GLuint nrIndices, nrVertices, nrIndicesWired;
	Vertex* verticesData;
	unsigned short* indices;
	Model::Model(ModelResource* mr);
	void Init();
	void Load();
	void freeModel();
	~Model();
};