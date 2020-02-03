#pragma once

#include "Color4.h"     // for Color4ub type alias in Color4
#include "GameObject.h" // for GameObject class
#include "Mesh.h"       // for Mesh class
#include "Program.h"    // for friending the Program class and giving it access to the pickableMeshes vector

#include <vector>       // for std::vector class

class PickableMesh : public Mesh
{
private:

    static std::vector<PickableMesh*> pickableMeshes;

protected:

    Color4ub pickingColor;

public:

    PickableMesh(GameObject &gameObject);
    ~PickableMesh();

    GameObject &gameObject;

    void Select();
    
    virtual void DrawToBackBuffer() = 0;

    friend class Program;
};

