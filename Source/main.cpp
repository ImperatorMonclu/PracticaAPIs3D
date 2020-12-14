/**
 * @file main.cpp
 * @author ImperatorMonclu (maurogarciamonclu@gmail.com)
 * @brief 
 * @version 0.1.0
 * @date 14-12-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "GLRender.h"
#include "ProgramManager.h"
#include "TriangleRot.h"
#include <cstring>
#include <iostream>
#include "GLFW/glfw3.h"
#include "glm/gtx/string_cast.hpp"

#define WINDOW_NAME "APIS3D"
#define FULLSCREEN false
#if FULLSCREEN
#define MONITOR 1
#else
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#endif

/**
 * @brief Inicializa la extensión GLEW y activa unos estados
 * 
 * @return true 
 * @return false 
 */
bool init()
{
    if (glewInit() != GLEW_OK) /**< Comprueba si puede iniciar GLEW */
    {
        return false;
    }
    glEnable(GL_DEPTH_TEST);   /**< Activa el estado GL_DEPTH_TEST */
    glEnable(GL_SCISSOR_TEST); /**< Activa el estado GL_SCISSOR_TEST */
    return true;
}

/**
 * @brief Proceso principal
 * 
 * @return 0 si ha terminado con éxito
 * @return -1 si ha terminado con errores
 */
int main(int, char **)
{
    int monitorID = 1;
    int screenWidth = SCREEN_WIDTH;
    int screenHeight = SCREEN_HEIGHT;
    GLFWmonitor *monitor = nullptr;

#if FULLSCREEN
    monitorID = MONITOR;
    monitor = *glfwGetMonitors(&monitorID);
    glfwGetMonitorPhysicalSize(monitor, &screenWidth, &screenHeight);
#endif

    if (glfwInit() != GLFW_TRUE) /**< Comprueba si puede iniciar GLFW */
    {
        return -1;
    }
    atexit(glfwTerminate);

    GLFWwindow *window = glfwCreateWindow(screenWidth, screenHeight, WINDOW_NAME, monitor, nullptr);
    if (!window) /**< Comprueba si la ventana se ha creado exitosamente */
    {
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!init())
    {
        return -1;
    }

    glClearColor(0, 0, 0, 1);

    GLSLShader *shader = new GLSLShader("Configuration/Shader.vert", "Configuration/Shader.frag");

    if (strcmp(shader->getError(), "") != 0)
    {
        std::cout << shader->getError() << std::endl;
    }

    shader->use();

    /*
Por el momento, la clase “GLRender” dejará fija las posiciones de la cámara y el tipo de
perspectiva usada en su constructor por defecto. Debemos crear una matriz de proyección
con perspectiva, y una matriz vista que coloque la cámara en 0, 0, 6 mirando hacia el origen
de la escena.
Vamos a pintar un total de 9 triángulos (todos utilizando el mismo buffer), ordenados en tres
filas (en las posiciones Z 0, -3, -6 respectivamente), con tres triángulos en cada fila (en las
posiciones X -3, 0 y 3 respectivamente). Antes del pintado, borraremos los buffers de color y
profundidad.
Cada uno de los triángulos rotará sobre su eje Y a una velocidad de 32 grados por segundo.
La matriz MVP debe ser calculada y pasada al shader antes del pintado de cada objeto.

*/

    GLRender *render = new GLRender();

    ProgramManager::getInstance().setMeshID(0);
    std::cout << std::to_string(ProgramManager::getInstance().getMeshID()) << std::endl;
    TriangleRot *triangle = new TriangleRot();
    triangle->setGLSLShader(shader);
    render->setupObj(triangle);
    ProgramManager::getInstance().setMeshID(ProgramManager::getInstance().getMeshID() + 1);
    std::cout << std::to_string(ProgramManager::getInstance().getMeshID()) << std::endl;

    float radiansRot = 0.0f;

    float lastTime = static_cast<float>(glfwGetTime());

    while (!glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_Q))
    {
        float newTime = static_cast<float>(glfwGetTime());
        float deltaTime = newTime - lastTime;
        lastTime = newTime;

        glfwGetWindowSize(window, &screenWidth, &screenHeight);

        glViewport(0, 0, screenWidth, screenHeight);
        glScissor(0, 0, screenWidth, screenHeight);

        //triangle->step();

        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        radiansRot += (glm::radians(32.0f) * deltaTime);

        render->drawObject(triangle);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}
