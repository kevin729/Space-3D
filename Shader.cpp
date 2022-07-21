#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include "Engine.h"
#include <iostream>
#include <fstream>
#include "string";
#include <sstream>;

std::vector<Shader> shaders;

void validate(int shader) {
	int result;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(shader, length, &length, message);
		std::cout << "Compiling debug...";
		std::cout << message;

		glDeleteShader(shader);
	}
}

void entityShade(std::string* vertexPath, std::string* fragmentPath) {
	std::stringstream ss[2];

	std::ifstream vertexStream(*vertexPath);
	std::string vertexline;
	while (getline(vertexStream, vertexline))
	{
		ss[0] << vertexline << '\n';
	}

	std::ifstream fragmentStream(*fragmentPath);
	std::string fragmentline;
	while (getline(fragmentStream, fragmentline))
	{
		ss[1] << fragmentline << '\n';
	}

	std::string vertex = ss[0].str();
	std::string fragment = ss[1].str();

	const char* vertexString = vertex.c_str();
	const char* fragmentString = fragment.c_str();

	unsigned int program = glCreateProgram();

	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexString, nullptr);
	glCompileShader(vertexShader);

	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentString, nullptr);
	glCompileShader(fragmentShader);

	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);
	glValidateProgram(program);

	validate(vertexShader);
	validate(fragmentShader);

	Shader shader = Shader();
	shader.program = program;
	shader.vertexLocation = glGetAttribLocation(program, "vertex");
	shader.textureCoLocation = glGetAttribLocation(program, "textureCo");
	shader.normalLocation = glGetAttribLocation(program, "normal");

	shaders.push_back(shader);
}

void shade()
{	
	std::string vertexFile = "vertex.shader";
	std::string fragmentFile = "fragment.shader";
	entityShade(&vertexFile, &fragmentFile);
}

std::vector<Shader> getShaders()
{
	return shaders;
}
