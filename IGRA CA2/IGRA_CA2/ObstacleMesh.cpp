#include "ObstacleMesh.h"

#include "framework.h"      // to define the Windows stuff inside the OpenGL library
#include <gl/GL.h>          // for the OpenGL 32-bit library
#include <gl/GLU.h>         // for the OpenGL Utilities 32-bit library

ObstacleMesh::ObstacleMesh(GameObject &gameObject) : PickableMesh{gameObject}, quadric{gluNewQuadric()}
{}

ObstacleMesh::~ObstacleMesh()
{}

void ObstacleMesh::DrawShape()
{
    obstacleMaterial.SetMaterial();
    gluCylinder(quadric, 0.25, 0.25, 1, 12, 12);
}

void ObstacleMesh::DrawToBackBuffer(const Vector3f & position, const Vector3f & rotation, const Vector3f & scale)
{}
