#pragma once
#include <vector>;

struct Model {
	unsigned int vertexBuffer;
	int textureCoBuffer;
	int normalBuffer;
	int indicesBuffer;
	int indicesLength;
};

struct Shader {
	unsigned int program;
	unsigned int vertexLocation;
	unsigned int textureCoLocation;
	unsigned int normalLocation;
};

std::vector<Model> getEntities();
std::vector<Shader> getShaders();

int display();
void load();
void shade();
void render();