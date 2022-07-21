#pragma once
#include <vector>;

struct Model {
	unsigned int vertexBuffer;
	int textureCoBuffer;
	int normalBuffer;
	int indicesBuffer;
};


std::vector<Model> getEntities();
int display();
void load();
void shade();
void render();