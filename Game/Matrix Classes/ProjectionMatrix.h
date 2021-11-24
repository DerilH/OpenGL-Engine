#pragma once
#ifndef PROJECTIONMATRIX_H
#define PROJECTIONMATRIX_H
//#include "../Window.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

class ProjectionMatrix
{
public:
	static mat4 Perspective()
	{
	  return perspective(glm::radians(45.0f), 1280.0f / 720.0f, 0.1f, 100.0f);
	}
};
#endif 


