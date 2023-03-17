#include <stdafx.h>
#include "ResourceManager.h"
#include "Model.h"
#include "Texture.h"
#include "Shader.h"
#include <map>
#include <fstream>
#include "../Utilities/rapidxml-1.13/rapidxml.hpp"
#include <sstream>
#include "../Utilities/utilities.h"

using namespace rapidxml;


ResourceManager* ResourceManager:: spInstance = NULL;


ResourceManager* ResourceManager:: getInstance()
{
	if (!spInstance)
	{
		spInstance = new ResourceManager();
	}
	return spInstance;
}

void ResourceManager :: Init() {
	spInstance = new ResourceManager();
}

void ResourceManager::loadXML() {
    xml_document<> doc;
    std::ifstream file("Managers/resourceManager.xml");
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content(buffer.str());
    doc.parse<0>(&content[0]);
    ResourceManager::resourceManagerNode = doc.first_node();
}

Model* ResourceManager::loadModel(int modelId) {
    //models
    //daca modelul exista in map, returneaza pointer 
    std::map<int, Model>::iterator it;
    it = models.find(modelId);
    if (it != models.end()) {
        return *(it->second);
    }
    else {
        //altfel, incarca din xml
        xml_node<>* modelsNode = ResourceManager::resourceManagerNode->first_node("models");
        for (xml_node<>* folderNode = modelsNode->first_node("folder"); folderNode; folderNode = folderNode->next_sibling())
        {
            for (xml_node<>* modelNode = folderNode->first_node("model"); modelNode; modelNode = modelNode->next_sibling())
            {
                int mId = atoi(modelNode->first_attribute("id")->value());
                if (mId == modelId) {
                    ResourceManager::ModelResource model;
                    model.path = folderNode->first_attribute("path")->value();
                    model.file = modelNode->first_node("file")->value();
                    Model m = new Model(*model);
                    ResourceManager::models.insert(std::pair<int,Model>(mId, m));
                    return *m;
                }

            }
        }
    }
}

Texture* ResourceManager::loadTexture(int textureId) {
    std::map<int, Texture>::iterator it;
    it = textures.find(textureId);
    if (it != textures.end()) {
        return *(it->second);
    }
    else {
        xml_node<>* texturesNode = ResourceManager::resourceManagerNode->first_node("textures");
        for (xml_node<>* folderNode = texturesNode->first_node("folder"); folderNode; folderNode = folderNode->next_sibling())
        {
            for (xml_node<>* textureNode = folderNode->first_node("texture"); textureNode; textureNode = textureNode->next_sibling())
            {
                int tId = atoi(textureNode->first_attribute("id")->value());
                if (tId == textureId) {
                    ResourceManager::TextureResource tr;
                    tr.path = folderNode->first_attribute("path")->value();
                    if (textureNode->first_attribute("type")->value() == "2d") {
                        tr.type = GL_TEXTURE_2D;
                    }
                    tr.file = textureNode->first_node("file")->value();
                    if (textureNode->first_node("min_filter")->value() == "LINEAR") {
                        tr.min_filter = GL_LINEAR;
                    }
                    if (textureNode->first_node("mag_filter")->value() == "LINEAR") {
                        tr.mag_filter = GL_LINEAR;
                    }
                    if (textureNode->first_node("wrap_s")->value() == "CLAMP_TO_EDGE") {
                        tr.wrap_s = GL_CLAMP_TO_EDGE;
                    }
                    if (textureNode->first_node("wrap_t")->value() == "CLAMP_TO_EDGE") {
                        tr.wrap_t = GL_CLAMP_TO_EDGE;
                    }
                    Texture texture = new Texture(*tr);
                    ResourceManager::textures.insert(std::pair<int, Texture>(tId, texture));
                }
            }
        }
    }
}

