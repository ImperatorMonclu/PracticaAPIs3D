/**
 * @file TriangleRot.cpp
 * @author ImperatorMonclu (maurogarciamonclu@gmail.com)
 * @brief 
 * @version 0.1.0
 * @date 14-12-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "TriangleRot.h"

TriangleRot::TriangleRot()
{
    Mesh3D *mesh = new Mesh3D();

    vertex_t v1;
    v1.pos = glm::vec4(0.0f, 0.5f, 0.0f, 1.0f);
    vertex_t v2;
    v2.pos = glm::vec4(-0.5f, 0.0f, 0.0f, 1.0f);
    vertex_t v3;
    v3.pos = glm::vec4(0.5f, 0.0f, 0.0f, 1.0f);

    mesh->addVertex(v1);
    mesh->addVertex(v2);
    mesh->addVertex(v3);

    mesh->addTriangleIdx(0, 2, 1);

    setMesh(mesh);
}

void TriangleRot::step()
{
    setRot(getRot() + glm::vec3(0.0f, 0.01f, 0.0f));
}
