#pragma once
#ifndef VIEWMATRIX_H
#define VIEWMATRIX_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

class ViewMatrix
{
public:
	mat4 matrix = mat4(1.0f);

	void SetTranslationMat4(vec3 translation)
	{
		matrix = translate(matrix, translation);
	}
	void SetRotationMat4(float rotation, vec3 axis)
	{
		matrix = rotate(matrix, radians(rotation), axis);
	}
};
#endif 

