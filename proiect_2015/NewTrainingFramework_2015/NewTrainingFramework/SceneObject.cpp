#include "stdafx.h"
#include "SceneObject.h"
#include "stdafx.h"
#include "../Utilities/utilities.h"
#include "ResourceManager.h"
#include "Model.h"
#include "Shader.h"

Model model;
Shader shader;
Texture* textures;

SceneObject::SceneObject() {
	
}

void SceneObject::Load() {
	model = &(ResourceManager::loadModel(SceneObject::modelId));
	shader = &(ResourceManager::loadShader(SceneObject::shaderId));
	for (int i = 0; i < sizeof(texturesId) / sizeof(int); i++) {
		textures[i] = &(ResourceManager::loadTexture(SceneObject::texturesId[i]))
	}
}

void SceneObject::Init() {
	SceneObject::Load();
	model.Init();
	for (int i = 0; i < sizeof(texturesId) / sizeof(int); i++) {
		textures[i].Init();
	}
	shader.Init();
}

void SceneObject::Draw() {

	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);

	glUseProgram(shader.program);

	glBindBuffer(GL_ARRAY_BUFFER,model.vboId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model.iboId);

	glActiveTexture(GL_TEXTURE0);
	for (int i = 0; i < sizeof(texturesId) / sizeof(int); i++) {
		glBindTexture(GL_TEXTURE_2D, textures[i].tId);
	}
	
	if (shader.positionAttribute != -1)
	{
		glEnableVertexAttribArray(shader.positionAttribute);
		glVertexAttribPointer(shader.positionAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	}

	if (shader.colorAttribute != -1)
	{
		glEnableVertexAttribArray(shader.colorAttribute);
		glVertexAttribPointer(shader.colorAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(Vector3)));
	}

	if (shader.normAttribute != -1)
	{
		glEnableVertexAttribArray(shader.normAttribute);
		glVertexAttribPointer(shader.normAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(2 * sizeof(Vector3)));
	}

	if (shader.binormAttribute != -1)
	{
		glEnableVertexAttribArray(shader.binormAttribute);
		glVertexAttribPointer(shader.binormAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(Vector3)));
	}

	if (shader.tgtAttribute != -1)
	{
		glEnableVertexAttribArray(shader.tgtAttribute);
		glVertexAttribPointer(shader.tgtAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(4 * sizeof(Vector3)));
	}

	if (shader.uvAttribute != -1)
	{
		glEnableVertexAttribArray(shader.uvAttribute);
		glVertexAttribPointer(shader.uvAttribute, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(5 * sizeof(Vector3)));
	}

	if (SceneObject::isWired == false) {
		glDrawElements(GL_TRIANGLES, model.nrIndices, GL_UNSIGNED_SHORT, 0);
	}
	else {
		glDrawElements(GL_LINES, model.nrIndices, GL_UNSIGNED_SHORT, 0);
	}
}