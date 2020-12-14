/**
 * @file GLSLShader.h
 * @author ImperatorMonclu (maurogarciamonclu@gmail.com)
 * @brief 
 * @version 0.1.0
 * @date 14-12-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once
#include <iostream>
#include <map>
#include "GL/glew.h"
#include "glm/glm.hpp"

/**
 * @brief Shader de GLSL.
 * Permite modificar las variables uniformes del shader
 * 
 */
class GLSLShader
{
public:
    //identificador del programa
    glm::uint32 programID;

    //lista con las variables uniform que puede utilizar este shader
    std::map<std::string, glm::uint32> vShaderAttribs;

private:
    char *error;

public:
    //Constructor de clase, recibe por parámetros el nombre de los ficheros que se
    // compilarán para cargar el shader
    /**
     * @brief Construct a new GLSLShader object
     * 
     * @param vertexPrg dirección del fichero para el shader de vértices
     * @param fragPrg dirección del fichero para el shader de fragmentos
     */
    GLSLShader(std::string vertexPrg, std::string fragPrg);

    // Devuelve el identificador de OpenGL del programa
    /**
     * @brief Get the Id object
     * 
     * @return glm::uint32 identificador del programa
     */
    glm::uint32 getId();

    // Obtiene el mensaje de error generado al compilar o enlazar
    /**
     * @brief Get the Error object
     * 
     * @return const char* 
     */
    const char *getError();

    // Activa el uso de este programa
    /**
     * @brief Activa el programa
     * 
     */
    void use();

    // Activa la escritura de las variables attribute,
    // y especifica su formato
    /**
     * @brief Activa la escritura de los atributos del shader
     * 
     */
    void setupAttribs();

    // Obtiene la localización de una variable uniform
    /**
     * @brief Obtiene la localización de una variable específica del shader por su nombre
     * 
     * @param name nombre de la variable en el shader
     * @return glm::uint32 posición de la variable en el shader
     */
    glm::uint32 getLocation(std::string name);

    // Da valor a una variable uniform
    /**
     * @brief Modifica una variable del shader de tipo entero a partir de su localización
     * 
     * @param loc posición de la variable en el shader
     * @param val valor de la variable
     */
    void setInt(glm::uint32 loc, int val);

    /**
     * @brief Modifica una variable del shader de tipo coma flotante a partir de su localización
     * 
     * @param loc posición de la variable en el shader
     * @param val valor de la variable
     */
    void setFloat(glm::uint32 loc, float val);

    /**
     * @brief Modifica una variable del shader de tipo vector de tamaño 3 a partir de su localización
     * 
     * @param loc posición de la variable en el shader
     * @param vec valor del vector
     */
    void setVec3(glm::uint32 loc, const glm::vec3 &vec);

    /**
     * @brief Modifica una variable del shader de tipo vector de tamaño 4 a partir de su localización
     * 
     * @param loc posición de la variable en el shader
     * @param vec valor del vector
     */
    void setVec4(glm::uint32 loc, const glm::vec4 &vec);

    /**
     * @brief Modifica una variable del shader de tipo matriz de tamaño 4x4 a partir de su localización
     * 
     * @param loc posición de la variable en el shader
     * @param matrix valor de la matriz
     */
    void setMatrix(glm::uint32 loc, const glm::mat4 &matrix);

private:
    /**
     * @brief Devuelve el texto leido en un fichero
     * 
     * @param filename dirección del fichero a leer
     * @return const char* contenido del fichero
     */
    const char *readFile(std::string filename);

    /**
     * @brief Compila el código del shader a partir de su tipo
     * 
     * @param code código fuente del shader
     * @param shaderType tipo de shader
     * @return int identificador del shader
     */
    int compileShader(const char *code, GLenum shaderType);
};
