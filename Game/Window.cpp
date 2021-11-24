#include "Window.h"



void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	/*if (firstMouse)
	{
	lastX = xpos;
	lastY = ypos;
	firstMouse = false;
	}*/

	float xoffset = xpos - Camera::lastX;
	float yoffset = Camera::lastY - ypos;
	Camera::lastX = xpos;
	Camera::lastY = ypos;

	float sensitivity = 0.05;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	Camera::yaw += xoffset;
	Camera::pitch += yoffset;

	if (Camera::pitch > 89.0f)
		Camera::pitch = 89.0f;
	if (Camera::pitch < -89.0f)
		Camera::pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(Camera::yaw)) * cos(glm::radians(Camera::pitch));
	direction.y = sin(glm::radians(Camera::pitch));
	direction.z = sin(glm::radians(Camera::yaw)) * cos(glm::radians(Camera::pitch));
	Camera::front = glm::normalize(direction);
}

int Window::Width;
int Window::Height;
GLFWwindow* Window::window;

Window::Window(int Width, int Height)
{
	this->Width = Width;
	this->Height = Height;
}

void Window::Open()
{
	GLFWwindow* window = InitGLFWwindow();
	RenderPipeline::InitRenderPipeline();
	Camera::InitCamera();
	InputHandler::InitInputHandler();

	std::thread inputThread(InputHandler::startHandleInput);
	inputThread.detach();
	std::thread inputConsoleThread(InputHandler::startHandleConsoleInput);
	inputConsoleThread.detach();

	RenderPipeline::startRender(window);

	glfwTerminate();
	exit(0);
}

GLFWwindow* Window::InitGLFWwindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	window = glfwCreateWindow(Width, Height, "Game", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		exit(-1);
	}
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwMakeContextCurrent(window);
	
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		exit(-2);
	}
	
	glfwGetFramebufferSize(window, &Width, &Height);
	glViewport(0, 0, Width, Height);

	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_callback);

	return window;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) 
{
	if (action == GLFW_PRESS) 
	{
		InputHandler::KeysStates[key] = true;
	}
	else if (action == GLFW_RELEASE) InputHandler::KeysStates[key] = false;
}

