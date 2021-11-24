#pragma once

#ifndef RENDERPIPELINE_H
#define RENDERPIPELINE_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <typeinfo>
#include <list>
#include <tuple>
#include <thread>

#include "ResourseManager/Shader.h"
#include "ResourseManager/ResourceManager.h"
#include <../Matrix Classes/ModelMatrix.h>
#include <../Matrix Classes/ViewMatrix.h>

#include "DirectedLight.h"
#include "SpotLight.h"
#include "PointLight.h"
#include "RenderingObject.h"
#include "Camera.h"


class RenderPipeline
{
public:
	static float deltaTime;
	static float lastFrame;

	static Shader shader;
	static std::map<int, RenderingObject*> objects;
	static std::map<int,LightObject*> lightObjects;

	static void InitRenderPipeline();
	static void startRender(GLFWwindow* window);

	static void addObject(RenderingObject* object);
};
#endif


