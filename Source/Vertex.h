/**
 * @file Vertex.h
 * @author ImperatorMonclu (maurogarciamonclu@gmail.com)
 * @brief 
 * @version 0.1.0
 * @date 13-12-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once
#include "glm/glm.hpp"

/**
 * @brief Información de un vértice
 * 
 */
typedef struct vertex_t
{
    glm::vec4 pos; /**< Posición del vértice */
} vertex_t;
