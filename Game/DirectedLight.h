#pragma once
#include "LightObject.h"
#include "RenderPipeline.h"

class DirectedLight : public LightObject
{
public:
	DirectedLight(vec3 position, vec3 diffuse, vec3 specular, vec3 ambient, vec3 direction);
	virtual void allow();
};

