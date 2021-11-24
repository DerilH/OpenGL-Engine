#include "DirectedLight.h"
#include "LightObject.h"

DirectedLight::DirectedLight(vec3 position, vec3 diffuse, vec3 specular, vec3 ambient, vec3 direction)
{
    this->position = position;
    this->direction = direction;

    this->diffuse = diffuse;
    this->specular = specular;
    this->ambient = ambient;
}

void DirectedLight::allow()
{
    RenderPipeline::shader.SetVector3f("dirLight.position", this->position);
    RenderPipeline::shader.SetVector3f("dirLight.direction", this->direction);
    RenderPipeline::shader.SetVector3f("dirLight.ambient", this->ambient);
    RenderPipeline::shader.SetVector3f("dirLight.diffuse", this->diffuse);
    RenderPipeline::shader.SetVector3f("dirLight.specular", this->specular);
}
