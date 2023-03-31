#include "stdafx.h"
#include "Model.h"
#include "stdafx.h"
#include <fstream>
#include "../Utilities/utilities.h"

Model::Model(ModelResource *mr) {
	this->mr = mr;
}

void Model::Load() {
	FILE* modelFile;

	modelFile = fopen(Model::mr->file_path, "r");
	char* line = (char*)malloc(sizeof(char) * 1000);
	fgets(line, 1000, modelFile);
	int nrVerticesCpy;
	int nrIndicesCpy;
	int lineIndice;
	int res = sscanf(line, "NrVertices: %u", &nrVerticesCpy);
	Model::nrVertices = nrVerticesCpy;
	Model::verticesData = new Vertex[Model::nrVertices];
	int i = -1;

	while (nrVerticesCpy) {
		fgets(line, 1000, modelFile);
		Vertex newVertex;
		int res2 = sscanf(line, "   %u. pos:[%f, %f, %f]; norm:[%f, %f, %f]; binorm:[%f, %f, %f]; tgt:[%f, %f, %f]; uv:[%f, %f];", &lineIndice, &newVertex.pos.x, &newVertex.pos.y, &newVertex.pos.z, &newVertex.norm.x, &newVertex.norm.y, &newVertex.norm.z, &newVertex.binorm.x, &newVertex.binorm.y, &newVertex.binorm.z, &newVertex.tgt.x, &newVertex.tgt.y, &newVertex.tgt.z, &newVertex.uv.x, &newVertex.uv.y);

		newVertex.color.x = 0.5f;
		newVertex.color.y = 0.5f;
		newVertex.color.z = 0.5f;

		Model::verticesData[++i] = newVertex;
		nrVerticesCpy--;
	}

	fgets(line, 1000, modelFile);
	unsigned short ind1, ind2, ind3;
	int lineIndiceI;
	int res3 = sscanf(line, "NrIndices: %u", &nrIndicesCpy);
	Model::nrIndices = nrIndicesCpy;
	Model::indices = new unsigned short[Model::nrIndices];
	int j = -1;

	while (nrIndicesCpy / 3) {
		fgets(line, 1000, modelFile);
		int res4 = sscanf(line, "   %u.    %hu,    %hu,    %hu", &lineIndiceI, &ind1, &ind2, &ind3);
		Model::indices[++j] = ind1;
		Model::indices[++j] = ind2;
		Model::indices[++j] = ind3;
		nrIndicesCpy -= 3;
	}
}

void Model::Init() {
	Model::Load();

	glEnable(GL_DEPTH_TEST);
	glGenBuffers(1, &(Model::vboId));
	glBindBuffer(GL_ARRAY_BUFFER, Model::vboId);
	glBufferData(GL_ARRAY_BUFFER, Model::nrVertices * sizeof(Vertex), Model::verticesData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glGenBuffers(1, &(Model::iboId));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Model::iboId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, Model::nrIndices * sizeof(unsigned short), Model::indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Model::freeModel() {
	delete(Model::mr);
}