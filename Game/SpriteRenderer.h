#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "RenderingObject.h"
#include "ResourseManager/ResourceManager.h"
#include "ResourseManager/Texture.h"
#include "RenderPipeline.h"

class SpriteRenderer : public RenderingObject
{
public:
	unsigned int VAO;
	Texture2D texture;

	ModelMatrix modelMatrix;
	//ViewMatrix viewMatrix;

	glm::vec3 position, size, rotationAxis, spriteColor;
	float rotation;

	SpriteRenderer(std::string textureName, glm::vec3 position, glm::vec3 size, float rotation, glm::vec3 rotationAxis);
	virtual void render();
};

