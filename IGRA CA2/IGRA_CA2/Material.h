#pragma once

#include "Color4.h"     // for Color4f, a type alias of the class Color4 which uses GLfloats

#include "framework.h"  // for Window stuff inside the OpenGL library
#include <gl/GL.h>      // for OpenGL 32-bit library

class Material
{
private:

    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat shininess;

public:

    Material();
    Material(const Color4f &ambient, const Color4f &diffuse, const Color4f &specular, GLfloat shininess);
    ~Material();
};

