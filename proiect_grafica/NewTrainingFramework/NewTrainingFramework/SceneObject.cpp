#include "stdafx.h"
#include "SceneObject.h"
#include "stdafx.h"
#include "../Utilities/utilities.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "Model.h"
#include "Camera.h"
#include "Shader.h"

std::map<int, Texture*> SceneObject::textures;

SceneObject::SceneObject() {
	
}

void SceneObject::Load() {
	this->model = ResourceManager::getInstance() -> loadModel(SceneObject::modelId);
	this->shader = ResourceManager::getInstance() -> loadShader(SceneObject::shaderId);
	for (int i = 0; i < texturesIdLength; i++) {
		//textures[i] = new Texture(*(ResourceManager::getInstance() -> loadTexture(SceneObject::texturesId[i])));
		textures.insert(std::pair<int, Texture*>(texturesId[i], ResourceManager::getInstance()->loadTexture(texturesId[i])));
	}
}

void SceneObject::Init() {
	SceneObject::Load();
	/*for (int i = 0; i < sizeof(texturesId) / sizeof(int); i++) {
		(*textures[i]).Init();
	}*/
	/*std::map<int, Texture*>::iterator it = textures.begin();
	while (it != textures.end()) {
		it->second->Init();
		it++;
	}

	this->shader->Init();*/
}

void SceneObject::Update() {

}

void SceneObject::Draw() {
	// camera
	//int err = glGetError();
	// glClear(GL_COLOR_BUFFER_BIT);
	// glClear(GL_DEPTH_BUFFER_BIT);
	

	glUseProgram(shader->program);
	//err = glGetError();
	glBindBuffer(GL_ARRAY_BUFFER, model->vboId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model->iboId);
	//err = glGetError();
	// glActiveTexture(GL_TEXTURE0);
	/*for (int i = 0; i < sizeof(texturesId) / sizeof(int); i++) {
		glBindTexture(GL_TEXTURE_2D, (*textures[i]).tId);
	}*/

	std::map<int, Texture*>::iterator it;

	for (int i = 0; i < texturesIdLength; i++) {
		it = textures.find(texturesId[i]);
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, (it->second)->tId);
		if (shader->textureUniform != -1) {
			glUniform1i(shader->textureUniform, i);
		}
	}
	// err = glGetError();

	Camera* c = SceneManager::getInstance()->getActiveCamera();
	Matrix cameraView = c->getViewMatrix();
	Matrix cameraPerspective = c->getPerspectiveMatrix();
	Matrix Rx, Ry, Rz, T, S;
	Rx.SetRotationX(rotation.x);
	Ry.SetRotationY(rotation.y);
	Rz.SetRotationZ(rotation.z);
	S.SetScale(scale);
	T.SetTranslation(position);

	Matrix M = S * Rx * Ry * Rz * T;

	Matrix  MVP(M * cameraView * cameraPerspective);
	
	if (shader->positionAttribute != -1)
	{
		glEnableVertexAttribArray(shader->positionAttribute);
		glVertexAttribPointer(shader->positionAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	}

	if (shader->colorAttribute != -1)
	{
		glEnableVertexAttribArray(shader->colorAttribute);
		glVertexAttribPointer(shader->colorAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(Vector3)));
	}

	if (shader->normAttribute != -1)
	{
		glEnableVertexAttribArray(shader->normAttribute);
		glVertexAttribPointer(shader->normAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(2 * sizeof(Vector3)));
	}

	if (shader->binormAttribute != -1)
	{
		glEnableVertexAttribArray(shader->binormAttribute);
		glVertexAttribPointer(shader->binormAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(Vector3)));
	}

	if (shader->tgtAttribute != -1)
	{
		glEnableVertexAttribArray(shader->tgtAttribute);
		glVertexAttribPointer(shader->tgtAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(4 * sizeof(Vector3)));
	}

	if (shader->uvAttribute != -1)
	{
		glEnableVertexAttribArray(shader->uvAttribute);
		glVertexAttribPointer(shader->uvAttribute, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(5 * sizeof(Vector3)));
	}
	
	/*if (shader->viewUniform != -1)
	{
		glUniformMatrix4fv(shader->viewUniform, 1, GL_FALSE, (GLfloat*)cameraView.m);
	}
	
	if (shader->perspectiveUniform != -1)
	{
		glUniformMatrix4fv(shader->perspectiveUniform, 1, GL_FALSE, (GLfloat*)cameraPerspective.m);
	}*/
	if (shader->modelUniform != -1) {
		glUniformMatrix4fv(shader->modelUniform, 1, GL_FALSE, (GLfloat*)MVP.m);
	}
	/*if (shader->uvAttribute != -1) {
		glUniform1i(shader->textureUniform, 0);
	}*/
	
	// glDrawArrays(GL_LINES, 0, 12);
	glDrawElements(GL_TRIANGLES, model->nrIndices, GL_UNSIGNED_SHORT, 0);

	/*if (SceneObject::isWired == false) {
		glDrawElements(GL_TRIANGLES, model->nrIndices, GL_UNSIGNED_SHORT, 0);
	}
	else {
		glDrawElements(GL_LINES, model->nrIndices, GL_UNSIGNED_SHORT, 0);
	}*/
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	//eglSwapBuffers(esContext->eglDisplay, esContext->eglSurface);
}