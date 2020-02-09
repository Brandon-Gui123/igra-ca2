// Done by Brandon Gui (1828865) from DIT/FT/2B/05

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

void Material::SetMaterial()
{
    glMaterialfv(GL_FRONT, GL_AMBIENT, this->ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, this->diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, this->specular);
    glMaterialf(GL_FRONT, GL_SHININESS, this->shininess);
}

Color4f Material::GetAmbient()
{
    return Color4f(ambient[0], ambient[1], ambient[2], ambient[3]);
}

Color4f Material::GetDiffuse()
{
    return Color4f(diffuse[0], diffuse[1], diffuse[2], diffuse[3]);
}

Color4f Material::GetSpecular()
{
    return Color4f(specular[0], specular[1], specular[2], specular[3]);
}

GLfloat Material::GetShininess()
{
    return shininess;
}

void Material::SetAmbient(const Color4f &newAmbient)
{
    ambient[0] = newAmbient.red;
    ambient[1] = newAmbient.green;
    ambient[2] = newAmbient.blue;
    ambient[3] = newAmbient.alpha;
}

void Material::SetDiffuse(const Color4f &newDiffuse)
{
    diffuse[0] = newDiffuse.red;
    diffuse[1] = newDiffuse.green;
    diffuse[2] = newDiffuse.blue;
    diffuse[3] = newDiffuse.alpha;
}

void Material::SetSpecular(const Color4f &newSpecular)
{
    specular[0] = newSpecular.red;
    specular[1] = newSpecular.green;
    specular[2] = newSpecular.blue;
    specular[3] = newSpecular.alpha;
}

void Material::SetShininess(const GLfloat &newShininess)
{
    shininess = newShininess;
}
