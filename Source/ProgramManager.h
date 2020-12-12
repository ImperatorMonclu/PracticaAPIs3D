#pragma once
#include <glm/glm.hpp>

//Singleton
class ProgramManager
{
private:
    glm::int32 globalMeshID;

public:
    static ProgramManager &getInstance()
    {
        static ProgramManager instance;
        return instance;
    }
    glm::int32 getMeshID() { return globalMeshID; }
    void setMeshID(glm::int32 nGlobalMeshID) { globalMeshID = nGlobalMeshID; }

private:
    ProgramManager() { globalMeshID = 1; }
};
