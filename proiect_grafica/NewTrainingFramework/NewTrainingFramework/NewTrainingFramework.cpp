// NewTrainingFramework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vertex.h"
#include <conio.h>
#include "Globals.h"
#include "Camera.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <ctype.h>
#include "../Utilities/utilities.h" // if you use STL, please include this line AFTER all other include




//GLuint vboIdVertices;
//GLuint vboIdIndices;
//GLuint vboIdTextures;
//
//Shaders myShaders;
//GLfloat angle = 0.01;
//GLfloat currentTime = 0;
//GLfloat maxTime = 0.05;
//
//Vector3 position = Vector3(0.0f, 0.0f, 900.0f);
//Vector3 target = Vector3(0.0f, 0.0f, -1.0f);
//Vector3 up = Vector3(0.0f, 1.0f, 0.0f);
//Camera camera = Camera(position, target, up);
//
//Vertex *verticesData;
//unsigned short* indices;
//int nrVertices = 0;
//int nrIndices = 0;
//
//int textureWidth;
//int textureHeight;
//int textureBpp;
//
//bool wired_format;

//void readFile(char* filename) {
//	FILE* modelFile;
//
//	modelFile = fopen(filename, "r");
//	char* line = (char*)malloc(sizeof(char) * 1000);
//	fgets(line, 1000, modelFile);
//	int nrVerticesCpy;
//	int nrIndicesCpy;
//
//	int lineIndice;
//	int res = sscanf(line, "NrVertices: %u", &nrVerticesCpy);
//	nrVertices = nrVerticesCpy;
//	verticesData = new Vertex[nrVertices];
//	int i = -1;
//	float posx, posy, posz, normx, normy, normz, binormx, binormy, binormz, tgtx, tgty, tgtz, uvx, uvy;
//
//	while (nrVerticesCpy) {
//		fgets(line, 1000, modelFile);
//		Vertex newVertex;
//		//std::cout << line;
//		int res2 = sscanf(line, "   %u. pos:[%f, %f, %f]; norm:[%f, %f, %f]; binorm:[%f, %f, %f]; tgt:[%f, %f, %f]; uv:[%f, %f];", &lineIndice, &newVertex.pos.x, &newVertex.pos.y, &newVertex.pos.z, &newVertex.norm.x, &newVertex.norm.y, &newVertex.norm.z, &newVertex.binorm.x, &newVertex.binorm.y, &newVertex.binorm.z, &newVertex.tgt.x, &newVertex.tgt.y, &newVertex.tgt.z, &newVertex.uv.x, &newVertex.uv.y);
//
//		newVertex.color.x = 0.5f;
//		newVertex.color.y = 0.5f;
//		newVertex.color.z = 0.5f;
//
//		verticesData[++i] = newVertex;
//		
//		nrVerticesCpy--;
//	}
//	//std::cout << i << std::endl;
//
//	fgets(line, 1000, modelFile);
//	int nrindicesCpy;
//
//	unsigned short ind1, ind2, ind3;
//	int lineIndiceI;
//	int res3 = sscanf(line, "NrIndices: %u", &nrIndicesCpy);
//	nrIndices = nrIndicesCpy;
//	indices = new unsigned short[nrIndices];
//	int j = -1;
//
//	while (nrIndicesCpy/3) {
//		fgets(line, 1000, modelFile);
//		int res4 = sscanf(line, "   %u.    %hu,    %hu,    %hu", &lineIndiceI, &ind1, &ind2, &ind3);
//		indices[++j] = ind1;
//		indices[++j] = ind2;
//		indices[++j] = ind3;
//		nrIndicesCpy-=3;
//	}
//	//std::cout << j << std::endl;
//}

//ResourceManager* resourceManager;
//SceneManager* sceneManager;

int i = 0;
int screenWidth;
int screenHeight;

