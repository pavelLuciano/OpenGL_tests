#pragma once
#include <glm/glm.hpp>
#include <iostream>
class Shader
{
private:
	unsigned int ID;
	std::string vertexSource;
	std::string fragmentSource;
	unsigned int compileShader(unsigned int type, const std::string& source);

public:
	Shader(const std::string& filepath);
	~Shader();
	void compileProgram();
	unsigned int getID();

	void setMat4(const char* uniformName, const glm::mat4& mat) const;
	void setMat3(const char* uniformName);
	void setMat2(const char* uniformName);
	void setVec4(const char* uniformName);
	void setVec3(const char* uniformName);
	void setVec2(const char* uniformName);
};

