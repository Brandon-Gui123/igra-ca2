// Done by Brandon Gui (1828865) from DIT/FT/2B/05

#pragma once

#include "Color4.h"         // for Color4f, a type alias of Color4 which uses GLfloats
#include "GameObject.h"     // for GameObject class
#include "Material.h"       // for Material class
#include "PickableMesh.h"   // to inherit from base class PickableMesh

#include "framework.h"      // to define the Windows stuff inside the OpenGL library
#include <gl/GL.h>          // for the OpenGL 32-bit library
#include <gl/GLU.h>         // for the OpenGL Utilities 32-bit library

class ObstacleMesh : public PickableMesh
{
private:

    GLUquadric *quadric;
    Material obstacleMaterial{Color4f{0.6f, 0.3f, 0.f, 1.f}, Color4f{1.f, 0.f, 0.f, 1.f}, Color4f{1.f, 1.f, 1.f, 1.f}, 32};

public:
    ObstacleMesh(GameObject &gameObject);
    ~ObstacleMesh();

    virtual void DrawShape() override;

    virtual void DrawToBackBuffer(const Vector3f &position, const Vector3f &rotation, const Vector3f &scale) override;
};