int Init ( ESContext *esContext )
{
	//glClearColor ( 1.0f, 0.0f, 0.0f, 1.0f );
	// i++;
	//readFile("../../NewResourcesPacket/Models/Croco.nfg");
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_DEPTH_TEST);
	////glDepthFunc(GL_GREATER);
	////buffer object
	//glGenBuffers(1, &vboIdVertices); //genereaza un id de buffer 
	//glBindBuffer(GL_ARRAY_BUFFER, vboIdVertices); //punem tipul de buffer
	//glBufferData(GL_ARRAY_BUFFER, nrVertices* sizeof(Vertex), verticesData, GL_STATIC_DRAW); //verticesData e static; va avea 3*sizeof vertex
	//glBindBuffer(GL_ARRAY_BUFFER, 0); //se inchide buffer-ul
	////p GL_ELEMENT_ARRAY_BUFFER
	//glGenBuffers(1, &vboIdIndices);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIdIndices);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, nrIndices * sizeof(unsigned short), indices, GL_STATIC_DRAW); 
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	////glGenTextures(1, &id_textura);
	//glGenTextures(1, &vboIdTextures);
	//glBindTexture(GL_TEXTURE_2D, vboIdTextures);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	//char* loadTextureTGA = LoadTGA("../../NewResourcesPacket/Textures/Croco.tga", &textureWidth, &textureHeight, &textureBpp);
	//if (textureBpp == 24){
	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, (GLsizei)textureWidth, (GLsizei)textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, loadTextureTGA);
	//}
	//else {
	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)textureWidth, (GLsizei)textureHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, loadTextureTGA);
	//}
	//glBindTexture(GL_TEXTURE_2D, 0);
	////glGenBuffers(1, &vboId); //genereaza un id de buffer 
	////glBindBuffer(GL_ARRAY_BUFFER, vboId); //punem tipul de buffer
	////glBufferData(GL_ARRAY_BUFFER, sizeof(lineVertices), lineVertices, GL_STATIC_DRAW); //verticesData e static; va avea 3*sizeof vertex
	////glBindBuffer(GL_ARRAY_BUFFER, 0); //se inchide buffer-ul
	////creation of shaders and program 
	//return myShaders.Init("../Resources/Shaders/TriangleShaderVS.vs", "../Resources/Shaders/TriangleShaderFS.fs");
	
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	/*GLuint a = 7;
	glGenBuffers(1, &a);
	glGenBuffers(1, &a);*/

	ResourceManager::getInstance() -> Init();
	SceneManager::getInstance()->Init();
	return 0;
}

void Draw ( ESContext *esContext )
{ //strict desen; la fiecare frame
	//glClear(GL_COLOR_BUFFER_BIT);
	//glClear( GL_DEPTH_BUFFER_BIT);
	// 
	//glUseProgram(myShaders.program);
	// 
	//glBindBuffer(GL_ARRAY_BUFFER, vboIdVertices);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIdIndices);
	//glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, vboIdTextures);
	//if(myShaders.positionAttribute != -1)
	//{	
	//	glEnableVertexAttribArray(myShaders.positionAttribute);
	//	glVertexAttribPointer(myShaders.positionAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0); //sizeof - din cat in cat sa sara in mem sa gaseasca urm informatie
	//}
	//if (myShaders.colorAttribute != -1)
	//{
	//	glEnableVertexAttribArray(myShaders.colorAttribute);
	//	glVertexAttribPointer(myShaders.colorAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(sizeof(Vector3)));
	//}
	//if (myShaders.normAttribute != -1)
	//{
	//	glEnableVertexAttribArray(myShaders.normAttribute);
	//	glVertexAttribPointer(myShaders.normAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(2*sizeof(Vector3))); 
	//}
	//if (myShaders.binormAttribute != -1)
	//{
	//	glEnableVertexAttribArray(myShaders.binormAttribute);
	//	glVertexAttribPointer(myShaders.binormAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3*sizeof(Vector3)));
	//}
	//if (myShaders.tgtAttribute != -1)
	//{
	//	glEnableVertexAttribArray(myShaders.tgtAttribute);
	//	glVertexAttribPointer(myShaders.tgtAttribute, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(4*sizeof(Vector3)));
	//}
	//if (myShaders.uvAttribute != -1)
	//{
	//	glEnableVertexAttribArray(myShaders.uvAttribute);
	//	glVertexAttribPointer(myShaders.uvAttribute, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(5 * sizeof(Vector3)));
	//}
	//Matrix cameraView = camera.getViewMatrix();
	//if (myShaders.viewUniform != -1)
	//{
	//	glUniformMatrix4fv(myShaders.viewUniform, 1, GL_FALSE, (GLfloat*)cameraView.m);
	//}
	//Matrix cameraPerspective = camera.getPerspectiveMatrix();
	//if (myShaders.perspectiveUniform != -1)
	//{
	//	glUniformMatrix4fv(myShaders.perspectiveUniform, 1, GL_FALSE, (GLfloat*)cameraPerspective.m);
	//}
	//if (myShaders.uvAttribute != -1) {
	//	glUniform1i(myShaders.textureUniform, 0);
	//}
	////se inmulteste cu viewMatrix
	//// Matrix m;
	//// angle += 0.01;
	//// m.SetRotationZ(angle);
	//
	//// if (myShaders.matrixUniform != -1)
	//// {
	//// 	glUniformMatrix4fv(myShaders.matrixUniform, 1, GL_FALSE, (GLfloat*)m.m);
	//// }
	////color -offset - sizeof(vector3)
	////glDrawArrays(GL_LINES, 0, 12);
	////glDrawElements(GL_TRIANGLES, nr_indici, GL_UNSIGNED_SHORT, 0);
	//if (wired_format == false) {
	//	glDrawElements(GL_TRIANGLES, nrIndices, GL_UNSIGNED_SHORT, 0);
	//}
	//else {
	//	glDrawElements(GL_LINES, nrIndices, GL_UNSIGNED_SHORT, 0);
	//}
	//
	//glBindBuffer(GL_ARRAY_BUFFER, 0);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	//
	//eglSwapBuffers ( esContext->eglDisplay, esContext->eglSurface ); //schimba buffers; pt urmatoarea scena care urm a fi vizualiata; pt optimizare
	//
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SceneManager::getInstance() -> Draw();
	eglSwapBuffers(esContext->eglDisplay, esContext->eglSurface);
}

