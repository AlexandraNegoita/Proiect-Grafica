#include "stdafx.h"
#include "../Utilities/rapidxml-1.13/rapidxml.hpp"
#include "ResourceManager.h"
#include "Model.h"
#include "Resources.h"
#include "Texture.h"
#include "Shader.h"
#include <map>
#include <fstream>
#include <sstream>
#include "../Utilities/utilities.h"
#include <iostream>

using namespace rapidxml;


ResourceManager* ResourceManager:: spInstance = NULL;

ResourceManager::ResourceManager() {}

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
    ResourceManager::parseResourceManagerXML();
}

//void ResourceManager::parseResourceManagerXML() {
//    xml_document<> doc;
//    std::ifstream file("Managers/resourceManager.xml");
//    std::stringstream buffer;
//    buffer << file.rdbuf();
//    file.close();
//    std::string content(buffer.str());
//    doc.parse<0>(&content[0]);
//    ResourceManager::resourceManagerNode = doc.first_node();
//}
std::map<int, Model*> Model::loadedModels;
std::map<int, Texture*> Texture::loadedTextures;
std::map<int, Shader*> Shader::loadedShaders;

Model* ResourceManager::loadModel(int modelId) {
    //models
    //daca modelul exista in map, returneaza pointer 
    std::map<int, ModelResource*>::iterator it;
    it = models.find(modelId);
    if (it != models.end()) {
        if (it->second->isLoaded == true) {
            // daca exista si in models si in loaded 
            // returneaza modelul loaded
            std::map<int, Model*>::iterator itM;
            itM = Model::loadedModels.find(modelId);
            if (itM != Model::loadedModels.end()) {
                return itM->second;
            }
        }
        else {
            // daca exista in models dar nu e loaded 
            // returneaza un Model care trebuie loaded
            Model m =  Model(it->second);
            return &m; //nu e loaded
        }
    }
    else {
        // daca nu exista in models - > eroare ?
       // return new Model(it->second);
        std::cout << "eroare";
    }
    //else {
    //    //altfel, verifica daca exista in Model Resource si il incarca
    //    xml_node<>* modelsNode = ResourceManager::resourceManagerNode->first_node("models");
    //    for (xml_node<>* folderNode = modelsNode->first_node("folder"); folderNode; folderNode = folderNode->next_sibling())
    //    {
    //        for (xml_node<>* modelNode = folderNode->first_node("model"); modelNode; modelNode = modelNode->next_sibling())
    //        {
    //            int mId = atoi(modelNode->first_attribute("id")->value());
    //            if (mId == modelId) {
    //                ModelResource* model;
    //                (*model).file_path = strcat(folderNode->first_attribute("path")->value(), modelNode->first_node("file")->value());
    //                ResourceManager::models.insert(std::pair<int,ModelResource*>(mId, model));
    //                return model;
    //            }

    //        }
    //    }
    //}
}

Texture* ResourceManager::loadTexture(int textureId) {
    std::map<int, TextureResource*>::iterator it;
    it = textures.find(textureId);
    if (it != textures.end() && it->second->isLoaded == true) {
        std::map<int, Texture*>::iterator itT;
        itT = Texture::loadedTextures.find(textureId);
        if (itT != Texture::loadedTextures.end()) {
            return itT->second;
        }
    }
    else {
        return new Texture(it->second);
    }
    //std::map<int, TextureResource*>::iterator it;
    //it = textures.find(textureId);
    //if (it != textures.end()) {
    //    return it->second;
    //}
    //else {
    //    xml_node<>* texturesNode = ResourceManager::resourceManagerNode->first_node("textures");
    //    for (xml_node<>* folderNode = texturesNode->first_node("folder"); folderNode; folderNode = folderNode->next_sibling())
    //    {
    //        for (xml_node<>* textureNode = folderNode->first_node("texture"); textureNode; textureNode = textureNode->next_sibling())
    //        {
    //            int tId = atoi(textureNode->first_attribute("id")->value());
    //            if (tId == textureId) {
    //                TextureResource *texture;
    //                (*texture).file_path = strcat(folderNode->first_attribute("path")->value(), textureNode->first_node("file")->value());
    //                if (textureNode->first_attribute("type")->value() == "2d") {
    //                    (*texture).type = GL_TEXTURE_2D;
    //                }
    //                //(*texture).file = textureNode->first_node("file")->value();
    //                if (textureNode->first_node("min_filter")->value() == "LINEAR") {
    //                    (*texture).min_filter = GL_LINEAR;
    //                }
    //                if (textureNode->first_node("mag_filter")->value() == "LINEAR") {
    //                    (*texture).mag_filter = GL_LINEAR;
    //                }
    //                if (textureNode->first_node("wrap_s")->value() == "CLAMP_TO_EDGE") {
    //                    (*texture).wrap_s = GL_CLAMP_TO_EDGE;
    //                }
    //                if (textureNode->first_node("wrap_t")->value() == "CLAMP_TO_EDGE") {
    //                    (*texture).wrap_t = GL_CLAMP_TO_EDGE;
    //                }
    //                ResourceManager::textures.insert(std::pair<int, TextureResource*>(tId, texture));
    //                return texture;
    //            }
    //        }
    //    }
    //}
}

