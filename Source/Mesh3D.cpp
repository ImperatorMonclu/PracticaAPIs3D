#include "Mesh3D.h"
#include "GLSLShader.h"
#include "ProgramManager.h"

Mesh3D::Mesh3D()
{
    meshID = ProgramManager::getInstance().getMeshID();
    colorRGB = glm::vec3(1.0f);
    vVertList = new std::vector<struct vertex_t>();
    vIdxList = new std::vector<glm::int32>();
}

glm::uint32 Mesh3D::getMeshID()
{
    return meshID;
}

void Mesh3D::addVertex(struct vertex_t vertex)
{
    vVertList->push_back(vertex);
}

void Mesh3D::addTriangleIdx(glm::int32 v1, glm::int32 v2, glm::int32 v3)
{
    vIdxList->push_back(v1);
    vIdxList->push_back(v3);
    vIdxList->push_back(v2);
}

std::vector<struct vertex_t> *Mesh3D::getVertList()
{
    return vVertList;
}

std::vector<glm::int32> *Mesh3D::getTriangleIdxList()
{
    return vIdxList;
}

glm::vec3 Mesh3D::getColorRGB()
{
    return colorRGB;
}

void Mesh3D::setColorRGB(float r, float g, float b)
{
    colorRGB = glm::vec3(r, b, g);
}
