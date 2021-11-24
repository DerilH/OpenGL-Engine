#include "InputHandler.h"

bool InputHandler::KeysStates[348];

void InputHandler::InitInputHandler()
{
	for (int i = 0; i < 348; i++) 
	{
		KeysStates[i] = false;
	}
	ConsoleCommandHandler::InitConsoleCommands();
}

void InputHandler::startHandleInput()
{
		bool cursorVisibility = false;
		while (true) {
			std::this_thread::sleep_for(std::chrono::milliseconds(20));

			for (int i = 0; i < 348; i++) 
			{
				if (KeysStates[i]) {

					switch (i)
					{
					case GLFW_KEY_W:
						if (KeysStates[GLFW_KEY_W] && KeysStates[GLFW_KEY_S]) continue;
						Camera::position += Camera::cameraSpeed * Camera::front;
						break;
					case GLFW_KEY_A:
						if (KeysStates[GLFW_KEY_A] && KeysStates[GLFW_KEY_D]) continue;
						Camera::position -= glm::normalize(glm::cross(Camera::front, Camera::up)) * Camera::cameraSpeed;
						break;
					case GLFW_KEY_S:
						if (KeysStates[GLFW_KEY_W] && KeysStates[GLFW_KEY_S]) continue;
						Camera::position -= Camera::cameraSpeed * Camera::front;
						break;
					case GLFW_KEY_D:
						if (KeysStates[GLFW_KEY_A] && KeysStates[GLFW_KEY_D]) continue;
						Camera::position += glm::normalize(glm::cross(Camera::front, Camera::up)) * Camera::cameraSpeed;
						break;
					case GLFW_KEY_ESCAPE:
						exit(0);
						break;
					}
				}
				else continue;
			}
		}
}
void InputHandler::startHandleConsoleInput() 
{
	while (true) {
		std::string command;
		command += " ";
		std::cout << ">";
		std::getline(std::cin, command);
		std::vector<std::string> args = parseArgs(command);
		ConsoleCommandHandler::callCommand(args[0], args);
	}
}
std::vector<std::string> InputHandler::parseArgs(const std::string &str)
{
		std::string word = "";
		std::vector<std::string> args;
		for (auto x : str)
		{
			if (x == ' ' || typeid(x) != typeid(char))
			{
				args.push_back(word);
				word = "";
			}
			else {
				word = word + x;
			}
		}
		args.push_back(word);
		return args;
}