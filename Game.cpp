#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include "Engine.h";
#include "wtypes.h";
#include <iostream>;

unsigned int width;
unsigned int height;
Camera camera = Camera();

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

    shade();
    
    Entity space = Entity();
    Entity player = Entity();

    //loads the texture and pushes the memory address of the entity 
    load("space.png", "space.png", space);
    load("ship.png", "ship.png", player);

    space.scale[0] = 10;
    space.scale[1] = 10;
    space.z = -5;

    player.scale[0] = 0.2;
    player.scale[1] = 0.2;
    player.scale[2] = 0.2;
    player.z = -5;

    Shader shader = getShaders()[0];

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        //player.y -= 0.00001f;

        camera.x += 0.001f;

        update();
        render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}