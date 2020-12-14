/**
 * @file Mesh3D.h
 * @author ImperatorMonclu (maurogarciamonclu@gmail.com)
 * @brief 
 * @version 0.1.0
 * @date 13-12-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once
#include <vector>
#include "Vertex.h"

/**
 * @brief Malla 3D donde almacena vértices, triángulos y color
 * 
 */
class Mesh3D
{
private:
    // Identificador único de la malla, asignado en el constructor del objeto
    //(PISTA: Se pueden usar variables de clase estática, actualizadas cada vez que se
    //crea un nuevo objeto Mesh3D)
    glm::uint32 meshID;

    // color básico de esta malla
    glm::vec3 colorRGB;

    //Lista de vértices que forman la malla
    std::vector<struct vertex_t> *vVertList;

    //Lista de índices de vértices. Tres índices seguidos formarán un triángulo
    std::vector<glm::int32> *vIdxList;

public:
    //constructor por defecto de la clase. Inicializa los atributos a valores por defecto
    /**
     * @brief Construct a new Mesh 3D object
     * 
     */
    Mesh3D();

    //devuelve el identificador de esta malla
    /**
     * @brief Get the Mesh ID object
     * 
     * @return glm::uint32 identificador de la malla
     */
    glm::uint32 getMeshID();

    //Método para añadir vértices a la malla
    /**
     * @brief Añade un vértice a la lista de vértices de la malla
     * 
     * @param vertex vértice que se añadirá
     */
    void addVertex(struct vertex_t vertex);

    //Método para añadir un triángulo en base a tres índices de vértices previamente
    //añadidos
    /**
     * @brief Añade un triángulo a partir de 3 identificadores de vértices para la lista.
     * La dirección del plano se rige por la regla de la mano derecha
     * 
     * @param v1 identificador del vértice 1
     * @param v2 identificador del vértice 2
     * @param v3 identificador del vértice 3
     */
    void addTriangleIdx(glm::int32 v1, glm::int32 v2, glm::int32 v3);

    //Método para acceder a la lista de vértices almacenada
    /**
     * @brief Get the Vert List object
     * 
     * @return std::vector<struct vertex_t>* lista con los vértices de la malla
     */
    std::vector<struct vertex_t> *getVertList();

    //Método para acceder a la lista de identificadores de vértices almacenada
    /**
     * @brief Get the Triangle Idx List object
     * 
     * @return std::vector<glm::int32>* lista con los identificadores de los vértices de cada triángulo de la malla
     */
    std::vector<glm::int32> *getTriangleIdxList();

    //método para acceder al color básico de la malla
    /**
     * @brief Get the Color RGB object
     * 
     * @return glm::vec3 color RGB de la malla
     */
    glm::vec3 getColorRGB();

    /**
     * @brief Set the Color RGB object
     * 
     * @param r cantidad de rojo
     * @param g cantidad de verde
     * @param b cantidad de azul
     */
    void setColorRGB(float r, float g, float b);
};
