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

void ObstacleMesh::DrawToBackBuffer(const Vector3f &position, const Vector3f &rotation, const Vector3f &scale)
{
    glDisable(GL_LIGHTING);
    {
        glPushMatrix();
        {
            glTranslatef(position.x, position.y, position.z);

            glRotatef(rotation.x, 1, 0, 0);
            glRotatef(rotation.y, 0, 1, 0);
            glRotatef(rotation.z, 0, 0, 1);

            glScalef(scale.x, scale.y, scale.z);

            glColor4ub(pickingColor.red, pickingColor.green, pickingColor.blue, 1.f);
            gluCylinder(quadric, 0.25, 0.25, 1, 12, 12);
        }
        glPopMatrix();
    }
    glEnable(GL_LIGHTING);
}
