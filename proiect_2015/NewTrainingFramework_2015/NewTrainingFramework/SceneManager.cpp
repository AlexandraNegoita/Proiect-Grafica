#include <stdafx.h>
#include "SceneManager.h"
#include "ResourceManager.h"
#include "Model.h"
#include "Texture.h"
#include "Shader.h"
#include <map>
#include <fstream>
#include "../Utilities/rapidxml-1.13/rapidxml.hpp"
#include <sstream>
#include "../Utilities/utilities.h"
#include "SceneObject.h"
#include "TerrainObject.h"

using namespace rapidxml;


SceneManager* SceneManager::spInstance = NULL;
SceneManager* SceneManager::getInstance()
{
	if (!spInstance)
	{
		spInstance = new SceneManager();
	}
	return spInstance;
}



void SceneManager::Init() {
	spInstance = new SceneManager();
    SceneManager::parseSceneManagerXML(SceneManager::XMLpath);
    std::map<std::string, int>::iterator objectsIt = objects.begin();
    // Iterate over the map using Iterator till end.
    while (objectsIt != objects.end())
    {
        //// Accessing KEY from element pointed by it.
        //std::string word = it->first;
        //// Accessing VALUE from element pointed by it.
        //int count = it->second;
        //std::cout << word << " :: " << count << std::endl;
        //// Increment the Iterator to point to next entry
        (objectsIt->second).Init();
        objectsIt++;
    }
}
void SceneManager::Draw() {
	

}
void SceneManager::Update() {
	

}

void SceneManager::freeResources() {
	delete spInstance;
}

void SceneManager::parseSceneManagerXML(char* path) {
    xml_document<> doc;
    std::ifstream file(path);
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content(buffer.str());
    doc.parse<0>(&content[0]);
    xml_node<>* sceneManagerNode = doc.first_node();

    //defaultScreenSize
    xml_node<>* defaultScreenSizeNode = sceneManagerNode->first_node("defaultScreenSize");
    SceneManager::defaultScreenSize dss;
    dss.width = atoi(defaultScreenSizeNode->first_node("width")->value());
    dss.height = atoi(defaultScreenSizeNode->first_node("height")->value());
    if (defaultScreenSizeNode->first_node("height")) {
        dss.isFullscreen = true;
    }
    else {
        dss.isFullscreen = false;
    }

    //backgroundColor
    xml_node<>* backgroundColorNode = sceneManagerNode->first_node("backgroundColor");
    SceneManager::backgroundColor bc;
    bc.r = atof(backgroundColorNode->first_node("r")->value());
    bc.g = atof(backgroundColorNode->first_node("g")->value());
    bc.b = atof(backgroundColorNode->first_node("b")->value());

    //controls
    xml_node<>* controlsNode = sceneManagerNode->first_node("controls");
    int i = 0;
    for (xml_node<>* controlNode = controlsNode->first_node("control"); controlNode; controlNode = controlNode->next_sibling())
    {
        Control c;
        c.key = controlNode->first_node("key")->value();
        c.action = controlNode->first_node("action")->value();
        SceneManager::controls[i] = c;
    }

    //cameras
    xml_node<>* camerasNode = sceneManagerNode->first_node("cameras");
    for (xml_node<>* cameraNode = camerasNode->first_node("camera"); cameraNode; cameraNode = cameraNode->next_sibling())
    {
        int cameraId = atoi(cameraNode->first_attribute("id")->value());
        Camera c;
        c.type = cameraNode->first_node("type")->value();
        c.position.x = cameraNode->first_node("position")->first_node("x")->value();
        c.position.y = cameraNode->first_node("position")->first_node("y")->value();
        c.position.z = cameraNode->first_node("position")->first_node("z")->value();

        c.target.x = cameraNode->first_node("target")->first_node("x")->value();
        c.target.y = cameraNode->first_node("target")->first_node("y")->value();
        c.target.z = cameraNode->first_node("target")->first_node("z")->value();

        c.up.x = cameraNode->first_node("up")->first_node("x")->value();
        c.up.y = cameraNode->first_node("up")->first_node("y")->value();
        c.up.z = cameraNode->first_node("up")->first_node("z")->value();

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
        SceneObject o;
        if (type == "normal") {
            o = new SceneObject();
        }
        else if (type == "terrain") {
            o = new TerrainObject();
        }
        
        o.model = atoi(objectNode->first_node("model")->value());
        o.shader = atoi(objectNode->first_node("shader")->value());
        
        o.name = objectNode->first_node("name")->value();
        
        if (objectNode->first_node("wired")) {
            o.isWired = true;
        }
        else {
            o.isWired = false;
        }

        int i = 0;
        
        for (xml_node<>* textureNode = objectNode->first_node("textures")->first_node("texture"); textureNode; textureNode = textureNode->next_sibling())
        {
            o.texturesId[i] = atoi(textureNode->first_attribute("id")->value());
        }
        o.position.x = objectNode->first_node("position")->first_node("x")->value();
        o.position.y = objectNode->first_node("position")->first_node("y")->value();
        o.position.z = objectNode->first_node("position")->first_node("z")->value();

        o.rotation.x = objectNode->first_node("rotation")->first_node("x")->value();
        o.rotation.y = objectNode->first_node("rotation")->first_node("y")->value();
        o.rotation.z = objectNode->first_node("rotation")->first_node("z")->value();

        o.scale.x = objectNode->first_node("scale")->first_node("x")->value();
        o.scale.y = objectNode->first_node("scale")->first_node("y")->value();
        o.scale.z = objectNode->first_node("scale")->first_node("z")->value();

        if (objectNode->first_node("color")) {
            o.color.x = objectNode->first_node("color")->first_node("x")->value();
            o.color.y = objectNode->first_node("color")->first_node("y")->value();
            o.color.z = objectNode->first_node("color")->first_node("z")->value();
        }
        SceneManager::objects.insert(std::pair<int, SceneObject>(objectId, o));
    }
}

//void SceneManager::metodaInstanta() {
//	//nitel cod
//}