#pragma once
#include "Camera.h"
#include "Control.h"
#include "SceneObject.h"
#include <string>
#include <map>
class SceneManager {
private:
	static SceneManager* spInstance;
	SceneManager();
public:
	static SceneManager* getInstance();
	char* XMLpath;
	int Init();
	void Draw();
	void Update();
	void freeResources();

	std::string gameName;
	struct defaultScreenSize {
		int width;
		int height;
		bool isFullscreen;
	};
	defaultScreenSize dss;
	struct backgroundColor {
		float r;
		float g;
		float b;
	};
	backgroundColor bc;

	std::map<int, Camera> cameras;
	Control* controls[100];
	int activeCamera;
	std::map<int, SceneObject*> objects;
	//std::map<int, Light> lights;
	void parseSceneManagerXML();

	~SceneManager();
};