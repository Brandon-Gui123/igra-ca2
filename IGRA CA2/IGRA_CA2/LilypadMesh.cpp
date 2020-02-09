// Done by Ryan Tan (1829105) from DIT/FT/2B/05

#include "LilypadMesh.h"

#include "Program.h"
#include "Vector3f.h"

#include "framework.h"
#include <gl/GL.h>  // OpenGL 32-bit library
#include <gl/GLU.h> // OpenGL Utilities 32-bit library

#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <vector>

GLUquadricObj *quadratic;

void LilypadMesh::DrawShape()
{
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	quadratic = gluNewQuadric();          // Create A Pointer To The Quadric Object ( NEW )
	gluQuadricNormals(quadratic, GLU_SMOOTH);   // Create Smooth Normals ( NEW )
	gluQuadricTexture(quadratic, GL_TRUE);
	/*GLfloat matcolour[] = { 0, 1, 0.4, 1 };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matcolour);*/

	lilypadMaterial.SetMaterial();

	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW); // Front face is clockwise
	glPolygonMode(GL_FRONT, GL_FILL);
	gluPartialDisk(quadratic, 0, 0.5f, 32, 32, 0, 340);
	glDisable(GL_CULL_FACE);
	glPopMatrix();
}

LilypadMesh::LilypadMesh()
{
}


LilypadMesh::~LilypadMesh()
{
}
