#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Matrix Classes/ViewMatrix.h"
#include "Matrix Classes/ProjectionMatrix.h"
#include "Window.h"
#include "RenderPipeline.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
	static ViewMatrix viewMatrix;
	static glm::vec3 position, direction, front, up;
	static float cameraSpeed, yaw, pitch, lastX, lastY;

	static void InitCamera();
	static void render();
	static void move(glm::vec3 direction);
	static void direct(glm::vec3 direct);
};