void Update ( ESContext *esContext, float deltaTime )
{
	//partea de calculare; apelat la fiecare frame
	Camera* c = SceneManager::getInstance() -> getActiveCamera();
	if (c->currentTime > c->maxTime) {
		c->setDeltaTime(deltaTime);
		c->currentTime -= deltaTime;
	}
	SceneManager::getInstance() -> Update();
}

void Key ( ESContext *esContext, unsigned char key, bool bIsPressed)
{
	//cand apasam o tasta//ispressed - 0 cand luam degetul de pe tasta, 1 cand e apasat in continuu
	Camera* c = SceneManager::getInstance()->getActiveCamera();

	switch (key) {
		case 'W': case 'w': {
			c->moveOz(-1);
			c->updateWorldView();
			break;
		}
		case 'S': case 's': {
			c->moveOz(1);
			c->updateWorldView(); 
			break;
		}
		case 'A': case 'a': {
			c->moveOx(-1);
			c->updateWorldView();
			break;
		}
		case 'D': case 'd': {
			c->moveOx(1);
			c->updateWorldView();
			break;
		}
		case 'Z': case 'z': {
			c->moveOy(1);
			c->updateWorldView();
			break;
		}
		case 'X': case 'x': {
			c->moveOy(-1);
			c->updateWorldView();
			break;
		}
		case char(37): {
			c->rotateOy(1);
			c->updateWorldView();
			break;
		}
		case char(39) : {
			c->rotateOy(-1);
			c->updateWorldView();
			break;
		}
		case char(38) : {
			c->rotateOx(1);
			c->updateWorldView();
			break;
		}
		case char(40) : {
			c->rotateOx(-1);
			c->updateWorldView();
			break;
		}
		case 'k': case 'K': {
			c->rotateOz(1);
			c->updateWorldView();
			break;
		}
		case 'l': case 'L': {
			c->rotateOz(-1);
			c->updateWorldView();
			break;
		}
		/*case 'p': case 'P': {
			if (bIsPressed) {
				wired_format = true;
			}
			else {
				wired_format = false;
			}
			break;
		}*/
		//left 37
		//up 38
		//right 39
		//down 40
	}
}


void Mouse(ESContext* esContext, int LeftRightClick, bool isDoubleClick, bool isPressed, float coordX, float coordY)//left/right button, click/dublu-click, isPressed, coordX, coordY
{
	Camera* c = SceneManager::getInstance()->getActiveCamera();

	char* type;
	if (LeftRightClick) {
		type = "right";
	} else {
		type = "left";
	}
	GLint screenWidth = Globals::screenWidth;
	GLint screenHeight = Globals::screenHeight;
	if (coordX > 0 && coordX < screenWidth * 0.25f) {
		c->rotateOy(1);
		c->updateWorldView();
	} else if (coordX > screenWidth * 0.75f && coordX < screenWidth) {
		c->rotateOy(-1);
		c->updateWorldView();
	}
	if (coordY > 0 && coordY < screenHeight * 0.25f) {
		c->rotateOx(1);
		c->updateWorldView();
	} else if (coordY > screenHeight * 0.75f && coordY < screenHeight) {
		c->rotateOx(-1);
		c->updateWorldView();
	}
	/* std::cout << "Type: " << type << "\tIs Double-click: " << isDoubleClick << "\tIs pressed: " << isPressed << "\nCoords: X:" << coordX << "\tY:" << coordY << "\n"; */
}

void CleanUp()
{
	//glDeleteBuffers(1, &vboIdVertices);
	//glDeleteBuffers(1, &vboIdIndices);
}

int _tmain(int argc, _TCHAR* argv[])
{
	//identifying memory leaks
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF ); 

	ESContext esContext; //fereastra 

    esInitContext ( &esContext );

	
	// esCreateWindow(&esContext, (SceneManager::getInstance()->gameName).c_str(), SceneManager::getInstance()->dss.width, SceneManager::getInstance()->dss.height, ES_WINDOW_RGB | ES_WINDOW_DEPTH);
	esCreateWindow(&esContext, "Hello Croco", Globals::screenWidth, Globals::screenHeight, ES_WINDOW_RGB | ES_WINDOW_DEPTH);


	if (Init(&esContext) != 0)
		return 0;


	esRegisterDrawFunc ( &esContext, Draw );
	esRegisterUpdateFunc ( &esContext, Update );
	esRegisterKeyFunc ( &esContext, Key);
	esRegisterMouseFunc(&esContext, Mouse);

	esMainLoop ( &esContext );

	//releasing OpenGL resources
	CleanUp();


	printf("Press any key...\n");
	_getch();

	
	return 0;
}

