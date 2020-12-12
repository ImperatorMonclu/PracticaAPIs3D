#pragma once
#include <glm/glm.hpp>
#include <map>
#include <string>

class GLSLShader
{
public:
    //identificador del programa
    glm::uint32 programID;
    //lista con las variables uniform que puede utilizar este shader
    std::map<std::string, glm::uint32> vShaderAttribs;

private:
    char error[1024];

public:
    ~GLSLShader();

    //Constructor de clase, recibe por parámetros el nombre de los ficheros que se
    // compilarán para cargar el shader
    /**
     * @brief Construct a new GLSLShader object
     * 
     * @param vertexPrg 
     * @param fragPrg 
     */
    GLSLShader(std::string vertexPrg, std::string fragPrg);

    // Devuelve el identificador de OpenGL del programa
    /**
     * @brief Get the Id object
     * 
     * @return uint32_t 
     */
    uint32_t getId();

    // Obtiene el mensaje de error generado al compilar o enlazar
    const char *getError(); //void

    // Activa el uso de este programa
    void use();

    // Activa la escritura de las variables attribute,
    // y especifica su formato
    void setupAttribs();

    // Obtiene la localización de una variable uniform
    /**
     * @brief Obtiene la localización de una variable específica del shader por su nombre
     * 
     * @param name nombre de la variable en el shader por una cadena de texto
     * @return glm::uint32 posición de la variable en el shader por un entero
     */
    glm::uint32 getLocation(std::string name);

    // Da valor a una variable uniform
    /**
     * @brief Modifica una variable del shader de tipo entero a partir de su localización
     * 
     * @param loc 
     * @param val 
     */
    void setInt(glm::uint32 loc, int val);

    void setFloat(glm::uint32 loc, float val);

    void setVec3(glm::uint32 loc, const glm::vec3 &vec);

    void setVec4(glm::uint32 loc, const glm::vec4 &vec); //void

    void setMatrix(glm::uint32 loc, const glm::mat4 &matrix); //glUniformMatrix
};
