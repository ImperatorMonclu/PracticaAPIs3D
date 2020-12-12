#include "Object3D.h"
#include <glm/gtc/matrix_transform.hpp>
#include <cmath>

#define _USE_MATH_DEFINES

Object3D::Object3D()
{
    pos = glm::vec4(0.0f);
    size = glm::vec4(1.0f);
    rot = glm::vec4(0.0f);
    modelMtx = glm::mat4x4(1.0f);
    mesh = nullptr;
    shader = nullptr;
}

void Object3D::setMesh(Mesh3D *nMesh)
{
    mesh = nMesh;
}

Mesh3D *Object3D::getMesh()
{
    return mesh;
}

void Object3D::setGLSLShader(GLSLShader *nShader)
{
    shader = nShader;
}

GLSLShader *Object3D::getGLSLShader()
{
    return shader;
}

void Object3D::computeModelMtx()
{
    ////////////////////////////
    modelMtx = glm::rotate(glm::translate(glm::scale(glm::mat4x4(1.0f), getSize()), getPos()), (float)M_PI, getRot());
}

glm::mat4x4 Object3D::getModelMtx()
{
    return modelMtx;
}

void Object3D::setPos(glm::vec3 nPos)
{
    pos = glm::vec4(nPos.x, nPos.y, nPos.z, 1.0f);
}

glm::vec3 Object3D::getPos()
{
    return glm::vec3(pos.x, pos.y, pos.z);
}

void Object3D::setRot(glm::vec3 nRot)
{
    rot = glm::vec4(nRot.x, nRot.y, nRot.z, 1.0f);
}

glm::vec3 Object3D::getRot()
{
    return glm::vec3(rot.x, rot.y, rot.z);
}

void Object3D::setSize(glm::vec3 nSize)
{
    size = glm::vec4(nSize.x, nSize.y, nSize.z, 1.0f);
}

glm::vec3 Object3D::getSize()
{
    return glm::vec3(size.x, size.y, size.z);
}