Shader* ResourceManager::loadShader(int shaderId) {
    std::map<int, Texture>::iterator it;
    it = textures.find(textureId);
    if (it != textures.end()) {
        return *(it->second);
    }
    else {
        xml_node<>* shadersNode = ResourceManager::resourceManagerNode->first_node("shaders");
        for (xml_node<>* folderNode = shadersNode->first_node("folder"); folderNode; folderNode = folderNode->next_sibling())
        {
            for (xml_node<>* shaderNode = folderNode->first_node("shader"); shaderNode; shaderNode = shaderNode->next_sibling())
            {
                int sId = atoi(shaderNode->first_attribute("id")->value());
                if (sId == shaderId) {
                    ResourceManager::ShaderResource sr;
                    sr.path = folderNode->first_attribute("path")->value();
                    sr.vs = shaderNode->first_node("vs")->value();
                    sr.fs = shaderNode->first_node("fs")->value();
                    Shader shader = new Shader(*sr);
                    ResourceManager::shaders.insert(std::pair<int, Shader>(sId, shader));
                }
                
            }
        }
    }
}

void ResourceManager::parseResourceManagerXML() {
    xml_document<> doc;
    std::ifstream file("Managers/resourceManager.xml");
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string content(buffer.str());
    doc.parse<0>(&content[0]);
    xml_node<>* resourceManagerNode = doc.first_node();

    //models
    xml_node<>* modelsNode = resourceManagerNode->first_node("models");
    for(xml_node<>* folderNode = modelsNode->first_node("folder"); folderNode; folderNode = folderNode->next_sibling())
    {
        for(xml_node<>* modelNode = folderNode->first_node("model"); modelNode; modelNode = modelNode->next_sibling())
        {
            int modelId = atoi(modelNode->first_attribute("id")->value());
            ResourceManager::ModelResource model;
            model.path = folderNode->first_attribute("path")->value();
            model.file = modelNode->first_node("file")->value();
            ResourceManager::models.insert(std::pair<int, ResourceManager::ModelResource>(modelId, model));
        }
    }

    //shaders
    xml_node<>* shadersNode = resourceManagerNode->first_node("shaders");
    for(xml_node<>* folderNode = shadersNode->first_node("folder"); folderNode; folderNode = folderNode->next_sibling())
    {
        for (xml_node<>* shaderNode = folderNode->first_node("shader"); shaderNode; shaderNode = shaderNode->next_sibling())
        {
            int shaderId = atoi(shaderNode->first_attribute("id")->value());
            ResourceManager::ShaderResource shader;
            shader.path = folderNode->first_attribute("path")->value();
            shader.vs = shaderNode->first_node("vs")->value();
            shader.fs = shaderNode->first_node("fs")->value();
            ResourceManager::shaders.insert(std::pair<int, ResourceManager::ShaderResource>(shaderId, shader));
        }
    }

    //textures
    xml_node<>* texturesNode = resourceManagerNode->first_node("textures");
    for (xml_node<>* folderNode = texturesNode->first_node("folder"); folderNode; folderNode = folderNode->next_sibling())
    {
        for (xml_node<>* textureNode = folderNode->first_node("texture"); textureNode; textureNode = textureNode->next_sibling())
        {
            int textureId= atoi(textureNode->first_attribute("id")->value());
            ResourceManager::TextureResource texture;
            texture.path = folderNode->first_attribute("path")->value();
            if (textureNode->first_attribute("type")->value() == "2d") {
                texture.type = GL_TEXTURE_2D;
            }
            texture.file = textureNode->first_node("file")->value();
            if (textureNode->first_node("min_filter")->value() == "LINEAR") {
                texture.min_filter = GL_LINEAR;
            }
            if (textureNode->first_node("mag_filter")->value() == "LINEAR") {
                texture.mag_filter = GL_LINEAR;
            }
            if (textureNode->first_node("wrap_s")->value() == "CLAMP_TO_EDGE") {
                texture.wrap_s = GL_CLAMP_TO_EDGE;
            }
            if (textureNode->first_node("wrap_t")->value() == "CLAMP_TO_EDGE") {
                texture.wrap_t = GL_CLAMP_TO_EDGE;
            }
            ResourceManager::textures.insert(std::pair<int, ResourceManager::TextureResource>(textureId, texture));
        }
    }
}

void ResourceManager::freeResources() {
	delete spInstance;
}

ResourceManager::~ResourceManager()
{
}

