#pragma once

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <map>
#include <json/json.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <filesystem>

#include "stb_image.h"
#include "Shader.h"
#include "Texture.h"
#include "../RenderPipeline.h"

class ResourceManager
{
private:
    static Texture2D loadTextureFromFile(const char* file, bool alpha);
public:
    static std::map<std::string, Texture2D> Textures;
    static std::string SavesPath;

    static void LoadTextures();
    static Shader LoadShader();

    static bool sceneSave(std::string sceneName);
    static bool sceneLoad(std::string sceneName);
};
#endif



