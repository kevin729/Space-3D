#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <GL/GL.h>
#include <GL/freeglut.h>

#include "Engine.h";
#include "wtypes.h";
#include <iostream>;

unsigned int width;
unsigned int height;
Camera camera = Camera();
Entity space = Entity();
Entity player = Entity();
Entity enemy = Entity();

void follow(Entity e);
void keyboardCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);

Keyboard keyboard;

Keyboard* getKeyboard() {
	return &keyboard;
}

Entity* getPlayer() {
	return &player;
}

unsigned int getScreenWidth() {
	return width;
}

unsigned int getScreenHeight() {
	return height;
}

Camera* getCamera() {
	return &camera;
}

GLFWwindow* loadWindow() {

	RECT rect;
	const HWND desktop = GetDesktopWindow();
	GetWindowRect(desktop, &rect);

	width = rect.right;
	height = rect.bottom;

	return glfwCreateWindow(rect.right, rect.bottom, "Star Warrior", NULL, NULL);
}

int display()
{
	if (!glfwInit())
		return -1;

	GLFWwindow* window = loadWindow();
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glewInit();
	glfwSetKeyCallback(window, keyboardCallBack);
	keyboard = Keyboard();

	shade();

	//loads the texture and pushes the memory address of the entity 
	load("space.png", "space.png", space);
	load("ship.png", "ship.png", player);
	load("ship.png", "rock.png", enemy);

	space.scale[0] = 10;
	space.scale[1] = 10;
	space.z = -5;

	player.scale[0] = 0.2;
	player.scale[1] = 0.2;
	player.scale[2] = 0.2;
	player.z = 5;

	enemy.x = 1;
	enemy.z = 5;

	Shader shader = getShaders()[0];

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		if (player.z <= -5)
		{
			player.z = -5;
			enemy.z = -5;
			follow(player);
		}
		else
		{
			player.z -= 0.01;
			player.rotation[0] += 0.05;
			player.rotation[2] += 0.05;

			enemy.z -= 0.01;
			enemy.rotation[0] += 0.05;
			enemy.rotation[2] += 0.05;
		}


		update();
		updatePlayer(player, keyboard);
		render();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

void follow(Entity e)
{
	camera.x = e.x;
	camera.y = e.y;
}

void keyboardCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) {
		keyboard.keys[key] = true;
	}
	else if (action == GLFW_RELEASE) {
		keyboard.keys[key] = false;
	}
	
}