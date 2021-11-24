#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


using namespace glm;

class LightObject
{
protected:
	static int GlobalID;
	LightObject();

public:
	int uniqueID;
	glm::vec3 position, direction;
	glm::vec3 ambient, diffuse, specular;
	
	virtual void allow() {};
};

