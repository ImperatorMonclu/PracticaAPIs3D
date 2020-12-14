/**
 * @file GLRender.h
 * @author ImperatorMonclu (maurogarciamonclu@gmail.com)
 * @brief 
 * @version 0.1.0
 * @date 14-12-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once
#include "Object3D.h"
#include <map>

/**
 * @brief Inizializa OpenGL y dibuja objetos 3D
 * 
 */
class GLRender
{
private:
    //estructura que almacena los datos de una malla cargada anteriormente en openGL
    /**
     * @brief Atributos de una malla previamente cargada
     * 
     */
    typedef struct glMeshAttribs_t
    {
        /*@{*/
        GLuint bufferID;      /**< vertex buffer ID */
        GLuint indexArrayID;  /**< index buffer */
        GLuint vertexArrayID; /**< vertex array (objeto) */
        /*@}*/
    } glMeshAttribs_t;

    //Lista de mallas ya cargadas en memoria de GPU. Almacena sus identificadores para
    // poder usarlos en el shader cuando se dibuje
    std::map<glm::uint32, glMeshAttribs_t> vMeshIds;

public:
    //Constructor por defecto, inicializa OpenGL y las librerías extra necesarias
    /**
     * @brief Construct a new GL Render object
     * 
     */
    GLRender();

    //Método que realiza las operaciones necesarias para cargar la malla 3d del objeto en
    //memoria de GPU. En concreto, comprobará si no se ha cargado anteriormente su
    /**
     * @brief Carga la malla 3D de un objeto en memoria
     * 
     * @param obj objeto 3D a cargar
     */
    void setupObj(Object3D *obj);

    //Método para dibujar por pantalla un objeto 3D. En este caso, accederá a los atributos
    //necesarios del objeto y a su shader para poder dibujarlos en pantalla
    /**
     * @brief Dibuja por pantalla un objeto
     * 
     * @param obj objeto 3D a dibujar
     */
    void drawObject(Object3D *obj);
};
