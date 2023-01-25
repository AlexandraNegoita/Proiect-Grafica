#pragma once
#include "Camera.h"
#include "Control.h"
#include "SceneObject.h"
#include <map>
class SceneManager {
private:
	static SceneManager* spInstance;
	SceneManager();
public:
	static SceneManager* getInstance();
	char* XMLpath;
	void Init();
	void Draw();
	void Update();
	void freeResources();

	struct defaultScreenSize {
		int width;
		int height;
		bool isFullscreen;
	};

	struct backgroundColor {
		float r;
		float g;
		float b;
	};

	std::map<int, Camera> cameras;
	Control* controls;
	int activeCamera;
	std::map<int, SceneObject> objects;
	//std::map<int, Light> lights;
	void parseSceneManagerXML(char* path);

	~SceneManager();
};