#include "ObstacleMesh.h"

#include "framework.h"      // to define the Windows stuff inside the OpenGL library
#include <gl/GL.h>          // for the OpenGL 32-bit library
#include <gl/GLU.h>         // for the OpenGL Utilities 32-bit library

ObstacleMesh::ObstacleMesh(GameObject &gameObject) : PickableMesh{gameObject}, quadric{gluNewQuadric()}
{}

ObstacleMesh::~ObstacleMesh()
{}

void ObstacleMesh::DrawShape()
{}

