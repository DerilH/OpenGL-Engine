#pragma once
#ifndef MODELMATRIX_H
#define MODELMATRIX_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

class ModelMatrix
{
public:
	mat4 matrix = mat4(1.0f);

	void SetTransformMat4(vec4 rotation, vec3 scaling, vec3 translation)
	{
		matrix = rotate(matrix, radians(rotation.x), vec3(rotation.y, rotation.z, rotation.w));
		matrix = scale(matrix, scaling);
		matrix = translate(matrix, translation);
	}
	void SetTranslationMat4(vec3 translation)
	{
		matrix = translate(matrix, translation);
	}
	void SetRotationMat4(float rotation, vec3 axis)
	{
		matrix = rotate(matrix, radians(rotation), axis);
	}
	void SetScaleMat4(vec3 scaling)
	{
		matrix = scale(matrix, scaling);
	}
	void SetPos(vec3 pos) 
	{
		matrix = translate(mat4(1.0f), pos);
	}
};
#endif 

