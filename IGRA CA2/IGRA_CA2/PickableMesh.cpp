// Done by Brandon Gui (1828865) from DIT/FT/2B/05

#include "PickableMesh.h"

#include "Color4.h"     // for Color4ub type alias in Color4

#include "framework.h"  // to support the Windows stuff inside the GL header file
#include <gl/GL.h>      // for GLubyte

#include <vector>       // for std::vector class

std::vector<PickableMesh*> PickableMesh::pickableMeshes{};

PickableMesh::PickableMesh(GameObject &gameObject) : Mesh{}, gameObject{gameObject}
{
    GLubyte vectorSize{static_cast<GLubyte>(pickableMeshes.size())};

    // TODO overkill but maybe make use of all 3 variables for 16,777,216 possibilities
    // stick with 256 possibilities using just the red value in the color

    pickingColor = Color4ub{static_cast<GLubyte>(vectorSize), static_cast<GLubyte>(0), static_cast<GLubyte>(0), static_cast<GLubyte>(1)};

    pickableMeshes.push_back(this);
}

PickableMesh::~PickableMesh()
{}

void PickableMesh::Select()
{
    gameObject.OnMeshSelected();
}
