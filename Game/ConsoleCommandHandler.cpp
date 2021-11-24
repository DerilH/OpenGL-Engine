#include "ConsoleCommandHandler.h"

std::map<std::string, std::function<bool(std::vector<std::string> args)>> ConsoleCommandHandler::commandFunc;
std::map<std::string, std::string> ConsoleCommandHandler::commandDescriptions;

void ConsoleCommandHandler::InitConsoleCommands()
{
	//help
	commandFunc.insert(std::make_pair("help", help));
	commandDescriptions.insert(std::make_pair("help", " - List of all commands"));
	//setblock
	commandFunc.insert(std::make_pair("setblock",setblock));
	commandDescriptions.insert(std::make_pair("setblock", " - Sets block at given position"));
	//speed
	commandFunc.insert(std::make_pair("speed", changeSpeed));
	commandDescriptions.insert(std::make_pair("speed", " - Sets camera speed"));
	//teleport
	commandFunc.insert(std::make_pair("teleport", changePosition));
	commandDescriptions.insert(std::make_pair("teleport", " - Teleports object to given position"));
	//scene
	commandFunc.insert(std::make_pair("scene", sceneInteraction));
	commandDescriptions.insert(std::make_pair("scene", " - Interact with scene. Example: scene (load||save||delete||get) (sceneName) "));
	//object transform
	commandFunc.insert(std::make_pair("object", transformObject));
	commandDescriptions.insert(std::make_pair("object", " - Interact with scene objects. Example: object getObjects||move||rotate object||lightObject objectID"));
}

void ConsoleCommandHandler::callCommand(std::string name, std::vector<std::string> args)
{
	std::transform(name.begin(), name.end(), name.begin(),
		[](unsigned char c) { return std::tolower(c); });
	for (auto arg : args)
	{
		std::transform(arg.begin(), arg.end(), arg.begin(),
		[](unsigned char c) { return std::tolower(c); });
	}
	if (commandFunc.contains(name)) {
		if (commandFunc[name](args)) {
		}
		else std::cout << "Fail" << std::endl;
	}
	else std::cout << "No such command exists" << std::endl;
}

bool ConsoleCommandHandler::help(std::vector<std::string> args)
{
	for (auto desc: commandDescriptions) 
	{
		std::cout << " " << desc.first << desc.second << std::endl;
	}
	return true;
}

bool ConsoleCommandHandler::setblock(std::vector<std::string> args)
{
	glm::vec3 position(std::stoi(args[1], nullptr, 16), std::stoi(args[2], nullptr, 16), std::stoi(args[3], nullptr, 16));
	RenderPipeline::addObject(new CubeRenderer("container", position, glm::vec3(1, 1, 1), 0, glm::vec3(0, 0, 0)));
	return true;
}

bool ConsoleCommandHandler::changeSpeed(std::vector<std::string> args)
{
	Camera::cameraSpeed = std::stoi(args[1]);
	return true;
}

bool ConsoleCommandHandler::changePosition(std::vector<std::string> args)
{
	if (args[1] == "camera" || args[1] == "c")
	{
		glm::vec3 position(std::stoi(args[2], nullptr, 16), std::stoi(args[3], nullptr, 16), std::stoi(args[4], nullptr, 16));

		Camera::position = position;
	}
	return true;
}

bool ConsoleCommandHandler::sceneInteraction(std::vector<std::string> args)
{
	if (args[1] == "load" || args[1] == "l")
	{
		ResourceManager::sceneLoad(args[2]);
	}
	else if(args[1] == "save" || args[1] == "s")
	{
		ResourceManager::sceneSave(args[2]);
	}
	else if (args[1] == "get" || args[1] == "g") 
	{
		getScenes(args);
	}
	else if (args[1] == "delete" || "d")
	{
		std::string filePath = ResourceManager::SavesPath + args[2] + ".json";

		if (std::filesystem::exists(filePath)) {
			std::remove(filePath.c_str());
			std::cout << "Scene succesfully deleted" << std::endl;
		} else
		{
			std::cout << "No such scene to delete" << std::endl;
		}
	}
	return true;
}

bool ConsoleCommandHandler::getScenes(std::vector<std::string> args) 
{
	for (const auto& entry : std::filesystem::directory_iterator(ResourceManager::SavesPath)) 
	{
		std::cout << entry.path() << std::endl;
	}
	return true;
}

bool ConsoleCommandHandler::transformObject(std::vector<std::string> args)
{
	if (args[1] == "getObjects") 
	{
		std::cout << "Objects" << std::endl;
		for (auto obj : RenderPipeline::objects) 
		{
			std::cout << "ID:" << obj.second->uniqueID << " pos:" << obj.second->position.x << " " << obj.second->position.y << " " << obj.second->position.z << std::endl;
		}
		std::cout << "Light" << std::endl;
		for (auto obj : RenderPipeline::lightObjects)
		{
			std::cout << "ID:" << obj.second->uniqueID << " pos:" << obj.second->position.x << " " << obj.second->position.y << " " << obj.second->position.z << std::endl;
		}
	}
	else if (args[1] == "move") 
	{
		if (args[2] == "object") 
		{
			RenderPipeline::objects[std::stoi(args[3], nullptr, 16)]->modelMatrix.SetPos(vec3(std::stoi(args[4], nullptr, 16), std::stoi(args[5], nullptr, 16), std::stoi(args[6], nullptr, 16)));
		}
		else if (args[2] == "lightObject") 
		{
			RenderPipeline::lightObjects[std::stoi(args[3], nullptr, 16)]->position = vec3(std::stoi(args[4], nullptr, 16), std::stoi(args[5], nullptr, 16), std::stoi(args[6], nullptr, 16));
		}
	}
	return true;
}



