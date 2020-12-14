/**
 * @file GLRender.cpp
 * @author ImperatorMonclu (maurogarciamonclu@gmail.com)
 * @brief 
 * @version 0.1.0
 * @date 14-12-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "GLRender.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"

GLRender::GLRender()
{
}

void GLRender::setupObj(Object3D *obj)
{
    glMeshAttribs_t meshAttribs;

    glGenVertexArrays(1, &meshAttribs.bufferID);
    glGenBuffers(1, &meshAttribs.vertexArrayID);
    glGenBuffers(1, &meshAttribs.indexArrayID);

    glBindVertexArray(meshAttribs.bufferID);

    std::vector<struct vertex_t> *vertexes = obj->getMesh()->getVertList();
    glBindBuffer(GL_ARRAY_BUFFER, meshAttribs.vertexArrayID);
    glBufferData(GL_ARRAY_BUFFER, vertexes->size() * sizeof(struct vertex_t), vertexes->data(), GL_STATIC_DRAW);

    std::vector<glm::int32> *indexes = obj->getMesh()->getTriangleIdxList();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, meshAttribs.indexArrayID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexes->size() * sizeof(glm::int32), indexes->data(), GL_STATIC_DRAW);

    vMeshIds.insert({obj->getMesh()->getMeshID(), meshAttribs});
}

void GLRender::drawObject(Object3D *obj)
{
    glm::int32 meshID = obj->getMesh()->getMeshID();

    glBindVertexArray(vMeshIds[meshID].bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, vMeshIds[meshID].vertexArrayID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vMeshIds[meshID].indexArrayID);

    GLSLShader *shader = obj->getGLSLShader();

    shader->use();

    shader->setupAttribs();

    shader->setMatrix(shader->getLocation("mvpMatrix"), glm::perspective(45.0f, 1280.0f / 720.0f, 0.1f, 100.0f) * glm::lookAt(glm::vec3(0.0f, 0.0f, 6.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)) * glm::mat4(1.0f) * obj->getModelMtx());

    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
}
