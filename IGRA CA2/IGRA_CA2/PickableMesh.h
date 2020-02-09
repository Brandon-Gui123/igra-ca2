// Done by Brandon Gui (1828865) from DIT/FT/2B/05

#pragma once

#include "Color4.h"     // for Color4ub type alias in Color4
#include "GameObject.h" // for GameObject class
#include "Mesh.h"       // for Mesh class
#include "Program.h"    // for friending the Program class and giving it access to the pickableMeshes vector
#include "Vector3f.h"   // for Vector3f class

#include <vector>       // for std::vector class

class PickableMesh : public Mesh
{
private:

    static std::vector<PickableMesh*> pickableMeshes;

    bool markedForDestruction{false};

protected:

    Color4ub pickingColor;

public:

    PickableMesh(GameObject &gameObject);
    ~PickableMesh();

    GameObject &gameObject;

    void Select();
    
    virtual void DrawToBackBuffer(const Vector3f &position, const Vector3f &rotation, const Vector3f &scale) = 0;

    // To allow the Program class to access the static vector of PickableMeshes objects
    // so that it can draw all pickable meshes to the back buffer.
    friend class Program;

    // To allow the GameObject class to also mark the pickable mesh for destruction if its
    // GameObject is marked for destruction.
    friend class GameObject;
};

