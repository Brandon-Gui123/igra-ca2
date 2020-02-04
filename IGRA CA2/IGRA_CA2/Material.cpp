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

Material::Material(const Color4f &ambient, const Color4f &diffuse, const Color4f &specular, GLfloat shininess) : 
    ambient    {ambient.red,  ambient.green,  ambient.blue,  ambient.alpha},
    diffuse     {diffuse.red ,  diffuse.green,   diffuse.blue,   diffuse.alpha}, 
    specular   {specular.red, specular.green, specular.blue, specular.alpha}, 
    shininess  {shininess}
{}

Material::~Material()
{}
