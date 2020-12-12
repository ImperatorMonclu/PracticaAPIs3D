#include "TriangleRot.h"

TriangleRot::TriangleRot()
{
    Mesh3D *mesh = new Mesh3D();

    vertex_t v1;
    v1.pos = glm::vec3(0.0f, 1.0f, 0.0f);
    vertex_t v2;
    v2.pos = glm::vec3(-1.0f, -1.0f, 0.0f);
    vertex_t v3;
    v3.pos = glm::vec3(1.0f, -1.0f, 0.0f);

    mesh->addVertex(v1);
    mesh->addVertex(v2);
    mesh->addVertex(v3);

    mesh->addTriangleIdx(0, 1, 2);

    setMesh(mesh);
}

void TriangleRot::step()
{
    /////////////////actualizará su atributo de rotaciones, haciéndolo girar sobre el eje “Y”.
}
