#pragma once

#include "GameObject.h"     // for GameObject class
#include "PickableMesh.h"   // to inherit from base class PickableMesh

#include "framework.h"      // to define the Windows stuff inside the OpenGL library
#include <gl/GL.h>          // for the OpenGL 32-bit library
#include <gl/GLU.h>         // for the OpenGL Utilities 32-bit library

class ObstacleMesh : public PickableMesh
{
private:

    GLUquadric *quadric;

};