Shader* ResourceManager::loadShader(int shaderId) {
    std::map<int, ShaderResource*>::iterator it;
    it = shaders.find(shaderId);
    if (it != shaders.end() && it->second->isLoaded == true) {
        std::map<int, Shader*>::iterator itS;
        itS = Shader::loadedShaders.find(shaderId);
        if (itS != Shader::loadedShaders.end()) {
            return itS->second;
        }
    }
    else {
        return new Shader(it->second);
    }
    //std::map<int, ShaderResource*>::iterator it;
    //it = shaders.find(shaderId);
    //if (it != shaders.end()) {
    //    return it->second;
    //}
    //else {
    //    xml_node<>* shadersNode = ResourceManager::resourceManagerNode->first_node("shaders");
    //    for (xml_node<>* folderNode = shadersNode->first_node("folder"); folderNode; folderNode = folderNode->next_sibling())
    //    {
    //        for (xml_node<>* shaderNode = folderNode->first_node("shader"); shaderNode; shaderNode = shaderNode->next_sibling())
    //        {
    //            int sId = atoi(shaderNode->first_attribute("id")->value());
    //            if (sId == shaderId) {
    //                ShaderResource* sr;
    //                //(*sr).path = folderNode->first_attribute("path")->value();
    //                (*sr).vs_path = strcat(folderNode->first_attribute("path")->value(), shaderNode->first_node("vs")->value());
    //                (*sr).fs_path = strcat(folderNode->first_attribute("path")->value(), shaderNode->first_node("fs")->value());
    //                shaders.insert(std::pair<int, ShaderResource*>(sId, sr));
    //            }
    //        }
    //    }
    //}
}

void ResourceManager::parseResourceManagerXML() {
    xml_document<> doc;
    std::ifstream file("../Managers/resourceManager.xml");
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
            ModelResource* model = new ModelResource();
            (*model).modelId = modelId;
            char pathCpy[1000];
            (*model).file_path = strcat(strcpy(pathCpy, folderNode->first_attribute("path")->value()), modelNode->first_node("file")->value());
            (*model).isLoaded = false;
            
            models.insert(std::pair<int, ModelResource*>(modelId, model));
            
        }
    }

    //shaders
    xml_node<>* shadersNode = resourceManagerNode->first_node("shaders");
    for(xml_node<>* folderNode = shadersNode->first_node("folder"); folderNode; folderNode = folderNode->next_sibling())
    {
        for (xml_node<>* shaderNode = folderNode->first_node("shader"); shaderNode; shaderNode = shaderNode->next_sibling())
        {
            int shaderId = atoi(shaderNode->first_attribute("id")->value());
            ShaderResource* shader = new ShaderResource();
            (*shader).shaderId = shaderId;
            char vsPathCpy[1000];
            char fsPathCpy[1000];
            (*shader).vs_path = strcat(strcpy(vsPathCpy,folderNode->first_attribute("path")->value()), shaderNode->first_node("vs")->value());
            (*shader).fs_path = strcat(strcpy(fsPathCpy,folderNode->first_attribute("path")->value()), shaderNode->first_node("fs")->value());
            (*shader).isLoaded = false;
            shaders.insert(std::pair<int, ShaderResource*>(shaderId, shader));
        }
    }

    //textures
    xml_node<>* texturesNode = resourceManagerNode->first_node("textures");
    for (xml_node<>* folderNode = texturesNode->first_node("folder"); folderNode; folderNode = folderNode->next_sibling())
    {
        for (xml_node<>* textureNode = folderNode->first_node("texture"); textureNode; textureNode = textureNode->next_sibling())
        {
            int textureId= atoi(textureNode->first_attribute("id")->value());
            TextureResource* texture = new TextureResource();
            (*texture).textureId = textureId;
            char pathCpy[1000];
            (*texture).file_path = strcat(strcpy(pathCpy,folderNode->first_attribute("path")->value()), textureNode->first_node("file")->value());
            //(*texture).file = textureNode->first_node("file")->value();
            if (textureNode->first_attribute("type")->value() == "2d") {
                (*texture).type = GL_TEXTURE_2D;
            }
            if (textureNode->first_node("min_filter")->value() == "LINEAR") {
                (*texture).min_filter = GL_LINEAR;
            }
            if (textureNode->first_node("mag_filter")->value() == "LINEAR") {
                (*texture).mag_filter = GL_LINEAR;
            }
            if (textureNode->first_node("wrap_s")->value() == "CLAMP_TO_EDGE") {
                (*texture).wrap_s = GL_CLAMP_TO_EDGE;
            }
            if (textureNode->first_node("wrap_t")->value() == "CLAMP_TO_EDGE") {
                (*texture).wrap_t = GL_CLAMP_TO_EDGE;
            }
            (*texture).isLoaded = false;
            textures.insert(std::pair<int, TextureResource*>(textureId, texture));
        }
    }
}

void ResourceManager::freeResources() {
	delete spInstance;
}

ResourceManager::~ResourceManager()
{
}

