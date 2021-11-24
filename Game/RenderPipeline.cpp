#include "RenderPipeline.h"
#include "SpriteRenderer.h"
#include "SquareRenderer.h"
#include "CubeRenderer.h"

std::map<int,RenderingObject*> RenderPipeline::objects;
std::map<int, LightObject*> RenderPipeline::lightObjects;

Shader RenderPipeline::shader;
float RenderPipeline::deltaTime = 0.0f;
float RenderPipeline::lastFrame = 0.0f;

void RenderPipeline::InitRenderPipeline() 
{
	shader = ResourceManager::LoadShader();
	ResourceManager::LoadTextures();

	static CubeRenderer cube("container", glm::vec3(0, 0, 5), glm::vec3(1, 1, 1), 0, glm::vec3(0, 0, 0));
	static CubeRenderer cube2("container", glm::vec3(0, 0, -5), glm::vec3(1, 1, 1), 0, glm::vec3(0, 0, 0));
	
	
	objects.insert(std::pair(cube.uniqueID, (RenderingObject*)&cube));
	objects.insert(std::pair(cube2.uniqueID, (RenderingObject*)&cube2));

}

void RenderPipeline::startRender(GLFWwindow *window)
{
	glEnable(GL_DEPTH_TEST);
	static PointLight pLight(vec3(0.0f), vec3(0.8f), vec3(1.0f), vec3(0.95f), vec3(0.0f));
	static DirectedLight dLight(vec3(0.0f), vec3(0.8f), vec3(1.0f), vec3(0.95f), vec3(0.0f));
	static SpotLight sLight(vec3(0.0f), vec3(0.8f), vec3(1.0f), vec3(0.95f), vec3(0.0f));
	lightObjects.insert(std::pair(pLight.uniqueID, (LightObject*)&pLight));
	lightObjects.insert(std::pair(sLight.uniqueID, (LightObject*)&sLight));
	lightObjects.insert(std::pair(dLight.uniqueID, (LightObject*)&dLight));



	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		Camera::cameraSpeed = 2.5f * deltaTime;

		glClearColor(0.0f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Camera::render();

		shader.use();
		shader.SetVector3f("viewPos", Camera::position);
		shader.setFloat("material.shininess", 32.0f);

		pLight.allow();
		sLight.allow();
		dLight.allow();

		for (auto objectToRender : objects)
		{
			objectToRender.second->render();
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void RenderPipeline::addObject(RenderingObject* object)
{
	objects.insert(std::pair(object->uniqueID, object));
}
