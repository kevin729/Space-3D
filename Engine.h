#pragma once
#include <vector>;
#include <string>

struct Entity {
	unsigned int vertexBuffer;
	unsigned int textureCoBuffer;
	unsigned int normalBuffer;
	unsigned int indicesBuffer;
	unsigned int indicesLength;
	unsigned int textureBuffer;
};

struct Shader {
	unsigned int program;
	unsigned int vertexLocation;
	unsigned int textureCoLocation;
	unsigned int normalLocation;
};

std::vector<Entity> getEntities();
std::vector<Shader> getShaders();

int display();
void load();
void shade();
void render();