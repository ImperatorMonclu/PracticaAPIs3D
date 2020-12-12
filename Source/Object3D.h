#pragma once
#include "Mesh3D.h"
#include "GLSLShader.h"

class Object3D
{
private:
    //Posición de nuestro objeto en coordenadas 3D
    glm::vec4 pos;

    //Tamaño de nuestro objeto en coordenadas 3D
    glm::vec4 size;

    //Ángulo de rotación de nuestro objeto en cada uno de los ejes
    glm::vec4 rot;

    //Matriz “modelo” de este objeto.
    glm::mat4x4 modelMtx;

    // malla 3d de este objeto
    Mesh3D *mesh;

    //Shader para dibujar este objeto
    GLSLShader *shader;

public:
    //Constructor por defecto del objeto
    Object3D();

    //Método virtual, implementado por los objetos que hereden de esta clase
    virtual void step() = 0;

    //Métodos para inicializar/acceder a la malla
    void setMesh(Mesh3D *mesh);

    Mesh3D *getMesh();

    //Métodos para inicializar/acceder al shader del objeto
    void setGLSLShader(GLSLShader *shader);

    GLSLShader *getGLSLShader();

    //métodos para actualizar y acceder a la matriz modelo de este objeto
    void computeModelMtx();

    glm::mat4x4 getModelMtx();

    void setPos(glm::vec3 pos);

    glm::vec3 getPos();

    void setRot(glm::vec3 rot);

    glm::vec3 getRot();

    void setSize(glm::vec3 size);

    glm::vec3 getSize();
};
