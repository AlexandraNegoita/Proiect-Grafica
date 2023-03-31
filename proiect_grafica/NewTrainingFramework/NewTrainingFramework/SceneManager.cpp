#include <stdafx.h>
#include "../Utilities/rapidxml-1.13/rapidxml.hpp"
#include <string>
#include "SceneManager.h"
#include "ResourceManager.h"
#include "Model.h"
#include "Texture.h"
#include "Shader.h"
#include <map>
#include <fstream>
#include <sstream>
#include "../Utilities/utilities.h"
#include "SceneObject.h"
#include "TerrainObject.h"


using namespace rapidxml;

SceneManager::SceneManager() {}

SceneManager* SceneManager::spInstance = NULL;
SceneManager* SceneManager::getInstance()
{
	if (!spInstance)
	{
		spInstance = new SceneManager();
	}
	return spInstance;
}



int SceneManager::Init() {
	spInstance = new SceneManager();
    SceneManager::parseSceneManagerXML();
    std::map<int, SceneObject*>::iterator objectsIt = objects.begin();
    // Iterate over the map using Iterator till end.
    while (objectsIt != objects.end())
    {
        (*(objectsIt->second)).Init();
        objectsIt++;
    }
    return 0;
}
void SceneManager::Draw() {
    std::map<int, SceneObject*>::iterator objectsIt = objects.begin();
    // Iterate over the map using Iterator till end.
    while (objectsIt != objects.end())
    {
        (*(objectsIt->second)).Draw();
        objectsIt++;
    }

}
void SceneManager::Update() {
    //SceneManager::parseSceneManagerXML();
    std::map<int, SceneObject*>::iterator objectsIt = objects.begin();
    // Iterate over the map using Iterator till end.
    while (objectsIt != objects.end())
    {
        (*(objectsIt->second)).Load();
        objectsIt++;
    }

}

void SceneManager::freeResources() {
	delete spInstance;
}

