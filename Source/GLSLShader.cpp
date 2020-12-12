#include "GLSLShader.h"
#include <GL/glew.h>
#include "Vertex.h"
#include <iostream>

GLSLShader::~GLSLShader()
{
	if (programID != -1)
	{
		glDeleteProgram(programID);
	}
}

GLSLShader::GLSLShader(std::string vertexPrg, std::string fragPrg)
{
	int param = GL_FALSE;

	uint32_t vertexPrgID = glCreateShader(GL_VERTEX_SHADER);
	const char *vertexPrgC = vertexPrg.c_str();
	glShaderSource(vertexPrgID, 1, &vertexPrgC, nullptr);
	glCompileShader(vertexPrgID);

	glGetShaderiv(vertexPrgID, GL_COMPILE_STATUS, &param);
	if (param == GL_FALSE)
	{
		glGetShaderInfoLog(vertexPrgID, sizeof(error), nullptr, error);
		std::cout << error << std::endl;
		return;
	}

	uint32_t fragPrgID = glCreateShader(GL_FRAGMENT_SHADER);
	const char *fragPrgC = fragPrg.c_str();
	glShaderSource(fragPrgID, 1, &fragPrgC, nullptr);
	glCompileShader(fragPrgID);

	glGetShaderiv(fragPrgID, GL_COMPILE_STATUS, &param);
	if (param == GL_FALSE)
	{
		glGetShaderInfoLog(fragPrgID, sizeof(error), nullptr, error);
		std::cout << error << std::endl;
		glDeleteShader(vertexPrgID);
		return;
	}

	programID = glCreateProgram();
	glAttachShader(programID, vertexPrgID);
	glAttachShader(programID, fragPrgID);
	glLinkProgram(programID);

	glGetProgramiv(programID, GL_LINK_STATUS, &param);
	if (param == GL_FALSE)
	{
		glGetProgramInfoLog(programID, sizeof(error), nullptr, error);
		std::cout << error << std::endl;
		glDeleteShader(vertexPrgID);
		glDeleteShader(fragPrgID);
		return;
	}

	glDeleteShader(vertexPrgID);
	glDeleteShader(fragPrgID);

	vShaderAttribs["vPos"] = glGetAttribLocation(programID, "vPos");
	vShaderAttribs["mvpMatrix"] = glGetAttribLocation(programID, "mvpMatrix");
	vShaderAttribs["fColor"] = glGetAttribLocation(programID, "fColor");
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
	if (vShaderAttribs["vPos"] != -1)
	{
		glEnableVertexAttribArray(vShaderAttribs["vPos"]);
		glVertexAttribPointer(vShaderAttribs["vPos"], 3, GL_FLOAT, false, sizeof(vertex_t), 0);
	}
	if (vShaderAttribs["mvpMatrix"] != -1)
	{
		glEnableVertexAttribArray(vShaderAttribs["mvpMatrix"]);
		glVertexAttribPointer(vShaderAttribs["mvpMatrix"], 3, GL_FLOAT, false, sizeof(glm::mat4), 0);
	}
	if (vShaderAttribs["fColor"] != -1)
	{
		glEnableVertexAttribArray(vShaderAttribs["fColor"]);
		glVertexAttribPointer(vShaderAttribs["fColor"], 3, GL_FLOAT, false, sizeof(glm::vec3), 0);
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
		glUniformMatrix4fv(loc, 1, GL_FALSE, &matrix[0][0]);
	}
}