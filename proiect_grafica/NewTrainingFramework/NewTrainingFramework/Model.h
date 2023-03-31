#pragma once
#include "stdafx.h"
#include "../Utilities/utilities.h"

#include "Resources.h"
#include "Vertex.h"



class Model {
public:
	static std::map<int, Model*> loadedModels;
	ModelResource* mr;
	GLuint iboId, wiredIboId, vboId;
	GLuint nrIndices, nrVertices, nrIndicesWired;
	Vertex* verticesData;
	unsigned short* indices;
	Model(ModelResource* mr);
	void Init();
	void Load();
	void freeModel();
	~Model();
};