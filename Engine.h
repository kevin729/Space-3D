#pragma once
#include <vector>;
#include <string>

unsigned int getScreenWidth();
unsigned int getScreenHeight();

struct Entity {
	unsigned int vertexBuffer;
	unsigned int textureCoBuffer;
	unsigned int normalBuffer;
	unsigned int indicesBuffer;
	unsigned int indicesLength;
	unsigned int textureBuffer;
	unsigned int overlayTextureBuffer;

	float position[3] = {0, 0, 0};
	float rotation[3] = {0, 0, 0};
	float scale[3] = {1, 1, 1};
};

struct Shader {
	unsigned int program;
	unsigned int vertexLocation;
	unsigned int textureCoLocation;
	unsigned int normalLocation;
	unsigned int texture1Location;
	unsigned int texture2Location;
	unsigned int transformLocation;
	unsigned int viewLocation;
	unsigned int projectionLocation;
};

std::vector<Entity> getEntities();
std::vector<Shader> getShaders();

int display();
void load(const char* texture1Path, const char* texture2Path);
void shade();
void render();
