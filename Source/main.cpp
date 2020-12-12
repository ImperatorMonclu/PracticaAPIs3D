#include "GLRender.h"
#include "ProgramManager.h"
#include "TriangleRot.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
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

std::string readFile(const char *filename)
{
    std::ifstream f(filename, std::ios_base::binary);
    std::stringstream ss;
    ss << f.rdbuf();
    return ss.str();
}

int main(int, char **)
{
    int monitorID = 1;
    int screenWidth = 1;
    int screenHeight = 1;

    if (glfwInit() != GLFW_TRUE)
    {
        return -1;
    }
    atexit(glfwTerminate);

#if FULLSCREEN
    monitorID = MONITOR;
    GLFWmonitor *monitor = *glfwGetMonitors(&monitorID);
    glfwGetMonitorPhysicalSize(monitor, &screenWidth, &screenHeight);
    GLFWwindow *window = glfwCreateWindow(screenWidth, screenHeight, WINDOW_NAME, monitor, nullptr);
#else
    GLFWwindow *window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME, nullptr, nullptr);
#endif
    if (!window)
    {
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (glewInit())
    {
        return -1;
    }
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_SCISSOR_TEST);

    GLSLShader *shader = new GLSLShader(readFile("Configuration/Shader.vert"), readFile("Configuration/Shader.frag"));

    if (strcmp(shader->getError(), "") != 0)
    {
        std::cout << shader->getError() << std::endl;
        return -1;
    }

    shader->use();

    GLRender *render = new GLRender();

    ProgramManager::getInstance().setMeshID(0);
    std::cout << std::to_string(ProgramManager::getInstance().getMeshID()) << std::endl;
    TriangleRot *tri = new TriangleRot();
    tri->setGLSLShader(shader);
    render->setupObj(tri);
    ProgramManager::getInstance().setMeshID(ProgramManager::getInstance().getMeshID()+1);
    std::cout << std::to_string(ProgramManager::getInstance().getMeshID()) << std::endl;

    float radiansRot = 0.0f;

    float lastTime = static_cast<float>(glfwGetTime());

    while (!glfwWindowShouldClose(window) && !glfwGetKey(window, GLFW_KEY_ESCAPE))
    {
        float newTime = static_cast<float>(glfwGetTime());
        float deltaTime = newTime - lastTime;
        lastTime = newTime;

        glfwGetWindowSize(window, &screenWidth, &screenHeight);

        glViewport(0, 0, screenWidth, screenHeight);
        glScissor(0, 0, screenWidth, screenHeight);
        glClearColor(0, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        radiansRot += (glm::radians(32.0f) * deltaTime);

        glm::mat4x4 mvpMatrix;
        int matrixLocation = shader->getLocation("mvpMatrix");

        glm::mat4x4 projectionMatrix = glm::perspective(45.0f, static_cast<float>(screenWidth) / static_cast<float>(screenHeight), 0.1f, 100.0f);

        glm::mat4x4 viewMatrix = glm::lookAt(glm::vec3(0.0f, 0.0f, 6.0f),
                                             glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

        glm::mat4x4 viewProjectionMatrix = projectionMatrix * viewMatrix;

        glm::mat4x4 rotationMatrix = glm::rotate(glm::mat4x4(), radiansRot, glm::vec3(0.0f, 1.0f, 0.0f));

        for (int x = -3; x <= 3; x += 3)
        {
            for (int z = 0; z >= -6; z -= 3)
            {
                glm::mat4x4 translationMatrix = glm::translate(glm::mat4x4(), glm::vec3(static_cast<float>(x), 0.0f, static_cast<float>(z)));

                mvpMatrix = translationMatrix * rotationMatrix;

                mvpMatrix = viewProjectionMatrix * mvpMatrix;

                shader->setMatrix(matrixLocation, mvpMatrix);

                render->drawObject(tri);
            }
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}
