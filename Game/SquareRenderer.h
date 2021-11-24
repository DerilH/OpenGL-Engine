#pragma once
#ifndef SQUARERENDERER_H
#define SQUARERENDERER_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "ResourseManager/Shader.h"
#include "RenderPipeline.h"
#include "RenderingObject.h"

class SquareRenderer : public RenderingObject
{
private:
	unsigned int VAO, VBO, EBO;
public:
	void BindBuffers();
	virtual void render();
};
#endif