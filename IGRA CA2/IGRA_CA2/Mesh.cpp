#include "Mesh.h"

#include "Program.h"
#include "Vector3f.h"

#include "framework.h"
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
};

int cubeNormals[][3] = {
	{0,0,1},
	{0,0,-1},
	{1,0,0},
	{-1,0,0},
	{0,1,0},
	{0,-1,0},
};

float cubeTextureMap[][2]{
	{0,0},
	{0,1.0},
	{1.0,1.0},
	{1.0,0}
};

void Mesh::Draw(const Vector3f &pos, const Vector3f &rot, const Vector3f &sca)
{
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	glRotatef(rot.x, 1, 0, 0);
	glRotatef(rot.y, 0, 1, 0);
	glRotatef(rot.z, 0, 0, 1);
	glScalef(sca.x, sca.y, sca.z);
	glEnable(GL_LIGHTING);
	DrawShape();
	glDisable(GL_LIGHTING);
	glPopMatrix();
}

void Mesh::DrawShape() {
	GLfloat matcolour[] = { 1, 1, 1, 1 };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matcolour);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW); // Front face is clockwise
	glPolygonMode(GL_FRONT, GL_FILL);	
	glEnable(GL_TEXTURE_2D);
	//glColor3f(1, 1, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		64, 64, 0, GL_RGB, GL_UNSIGNED_BYTE, Program::placeholderTexture);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	// The index in cubeIndices array
	// points to next vertex to draw.
	int index = 0;
	// Draw the cube quad by quad
	for (int qd = 0; qd < 6; qd++) {
		glBegin(GL_POLYGON);
		glNormal3f(cubeNormals[qd][0], cubeNormals[qd][1], cubeNormals[qd][2]);
		for (int v = 0; v < 4; v++) {// Four vertices for one quad
			glTexCoord2f(cubeTextureMap[v][0], cubeTextureMap[v][1]);
			glVertex3f(cubeVertices[cubeIndices[index]][0],
				cubeVertices[cubeIndices[index]][1],
				cubeVertices[cubeIndices[index]][2]);
			index++; // Move to next vertex in quad
		}

		glEnd();
	}
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_CULL_FACE);
}
