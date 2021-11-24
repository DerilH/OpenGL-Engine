#pragma once
#include "RenderPipeline.h"
#include "ResourseManager/ResourceManager.h"
#include <iostream>
#include <vector>
#include <functional>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <tuple>

class ConsoleCommandHandler
{
public:
	static std::map<std::string, std::function<bool(std::vector<std::string> args)>> commandFunc;
	static std::map<std::string, std::string> commandDescriptions;

	static void InitConsoleCommands();
	static void callCommand(std::string name, std::vector<std::string> args);
	
	static bool help(std::vector<std::string> args);
	static bool setblock(std::vector<std::string> args);
	static bool changeSpeed(std::vector<std::string> args);
	static bool changePosition(std::vector<std::string> args);
	static bool sceneInteraction(std::vector<std::string> args);
	static bool getScenes(std::vector<std::string> args);
	static bool transformObject(std::vector<std::string> args);
};

