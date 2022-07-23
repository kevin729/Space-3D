#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "Engine.h";

std::vector<Model> entities;
std::vector<Model> getEntities() {
	return entities;
}

void load() {
	const float vertices[9] = {0.0f,1.0f,0.0f, -1.0f,-1.0f,0.0f, 1.0f,-1.0f,0.0f}; //verticesVBO
	const float textureCo[6] = {0.5f,1.0f, 0.0f,0.0f, 1.0f,0.0f}; //textureCoVBO
	const float normals[9] = {0.0f,0.0f,1.0f, 0.0f,0.0f,1.0f, 0.0f,0.0f,1.0f}; //normalsVBO
	const int indices[3] = {0, 1, 2}; //indices

	unsigned int verticesBuffer;
	glGenBuffers(1, &verticesBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, verticesBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	unsigned int textureCoBuffer;
	glGenBuffers(1, &textureCoBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, textureCoBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(textureCo), textureCo, GL_STATIC_DRAW);

	unsigned int normalsBuffer;
	glGenBuffers(1, &normalsBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalsBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normals), normals, GL_STATIC_DRAW);

	unsigned int indicesBuffer;
	glGenBuffers(1, &indicesBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	Model model = Model();
	model.vertexBuffer = verticesBuffer;
	model.textureCoBuffer = textureCoBuffer;
	model.normalBuffer = normalsBuffer;
	model.indicesBuffer = indicesBuffer;

	auto it = entities.begin();
	entities.insert(it, model);

	
}
