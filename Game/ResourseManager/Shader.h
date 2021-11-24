#pragma once
#ifndef SHADER_H
#define SHADER_H

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public: unsigned int ID;
      Shader();
      Shader(const char* vertexPath, const char* fragmentPath);
      void use();
      void setBool(const std::string& name, bool value) const;
      void setInt(const std::string& name, int value) const;
      void setFloat(const std::string& name, float value) const;
      void SetVector2f(const char* name, float x, float y);
      void SetVector2f(const char* name, const glm::vec2& value);
      void SetVector3f(const char* name, float x, float y, float z);
      void SetVector3f(const char* name, const glm::vec3& value);
      void SetVector4f(const char* name, float x, float y, float z, float w);
      void SetVector4f(const char* name, const glm::vec4& value);
      void SetMatrix4(const char* name, const glm::mat4& matrix);
private:
    void checkCompileErrors(unsigned int shader, std::string type);
};
#endif



