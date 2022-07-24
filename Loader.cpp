#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "Engine.h"
#include <Magick++.h>
#include <stb/stb_image.h>

std::vector<Entity> entities;
std::vector<Entity> getEntities() {
	return entities;
}

void loadTexture(const char* path, unsigned int* textureBuffer) {
	glGenTextures(1, textureBuffer);
	glBindTexture(GL_TEXTURE_2D, *textureBuffer);
	glActiveTexture(GL_TEXTURE0);

	int w, h, numColCh;
	unsigned char* bytes = stbi_load("ship.png", &w, &h, &numColCh, 0);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);

	stbi_image_free(bytes);
	glBindBuffer(GL_TEXTURE_2D, 0);
}

void load() {
	const float vertices[18] = { -1.0f,1.0f,0.0f,
								 -1.0f,-1.0f,0.0f,
								  1.0f,-1.0f,0.0f,
								  -1.0f,1.0f,0.0f,
								  1.0f,-1.0f,0.0f,
								  1.0f,1.0f,0.0f
								}; //verticesVBO
	const float textureCo[12] = { 0.0f,0.0f, 0.0f,1.0f, 1.0f,1.0f, 0.0f,0.0f, 1.0f,1.0f, 1.0f,0.0f }; //textureCoVBO
	const float normals[12] = { 0.0f,0.0f,1.0f, 0.0f,0.0f,1.0f, 0.0f,0.0f,1.0f, 0.0f,0.0f,1.0f }; //normalsVBO
	const int indices[4] = {}; //indices

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

	unsigned int textureBuffer;
	loadTexture("ship.png", &textureBuffer);

	Entity model = Entity();
	model.vertexBuffer = verticesBuffer;
	model.textureCoBuffer = textureCoBuffer;
	model.normalBuffer = normalsBuffer;
	model.indicesBuffer = indicesBuffer;
	model.indicesLength = sizeof(indices);
	model.textureBuffer = textureBuffer;

	auto it = entities.begin();
	entities.insert(it, model);
}
