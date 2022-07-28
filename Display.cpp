#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include "Engine.h";
#include "wtypes.h";
#include <iostream>;

unsigned int width;
unsigned int height;

unsigned int getScreenWidth() {
    return width;
}

unsigned int getScreenHeight() {
    return height;
}

GLFWwindow* loadWindow() {

    RECT rect;
    const HWND desktop = GetDesktopWindow();
    GetWindowRect(desktop, &rect);

    width = rect.right;
    height = rect.bottom;

    return glfwCreateWindow(rect.right, rect.bottom, "3D World", NULL, NULL);
}

int display(void)
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
    
    load("space.png", "space.png");
    load("ship.png", "rock.png");
    
    Shader shader = getShaders()[0];

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}