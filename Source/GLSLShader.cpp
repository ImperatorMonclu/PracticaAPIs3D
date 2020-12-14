/**
 * @file GLSLShader.cpp
 * @author ImperatorMonclu (maurogarciamonclu@gmail.com)
 * @brief 
 * @version 0.1.0
 * @date 14-12-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "GLSLShader.h"
#include <iostream>
#include <fstream>
#include "glm/gtc/type_ptr.hpp"

GLSLShader::GLSLShader(std::string vertexPrg, std::string fragPrg)
{
	error = new char[1024];

	programID = glCreateProgram();
	int vertexPrgID = compileShader(readFile(vertexPrg), GL_VERTEX_SHADER);
	int fragPrgID = compileShader(readFile(fragPrg), GL_FRAGMENT_SHADER);

	glAttachShader(programID, vertexPrgID);
	glAttachShader(programID, fragPrgID);
	glLinkProgram(programID);

	GLint success = 1;
	glGetProgramiv(programID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(programID, sizeof(error), nullptr, error);
		std::cout << "Error en programa al linkar\n"
				  << error << "\n";
		return;
	}

	glDeleteShader(vertexPrgID);
	glDeleteShader(fragPrgID);

	vShaderAttribs["mvpMatrix"] = glGetAttribLocation(programID, "mvpMatrix");
	vShaderAttribs["vertexPosition"] = glGetAttribLocation(programID, "vertexPosition");
}

uint32_t GLSLShader::getId()
{
	return programID;
}

const char *GLSLShader::getError()
{
	return error;
}

void GLSLShader::use()
{
	glUseProgram(programID);
}

void GLSLShader::setupAttribs()
{
	if (vShaderAttribs["vertexPosition"] != -1)
	{
		glEnableVertexAttribArray(vShaderAttribs["vertexPosition"]);
		glVertexAttribPointer(vShaderAttribs["vertexPosition"], 4, GL_FLOAT, false, 0, nullptr);
	}
}

glm::uint32 GLSLShader::getLocation(std::string name)
{
	return vShaderAttribs[name];
}

void GLSLShader::setInt(glm::uint32 loc, int val)
{
	if (loc != -1)
	{
		glUniform1i(loc, val);
	}
}

void GLSLShader::setFloat(glm::uint32 loc, float val)
{
	if (loc != -1)
	{
		glUniform1f(loc, val);
	}
}

void GLSLShader::setVec3(glm::uint32 loc, const glm::vec3 &vec)
{
	if (loc != -1)
	{
		glUniform3f(loc, vec.x, vec.y, vec.z);
	}
}

void GLSLShader::setVec4(glm::uint32 loc, const glm::vec4 &vec)
{
	if (loc != -1)
	{
		glUniform4f(loc, vec.r, vec.g, vec.b, vec.a);
	}
}

void GLSLShader::setMatrix(glm::uint32 loc, const glm::mat4 &matrix)
{
	if (loc != -1)
	{
		glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(matrix));
	}
}

const char *GLSLShader::readFile(std::string filename)
{
	std::ifstream::pos_type size;
	char *memblock;
	std::string text;

	std::ifstream file(filename, std::ios::in | std::ios::binary | std::ios::ate);
	if (file.is_open())
	{
		size = file.tellg();
		memblock = new char[1 + size];
		file.seekg(0, std::ios::beg);
		file.read(memblock, size);
		file.close();
		memblock[size] = '\0';
		std::cout << "File " << filename << " loaded" << std::endl;
		text.assign(memblock);
	}
	else
	{
		std::cout << "Unable to open file " << filename << std::endl;
		exit(1);
	}
	return memblock;
}

int GLSLShader::compileShader(const char *code, GLenum shaderType)
{
	int shaderID = glCreateShader(shaderType);
	glShaderSource(shaderID, 1, &code, nullptr);
	glCompileShader(shaderID);
	GLint success = 1;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shaderID, 1024, nullptr, error);
		std::cout << "Error en shader\n"
				  << error << "\n";
	}
	return shaderID;
}