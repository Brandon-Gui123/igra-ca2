#include "Mesh.h"
#include "framework.h"
#include "Vector3f.h"

#include <gl/GL.h>  // OpenGL 32-bit library
#include <gl/GLU.h> // OpenGL Utilities 32-bit library


#include <iostream>   // std::cout
#include <string>     // std::string, std::to_string
#include <vector>

Mesh::Mesh()
{
}
Mesh::~Mesh()
{
}

float cubeVertices[][3] = {
	{ -1.0f, -1.0f, 1.0f }, // v0
	{ -1.0f, 1.0f, 1.0f }, // v1
	{ 1.0f, 1.0f, 1.0f }, // v2
	{ 1.0f, -1.0f, 1.0f }, // v3
	{ -1.0f, -1.0f, -1.0f }, // v4
	{ -1.0f, 1.0f, -1.0f }, // v5
	{ 1.0f, 1.0f, -1.0f }, // v6
	{ 1.0f, -1.0f, -1.0f }, // v7
};

int cubeIndices[] = {
	0, 1, 2, 3, // Front Face
	7, 6, 5, 4, // Back Face
	2, 6, 7, 3, // Right Face
	0, 4, 5, 1, // Left Face
	1, 5, 6, 2, // Top Face
	3, 7, 4, 0 // Bottom Face
};

float cubeColors[][3] = {
	0, 1, 0, // Front is Green
	1, 0, 0, // Back is Red
	0, 0, 1, // Right is Blue
	1, 1, 0, // Left is Yellow
	0, 0, 0, // Top is Black
	0.5, 0.5, 0.5 // Bottom is Grey
};int cubeNormals[][3] = {	{0,0,1},	{0,0,-1},	{1,0,0},	{-1,0,0},	{0,1,0},	{0,-1,0},};

void Mesh::Draw(Vector3f pos, Vector3f rot, Vector3f sca) //TODO, rot and scale
{
	glEnable(GL_LIGHTING);
	GLfloat blue[] = { 0, 0, 1, 0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW); // Front face is clockwise
	glPolygonMode(GL_FRONT, GL_FILL);
	glColor3f(0.0, 0.0, 0.0);
	// The index in cubeIndices array
	// points to next vertex to draw.
	int index = 0;
	// Draw the cube quad by quad
	for (int qd = 0; qd < 6; qd++) {
		glBegin(GL_QUADS);
		//glColor3f(cubeColors[qd][0], cubeColors[qd][1], cubeColors[qd][2]);
		glNormal3f(cubeNormals[qd][0], cubeNormals[qd][1], cubeNormals[qd][2]);
		for (int v = 0; v < 4; v++) {// Four vertices for one quad
			glVertex3f(cubeVertices[cubeIndices[index]][0] + pos.x,
				cubeVertices[cubeIndices[index]][1] + pos.y,
				cubeVertices[cubeIndices[index]][2] + pos.z);
			index++; // Move to next vertex in quad
		}

		glEnd();
	}
	glDisable(GL_LIGHTING);
}
