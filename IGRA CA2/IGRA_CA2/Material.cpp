#include "Material.h"

#include "Color4.h"     // for Color4f, a type alias of the class Color4 which uses GLfloats

#include "framework.h"  // for Window stuff inside the OpenGL library
#include <gl/GL.h>      // for OpenGL 32-bit library

Material::Material() : 
    ambient     {0.f , 0.f , 0.f,  1.f}, 
    diffuse      {0.f , 0.f , 0.f,  1.f}, 
    specular    {0.8f, 0.8f, 0.8f, 1.f}, 
    shininess   {32.f}
{}
