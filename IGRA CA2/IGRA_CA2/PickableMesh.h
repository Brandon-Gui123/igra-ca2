#pragma once

#include "Mesh.h"       // for Mesh class

#include <vector>       // for std::vector class

class PickableMesh : public Mesh
{
private:

    static std::vector<PickableMesh*> pickableMeshes;

};
