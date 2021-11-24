#pragma once
#ifndef RENDERINGOBJECT_H
#define RENDERINGOBJECT_H

#include <iostream>

#include <../Matrix Classes/ModelMatrix.h>
#include <../Matrix Classes/ViewMatrix.h>
#include "../Matrix Classes/ProjectionMatrix.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class RenderingObject
{
protected:
	static int GlobalID;
	RenderingObject();
public:
	int uniqueID;

	std::string textureName;
	ModelMatrix modelMatrix;
	glm::vec3 position, size, rotationAxis, spriteColor;
	float rotation;
	
	virtual void render() {};
};
#endif



