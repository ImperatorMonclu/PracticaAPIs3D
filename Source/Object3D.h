/**
 * @file Object3D.h
 * @author ImperatorMonclu (maurogarciamonclu@gmail.com)
 * @brief 
 * @version 0.1.0
 * @date 14-12-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once
#include "Mesh3D.h"
#include "GLSLShader.h"

/**
 * @brief Objeto abstracto básico renderizable
 * 
 */
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
    /**
     * @brief Construct a new Object 3D object
     * 
     */
    Object3D();

    //Método virtual, implementado por los objetos que hereden de esta clase
    /**
     * @brief Acción del objeto que se construye en clases hijas
     * 
     */
    virtual void step() = 0;

    //Métodos para inicializar/acceder a la malla
    /**
     * @brief Set the Mesh object
     * 
     * @param mesh nueva malla 3D del objeto 3D
     */
    void setMesh(Mesh3D *mesh);

    /**
     * @brief Get the Mesh object
     * 
     * @return Mesh3D* malla 3D del objeto 3D
     */
    Mesh3D *getMesh();

    //Métodos para inicializar/acceder al shader del objeto
    /**
     * @brief Set the GLSL Shader object
     * 
     * @param shader nuevo shader del objeto 3D
     */
    void setGLSLShader(GLSLShader *shader);

    /**
     * @brief Get the GLSL Shader object
     * 
     * @return GLSLShader* shader del objeto 3D
     */
    GLSLShader *getGLSLShader();

    //métodos para actualizar y acceder a la matriz modelo de este objeto 3D
    /**
     * @brief Actualiza la matriz modelo del objeto 3D
     * 
     */
    void computeModelMtx();

    /**
     * @brief Get the Model Mtx object
     * 
     * @return glm::mat4x4 matriz modelo del objeto 3D
     */
    glm::mat4x4 getModelMtx();

    /**
     * @brief Set the Pos object
     * 
     * @param pos nueva posición del objeto 3D
     */
    void setPos(glm::vec3 pos);

    /**
     * @brief Get the Pos object
     * 
     * @return glm::vec3 posición del objeto 3D
     */
    glm::vec3 getPos();

    /**
     * @brief Set the Rot object
     * 
     * @param rot nueva rotación del objeto 3D
     */
    void setRot(glm::vec3 rot);

    /**
     * @brief Get the Rot object
     * 
     * @return glm::vec3 rotación del objeto 3D
     */
    glm::vec3 getRot();

    /**
     * @brief Set the Size object
     * 
     * @param size nuevo tamaño del objeto 3D
     */
    void setSize(glm::vec3 size);

    /**
     * @brief Get the Size object
     * 
     * @return glm::vec3 tamaño del objeto 3D
     */
    glm::vec3 getSize();
};
