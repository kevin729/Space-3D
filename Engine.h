#pragma once
#include <vector>;
#include <string>

unsigned int getScreenWidth();
unsigned int getScreenHeight();

struct Camera {
	float x = -1, y = 0, z = 0;
};

struct Entity {
	unsigned int vertexBuffer;
	unsigned int textureCoBuffer;
	unsigned int normalBuffer;
	unsigned int indicesBuffer;
	unsigned int indicesLength;
	unsigned int textureBuffer;
	unsigned int overlayTextureBuffer;

	float x = 0;
	float y = 0;
	float z = 0;
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

std::vector<Entity*> getEntities();
std::vector<Shader> getShaders();

int display();
void load(const char* texture1Path, const char* texture2Path, Entity& entity);
void shade();
Camera* getCamera();
void update();
void render();

Entity getPlayer();
