#include "GLRender.h"

GLRender::GLRender()
{
    vMeshIds = {};
}

void GLRender::setupObj(Object3D *obj)
{
    glMeshAttribs_t meshAttribs;

    glGenBuffers(2, &meshAttribs.bufferID);

    std::vector<struct vertex_t> *vertexes = obj->getMesh()->getVertList();
    glBindBuffer(GL_ARRAY_BUFFER, meshAttribs.vertexArrayID);
    glBufferData(GL_ARRAY_BUFFER, vertexes->size() * sizeof(struct vertex_t), vertexes->data(), GL_STATIC_DRAW);

    std::vector<glm::int32> *indexes = obj->getMesh()->getTriangleIdxList();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, meshAttribs.indexArrayID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexes->size() * sizeof(glm::int32), indexes->data(), GL_STATIC_DRAW);

    vMeshIds.insert(std::pair<glm::uint32, glMeshAttribs_t>(obj->getMesh()->getMeshID(), meshAttribs));
}

void GLRender::drawObject(Object3D *obj)
{
    glBindBuffer(GL_ARRAY_BUFFER, vMeshIds[obj->getMesh()->getMeshID()].vertexArrayID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vMeshIds[obj->getMesh()->getMeshID()].indexArrayID);

    obj->getGLSLShader()->setupAttribs();

    glDrawElements(GL_TRIANGLES, obj->getMesh()->getTriangleIdxList()->size(), GL_UNSIGNED_SHORT, nullptr);
}
