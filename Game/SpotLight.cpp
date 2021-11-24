#include "SpotLight.h"
#include "LightObject.h"

SpotLight::SpotLight(vec3 position, vec3 diffuse, vec3 specular, vec3 ambient, vec3 direction)
{
    this->position = position;
    this->direction = direction;

    this->diffuse = diffuse;
    this->specular = specular;
    this->ambient = ambient;
}

void SpotLight::allow()
{
    RenderPipeline::shader.SetVector3f("spotLight.position", Camera::position);
    RenderPipeline::shader.SetVector3f("spotLight.direction", Camera::front);
    RenderPipeline::shader.SetVector3f("spotLight.ambient", this->ambient);
    RenderPipeline::shader.SetVector3f("spotLight.diffuse", this->diffuse);
    RenderPipeline::shader.SetVector3f("spotLight.specular", this->specular);
    RenderPipeline::shader.setFloat("spotLight.constant", 1.0f);
    RenderPipeline::shader.setFloat("spotLight.linear", 0.09);
    RenderPipeline::shader.setFloat("spotLight.quadratic", 0.032);
    RenderPipeline::shader.setFloat("spotLight.cutOff", glm::cos(glm::radians(12.5f)));
    RenderPipeline::shader.setFloat("spotLight.outerCutOff", glm::cos(glm::radians(15.0f)));
}
