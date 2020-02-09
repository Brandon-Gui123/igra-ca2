// Done by Ryan Tan (1829105) from DIT/FT/2B/05

#include "PlankMesh.h"

#include "Program.h"
#include "Vector3f.h"

#include "framework.h"
#include <gl/GL.h>  // OpenGL 32-bit library
#include <gl/GLU.h> // OpenGL Utilities 32-bit library

#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <vector>

float cubeVerticesB[][3] = {
	{ -0.6f, -0.2f, 0.6f }, // v0
	{ -0.6f, 0.2f, 0.6f }, // v1
	{ 0.6f, 0.2f, 0.6f }, // v2
	{ 0.6f, -0.2f, 0.6f }, // v3
	{ -0.6f, -0.2f, -4.0f }, // v4
	{ -0.6f, 0.2f, -4.0f }, // v5
	{ 0.6f, 0.2f, -4.0f }, // v6
	{ 0.6f, -0.2f, -4.0f }, // v7
};

int cubeIndicesB[] = {
	0, 1, 2, 3, // Front Face
	7, 6, 5, 4, // Back Face
	2, 6, 7, 3, // Right Face
	0, 4, 5, 1, // Left Face
	1, 5, 6, 2, // Top Face
	3, 7, 4, 0 // Bottom Face
};

float cubeColorsB[][3] = {
	0, 1, 0, // Front is Green
	1, 0, 0, // Back is Red
	0, 0, 1, // Right is Blue
	1, 1, 0, // Left is Yellow
	0, 0, 0, // Top is Black
	0.5, 0.5, 0.5 // Bottom is Grey
};

int cubeNormalsB[][3] = {
	{0,0,1},
	{0,0,-1},
	{1,0,0},
	{-1,0,0},
	{0,1,0},
	{0,-1,0},
};

float cubeTextureMapB[][2]{
	{0,0},
	{0,1.0},
	{1.0,1.0},
	{1.0,0}
};

void PlankMesh::DrawShape()
{
	plankMaterial.SetMaterial();
	glEnable(GL_CULL_FACE);
	{
		glFrontFace(GL_CW); // Front face is clockwise
		glPolygonMode(GL_FRONT, GL_FILL);

		glEnable(GL_TEXTURE_2D);
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
				64, 64, 0, GL_RGB, GL_UNSIGNED_BYTE, Program::woodTexture);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

			// The index in cubeIndices array
			// points to next vertex to draw.
			int index = 0;

			// Draw the cube quad by quad
			for (int qd = 0; qd < 6; qd++) {
				glBegin(GL_POLYGON);
				{
					glNormal3f(cubeNormalsB[qd][0], cubeNormalsB[qd][1], cubeNormalsB[qd][2]);
					for (int v = 0; v < 4; v++) {// Four vertices for one quad
						glTexCoord2f(cubeTextureMapB[v][0], cubeTextureMapB[v][1]);
						glVertex3f(cubeVerticesB[cubeIndicesB[index]][0],
							cubeVerticesB[cubeIndicesB[index]][1] - 0.1f,
							cubeVerticesB[cubeIndicesB[index]][2]);
						index++; // Move to next vertex in quad
					}
				}
				glEnd();
			}
		}
		glDisable(GL_TEXTURE_2D);
	}
	glDisable(GL_CULL_FACE);
}

PlankMesh::PlankMesh()
{
}

PlankMesh::~PlankMesh()
{
}
