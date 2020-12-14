/**
 * @file TriangleRot.h
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

/**
 * @brief Triángulo en rotación
 * 
 */
class TriangleRot : public Object3D
{
public:
    /**
     * @brief Construct a new Triangle Rot object
     * 
     */
    TriangleRot();

    /**
     * @brief Acción del triángulo en rotación
     * 
     */
    void step();
};
