#include <iostream>
#include <Gl/glew.h>
#include <GLFW/glfw3.h>

#include "Mesh.h"
#include "Shader.h"

#define LOG(X) std::cout << X << "\n";
#define WIDTH 400
#define HEIGHT 300

int main()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit()) return -1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WIDTH, HEIGHT, "Hola Mundo!", NULL, NULL);
    if (!window)
    {
        std::cout << "Falló en crear la ventana GLFW" << "\n";
        glfwTerminate();
        return -1;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    if (glewInit() != GLEW_OK) return -1;
    std::cout << "OpenGL iniciado correctamente\nVersion: " << glGetString(GL_VERSION) << "\n";

    //while loop
    while (!glfwWindowShouldClose(window))
    {




    }
}