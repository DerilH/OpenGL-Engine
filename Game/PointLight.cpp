#include "PointLight.h"
#include "LightObject.h"

PointLight::PointLight(vec3 position, vec3 diffuse, vec3 specular, vec3 ambient, vec3 direction)
{
	this->position = position;
	this->direction = direction;

	this->diffuse = diffuse;
	this->specular = specular;
	this->ambient = ambient;
}

void PointLight::allow()
{
	RenderPipeline::shader.use();
	RenderPipeline::shader.SetVector3f("pointLight.position", this->position);
	RenderPipeline::shader.SetVector3f("pointLight.ambient", this->ambient);
	RenderPipeline::shader.SetVector3f("pointLight.diffuse", this->diffuse);
	RenderPipeline::shader.SetVector3f("pointLight.specular", this->specular);
	RenderPipeline::shader.setFloat("pointLight.constant", 1.0f);
	RenderPipeline::shader.setFloat("pointLight.linear", 0.09);
	RenderPipeline::shader.setFloat("pointLight.quadratic", 0.032);
}
