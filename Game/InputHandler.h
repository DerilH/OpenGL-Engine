#pragma once
#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <thread>
#include <chrono>
#include "Camera.h"
#include <vector>
#include <type_traits>

#include "CubeRenderer.h"
#include "RenderPipeline.h"
#include "ConsoleCommandHandler.h"

class InputHandler
{
public:
	static bool KeysStates[348];

	static void InitInputHandler();
	static void startHandleInput();
	static void startHandleConsoleInput();
	static std::vector<std::string> parseArgs(const std::string &str);
};
#endif 


