#include "ResourceManager.h"

std::map<std::string, Texture2D> ResourceManager::Textures;
std::string ResourceManager::SavesPath = "ResourseManager/Saves/";

Texture2D ResourceManager::loadTextureFromFile(const char* file, bool alpha)
{
    Texture2D texture;
    if (alpha)
    {
        texture.Internal_Format = GL_RGBA;
        texture.Image_Format = GL_RGBA;
    }

    int width, height, nrChannels;
    unsigned char* data = stbi_load(file, &width, &height, &nrChannels, 0);
    

    texture.Generate(width, height, data);

    stbi_image_free(data);
    return texture;
}
void ResourceManager::LoadTextures()
{
    Textures["container"] = loadTextureFromFile("ResourseManager/wooden_container.jpg", false);
}
Shader ResourceManager::LoadShader()
{
    return Shader("ResourseManager/Shaders/VertexShader.vs", "ResourseManager/Shaders/FragmentShader.fs");
}
bool ResourceManager::sceneSave(std::string sceneName)
{
	std::string fileName = sceneName + ".json";
	std::string filePath = SavesPath + fileName;

	Json::Value json;
	try
	{
		json["objectsCount"] = RenderPipeline::objects.size();
		int iter = 0;
		for (auto object : RenderPipeline::objects)
		{
			std::string objectName = "Object" + std::to_string(iter);
			std::cout << objectName << std::endl;

			json["objects"][objectName]["texture"] = object.second->textureName;

			json["objects"][objectName]["position"]["x"] = object.second->position.x;
			json["objects"][objectName]["position"]["y"] = object.second->position.y;
			json["objects"][objectName]["position"]["z"] = object.second->position.z;

			json["objects"][objectName]["size"]["x"] = object.second->size.x;
			json["objects"][objectName]["size"]["y"] = object.second->size.y;
			json["objects"][objectName]["size"]["z"] = object.second->size.z;

			json["objects"][objectName]["rotationAxis"]["x"] = object.second->rotationAxis.x;
			json["objects"][objectName]["rotationAxis"]["y"] = object.second->rotationAxis.y;
			json["objects"][objectName]["rotationAxis"]["z"] = object.second->rotationAxis.z;
			json["objects"][objectName]["rotationAngle"] = object.second->rotation;

			iter++;
		}
		Json::StreamWriterBuilder builder;
		builder["commentStyle"] = "None";
		builder["indentation"] = "   ";

		std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
		std::ofstream outputFileStream(filePath);
		writer->write(json, &outputFileStream);
		std::cout << "Scene succesfully saved" << std::endl;
	}
	catch (Json::Exception ex) 
	{
		std::cout << ex.what() << std::endl;
	}
	catch (std::exception ex) 
	{
		std::cout << ex.what() << std::endl;
	}
	return true;
}

bool ResourceManager::sceneLoad(std::string sceneName)
{
	try {
		std::string fileName = sceneName + ".json";
		std::string filePath = SavesPath + fileName;

		RenderPipeline::objects.clear();

		if (std::filesystem::exists(filePath)) {

			std::ifstream json_file(filePath, std::ifstream::binary);

			Json::Value json;
			json_file >> json;

			int objCount = json["objectsCount"].asInt();

			for (int i = 0; i < objCount; i++)
			{
				std::string objectName = "Object" + std::to_string(i);

				std::string objTexture;
				objTexture = json["objects"][objectName]["texture"].asString();
				
				if (objTexture.empty()) objTexture = "container";

				glm::vec3 objPos;
				objPos.x = json["objects"][objectName]["position"]["x"].asFloat();
				objPos.y = json["objects"][objectName]["position"]["y"].asFloat();
				objPos.z = json["objects"][objectName]["position"]["z"].asFloat();

				glm::vec3 objSize;
				objSize.x = json["objects"][objectName]["size"]["x"].asFloat();
				objSize.y = json["objects"][objectName]["size"]["y"].asFloat();
				objSize.z = json["objects"][objectName]["size"]["z"].asFloat();

				glm::vec3 objRotationAxis;
				objRotationAxis.x = json["objects"][objectName]["rotationAxis"]["x"].asFloat();
				objRotationAxis.y = json["objects"][objectName]["rotationAxis"]["y"].asFloat();
				objRotationAxis.z = json["objects"][objectName]["rotationAxis"]["z"].asFloat();

				float objRotationAngle;
				objRotationAngle = json["objects"][objectName]["rotationAngle"].asFloat();

				RenderPipeline::addObject(new CubeRenderer("container", objPos, objSize, objRotationAngle, objRotationAxis));
			}

			std::cout << "Scene " << '"' << sceneName << '"' << " succesfully loaded" << std::endl;
			return true;
		}
		else
		{
			std::cout << "File not exists" << std::endl;
			return false;
		}
	}
	catch (Json::Exception ex) 
	{
		std::cout << ex.what() << std::endl;
	}
}
