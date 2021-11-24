#pragma once
#include "LightObject.h"
#include "RenderPipeline.h"
class SpotLight : public LightObject
{
public:
	SpotLight(vec3 position, vec3 direction, vec3 diffuse, vec3 specular, vec3 ambient);
	virtual void allow();
};