void SceneManager::parseSceneManagerXML() {
    xml_document<> doc;
    std::ifstream file("../Managers/sceneManager.xml");
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content(buffer.str());
    doc.parse<0>(&content[0]);
    xml_node<>* sceneManagerNode = doc.first_node();

    //gameName
    char aux[100];
    
    strcpy(aux, sceneManagerNode->first_node("gameName")->value());
    gameName = std::string(sceneManagerNode->first_node("gameName")->value());


    //defaultScreenSize
    xml_node<>* defaultScreenSizeNode = sceneManagerNode->first_node("defaultScreenSize");
    dss.width = atoi(defaultScreenSizeNode->first_node("width")->value());
    dss.height = atoi(defaultScreenSizeNode->first_node("height")->value());

    if (defaultScreenSizeNode->first_node("fullscreen")) {
        dss.isFullscreen = true;
    }
    else {
        dss.isFullscreen = false;
    }

    //backgroundColor
    xml_node<>* backgroundColorNode = sceneManagerNode->first_node("backgroundColor");
    bc.r = atof(backgroundColorNode->first_node("r")->value());
    bc.g = atof(backgroundColorNode->first_node("g")->value());
    bc.b = atof(backgroundColorNode->first_node("b")->value());

    //controls
    xml_node<>* controlsNode = sceneManagerNode->first_node("controls");
    int i = 0;
    for (xml_node<>* controlNode = controlsNode->first_node("control"); controlNode; controlNode = controlNode->next_sibling())
    {
        //Control c(controlNode->first_node("key")->value(), controlNode->first_node("action")->value());
       // c.key = ;
       // c.action = controlNode->first_node("action")->value();
        controls[i] = new Control(controlNode->first_node("key")->value(), controlNode->first_node("action")->value());
    }

    //cameras
    xml_node<>* camerasNode = sceneManagerNode->first_node("cameras");
    for (xml_node<>* cameraNode = camerasNode->first_node("camera"); cameraNode; cameraNode = cameraNode->next_sibling())
    {
        int cameraId = atoi(cameraNode->first_attribute("id")->value());
        Camera c;
        c.setType(cameraNode->first_node("type")->value());
        c.setPosition(Vector3(atof(cameraNode->first_node("position")->first_node("x")->value()), atof(cameraNode->first_node("position")->first_node("y")->value()), atof(cameraNode->first_node("position")->first_node("z")->value())));
       /* c.position.x = cameraNode->first_node("position")->first_node("x")->value();
        c.position.y = cameraNode->first_node("position")->first_node("y")->value();
        c.position.z = cameraNode->first_node("position")->first_node("z")->value();*/

        c.setPosition(Vector3(atof(cameraNode->first_node("target")->first_node("x")->value()), atof(cameraNode->first_node("target")->first_node("y")->value()), atof(cameraNode->first_node("target")->first_node("z")->value())));
       /* c.target.x = cameraNode->first_node("target")->first_node("x")->value();
        c.target.y = cameraNode->first_node("target")->first_node("y")->value();
        c.target.z = cameraNode->first_node("target")->first_node("z")->value();*/

        c.setPosition(Vector3(atof(cameraNode->first_node("up")->first_node("x")->value()), atof(cameraNode->first_node("up")->first_node("y")->value()), atof(cameraNode->first_node("up")->first_node("z")->value())));
        /*c.up.x = cameraNode->first_node("up")->first_node("x")->value();
        c.up.y = cameraNode->first_node("up")->first_node("y")->value();
        c.up.z = cameraNode->first_node("up")->first_node("z")->value();*/

        c.setTranslationSpeed(atof(cameraNode->first_node("translationSpeed")->value()));
        c.setRotationSpeed(atof(cameraNode->first_node("rotationSpeed")->value()));
        c.setFov(atof(cameraNode->first_node("fov")->value()));
        c.setNear(atof(cameraNode->first_node("near")->value()));
        c.setFar(atof(cameraNode->first_node("far")->value()));
    }

    //objects
    xml_node<>* objectsNode = sceneManagerNode->first_node("objects");
    for (xml_node<>* objectNode = objectsNode->first_node("object"); objectNode; objectNode = objectNode->next_sibling())
    {
        int objectId = atoi(objectNode->first_attribute("id")->value());
        char* type = objectNode->first_node("type")->value();
        SceneObject* o = new SceneObject();
        /*if (type == "normal") {
            SceneObject o;
        }
        else if (type == "terrain") {
            TerrainObject o;
        }*/

        (*o).modelId = atoi(objectNode->first_node("model")->value());
        (*o).shaderId = atoi(objectNode->first_node("shader")->value());

        (*o).name = objectNode->first_node("name")->value();

        if (objectNode->first_node("wired")) {
            (*o).isWired = true;
        }
        else {
            (*o).isWired = false;
        }

        if (xml_node<>* textureNode = objectNode->first_node("textures")) {
            int i = 0;
            int texturesIdLength = 0;
            xml_node<>* textureNodeTest = objectNode->first_node("textures");
            for (xml_node<>* textureNode = textureNodeTest->first_node("texture"); textureNode; textureNode = textureNode->next_sibling()) {
                texturesIdLength++;
            }
            (*o).texturesId = (int*)malloc(texturesIdLength);

            for (xml_node<>* textureNode = objectNode->first_node("textures")->first_node("texture"); textureNode; textureNode = textureNode->next_sibling()) {
                (*o).texturesId[i] = atoi(textureNode->first_attribute("id")->value());
            }
        }
        (*o).position.x = atof(objectNode->first_node("position")->first_node("x")->value());
        (*o).position.y = atof(objectNode->first_node("position")->first_node("y")->value());
        (*o).position.z = atof(objectNode->first_node("position")->first_node("z")->value());

        (*o).rotation.x = atof(objectNode->first_node("rotation")->first_node("x")->value());
        (*o).rotation.y = atof(objectNode->first_node("rotation")->first_node("y")->value());
        (*o).rotation.z = atof(objectNode->first_node("rotation")->first_node("z")->value());

        (*o).scale.x = atof(objectNode->first_node("scale")->first_node("x")->value());
        (*o).scale.y = atof(objectNode->first_node("scale")->first_node("y")->value());
        (*o).scale.z = atof(objectNode->first_node("scale")->first_node("z")->value());

        if (objectNode->first_node("color")) {
            (*o).color.x = atof(objectNode->first_node("color")->first_node("r")->value());
            (*o).color.y = atof(objectNode->first_node("color")->first_node("g")->value());
            (*o).color.z = atof(objectNode->first_node("color")->first_node("b")->value());
        }
        SceneManager::objects.insert(std::pair<int, SceneObject*>(objectId, o));
    }
}

SceneManager::~SceneManager()
{
}
