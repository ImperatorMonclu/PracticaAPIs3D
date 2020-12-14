/**
 * @file ProgramManager.h
 * @author ImperatorMonclu (maurogarciamonclu@gmail.com)
 * @brief 
 * @version 0.1.0
 * @date 14-12-2020
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#pragma once
#include "glm/glm.hpp"

/**
 * @brief Manager del programa el cual actua de patrón "Singleton"
 * 
 */
class ProgramManager
{
private:
    glm::int32 meshID;

public:
    /**
     * @brief Get the Instance object
     * 
     * @return ProgramManager& 
     */
    static ProgramManager &getInstance()
    {
        static ProgramManager instance;
        return instance;
    }

    /**
     * @brief Get the Mesh ID object
     * 
     * @return glm::int32 identificador de la malla
     */
    glm::int32 getMeshID() { return meshID; }

    /**
     * @brief Set the Mesh ID object
     * 
     * @param nMeshID 
     */
    void setMeshID(glm::int32 nMeshID) { meshID = nMeshID; }

private:
    /**
     * @brief Construct a new Program Manager object
     * 
     */
    ProgramManager()
    {
        /**
         * @defgroup staticVariables Variables estáticas
         * 
         * @{
         */
        meshID = 1;
        /**@}*/
    }
};
