#pragma once

#include "Color4.h"     // for Color4ub type alias in Color4
#include "GameObject.h" // for GameObject class
#include "Mesh.h"       // for Mesh class

#include <vector>       // for std::vector class

class PickableMesh : public Mesh
{
private:

    static std::vector<PickableMesh*> pickableMeshes;

    Color4ub pickingColor;

public:

    PickableMesh(GameObject &gameObject);
    ~PickableMesh();

    GameObject &gameObject;

    void Select();
    
};
