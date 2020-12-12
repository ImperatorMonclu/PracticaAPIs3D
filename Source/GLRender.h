#pragma once
#include <GL/glew.h>
#include <GL/gl.h>
#include "Object3D.h"

class GLRender
{
private:
    //estructura que almacena los datos de una malla cargada anteriormente en openGL
    /**
     * @brief Estructura para los atributos de una malla previamente cargada
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
    GLRender();

    //Método que realiza las operaciones necesarias para cargar la malla 3d del objeto en
    //memoria de GPU. En concreto, comprobará si no se ha cargado anteriormente su
    void setupObj(Object3D *obj);

    //Método para dibujar por pantalla un objeto 3D. En este caso, accederá a los atributos
    //necesarios del objeto y a su shader para poder dibujarlos en pantalla
    void drawObject(Object3D *obj);
};
