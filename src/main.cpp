 /***********************
 * Miko³aj Noga  119246 *
 *                      *
 * Projekt z OpenGL     *
 * Biblioteki Graficzne *
 ***********************/

#include <iostream>
#include "Cube.h"
#include <GLFW/glfw3.h>

#define ERROR_MESSAGE(MESSAGE)                                \
    std::cout << MESSAGE << "\n"                              \
              << "Press enter to close application...\n";   \
    std::cin.get();

int main(void)
{
    if (glfwInit() == GLFW_FALSE)
    {
        ERROR_MESSAGE("GLFW library initialization failed.");
        return -1;
    }

    GLFWmonitor *primaryMonitor = glfwGetPrimaryMonitor();
    if (primaryMonitor == NULL)
    {
        glfwTerminate();
        ERROR_MESSAGE("Couldn't find any monitor.");
        return -1;
    }

    const GLFWvidmode* vidmode = glfwGetVideoMode(primaryMonitor);
    float windowWidth = vidmode->width;
    float windowHeight = vidmode->height;
    float xScale = windowHeight / windowWidth;

    GLFWwindow *window = glfwCreateWindow(windowWidth, windowHeight, "Biblioteki Graficzne - Mikolaj Noga | 119246", primaryMonitor, NULL);
    if (window == NULL)
    {
        glfwTerminate();
        ERROR_MESSAGE("GLFW window creation failed.");
        return -1;
    }

    glfwMakeContextCurrent(window);

    Cube cube = Cube();

    float rotation = 0.0f;
    const float rotationRate = 25.0f; // per second, in euler angle
    
    float colorProgress = 0.0f;
    const float colorProgressRate = 0.5f; // per second;
    int sign = 1;

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glEnable(GL_DEPTH_TEST);
        glScalef(xScale, 1, 1);

        float elapsedTime = (float)glfwGetTime();
        glfwSetTime(0);

        rotation += elapsedTime * rotationRate;
        while (rotation >= 360) 
        {
            rotation -= 360; 
        }
        glRotatef(rotation, 0.25f, 1, 0);

        colorProgress += elapsedTime * colorProgressRate * sign;
        if (colorProgress <= 0 || colorProgress >= 1)
        {
            sign *= -1;
            if (colorProgress <= 0)
            {
                colorProgress = 0;
            }
            else
            {
                colorProgress = 1;
            }
        }

        cube.Draw(colorProgress);

        glFlush();
        glfwSwapBuffers(window); 
        glfwPollEvents(); 
    } 

    glfwTerminate();
    return 0;
}
