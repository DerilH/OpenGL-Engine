#include "Camera.h"

ViewMatrix Camera::viewMatrix;
glm::vec3 Camera::position = glm::vec3(0, 0, -5);
glm::vec3 Camera::front = glm::vec3(0, 0, -1);
glm::vec3 Camera::up = glm::vec3(0, 1, 0);
glm::vec3 Camera::direction;
float Camera::cameraSpeed = 0.05f;
float Camera::yaw = -90.0f;
float Camera::pitch = 0.0f;
float Camera::lastX = Window::Width / 2;
float Camera::lastY = Window::Height / 2;


void Camera::InitCamera() 
{
	RenderPipeline::shader.use();
	RenderPipeline::shader.SetMatrix4("projection", ProjectionMatrix::Perspective());
}

void Camera::render()
{
	viewMatrix.matrix = glm::lookAt(position, position + front, up);
	RenderPipeline::shader.SetMatrix4("view", viewMatrix.matrix);
}

void Camera::move(glm::vec3 direction)
{
}
void Camera::direct(glm::vec3 direct) 
{
}
