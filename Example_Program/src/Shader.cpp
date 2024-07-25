#include "Shader.h"
#include <Gl/glew.h>
#include <fstream>
#include <string>
#include <sstream>


Shader::Shader(const std::string& filepath)
{
	this->ID = 0;
	enum class ShaderType
	{
		NONE = -1, VERTEX, FRAGMENT
	};
	ShaderType type = ShaderType::VERTEX;
	std::ifstream stream(filepath);
	std::string line;
	std::stringstream ss[2];
	while (getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				type = ShaderType::FRAGMENT;
			}
		}
		else
		{
			ss[(int)type] << line << "\n";
		}
	}

	this->vertexSource = ss[0].str();
	this->fragmentSource = ss[1].str();
}
Shader::~Shader()
{
	glDeleteProgram(this->ID); 
}

unsigned int Shader::compileShader(unsigned int type, const std::string& source)
{
	unsigned int shader = glCreateShader(type);
	const char* shaderSource = source.c_str();
	glShaderSource(shader, 1, &shaderSource, NULL);
	glCompileShader(shader);
	int success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	else std::cout << "ERROR::SHADER::COMPILATION_SUCCESS\n" << std::endl;
	return shader;
}

void Shader::compileProgram()
{
	int shader1, shader2;
	this->ID = glCreateProgram();
	shader1 = this->compileShader(GL_VERTEX_SHADER, this->vertexSource);
	shader2 = this->compileShader(GL_FRAGMENT_SHADER, this->fragmentSource);
	glAttachShader(this->ID, shader1);
	glAttachShader(this->ID, shader2);
	glLinkProgram(this->ID);
	int success;
	char infoLog[512];
	glGetProgramiv(this->ID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(this->ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	else std::cout << "ERROR::SHADER::PROGRAM::LINKING_SUCCESS\n";
	glDeleteShader(shader1);
	glDeleteShader(shader2);

}

unsigned int Shader::getID()
{
	return this->ID;
}

void setMat3(const char* uniformName);
void setMat2(const char* uniformName);
void setVec4(const char* uniformName);
void setVec3(const char* uniformName);

void Shader::setVec2(const char* uniformName)
{

}

void Shader::setMat4(const char* uniformName, const glm::mat4& mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(this->ID, uniformName), 1, GL_FALSE, &mat[0][0]);
}
