#pragma once

#ifndef WINDOW_H
#define WINDOW_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <thread>

#include "RenderPipeline.h"
#include "InputHandler.h"

class Window
{
private:
	GLFWwindow* InitGLFWwindow();
public:
	static GLFWwindow* window;
	static int Width, Height;
	Window(int Width, int Height);
	void Open();
};
#endif



