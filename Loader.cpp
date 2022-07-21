#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "Engine.h";

std::vector<Model> entities;
std::vector<Model>::iterator entitiesIt;

std::vector<Model> getEntities() {
	return entities;
}

void load()
{
	const int vertices[] = {0,1,0, -1,-1,0, 1,-1,0}; //verticesVBO
	const int textureCo[] = {0.5,1, 0,0, 1,0}; //textureCoVBO
	const int normals[] = {0,0,1, 0,0,1, 0,0,1}; //normalsVBO
	const int indices[] = { 0, 1, 2, 0 }; //normalsVBO

	unsigned int verticesBuffer;
	glGenBuffers(1, &verticesBuffer);

	std::cout << verticesBuffer;

	/*glBindBuffer(GL_ARRAY_BUFFER, verticesBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices) * sizeof(float), &vertices, GL_STATIC_DRAW);


	unsigned int textureCoBuffer;
	glGenBuffers(1, &textureCoBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, textureCoBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(textureCo) * sizeof(float), &textureCo, GL_STATIC_DRAW);


	unsigned int normalsBuffer;
	glGenBuffers(1, &normalsBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalsBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(normals) * sizeof(float), &normals, GL_STATIC_DRAW);

	unsigned int indicesBuffer;
	glGenBuffers(1, &indicesBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),  &indices, GL_STATIC_DRAW);

	Model model;
	model.vertexBuffer = verticesBuffer;
	model.textureCoBuffer = textureCoBuffer;
	model.normalBuffer = normalsBuffer;
	model.indicesBuffer = indicesBuffer;

	entitiesIt = entities.begin();
	entities.insert(entitiesIt, model);*/
}
