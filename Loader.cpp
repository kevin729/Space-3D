#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "Engine.h"
#include <stb/stb_image.h>

std::vector<Entity*> entities;
std::vector<Entity*> getEntities() {
	return entities;
}

/**
* creates and binds the textureBuffer and sets the data to buffer
**/
void loadTexture(const char* path, unsigned int& textureBuffer) {
	glGenTextures(1, &textureBuffer);
	glBindTexture(GL_TEXTURE_2D, textureBuffer);

	int w, h, numColCh;
	unsigned char* bytes = stbi_load(path, &w, &h, &numColCh, 0);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, bytes);

	stbi_image_free(bytes);
	glBindBuffer(GL_TEXTURE_2D, 0);
}

/**
* loads a quad with a outline texture and a texture to apply to the quad
*/
void load(const char* texture1Path, const char* texture2Path, Entity& entity) {
	const float vertices[18] = { 
								//FRONT	
							     -1.0f,1.0f,0.0f,
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
	loadTexture(texture1Path, textureBuffer);
	unsigned int overlayTextureBuffer;
	loadTexture(texture2Path, overlayTextureBuffer);

	entity.vertexBuffer = verticesBuffer;
	entity.textureCoBuffer = textureCoBuffer;
	entity.normalBuffer = normalsBuffer;
	entity.indicesBuffer = indicesBuffer;
	entity.indicesLength = sizeof(indices);
	entity.textureBuffer = textureBuffer;
	entity.overlayTextureBuffer = overlayTextureBuffer;

	entities.push_back(&entity);
}