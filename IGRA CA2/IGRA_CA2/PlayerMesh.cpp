#include "PlayerMesh.h"

#include "Program.h"
#include "Vector3f.h"

#include "framework.h"
#include <gl/GL.h>  // OpenGL 32-bit library
#include <gl/GLU.h> // OpenGL Utilities 32-bit library

#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <vector>

float cubeVerticesA[][3] = {
	{ -1.0f, -1.0f, 1.0f }, // v0
	{ -1.0f, 1.0f, 1.0f }, // v1
	{ 1.0f, 1.0f, 1.0f }, // v2
	{ 1.0f, -1.0f, 1.0f }, // v3
	{ -1.0f, -1.0f, -1.0f }, // v4
	{ -1.0f, 1.0f, -1.0f }, // v5
	{ 1.0f, 1.0f, -1.0f }, // v6
	{ 1.0f, -1.0f, -1.0f }, // v7
};

int cubeIndicesA[] = {
	0, 1, 2, 3, // Front Face
	7, 6, 5, 4, // Back Face
	2, 6, 7, 3, // Right Face
	0, 4, 5, 1, // Left Face
	1, 5, 6, 2, // Top Face
	3, 7, 4, 0 // Bottom Face
};

float cubeColorsA[][3] = {
	0, 1, 0, // Front is Green
	1, 0, 0, // Back is Red
	0, 0, 1, // Right is Blue
	1, 1, 0, // Left is Yellow
	0, 0, 0, // Top is Black
	0.5, 0.5, 0.5 // Bottom is Grey
};

int cubeNormalsA[][3] = {
	{0,0,1},
	{0,0,-1},
	{1,0,0},
	{-1,0,0},
	{0,1,0},
	{0,-1,0},
};

float cubeTextureMapA[][2]{
	{0,0},
	{0,1.0},
	{1.0,1.0},
	{1.0,0}
};

void PlayerMesh::DrawShape()
{
	GLfloat matcolour[] = { 1, 1, 0, 1 };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matcolour);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW); // Front face is clockwise
	glPolygonMode(GL_FRONT, GL_FILL);
	glEnable(GL_TEXTURE_2D);
	int index = 0;

	// Draw the cube quad by quad
	for (int qd = 0; qd < 6; qd++) {
		glBegin(GL_POLYGON);
		glNormal3f(cubeNormalsA[qd][0], cubeNormalsA[qd][1], cubeNormalsA[qd][2]);
		for (int v = 0; v < 4; v++) {// Four vertices for one quad
			glTexCoord2f(cubeTextureMapA[v][0], cubeTextureMapA[v][1]);
			glVertex3f(cubeVerticesA[cubeIndicesA[index]][0],
				cubeVerticesA[cubeIndicesA[index]][1],
				cubeVerticesA[cubeIndicesA[index]][2]);
			index++; // Move to next vertex in quad
		}

		glEnd();
	}
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_CULL_FACE);
}

PlayerMesh::PlayerMesh()
{
}

PlayerMesh::~PlayerMesh()
{
}
