#pragma once
#include "LightObject.h"
#include "RenderPipeline.h"
class PointLight : public LightObject
{
public:
	PointLight(vec3 position, vec3 diffuse, vec3 specular, vec3 ambient, vec3 direction);
	virtual void allow();
};

